#ifndef FAVORITES_H
#define FAVORITES_H

#include <QObject>
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <class/settings.h>

class Favorites : public QObject
{
    Q_OBJECT
public:
    explicit Favorites(QString path, QString type, QObject *parent = nullptr);
    Favorites();

signals:

public slots:
    void SetPath(QString path, QString type);
    void SetType(QString type);
    bool AddValue(QJsonObject newValue, bool deleteIfExist);
    void RemoveValue(QJsonObject newValue);
    bool AddValue(QJsonArray newValue, bool deleteIfExist);
    void RemoveValue(QJsonArray newValue);
    bool AddValue(QString game, QJsonObject newValue, bool deleteIfExist);
    bool RemoveValue(QString game, QJsonObject newValue);
    void RemoveGame(QString game);
    int AddGame(QString game);
    QString GetType();
    QJsonArray GetValues();

private slots:
    void Save();

private:
    Settings Setting;
    QString path;
    QJsonObject favorites;
};

#endif // FAVORITES_H
