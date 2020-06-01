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
#include <class/settings.h>
#include <QEventLoop>
#include <QDir>

class RequestData : public QObject
{
    Q_OBJECT
public:
    RequestData(QString url, bool parallel, QObject *parent = nullptr);
    RequestData(QObject *parent = nullptr);;
    ~RequestData();
    void get(QString url, bool parallel = false);
    QByteArray getAnswer();
    QPixmap getPixmap();
    //int GetRow() {return _row;}

signals:
    void s_finished(RequestData *imgr);

public slots:
    void onResultGet(QNetworkReply *reply);

private:
    QNetworkAccessManager *_manager;
    QByteArray _answer;
    QString _url;
    //int _row;
    Settings _setting;

};

#endif // IMAGEREQUEST_H
