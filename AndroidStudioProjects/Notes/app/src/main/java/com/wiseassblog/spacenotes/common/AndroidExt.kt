package com.wiseassblog.spacenotes.common

import android.app.Activity
import android.content.Intent

import android.text.Editable
import android.widget.Toast
import androidx.fragment.app.Fragment
import androidx.fragment.app.FragmentManager
import com.wiseassblog.spacenotes.notedetail.NoteDetailActivity
import com.wiseassblog.spacenotes.notedetail.NoteDetailView
import com.wiseassblog.spacenotes.notelist.NoteListActivity
import java.text.SimpleDateFormat
import java.util.*

internal fun String.toEditable(): Editable = Editable.Factory.getInstance().newEditable(this)


internal fun Activity.attachFragment(manager: FragmentManager, containerId: Int, view: Fragment, tag: String) {
    manager.beginTransaction()
            .replace(containerId, view, tag)
            .commitNowAllowingStateLoss()
}

internal fun Fragment.getCalendarTime(): String {
    val cal = Calendar.getInstance(TimeZone.getDefault())
    val format = SimpleDateFormat("d MMM yyyy HH:mm:ss Z")
    format.timeZone = cal.timeZone
    return format.format(cal.time)
}

internal fun Fragment.makeToast(value: String) {
    Toast.makeText(activity, value, Toast.LENGTH_SHORT).show()
}

internal fun Fragment.restartCurrentFeature() {
    val i: Intent
    when (this) {
        is NoteDetailView -> {
            i = Intent(this.activity, NoteDetailActivity::class.java)
        }

        //To Be Added

        else -> {
            i = Intent(this.activity, NoteListActivity::class.java)
        }
    }

    this.activity?.finish()
    startActivity(i)
}