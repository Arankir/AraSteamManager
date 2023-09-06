#ifndef HIDDENGAMES_H
#define HIDDENGAMES_H

#include "classes/steamApi/structures/sgames.h"
#include "classes/steamApi/structures/sprofile.h"
#include "classes/common/filesaveload.h"

class HiddenGame {
public:
    HiddenGame(const SGame &game);
    HiddenGame(const GameID &gameId, const QString &name, const QString &iconUrl);
    HiddenGame(const HiddenGame &game);
    HiddenGame(const QJsonObject &game);
    HiddenGame &fromJson(const QJsonObject &object);
    HiddenGame &operator=(const HiddenGame &object);
    QJsonObject toJson() const;

    GameID id() const;
    QString name() const;
    QString iconUrl() const;

private:
    GameID id_;
    QString name_;
    QString iconUrl_;
};

class HiddenGames: public QList<HiddenGame>, public FileSaveLoad {
public:
    HiddenGames(const ProfileID &profileId = "", bool isIncludeAll = false);
    void remove(const GameID &gameId);
    bool isGameExist(const GameID &gameId);

private:
    void load(const ProfileID &);
    QJsonObject toJson() const override;
    void fromJson(const QJsonObject &object) override;

    ProfileID profile_;
};

#endif // HIDDENGAMES_H
