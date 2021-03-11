#include "requestdata.h"

RequestData::RequestData(const QString &aUrl, bool aParallel, QObject *aParent): QObject(aParent), _manager(new QNetworkAccessManager), _reply(""), _url(aUrl) {
    connect(_manager, &QNetworkAccessManager::finished, this, &RequestData::onResultGet);
    if (!aUrl.isEmpty()) {
        get(aUrl,aParallel);
    }
}

RequestData::~RequestData() {
    disconnect(_manager, &QNetworkAccessManager::finished, this, &RequestData::onResultGet);
    delete _manager;
}

void RequestData::get(const QString &aUrl, bool aParallel) {
    get(QUrl(aUrl), aParallel);
}

void RequestData::get(const QUrl &aUrl, bool aParallel) {
    _manager->get(QNetworkRequest(aUrl));
    if (!aParallel) {
        QEventLoop loop;
        connect(_manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
        loop.exec();
        disconnect(_manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    }
}

void RequestData::onResultGet(QNetworkReply *aReply) {
    if(!aReply->error()) {
        _reply = aReply->readAll();
    }
    emit s_finished(this);
}
