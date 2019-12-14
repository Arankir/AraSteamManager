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
    int GetLevel() {return _player_level;}
    QString GetStatus() {return _status;}
    void Update();

signals:
    void s_finished(SLevels*);
    void s_finished();

public slots:
    //void Load(QNetworkReply *Reply);

private:
    QNetworkAccessManager *_manager;
    QString _steamid;//"76561198065018572"
    int _player_level=0;
    QString _status;
    QString _key;
};

#endif // SLEVELS_H
