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
    explicit RequestData(QString url, int column=-1, QString save="", bool autosave=false, QObject *parent = nullptr);
    RequestData(QString str, bool parallel, QObject *parent = nullptr);
    RequestData(QObject *parent = nullptr);
    ~RequestData();
    void LoadImage(QString url, int column=-1, QString save="", bool autosave=false);
    void Get(QString str, bool parallel = false);
    QByteArray GetAnswer() {return _answer;}
    QPixmap GetPixmap() { QPixmap result; result.loadFromData(_answer); return result;}
    QString GetSave() {return _save;}
    int GetRow() {return _row;}

signals:
    void s_finished(RequestData *imgr);

private:
    QNetworkAccessManager *_manager;
    QByteArray _answer;
    QString _url;
    int _row;
    QString _save;
    bool _autosave;
    Settings _setting;

public slots:
    void OnResultGet(QNetworkReply *reply);
};

#endif // IMAGEREQUEST_H
