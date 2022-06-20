package com.wiseassblog.spacenotes

import com.wiseassblog.domain.DispatcherProvider
import com.wiseassblog.domain.servicelocator.NoteServiceLocator
import com.wiseassblog.domain.servicelocator.UserServiceLocator
import com.wiseassblog.domain.domainmodel.Note
import com.wiseassblog.domain.domainmodel.Result
import com.wiseassblog.domain.domainmodel.User
import com.wiseassblog.domain.error.SpaceNotesError
import com.wiseassblog.domain.interactor.AnonymousNoteSource
import com.wiseassblog.domain.interactor.AuthSource
import com.wiseassblog.domain.interactor.PublicNoteSource
import com.wiseassblog.domain.interactor.RegisteredNoteSource
import com.wiseassblog.spacenotes.common.*
import com.wiseassblog.spacenotes.notelist.INoteListContract
import com.wiseassblog.spacenotes.notelist.NoteListAdapter
import com.wiseassblog.spacenotes.notelist.NoteListEvent
import com.wiseassblog.spacenotes.notelist.NoteListLogic
import io.mockk.*
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.runBlocking
import org.junit.After
import org.junit.jupiter.api.BeforeEach
import org.junit.jupiter.api.Test

class NoteListLogicTest {

    //This mocking framework is called Mockk
    private val dispatcher: DispatcherProvider = mockk()

    private val noteLocator: NoteServiceLocator = mockk()

    private val userLocator: UserServiceLocator = mockk()

    private val vModel: INoteListContract.ViewModel = mockk(relaxed = true)

    private val adapter: NoteListAdapter = mockk(relaxed = true)

    private val view: INoteListContract.View = mockk(relaxed = true)

    private val anonymous: AnonymousNoteSource = mockk()

    private val registered: RegisteredNoteSource = mockk()

    private val public: PublicNoteSource = mockk()

    private val auth: AuthSource = mockk()


    private val logic = NoteListLogic(
            dispatcher,
            noteLocator,
            userLocator,
            vModel,
            adapter,
            view,
            anonymous,
            registered,
            public,
            auth
    )

    //Shout out to Philipp Hauer @philipp_hauer for the snippet below (creating test data) with
    //a default argument wrapper function:
    fun getNote(creationDate: String = "28/10/2018",
                contents: String = "When I understand that this glass is already broken, every moment with it becomes precious.",
                upVotes: Int = 0,
                imageUrl: String = "",
                creator: User? = User(
                        "8675309",
                        "Ajahn Chah",
                        ""
                )
    ) = Note(
            creationDate = creationDate,
            contents = contents,
            upVotes = upVotes,
            imageUrl = imageUrl,
            creator = creator
    )

    fun getUser(uid: String = "8675309",
                name: String = "Ajahn Chah",
                profilePicUrl: String = ""
    ) = User(uid,
            name,
            profilePicUrl)

    val getNoteList = listOf<Note>(
            getNote(),
            getNote(),
            getNote()
    )


    @BeforeEach
    fun build() {
        clearAllMocks()
        every { dispatcher.provideUIContext() } returns Dispatchers.Unconfined
    }

    /**
     * New Note events will have two possible event streams, based on whether or not the user is
     * in private or public mode
     * a: User is in private mode (could be logged in or anonymous, either case is fine)
     * c: User is in public mode (must be logged in, but we'll check in the other activity to avoid
     * shared mutable state issues)
     *
     * a:
     * 1. check isPrivate status from ViewModel: true
     * 2. startNoteDetailFeatureWithExtras with empty string as extra
     */
    @Test
    fun `On New Note Click Private`() {
        //prepare mock interactions
        every { vModel.getIsPrivateMode() } returns true

        //call the unit to be tested
        logic.onChanged(NoteListEvent.OnNewNoteClick)

        //verify interactions and state if necessary
        verify { view.startNoteDetailFeatureWithExtras("", true) }
    }

    /**
     * b:
     * 1.
     * 2. startNoteDetailFeatureWithExtras with empty string as extra
     */
    @Test
    fun `On New Note Click Public`() {
        //prepare mock interactions
        every { vModel.getIsPrivateMode() } returns false

        //call the unit to be tested
        logic.onChanged(NoteListEvent.OnNewNoteClick)

        //verify interactions and state if necessary
        verify { view.startNoteDetailFeatureWithExtras("", false) }
    }

    /**
     * On bind process, called by view in onCreate. Check current user state, write that result to
     * vModel, show loading graphic, perform some initialization
     *
     * a. User is Anonymous
     * b. User is Registered
     *
     * a:
     * 1. Display Loading View
     * 2. Check for a logged in user from auth: null
     * 3. write null to vModel user state
     * 4. call On start process
     */
    @Test
    fun `On bind User anonymous`() = runBlocking {

        coEvery { auth.getCurrentUser(userLocator) } returns Result.build { null }

        logic.onChanged(NoteListEvent.OnBind)

        coVerify { auth.getCurrentUser(userLocator) }
        verify { vModel.setUserState(null) }
        verify { view.showLoadingView() }
        verify { view.setToolbarTitle(MODE_PRIVATE) }
        verify { view.setAdapter(adapter) }
        verify { adapter.setObserver(logic) }

    }

    @Test
    fun `On bind user registered`() = runBlocking {

        coEvery { auth.getCurrentUser(userLocator) } returns Result.build { getUser() }

        logic.onChanged(NoteListEvent.OnBind)

        coVerify { auth.getCurrentUser(userLocator) }
        verify { vModel.setUserState(getUser()) }
        verify { view.showLoadingView() }
        verify { view.setAdapter(adapter) }
        verify { view.setToolbarTitle(MODE_PRIVATE) }
        verify { adapter.setObserver(logic) }
    }

    @Test
    fun `On bind error retrieving user`() = runBlocking {

        coEvery { auth.getCurrentUser(userLocator) } returns Result.build { throw SpaceNotesError.AuthError }

        logic.onChanged(NoteListEvent.OnBind)

        coVerify { auth.getCurrentUser(userLocator) }
        verify { view.showLoadingView() }
        verify { view.setToolbarTitle(MODE_PRIVATE) }
        verify { view.setAdapter(adapter) }
        verify { adapter.setObserver(logic) }
    }

    /**
     *
     * On start basically means that we want to render the UI. This depends on whether the user is
     * anonymous, or registered (logged out or in), and if they are in public or private mode
     * a. User is anonymous (always private in that case)
     * b. User is registered, private mode
     * c. User is registered, public mode
     *
     * a:
     *1. Check isPrivate status: true
     *2. Check login status in backend if necessary
     *3. parse datasources accordingly
     *4. draw view accordingly
     */
    @Test
    fun `On Start anonymous`() = runBlocking {
        every { vModel.getIsPrivateMode() } returns true
        every { vModel.getUserState() } returns null
        coEvery { anonymous.getNotes(noteLocator) } returns Result.build { getNoteList }

        logic.onChanged(NoteListEvent.OnStart)

        verify { vModel.getIsPrivateMode() }
        verify { vModel.getUserState() }
        verify { view.showList() }
        verify { adapter.submitList(getNoteList) }
        coVerify { anonymous.getNotes(noteLocator) }
    }

    /**
     * b:
     *1. Check isPrivate status: false
     *2. Check login status in backend if necessary
     *3. parse datasources accordingly
     *4. draw view accordingly
     *
     */
    @Test
    fun `On Start Registered Private`() = runBlocking {
        every { vModel.getIsPrivateMode() } returns true
        every { vModel.getUserState() } returns getUser()
        coEvery { registered.getNotes(noteLocator) } returns Result.build { getNoteList }

        logic.onChanged(NoteListEvent.OnStart)

        verify { vModel.getIsPrivateMode() }
        verify { vModel.getUserState() }
        verify { view.showList() }
        verify { adapter.submitList(getNoteList) }
        coVerify { registered.getNotes(noteLocator) }
    }

    /**
     *c:
     *1. Check isPrivate status: false
     *2. Check login status in backend if necessary
     *3. parse datasources accordingly
     *4. draw view accordingly
     *
     */
    @Test
    fun `On Start Registered Public`() = runBlocking {
        every { vModel.getIsPrivateMode() } returns false
        every { vModel.getUserState() } returns getUser()
        coEvery { public.getNotes(noteLocator) } returns Result.build { getNoteList }

        logic.onChanged(NoteListEvent.OnStart)

        verify { vModel.getIsPrivateMode() }
        verify { vModel.getUserState() }
        verify { view.showList() }
        verify { adapter.submitList(getNoteList) }
        coVerify { public.getNotes(noteLocator) }
    }

    /**
     * error:
     *1. Check isPrivate status: false
     *2. Check login status in backend if necessary
     *3. parse datasources accordingly
     *4. draw view accordingly
     *
     */
    @Test
    fun `On Start Error`() = runBlocking {
        every { vModel.getIsPrivateMode() } returns true
        every { vModel.getUserState() } returns getUser()
        coEvery { registered.getNotes(noteLocator) } returns Result.build { throw SpaceNotesError.RemoteIOException }

        logic.onChanged(NoteListEvent.OnStart)

        verify { vModel.getIsPrivateMode() }
        verify { vModel.getUserState() }
        verify { view.showEmptyState() }
        verify { view.showErrorState(MESSAGE_GENERIC_ERROR) }
        coVerify { registered.getNotes(noteLocator) }
    }

    /**
     * For empty list, leave the loading animation active.
     */
    @Test
    fun `On Start a with empty list`() = runBlocking {
        every { vModel.getIsPrivateMode() } returns true
        every { vModel.getUserState() } returns getUser()
        coEvery { registered.getNotes(noteLocator) } returns Result.build { emptyList<Note>() }

        logic.onChanged(NoteListEvent.OnStart)

        verify { vModel.getIsPrivateMode() }
        verify { vModel.getUserState() }
        verify { view.showEmptyState() }
        verify { adapter.submitList(emptyList<Note>()) }
        coVerify { registered.getNotes(noteLocator) }
    }

    /**
     * c. auth is logged in and in public mode
     *1. Check auth status
     *2. Check isPrivate status
     *3.  parse datasources accordingly
     */
    @Test
    fun `On Start Public Mode`() = runBlocking {
        every { vModel.getIsPrivateMode() } returns false
        coEvery { public.getNotes(noteLocator) } returns Result.build { getNoteList }

        logic.onChanged(NoteListEvent.OnStart)

        verify { vModel.getIsPrivateMode() }
        verify { view.showList() }
        verify { adapter.submitList(getNoteList) }
        coVerify { public.getNotes(noteLocator) }
    }


    /**
     * On login click, send auth to Auth Activity in order to manage their login status
     *
     *1. start login activity
     */
    @Test
    fun `On Login Click `() {

        logic.onChanged(NoteListEvent.OnLoginClick)

        verify { view.startLoginFeature() }
    }

    /**
     * On Note Item Click, auth wishes to navigate to a detailed view of the selected item
     *a: isPrivate = true
     *1. Get appropriate Note from vModel
     *2. Get isPrivate from vModel
     *2. Start detail Activity with note id passed as extra, and isPrivate result
     */
    @Test
    fun `On Note Item Click a`() = runBlocking {


        every { vModel.getIsPrivateMode() } returns true
        every { vModel.getAdapterState() } returns getNoteList

        //auth selects first item in adapter
        val clickEvent = NoteListEvent.OnNoteItemClick(0)

        logic.onChanged(clickEvent)

        verify { view.startNoteDetailFeatureWithExtras(getNote().creationDate, true) }
        verify { vModel.getAdapterState() }
        verify { vModel.getIsPrivateMode() }
    }


    /**
     *b: isPrivate = false
     *1. Get appropriate Note from vModel
     *2. Get isPrivate from vModel
     *2. Start detail Activity with note id passed as extra, and isPrivate result
     */
    @Test
    fun `On Note Item Click b`() = runBlocking {

        every { vModel.getIsPrivateMode() } returns false
        every { vModel.getAdapterState() } returns getNoteList

        //auth selects first item in adapter
        val clickEvent = NoteListEvent.OnNoteItemClick(0)

        logic.onChanged(clickEvent)

        verify { view.startNoteDetailFeatureWithExtras(getNote().creationDate, false) }
        verify { vModel.getAdapterState() }
        verify { vModel.getIsPrivateMode() }
    }

    /**
     * When the user wants to switch between private and public mode
     * a: User is logged in, currently in private mode
     * b: User is logged in, currently in public mode
     * c: User is logged out, private only
     *
     *a:
     *1. Check current user status: User
     *2. Get isPrivate from vModel: true
     *3. Request public notes from repo: Notes
     *4. Update view/adapter appropriately
     *  */
    @Test
    fun `On Toggle Public Mode`() = runBlocking {

        every { vModel.getIsPrivateMode() } returns true andThen false
        coEvery { public.getNotes(noteLocator) } returns Result.build { getNoteList }

        logic.onChanged(NoteListEvent.OnTogglePublicMode)

        verify { vModel.setAdapterState(getNoteList) }
        verify { vModel.getIsPrivateMode() }
        verify { adapter.submitList(getNoteList) }
        coVerify { public.getNotes(noteLocator) }
        //ought to be false and MODE_PUBLIC, but
        verify { view.setPrivateIcon(false) }
        verify { view.setToolbarTitle(MODE_PUBLIC) }

    }

    /**
     * b:
    *1. Check current user status: User
    *2. Get isPrivate from vModel: false
    *3. Request private notes from repo: Notes
    *4. Update view/adapter appropriately
    *  */
    @Test
    fun `On Toggle Private Mode`() = runBlocking {


        every { vModel.getIsPrivateMode() } returns false andThen true
        coEvery { registered.getNotes(noteLocator) } returns Result.build { getNoteList }

        logic.onChanged(NoteListEvent.OnTogglePublicMode)

        verify { vModel.setAdapterState(getNoteList) }
        verify { vModel.getIsPrivateMode() }
        verify { adapter.submitList(getNoteList) }
        coVerify { registered.getNotes(noteLocator) }
        verify { view.setPrivateIcon(true) }
        verify { view.setToolbarTitle(MODE_PRIVATE) }
    }

    /**
     * C:
     *1. Check current user status: no user
     *2. Tell user to log in if they want to use the public feature
     *  */
    @Test
    fun `On Toggle Private Mode logged out`() = runBlocking {
        every { vModel.getUserState() } returns null

        logic.onChanged(NoteListEvent.OnTogglePublicMode)

        verify { view.showErrorState(MESSAGE_LOGIN) }
    }

    @After
    fun confirm() {
        excludeRecords { dispatcher.provideUIContext() }
        confirmVerified(
                dispatcher,
                noteLocator,
                userLocator,
                vModel,
                adapter,
                view,
                anonymous,
                registered,
                public,
                auth
        )
    }

}