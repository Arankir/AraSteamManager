#include "threadloading.h"

ThreadLoading::ThreadLoading(): _thread(new ThreadInfo) {
    this->moveToThread(_thread);
    connect(this, &ThreadLoading::s_finished,   _thread,    &QThread::quit);
    connect(this, &ThreadLoading::s_finished,   this,       &ThreadLoading::deleteLater);
    connect(_thread, &QThread::started,         this,       &ThreadLoading::fill);
}

ThreadLoading::~ThreadLoading() {
    if (_thread) {
        _thread->quit();
        _thread->deleteLater();
    }
}
