package com.wiseassblog.domain.repository

import com.wiseassblog.domain.domainmodel.Note
import com.wiseassblog.domain.domainmodel.NoteTransaction
import com.wiseassblog.domain.domainmodel.Result
import kotlinx.coroutines.channels.Channel

interface IPublicNoteRepository {
    suspend fun getNotes():Result<Exception, List<Note>>

    suspend fun getNote(id: String): Result<Exception, Note?>

    suspend fun deleteNote(note: Note): Result<Exception, Unit>

    suspend fun updateNote(note: Note):Result<Exception, Unit>
}