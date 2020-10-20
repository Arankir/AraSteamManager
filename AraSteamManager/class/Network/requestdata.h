#ifndef IMAGEREQUEST_H
#define IMAGEREQUEST_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTextCodec>
#include <QTcpSocket>
#include "class/settings.h"
#include <QEventLoop>
#include <QDir>

class RequestData : public QObject
{
    Q_OBJECT
public:
    RequestData(const QString &url, bool parallel, QObject *parent = nullptr);
    RequestData(QObject *parent = nullptr): RequestData("", true, parent) {}
    ~RequestData();

    void get(const QString &url, bool parallel = false);

    QByteArray getReply() const {return _reply;}

signals:
    void s_finished(RequestData *imgr);

private slots:
    void onResultGet(QNetworkReply *reply);

private:
    QNetworkAccessManager *_manager;
    QByteArray _reply;
    QString _url;

};

#endif // IMAGEREQUEST_H
