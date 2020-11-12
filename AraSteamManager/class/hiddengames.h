#ifndef HIDDENGAMES_H
#define HIDDENGAMES_H

#include "class/steamapi/Sgames.h"
#include "class/steamapi/Sprofile.h"

struct gameData {
    QString id;
    QString name;
    QString iconUrl;
};

class HiddenGames {
public:
    HiddenGames(SProfile profile = SProfile());

    HiddenGames &addGame(const SGame &game, bool removeIfExist = false);
    HiddenGames &removeGame(const SGame &game, bool addIfExist = false);
    HiddenGames &save();

    QList<gameData> getGames() const {return _games;}

private:
    void load();
    QJsonObject toJson();

    QList<gameData> _games;
    QString _profile;
};

#endif // HIDDENGAMES_H
