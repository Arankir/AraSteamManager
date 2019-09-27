#include "Sachievement.h"

SAchievement::SAchievement(SAchievementGlobal Global, SAchievementPlayer Player, SAchievementPercentage Percent, QObject *parent) : QObject(parent){
    Set(Global,Player,Percent);
}
SAchievement::SAchievement(){

}

void SAchievement::Set(SAchievementGlobal Global, SAchievementPlayer Player, SAchievementPercentage Percent){
    apiname=Global.GetApiname();
    defaultvalue=Global.GetDefaultvalue();
    displayname=Global.GetDisplayname();
    hidden=Global.GetHidden();
    description=Global.GetDescription();
    icon=Global.GetIcon();
    icongray=Global.GetIcongray();
    achieved=Player.GetAchieved();
    unlocktime=Player.GetUnlocktime();
    percent=Percent.GetPercent();
    statusglobal="success";
    statusplayer="success";
    statuspercent="success";
}

void SAchievement::SetGlobal(SAchievementGlobal Global){
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
void SAchievement::SetPlayer(SAchievementPlayer Player){
    if(apiname==""||apiname==Player.GetApiname()){
        apiname=Player.GetApiname();
        achieved=Player.GetAchieved();
        unlocktime=Player.GetUnlocktime();
        statusplayer="success";
    } else
        statusplayer="error: apiname is incorrect";
}
void SAchievement::SetPercent(SAchievementPercentage Percent){
    if(apiname==""||apiname==Percent.GetApiname()){
        apiname=Percent.GetApiname();
        percent=Percent.GetPercent();
        statuspercent="success";
    } else
        statuspercent="error: apiname is incorrect";
}

SAchievement::SAchievement(const SAchievement & achievement){
    apiname=achievement.apiname;
    defaultvalue=achievement.defaultvalue;
    displayname=achievement.displayname;
    hidden=achievement.hidden;
    description=achievement.description;
    icon=achievement.icon;
    icongray=achievement.icongray;
    achieved=achievement.achieved;
    unlocktime=achievement.unlocktime;
    percent=achievement.percent;
    statusglobal=achievement.statusglobal;
    statusplayer=achievement.statusplayer;
    statuspercent=achievement.statuspercent;
}
SAchievement & SAchievement::operator=(const SAchievement & achievement){
    apiname=achievement.apiname;
    defaultvalue=achievement.defaultvalue;
    displayname=achievement.displayname;
    hidden=achievement.hidden;
    description=achievement.description;
    icon=achievement.icon;
    icongray=achievement.icongray;
    achieved=achievement.achieved;
    unlocktime=achievement.unlocktime;
    percent=achievement.percent;
    statusglobal=achievement.statusglobal;
    statusplayer=achievement.statusplayer;
    statuspercent=achievement.statuspercent;
    return *this;
}
