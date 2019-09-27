#ifndef SLEVELS_H
#define SLEVELS_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTextCodec>
#include <QTcpSocket>
#include <QEventLoop>
#include <QObject>

class SLevels : public QObject
{
    Q_OBJECT
public:
    explicit SLevels(QString key, QString id, QObject *parent = nullptr);
    SLevels(QJsonDocument DocLevels);
    SLevels();
    ~SLevels();
    void Set(QString key, QString id);
    void Set(QJsonDocument DocLevel);
    int GetPlayer_level() {return player_level;}
    QString GetStatus() {return status;}
    void Update();

signals:
    void finished(SLevels*);
    void finished();

public slots:
    //void Load(QNetworkReply *Reply);

private:
    QNetworkAccessManager *manager;
    QString steamid;//"76561198065018572"
    int player_level=0;
    QString status;
    QString key;
};

#endif // SLEVELS_H
