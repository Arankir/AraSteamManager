#include "requestdata.h"

#include <QEventLoop>
#include <QNetworkReply>

RequestData::RequestData(const QString &aUrl, bool aParallel, QObject *aParent): RequestData(QUrl(aUrl), aParallel, aParent) {

}

RequestData::RequestData(const QUrl &aUrl, bool aParallel, QObject *aParent): QObject(aParent), manager_(new QNetworkAccessManager), reply_(""), url_(aUrl) {
    connect(manager_, &QNetworkAccessManager::finished, this, &RequestData::onResultGet);
    if (!aUrl.isEmpty()) {
        get(aUrl,aParallel);
    }
}

RequestData::RequestData(QObject *aParent): RequestData("", true, aParent) {

}

RequestData::~RequestData() {
    disconnect(manager_, &QNetworkAccessManager::finished, this, &RequestData::onResultGet);
    delete manager_;
}

void RequestData::get(const QString &aUrl, bool aParallel) {
    get(QUrl(aUrl), aParallel);
}

void RequestData::get(const QUrl &aUrl, bool aParallel) {
    manager_->get(QNetworkRequest(aUrl));
    if (!aParallel) {
        QEventLoop loop;
        connect(manager_, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
        loop.exec();
        disconnect(manager_, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    }
}

QByteArray RequestData::reply() const {
    return reply_;
}

QString RequestData::error() const {
    return error_;
}

void RequestData::onResultGet(QNetworkReply *aReply) {
    error_ = aReply->errorString();
//    auto error = aReply->error();
    if(!error_.isEmpty()) {
        reply_ = aReply->readAll();
    } else {
        qWarning() << aReply->url() << error_;
    }
    aReply->deleteLater();
    emit s_finished(this);
}
