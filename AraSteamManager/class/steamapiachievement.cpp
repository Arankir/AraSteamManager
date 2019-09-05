#include "steamapiachievement.h"

SteamAPIAchievement::SteamAPIAchievement(SteamAPIAchievementGlobal Global, SteamAPIAchievementPlayer Player, SteamAPIAchievementPercentage Percent, QObject *parent) : QObject(parent){
    Set(Global,Player,Percent);
}
SteamAPIAchievement::SteamAPIAchievement(){

}

void SteamAPIAchievement::Set(SteamAPIAchievementGlobal Global, SteamAPIAchievementPlayer Player, SteamAPIAchievementPercentage Percent){
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
void SteamAPIAchievement::SetPercent(SteamAPIAchievementPercentage Percent){
    if(apiname==""||apiname==Percent.GetApiname()){
        apiname=Percent.GetApiname();
        percent=Percent.GetPercent();
        statuspercent="success";
    } else
        statuspercent="error: apiname is incorrect";
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
