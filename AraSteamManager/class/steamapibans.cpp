#include "steamapibans.h"

SteamAPIBans::SteamAPIBans(QString key, QString id, QObject *parent) : QObject(parent){
    manager = new QNetworkAccessManager();
    Set(key, id);
}

SteamAPIBans::SteamAPIBans(QJsonDocument DocBans){
    manager = new QNetworkAccessManager();
    Set(DocBans);
}

SteamAPIBans::SteamAPIBans(){
    manager = new QNetworkAccessManager();
    status="null";
}

SteamAPIBans::~SteamAPIBans(){
    delete manager;
}

void SteamAPIBans::Set(QString key, QString id){
    connect(manager,&QNetworkAccessManager::finished,this,&SteamAPIBans::Load);
    this->key=key;
    manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerBans/v1/?key="+key+"&steamids="+id));
}
void SteamAPIBans::Set(QJsonDocument DocBans){
    if(DocBans.object().value("response").toObject().value("players").toArray().size()>0){
        QJsonObject Bans=DocBans.object().value("players").toArray().at(0).toObject();
        steamid=Bans.value("steamid").toString();
        CommunityBanned=Bans.value("CommunityBanned").toBool();
        VACBanned=Bans.value("VACBanned").toBool();
        NumberOfVACBans=Bans.value("NumberOfVACBans").toInt();
        DaysSinceLastBan=Bans.value("DaysSinceLastBan").toInt();
        NumberOfGameBans=Bans.value("NumberOfGameBans").toInt();
        EconomyBan=Bans.value("EconomyBan").toString();
        status="success";
    }
    else {
        status="error: profile is not exist";
    }
}

void SteamAPIBans::Load(QNetworkReply *Reply){
    disconnect(manager,&QNetworkAccessManager::finished,this,&SteamAPIBans::Load);
    QJsonDocument DocBans = QJsonDocument::fromJson(Reply->readAll());
    Reply->deleteLater();
    Set(DocBans);
    emit finished(this);
    emit finished();
}

QString SteamAPIBans::GetSteamid(){
    return steamid;
}
bool SteamAPIBans::GetCommunityBanned(){
    return CommunityBanned;
}
bool SteamAPIBans::GetVACBanned(){
    return VACBanned;
}
int SteamAPIBans::GetNumberOfVACBans(){
    return NumberOfVACBans;
}
int SteamAPIBans::GetDaysSinceLastBan(){
    return DaysSinceLastBan;
}
int SteamAPIBans::GetNumberOfGameBans(){
    return NumberOfGameBans;
}
QString SteamAPIBans::GetEconomyBan(){
    return EconomyBan;
}
QString SteamAPIBans::GetStatus(){
    return status;
}

void SteamAPIBans::Update(){
    Set(key, steamid);
}
