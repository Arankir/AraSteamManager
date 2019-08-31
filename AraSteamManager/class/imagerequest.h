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

class ImageRequest : public QObject
{
    Q_OBJECT
public:
    explicit ImageRequest(int i, QString Save, QObject *parent = nullptr);
    ~ImageRequest();
    void Get(QString str);
    QByteArray GetAnswer();

signals:
    void onReady(int i, QString Save, ImageRequest *imgr);

private:
    QNetworkAccessManager *manager;
    QByteArray answer;
    int i;
    QString Save;

public slots:
    void OnResultGet(QNetworkReply *reply);
};

#endif // IMAGEREQUEST_H
