#include "steamapiachievement.h"

SteamAPIAchievement::SteamAPIAchievement(QJsonObject ObjGlobal, QJsonObject ObjPlayer, QObject *parent) : QObject(parent){
    Set(ObjGlobal,ObjPlayer);
}
SteamAPIAchievement::SteamAPIAchievement(SteamAPIAchievementGlobal Global, SteamAPIAchievementPlayer Player){
    Set(Global,Player);
}
SteamAPIAchievement::SteamAPIAchievement(){

}

void SteamAPIAchievement::Set(QJsonObject ObjGlobal, QJsonObject ObjPlayer){
    apiname=ObjGlobal.value("name").toString();
    defaultvalue=ObjGlobal.value("defaultvalue").toInt();
    displayname=ObjGlobal.value("displayName").toString();
    hidden=ObjGlobal.value("hidden").toInt();
    description=ObjGlobal.value("description").toString();
    icon=ObjGlobal.value("icon").toString();
    icongray=ObjGlobal.value("icongray").toString();
    achieved=ObjPlayer.value("achieved").toInt();
    unlocktime=QDateTime::fromSecsSinceEpoch(ObjPlayer.value("unlocktime").toInt(),Qt::LocalTime);
    statusglobal="success";
    statusplayer="success";
}
void SteamAPIAchievement::Set(SteamAPIAchievementGlobal Global, SteamAPIAchievementPlayer Player){
    apiname=Global.GetApiname();
    defaultvalue=Global.GetDefaultvalue();
    displayname=Global.GetDisplayname();
    hidden=Global.GetHidden();
    description=Global.GetDescription();
    icon=Global.GetIcon();
    icongray=Global.GetIcongray();
    achieved=Player.GetAchieved();
    unlocktime=Player.GetUnlocktime();
    statusglobal="success";
    statusplayer="success";
}

QString SteamAPIAchievement::GetApiname(){
    return apiname;
}
int SteamAPIAchievement::GetDefaultvalue(){
    return defaultvalue;
}
QString SteamAPIAchievement::GetDisplayname(){
    return displayname;
}
int SteamAPIAchievement::GetHidden(){
    return hidden;
}
QString SteamAPIAchievement::GetDescription(){
    return description;
}
QString SteamAPIAchievement::GetIcon(){
    return icon;
}
QString SteamAPIAchievement::GetIcongray(){
    return icongray;
}
int SteamAPIAchievement::GetAchieved(){
    return achieved;
}
QDateTime SteamAPIAchievement::GetUnlocktime(){
    return unlocktime;
}
QString SteamAPIAchievement::GetStatusGlobal(){
    return statusglobal;
}
QString SteamAPIAchievement::GetStatusPlayer(){
    return statusplayer;
}

void SteamAPIAchievement::SetGlobal(QJsonObject ObjGlobal){
    if(apiname==""||apiname==ObjGlobal.value("name").toString()){
        apiname=ObjGlobal.value("name").toString();
        defaultvalue=ObjGlobal.value("defaultvalue").toInt();
        displayname=ObjGlobal.value("displayName").toString();
        hidden=ObjGlobal.value("hidden").toInt();
        description=ObjGlobal.value("description").toString();
        icon=ObjGlobal.value("icon").toString();
        icongray=ObjGlobal.value("icongray").toString();
        statusglobal="success";
    } else
        statusglobal="error: apiname is incorrect";
}
void SteamAPIAchievement::SetPlayer(QJsonObject ObjPlayer){
    if(apiname==""||apiname==ObjPlayer.value("apiname").toString()){
        apiname=ObjPlayer.value("apiname").toString();
        achieved=ObjPlayer.value("achieved").toInt();
        unlocktime=QDateTime::fromSecsSinceEpoch(ObjPlayer.value("unlocktime").toInt(),Qt::LocalTime);
        statusplayer="success";
    } else
        statusplayer="error: apiname is incorrect";
}
void SteamAPIAchievement::SetGlobal(SteamAPIAchievementGlobal Global){
    if(apiname==""||apiname==Global.GetApiname()){
        apiname=Global.GetApiname();
        defaultvalue=Global.GetDefaultvalue();
        displayname=Global.GetDisplayname();
        hidden=Global.GetHidden();
        description=Global.GetDescription();
        icon=Global.GetIcon();
        icongray=Global.GetIcongray();
        statusglobal="success";
    } else
        statusglobal="error: apiname is incorrect";
}
void SteamAPIAchievement::SetPlayer(SteamAPIAchievementPlayer Player){
    if(apiname==""||apiname==Player.GetApiname()){
        apiname=Player.GetApiname();
        achieved=Player.GetAchieved();
        unlocktime=Player.GetUnlocktime();
        statusplayer="success";
    } else
        statusplayer="error: apiname is incorrect";
}

SteamAPIAchievement::SteamAPIAchievement(const SteamAPIAchievement & achievement){
    apiname=achievement.apiname;
    defaultvalue=achievement.defaultvalue;
    displayname=achievement.displayname;
    hidden=achievement.hidden;
    description=achievement.description;
    icon=achievement.icon;
    icongray=achievement.icongray;
    achieved=achievement.achieved;
    unlocktime=achievement.unlocktime;
    statusglobal=achievement.statusglobal;
    statusplayer=achievement.statusplayer;
}
SteamAPIAchievement & SteamAPIAchievement::operator=(const SteamAPIAchievement & achievement){
    apiname=achievement.apiname;
    defaultvalue=achievement.defaultvalue;
    displayname=achievement.displayname;
    hidden=achievement.hidden;
    description=achievement.description;
    icon=achievement.icon;
    icongray=achievement.icongray;
    achieved=achievement.achieved;
    unlocktime=achievement.unlocktime;
    statusglobal=achievement.statusglobal;
    statusplayer=achievement.statusplayer;
    return *this;
}
