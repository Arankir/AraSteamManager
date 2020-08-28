#ifndef FAVORITES_H
#define FAVORITES_H

#include <QObject>
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <class/settings.h>

class Favorites : public QObject {
    Q_OBJECT

enum class jsonType{
    object,
    array
};

public slots:
    void setType(QString type);
    bool addValue(QJsonObject newValue, bool deleteIfExist);
    bool addValue(QJsonArray newValue, bool deleteIfExist);
    bool addValue(QJsonObject game, QJsonObject newValue, bool deleteIfExist);
    void removeValue(QJsonObject newValue);
    void removeValue(QJsonArray newValue);
    bool removeValue(QJsonObject game, QJsonObject newValue);
    void removeGame(QJsonObject game);
    int addGame(QJsonObject game);
    bool isInFavorites(QJsonObject aGame, QString id);
    QString getType();
    QJsonArray getValues();
    QJsonArray getValues(QJsonObject game);

public:
    explicit Favorites(QString path, QString type, QObject *parent = nullptr);
    Favorites(QString type, QObject *parent = nullptr);
    Favorites(QObject *a_parent = nullptr);

signals:

private slots:
    void save();
    void init(QString type);
    bool addValue(QJsonValue newValue, bool deleteIfExist, jsonType type);
    void removeValue(QJsonValue newValue);
    void load();

private:
    Settings _setting;
    QString _path;
    QJsonObject _favorites;
};

#endif // FAVORITES_H
