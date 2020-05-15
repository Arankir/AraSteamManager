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
    RequestData(QObject *parent = nullptr):RequestData("",true,parent){};
    ~RequestData();
    void Get(QString url, bool parallel = false);
    QByteArray GetAnswer() {return _answer;}
    QPixmap GetPixmap() { QPixmap result; result.loadFromData(_answer); return result;}
    //int GetRow() {return _row;}

signals:
    void s_finished(RequestData *imgr);

private:
    QNetworkAccessManager *_manager;
    QByteArray _answer;
    QString _url;
    //int _row;
    Settings _setting;

public slots:
    void OnResultGet(QNetworkReply *reply);
};

#endif // IMAGEREQUEST_H
