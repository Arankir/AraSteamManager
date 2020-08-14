#include "requestdata.h"

RequestData::RequestData(QString aUrl, bool aParallel, QObject *aParent): QObject(aParent), _answer(""), _url(aUrl) {
    _manager = new QNetworkAccessManager();
    connect(_manager, &QNetworkAccessManager::finished, this, &RequestData::onResultGet);
    if (!aUrl.isEmpty()) {
        get(aUrl,aParallel);
    }
}

RequestData::RequestData(QObject *parent): RequestData("", true, parent) {

}

void RequestData::get(QString aUrl, bool aParallel) {
    _manager->get(QNetworkRequest(QUrl(aUrl)));
    if (!aParallel) {
        QEventLoop loop;
        connect(_manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
        loop.exec();
        disconnect(_manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    }
}

QByteArray RequestData::getAnswer() {
    return _answer;
}

QPixmap RequestData::getPixmap() {
    QPixmap result;
    result.loadFromData(_answer);
    return result;
}

void RequestData::onResultGet(QNetworkReply *aReply) {
    if(!aReply->error()) {
        _answer=aReply->readAll();
    }
    emit s_finished(this);
}

RequestData::~RequestData() {
    disconnect(_manager, &QNetworkAccessManager::finished, this, &RequestData::onResultGet);
    delete _manager;
}
