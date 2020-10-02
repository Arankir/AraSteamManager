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
#include "class/settings.h"
#include "class/statusvalue.h"
#include <QObject>

class SLevels : public QObject
{
    Q_OBJECT
public:
    explicit SLevels(const QString &id, QObject *parent = nullptr);
    SLevels(QJsonDocument &docLevels, QObject *parent = nullptr);
    SLevels(QObject *parent = nullptr);;
    ~SLevels();
    void set(const QString &id);
    void set(QJsonDocument &docLevel);
    int getLevel();
    StatusValue getStatus();
    QString getError();
    void update();

signals:
    void s_finished(SLevels*);
    void s_finished();

private slots:
    //void Load(QNetworkReply *Reply);
    void load();

private:
    QNetworkAccessManager *_manager;
    QString _steamid;//"76561198065018572"
    int _player_level = 0;
    StatusValue _status;
    QString _error = "";

};

#endif // SLEVELS_H
