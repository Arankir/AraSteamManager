#include "threadloading.h"

void ThreadLoading::start() {
    thread_->start();
}

ThreadLoading::ThreadLoading(): thread_(new ThreadInfo) {
    this->moveToThread(thread_);
    connect(this, &ThreadLoading::s_finished,   thread_,    &QThread::quit);
    connect(this, &ThreadLoading::s_finished,   this,       &ThreadLoading::deleteLater);
    connect(thread_, &QThread::started,         this,       &ThreadLoading::fill);
}

ThreadLoading::~ThreadLoading() {
    if (thread_) {
        thread_->quit();
        disconnect(this, &ThreadLoading::s_finished,   thread_,    &QThread::quit);
        disconnect(this, &ThreadLoading::s_finished,   this,       &ThreadLoading::deleteLater);
        disconnect(thread_, &QThread::started,         this,       &ThreadLoading::fill);
        thread_->deleteLater();
    }
}

ThreadInfo::~ThreadInfo() {
    qInfo() << "Thread deleted";
}
