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
    explicit ImageRequest(QString url, int row, QString save, bool autosave, QObject* parent = nullptr);
    ImageRequest();
    ~ImageRequest();
    void LoadImage(QString url, int column=-1, QString save="", bool autosave=false);
    void Get(QString str);
    QByteArray GetAnswer() {return answer;}
    QString GetSave() {return Save;}
    int GetRow() {return i;}

signals:
    void onReady(ImageRequest* imgr);

private:
    QNetworkAccessManager* manager;
    QByteArray answer;
    QString Url;
    int i;
    QString Save;
    bool Autosave;
    Settings Setting;

public slots:
    void OnResultGet(QNetworkReply* reply);
};

#endif // IMAGEREQUEST_H
