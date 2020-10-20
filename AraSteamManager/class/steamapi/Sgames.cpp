#include "Sgames.h"

#define SGameStart {
SGame &SGame::operator=(const SGame &aGame) {
    _numberPlayers = aGame._numberPlayers;
    _pixmapIcon = aGame._pixmapIcon;
    _pixmapLogo = aGame._pixmapLogo;
    return *this;
}

const bool &SGame::operator<(const SGame &aGame) {
    static const bool b = _name.compare(aGame._name, Qt::CaseInsensitive) < 0;
    return b;
}

QPixmap SGame::getPixmapIcon() {
    return getPixmap(_pixmapIcon, _img_icon_url, QSize(32, 32));
}

QPixmap SGame::getPixmapLogo() {
    return getPixmap(_pixmapLogo, _img_logo_url, QSize(184, 69));
}

QPixmap SGame::getPixmap(QPixmap &aPixmap, const QString &aUrl, QSize aSize) {
    if (aPixmap.isNull()) {
        if ((aUrl != "") && (aUrl.lastIndexOf("/") != aUrl.length() - 1)) {
            QString savePath = Paths::imagesGames(aUrl);
            if (!QFile::exists(savePath)) {
                RequestImage img(gameImageUrl(QString::number(_appID), aUrl), savePath, true, this);
                QEventLoop loop;
                connect(&img, &RequestImage::s_loadComplete, &loop, &QEventLoop::quit);
                loop.exec();
                disconnect(&img, &RequestImage::s_loadComplete, &loop, &QEventLoop::quit);
                aPixmap = img.getPixmap();
            } else {
                aPixmap = QPixmap(savePath);
            }
        } else {
            aPixmap = QPixmap(Images::missingImage()).scaled(aSize);
        }
    }
    return aPixmap;
}



const QString SGame::getNumberPlayers(bool hardReload) {
    if (_numberPlayers == "" || hardReload) {
        _request.get(numberPlayersUrl(QString::number(_appID)), false);
        double playersCount = QJsonDocument::fromJson(_request.getReply()).object().value("response").toObject().value("player_count").toDouble();
        _numberPlayers = QString::number(playersCount);
    }
    return _numberPlayers;
}
#define SGameEnd }
#define SGamesStart {
SGames::SGames(const QString &aId, int aFreeGames, int aGameInfo, bool aParallel, QObject *aParent): Sapi(aParent) {
    load(aId, aFreeGames, aGameInfo, aParallel);
}

SGames &SGames::operator=(const SGames & aGames) {
    _games = aGames._games;
    _status = aGames._status;
    _error = aGames._error;
    _id = aGames._id;
    _free_games = aGames._free_games;
    _game_info = aGames._game_info;
    return *this;
}

SGames &SGames::load(const QString &aId, int aFreeGames, int aGameInfo, bool aParallel) {
    _id = aId;
    _free_games = aFreeGames;
    _game_info = aGameInfo;
    _request.get(gameUrl(_free_games, _game_info, _id), aParallel);
    return *this;
}

void SGames::onLoad() {
    parse(QJsonDocument::fromJson(_request.getReply()));
    emit s_finished(this);
    emit s_finished();
}

void SGames::parse(const QJsonDocument &doc) {
    clear();
    QJsonArray gamesArray = doc.object().value("response").toObject().value("games").toArray();
    if (gamesArray.size() > 0) {
        for (auto game: gamesArray) {
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
    //std::sort(_games.begin(), _games.end());
    std::list<SGame> list(_games.begin(), _games.end());
    list.sort(  [](const SGame &s1, const SGame &s2)-> const bool {
                    return s1._name.compare(s2._name, Qt::CaseInsensitive) < 0;
                });
    _games = QList<SGame>(list.begin(), list.end());
    return *this;
}
#define SGamesEnd }
