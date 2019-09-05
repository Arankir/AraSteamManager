#include "steamapiprofile.h"

SteamAPIProfile::SteamAPIProfile(QString key, QString id, QString type, QObject *parent) : QObject(parent){
    manager = new QNetworkAccessManager();
    Set(key, id, type);
}
SteamAPIProfile::SteamAPIProfile(QJsonDocument DocSummaries){
    manager = new QNetworkAccessManager();
    Set(DocSummaries);
}
SteamAPIProfile::SteamAPIProfile(QJsonDocument DocSummaries, int index){
    manager = new QNetworkAccessManager();
    Set(DocSummaries,index);
}
SteamAPIProfile::SteamAPIProfile(){
    manager = new QNetworkAccessManager();
}
SteamAPIProfile::~SteamAPIProfile(){
    delete manager;
}

void SteamAPIProfile::Set(QString key, QString id, QString type){
    if(type=="vanity"){
        connect(manager,&QNetworkAccessManager::finished,this,&SteamAPIProfile::LoadVanity);
        this->key=key;
        manager->get(QNetworkRequest("https://api.steampowered.com/ISteamUser/ResolveVanityURL/v1/?key="+key+"&vanityurl="+id+"&url_type=1"));
    } else {
        if(type=="url"){
            connect(manager,&QNetworkAccessManager::finished,this,&SteamAPIProfile::LoadURL);
            manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+key+"&steamids="+id));
        } else {
            status="error: unknown type";
            emit finished(this);
            emit finished();
        }
    }
}
void SteamAPIProfile::Set(QJsonDocument DocSummaries){
    Clear();
    if(DocSummaries.object().value("response").toObject().value("players").toArray().size()>0){
        QJsonObject Account=DocSummaries.object().value("response").toObject().value("players").toArray().at(0).toObject();
        steamid=Account.value("steamid").toString();
        communityvisibilitystate=Account.value("communityvisibilitystate").toInt();
        profilestate=Account.value("profilestate").toInt();
        personaname=Account.value("personaname").toString();
        lastlogoff=QDateTime::fromSecsSinceEpoch(Account.value("lastlogoff").toInt(),Qt::LocalTime);
        commentpermission=Account.value("commentpermission").toInt();
        profileurl=Account.value("profileurl").toString();
        avatar=Account.value("avatar").toString();
        avatarmedium=Account.value("avatarmedium").toString();
        avatarfull=Account.value("avatarfull").toString();
        personastate=Account.value("personastate").toInt();
        primaryclanid=Account.value("primaryclanid").toString();
        timecreated=QDateTime::fromSecsSinceEpoch(Account.value("timecreated").toInt(),Qt::LocalTime);
        personastateflags=Account.value("personastateflags").toInt();
        gameextrainfo=Account.value("gameextrainfo").toString();
        gameid=Account.value("gameid").toString();
        loccountrycode=Account.value("loccountrycode").toString();
        locstatecode=Account.value("locstatecode").toString();
        loccityid=Account.value("loccityid").toInt();
        realname=Account.value("realname").toString();
        status="success";
    }
    else {
        status="error: profile is not exist";
    }
}
void SteamAPIProfile::Set(QJsonDocument DocSummaries,int index){
    if(DocSummaries.object().value("response").toObject().value("players").toArray().size()>0){
        QJsonObject Account=DocSummaries.object().value("response").toObject().value("players").toArray().at(index).toObject();
        steamid=Account.value("steamid").toString();
        communityvisibilitystate=Account.value("communityvisibilitystate").toInt();
        profilestate=Account.value("profilestate").toInt();
        personaname=Account.value("personaname").toString();
        lastlogoff=QDateTime::fromSecsSinceEpoch(Account.value("lastlogoff").toInt(),Qt::LocalTime);
        commentpermission=Account.value("commentpermission").toInt();
        profileurl=Account.value("profileurl").toString();
        avatar=Account.value("avatar").toString();
        avatarmedium=Account.value("avatarmedium").toString();
        avatarfull=Account.value("avatarfull").toString();
        personastate=Account.value("personastate").toInt();
        primaryclanid=Account.value("primaryclanid").toString();
        timecreated=QDateTime::fromSecsSinceEpoch(Account.value("timecreated").toInt(),Qt::LocalTime);
        personastateflags=Account.value("personastateflags").toInt();
        gameextrainfo=Account.value("gameextrainfo").toString();
        gameid=Account.value("gameid").toString();
        loccountrycode=Account.value("loccountrycode").toString();
        locstatecode=Account.value("locstatecode").toString();
        loccityid=Account.value("loccityid").toInt();
        realname=Account.value("realname").toString();
        status="success";
    }
    else {
        status="error: profile is not exist";
    }
}

void SteamAPIProfile::LoadVanity(QNetworkReply *Reply){
    QJsonDocument Doc = QJsonDocument::fromJson(Reply->readAll());
    disconnect(manager,&QNetworkAccessManager::finished,this,&SteamAPIProfile::LoadVanity);
    connect(manager,&QNetworkAccessManager::finished,this,&SteamAPIProfile::LoadURL);
    QString id=Doc.object().value("response").toObject().value("steamid").toString();
    manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+key+"&steamids="+id));
}
void SteamAPIProfile::LoadURL(QNetworkReply *Reply){
    QJsonDocument DocSummaries = QJsonDocument::fromJson(Reply->readAll());
    disconnect(manager,&QNetworkAccessManager::finished,this,&SteamAPIProfile::LoadURL);
    Reply->deleteLater();
    Set(DocSummaries);
    emit finished(this);
    emit finished();
}

void SteamAPIProfile::Update(){
    Set(key, steamid, "url");
}
void SteamAPIProfile::Clear(){
    steamid="";
    communityvisibilitystate=0;
    profilestate=0;
    personaname="";
    lastlogoff=QDateTime::fromSecsSinceEpoch(0);
    commentpermission=0;
    profileurl="";
    avatar="";
    avatarmedium="";
    avatarfull="";
    personastate=0;
    primaryclanid="";
    timecreated=QDateTime::fromSecsSinceEpoch(0);
    personastateflags=0;
    gameextrainfo="";
    gameid="";
    loccountrycode="";
    locstatecode="";
    loccityid=0;
    realname="";
    status="none";
}

SteamAPIProfile::SteamAPIProfile( const SteamAPIProfile & a){
    steamid=a.steamid;
    communityvisibilitystate=a.communityvisibilitystate;
    profilestate=a.profilestate;
    personaname=a.personaname;
    lastlogoff=a.lastlogoff;
    commentpermission=a.commentpermission;
    profileurl=a.profileurl;
    avatar=a.avatar;
    avatarmedium=a.avatarmedium;
    avatarfull=a.avatarfull;
    personastate=a.personastate;
    primaryclanid=a.primaryclanid;
    timecreated=a.timecreated;
    personastateflags=a.personastateflags;
    gameextrainfo=a.gameextrainfo;
    gameid=a.gameid;
    loccountrycode=a.loccountrycode;
    locstatecode=a.locstatecode;
    loccityid=a.loccityid;
    realname=a.realname;
    status=a.status;
    manager = new QNetworkAccessManager;
}
SteamAPIProfile & SteamAPIProfile::operator=(const SteamAPIProfile & profile){
    delete manager;
    steamid=profile.steamid;
    communityvisibilitystate=profile.communityvisibilitystate;
    profilestate=profile.profilestate;
    personaname=profile.personaname;
    lastlogoff=profile.lastlogoff;
    commentpermission=profile.commentpermission;
    profileurl=profile.profileurl;
    avatar=profile.avatar;
    avatarmedium=profile.avatarmedium;
    avatarfull=profile.avatarfull;
    personastate=profile.personastate;
    primaryclanid=profile.primaryclanid;
    timecreated=profile.timecreated;
    personastateflags=profile.personastateflags;
    gameextrainfo=profile.gameextrainfo;
    gameid=profile.gameid;
    loccountrycode=profile.loccountrycode;
    locstatecode=profile.locstatecode;
    loccityid=profile.loccityid;
    realname=profile.realname;
    status=profile.status;
    manager = new QNetworkAccessManager;
    return *this;
}

