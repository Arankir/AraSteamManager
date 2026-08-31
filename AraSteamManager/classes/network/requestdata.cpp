#include "requestdata.h"

#include "qurlquery.h"

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
    reply_.clear();
    error_.clear();

    QNetworkRequest request(aUrl);
    request.setAttribute(QNetworkRequest::Http2AllowedAttribute, false);
    request.setHeader(QNetworkRequest::UserAgentHeader, "AraSteamManager/1.0");
    request.setTransferTimeout(15000);

    manager_->get(request);

    if (!aParallel) {
        QEventLoop loop;
        connect(manager_, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
        loop.exec();
        disconnect(manager_, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    }
}

bool RequestData::success() const
{
    return error_.isEmpty();
}

QByteArray RequestData::reply() const {
    return reply_;
}

QString RequestData::error() const {
    return error_;
}

void RequestData::onResultGet(QNetworkReply *aReply) {
    const int statusCode = aReply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

    const QByteArray body = aReply->readAll();

    if (aReply->error() == QNetworkReply::NoError) {
        reply_ = body;
        error_.clear();
    } else {
        reply_.clear();
        error_ = aReply->errorString();

        QUrl safeUrl = aReply->url();
        QUrlQuery query(safeUrl);
        query.removeAllQueryItems("key");
        safeUrl.setQuery(query);

        qWarning() << "Request failed:" << safeUrl << "networkError =" << static_cast<int>(aReply->error()) << "httpStatus =" << statusCode
                   << "error =" << aReply->errorString() << "retryAfter =" << aReply->rawHeader("Retry-After") << "body =" << body.left(300);
    }
    aReply->deleteLater();
    emit s_finished(this);
}
