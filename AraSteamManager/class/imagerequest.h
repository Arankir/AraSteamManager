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
#include <QDir>

class ImageRequest : public QObject
{
    Q_OBJECT
public:
    explicit ImageRequest(QString url, int column=-1, QString save="", bool autosave=false, QObject *parent = nullptr);
    ImageRequest();
    ~ImageRequest();
    void LoadImage(QString url, int column=-1, QString save="", bool autosave=false);
    void Get(QString str);
    QByteArray GetAnswer() {return _answer;}
    QString GetSave() {return _save;}
    int GetRow() {return _row;}

signals:
    void s_finished(ImageRequest *imgr);

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
