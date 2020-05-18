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

enum class jsonType{
    object,
    array
};

public:
    explicit Favorites(QString path, QString type, QObject *parent = nullptr);
    Favorites(QObject *a_parent = nullptr): QObject(a_parent) {}

signals:

public slots:
    void SetType(QString type);
    bool AddValue(QJsonObject newValue, bool deleteIfExist);
    bool AddValue(QJsonArray newValue, bool deleteIfExist);
    bool AddValue(QJsonObject game, QJsonObject newValue, bool deleteIfExist);
    void RemoveValue(QJsonObject newValue);
    void RemoveValue(QJsonArray newValue);
    bool RemoveValue(QJsonObject game, QJsonObject newValue);
    void RemoveGame(QJsonObject game);
    int AddGame(QJsonObject game);
    QString GetType() {return _favorites.value("Type").toString();}
    QJsonArray GetValues() {return _favorites.value("Values").toArray();}
    QJsonArray GetValues(QJsonObject game);

private slots:
    void Save();

private:
    void Init(QString type);
    bool AddValue(QJsonValue newValue, bool deleteIfExist, jsonType type);
    void RemoveValue(QJsonValue newValue);
    void Load();

    Settings _setting;
    QString _path;
    QJsonObject _favorites;
};

#endif // FAVORITES_H
