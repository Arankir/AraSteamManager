#include "Sgames.h"

#define SGameStart {
SGame &SGame::operator=(const SGame &aGame) {
    _numberPlayers = aGame._numberPlayers;
    _pixmapIcon = aGame._pixmapIcon;
    _pixmapLogo = aGame._pixmapLogo;
    return *this;
}

bool SGame::operator<(const SGame &aGame) {
//    qDebug() << _name.compare(aGame._name, Qt::CaseInsensitive);
    return (_name < aGame._name);
}

QPixmap SGame::getPixmapIcon() {
    return loadPixmap(_pixmapIcon, Sapi::gameImageUrl(QString::number(_appID), _img_icon_url), Paths::imagesGames(_img_icon_url), QSize(32, 32));
}

QPixmap SGame::getPixmapLogo() {
    return loadPixmap(_pixmapLogo, Sapi::gameImageUrl(QString::number(_appID), _img_logo_url), Paths::imagesGames(_img_logo_url), QSize(184, 69));
}

const QString SGame::getNumberPlayers(bool hardReload) {
    if (_numberPlayers == "" || hardReload) {
//        _request.get(numberPlayersUrl(QString::number(_appID)), false);
//        double playersCount = QJsonDocument::fromJson(_request.getReply()).object().value("response").toObject().value("player_count").toDouble();
//        _numberPlayers = QString::number(playersCount);
    }
    return _numberPlayers;
}
#define SGameEnd }
#define SGamesStart {
SGames::SGames(const QString &aId, int aFreeGames, int aGameInfo, bool aParallel, QObject *aParent): Sapi(aParent) {
    load(aId, aFreeGames, aGameInfo, aParallel);
}

SGames &SGames::operator=(const SGames &aGames) {
    Sapi::operator=(aGames);
    _games      = aGames._games;
    _id         = aGames._id;
    _free_games = aGames._free_games;
    _game_info  = aGames._game_info;
    return *this;
}

SGames &SGames::load(const QString &aId, int aFreeGames, int aGameInfo, bool aParallel) {
    _id         = aId;
    _free_games = aFreeGames;
    _game_info  = aGameInfo;
    _request.get(gameUrl(_free_games, _game_info, _id), aParallel);
    return *this;
}

void SGames::onLoad() {
    fromJson(QJsonDocument::fromJson(_request.getReply()).object().value("response").toObject().value("games"));
    emit s_finished(this);
    emit s_finished();
}

void SGames::fromJson(const QJsonValue &aValue) {
    clear();
    QJsonArray gamesArray = aValue.toArray();
    if (gamesArray.size() > 0) {
        for (const auto &game: gamesArray) {
            _games.append(std::move(SGame(game.toObject())));
        }
        _status = StatusValue::success;
    } else {
        _status = StatusValue::error;
        _error = tr("game is not exist");
    }
}

SGames &SGames::update(bool aParallel) {
    load(_id, _free_games, _game_info, aParallel);
    return *this;
}

SGames &SGames::clear() {
    _games.clear();
    return *this;
}

SGames &SGames::sort() {
    //Переделать нормально
//    std::sort(_games.begin(), _games.end(), [](const SGame &s1, const SGame &s2)-> const bool {
//                            return s1._name.compare(s2._name, Qt::CaseInsensitive) < 0;
//                        });
    std::list<SGame> list(_games.begin(), _games.end());
    list.sort(  [](const SGame &s1, const SGame &s2)-> const bool {
                    return s1._name.compare(s2._name, Qt::CaseInsensitive) < 0;
                });
    _games = QList<SGame>(list.begin(), list.end());
    return *this;
}
#define SGamesEnd }
