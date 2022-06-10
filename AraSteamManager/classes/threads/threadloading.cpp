#include "threadloading.h"

ThreadLoading::ThreadLoading(): thread_(new ThreadInfo) {
    this->moveToThread(thread_);
    connect(this, &ThreadLoading::s_finished,   thread_,    &QThread::quit);
    connect(this, &ThreadLoading::s_finished,   this,       &ThreadLoading::deleteLater);
    connect(thread_, &QThread::started,         this,       &ThreadLoading::fill);
}

ThreadLoading::~ThreadLoading() {
    if (thread_) {
        thread_->quit();
        thread_->deleteLater();
    }
}
