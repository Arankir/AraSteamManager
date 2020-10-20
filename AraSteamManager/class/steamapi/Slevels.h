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
#include "class/steamapi/Sapi.h"
#include <QObject>

class SLevels : public Sapi
{
    Q_OBJECT
public:
    explicit SLevels(const QString &id, QObject *parent = nullptr);
    SLevels(QObject *parent = nullptr): Sapi(parent) {}
    ~SLevels() {}

    SLevels &load(const QString &steamId);
    SLevels &update();

    int getLevel() const;

signals:
    void s_finished(SLevels*);
    void s_finished();

private slots:
    void onLoad() override;
    void parse(const QJsonDocument &doc);

private:
    QString _steamid;//"76561198065018572"
    int _player_level = 0;

};

#endif // SLEVELS_H
