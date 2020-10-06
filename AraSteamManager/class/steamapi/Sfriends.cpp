#include "Sfriends.h"

#define SFriendStart {
SFriend::SFriend(QJsonObject &aFriend, QObject *parent): QObject(parent), _steamID(aFriend.value("steamid").toString()),
_relationship(aFriend.value("relationship").toString()), _friend_since(QDateTime::fromSecsSinceEpoch(aFriend.value("friend_since").toInt(), Qt::LocalTime)) {

}

SFriend::SFriend(const SFriend &aFriend): QObject(aFriend.parent()), _steamID(aFriend._steamID),
_relationship(aFriend._relationship), _friend_since(aFriend._friend_since) {

}

SFriend &SFriend::operator=(const SFriend &) {
    return *this;
}

const bool &SFriend::operator<(const SFriend &aGame) {
    static const bool b = _steamID.toLower() < aGame._steamID.toLower();
    //qDebug()<<_game.value("name").toString().toLower()<<a_game._game.value("name").toString().toLower();
    return b;
}
#define SFriendEnd }
#define SFriendsStart {
SFriends::SFriends(const QString &aId, bool aParallel, QObject *aParent): QObject(aParent), _manager(new QNetworkAccessManager()) {
    set(aId, aParallel);
}
SFriends::SFriends(QJsonDocument &aFriends, QObject *aParent): QObject(aParent), _manager(new QNetworkAccessManager()) {
    set(aFriends);
}

SFriends::SFriends(QObject *aParent): QObject(aParent), _manager(new QNetworkAccessManager()) {

}

SFriends::~SFriends() {
    delete _manager;
}

void SFriends::set(const QString &aId, bool aParallel) {
    _id = std::move(aId);
    if (aParallel) {
        _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetFriendList/v0001/?key="+Settings::getKey()+"&steamid="+_id+"&relationship=friend"));
        connect(_manager, &QNetworkAccessManager::finished, this, &SFriends::onLoad);
    } else {
        QNetworkReply *reply = _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetFriendList/v0001/?key="+Settings::getKey()+"&steamid="+_id+"&relationship=friend"));
        QEventLoop loop;
        connect(_manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
        loop.exec();
        disconnect(_manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
        QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
        set(doc);
        delete reply;
        emit s_finished(this);
        emit s_finished();
    }
}

void SFriends::set(QJsonDocument &aFriends) {
    clear();
    if (aFriends.object().value("friendslist").toObject().value("friends").toArray().size() > 0) {
        for (auto friendP: aFriends.object().value("friendslist").toObject().value("friends").toArray()) {
            QJsonObject objectFriend = friendP.toObject();
            SFriend localFriend = SFriend(objectFriend);
            _friends.append(std::move(localFriend));
        }
        _status = StatusValue::success;
    } else {
        _status = StatusValue::error;
        _error = "profile is not exist";
    }
}

StatusValue SFriends::getStatus() {
    return _status;
}

QString SFriends::getError() {
    return _error;
}

int SFriends::getCount() {
    return _friends.size();
}

void SFriends::onLoad(QNetworkReply *aReply) {
    disconnect(_manager, &QNetworkAccessManager::finished, this, &SFriends::onLoad);
    QJsonDocument doc = QJsonDocument::fromJson(aReply->readAll());
    set(doc);
    aReply->deleteLater();
    emit s_finished(this);
    emit s_finished();
}

SProfiles SFriends::getProfiles() {
    QEventLoop loop;
    QNetworkAccessManager localManager;
    connect(&localManager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    int nowFriendsLoaded = 0;
    QJsonArray profilesArray;
    SProfiles profiles;
    while(nowFriendsLoaded < _friends.size()) {
        QString querry = "http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key=" + Settings::getKey() + "&steamids=" + _friends[nowFriendsLoaded++]._steamID;
        if(nowFriendsLoaded + 99 > _friends.size()) {
            while(nowFriendsLoaded < _friends.size()) {
                querry += ", " + _friends[nowFriendsLoaded++]._steamID;
            }
        } else {
            for (int i = 0; i < 99; i++) {
                querry += ", " + _friends[nowFriendsLoaded++]._steamID;
            }
        }
        //qDebug()<<"Запрос="<<querry;
        QNetworkReply &localReply = *localManager.get(QNetworkRequest(querry));
        loop.exec();
        QJsonArray profileFriends = QJsonDocument::fromJson(localReply.readAll()).object().value("response").toObject().value("players").toArray();
        for (auto profileFriend: profileFriends) {
            profilesArray.append(std::move(profileFriend.toObject()));
        }
    }
    profiles.set(profilesArray);
    qInfo() << "Друзей" << profiles.getCount();
    return profiles;
}

void SFriends::update(bool aParallel) {
    set(_id, aParallel);
}

void SFriends::clear() {
    _friends.clear();
    _status = StatusValue::none;
}

void SFriends::sort() {
    //Переделать нормально
    //std::list<SFriend> list = _friends.toList().toStdList();
    std::sort(_friends.begin(), _friends.end());
//    std::list<SFriend> list(_friends.begin(), _friends.end());
//    list.sort(/*[](const SFriend &s1, const SFriend &s2)-> const bool {
//        if(QString::compare(s1.GetName().toLower(),s2.GetName().toLower())<0)
//            return true;
//        else
//            return false;
//    }*/);
//    //_friends=QVector<SFriend>::fromList(QList<SFriend>::fromStdList(list));
//    _friends = QList<SFriend>(list.begin(), list.end());
}

SFriends::SFriends(const SFriends &aFriends) {
    _friends = aFriends._friends;
    _status = aFriends._status;
    _error = aFriends._error;
    _id = aFriends._id;
    _manager = new QNetworkAccessManager;
}

SFriends &SFriends::operator=(const SFriends & aFriends) {
    delete _manager;
    _friends = aFriends._friends;
    _status = aFriends._status;
    _error = aFriends._error;
    _id = aFriends._id;
    _manager = new QNetworkAccessManager;
    return *this;
}

SFriend &SFriends::operator[](const int &aIndex) {
    return _friends[aIndex];
}
#define SFriendsEnd }
