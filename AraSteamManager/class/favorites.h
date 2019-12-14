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
    bool AddValue(QJsonObject game, QJsonObject newValue, bool deleteIfExist);
    bool RemoveValue(QJsonObject game, QJsonObject newValue);
    void RemoveGame(QJsonObject game);
    int AddGame(QJsonObject game);
    QString GetType();
    QJsonArray GetValues();
    QJsonArray GetValues(QJsonObject game);

private slots:
    void Save();

private:
    Settings _setting;
    QString _path;
    QJsonObject _favorites;
};

#endif // FAVORITES_H
