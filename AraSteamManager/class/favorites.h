#ifndef FAVORITES_H
#define FAVORITES_H

#include <QObject>
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include "class/settings.h"

class Favorites : public QObject {
    Q_OBJECT

enum class jsonType {
    object,
    array
};

public slots:
    void setType(const QString &type);
    bool addValue(QJsonObject &newValue, bool deleteIfExist);
    bool addValue(QJsonArray &newValue, bool deleteIfExist);
    bool addValue(QJsonObject &game, QJsonObject &newValue, bool deleteIfExist);
    void removeValue(QJsonObject &newValue);
    void removeValue(QJsonArray &newValue);
    bool removeValue(QJsonObject &game, QJsonObject &newValue);
    void removeGame(QJsonObject &game);
    int addGame(QJsonObject &game);
    bool isInFavorites(QJsonObject &aGame, const QString &id);
    QString getType() const;
    QJsonArray getValues() const;
    QJsonArray getValues(QJsonObject &game) const;

public:
    explicit Favorites(const QString &path, const QString &type, QObject *parent = nullptr);
    Favorites(const QString &type, QObject *parent = nullptr);
    Favorites(QObject *parent = nullptr): QObject(parent) {}

signals:

private slots:
    void save();
    void init(const QString &type);
    bool addValue(QJsonValue newValue, bool deleteIfExist, jsonType type);
    void removeValue(QJsonValue newValue);
    void load();

private:
    QString _path;
    QJsonObject _favorites;
};

#endif // FAVORITES_H
