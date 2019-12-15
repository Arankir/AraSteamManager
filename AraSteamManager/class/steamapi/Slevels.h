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
#include <class/settings.h>
#include <QObject>

class SLevels : public QObject
{
    Q_OBJECT
public:
    explicit SLevels(QString id, QObject *parent = nullptr);
    SLevels(QJsonDocument DocLevels);
    SLevels();
    ~SLevels();
    void Set(QString id);
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
    Settings _setting;
    QString _steamid;//"76561198065018572"
    int _player_level=0;
    QString _status;
};

#endif // SLEVELS_H
