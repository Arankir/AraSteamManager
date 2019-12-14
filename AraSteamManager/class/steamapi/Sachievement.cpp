#include "Sachievement.h"

SAchievement::SAchievement(SAchievementGlobal AGlobal, SAchievementPlayer APlayer, SAchievementPercentage APercent, QObject *parent) : QObject(parent){
    _apiName=AGlobal.GetApiname();
    _defaultValue=AGlobal.GetDefaultvalue();
    _displayName=AGlobal.GetDisplayname();
    _hidden=AGlobal.GetHidden();
    _description=AGlobal.GetDescription();
    _icon=AGlobal.GetIcon();
    _iconGray=AGlobal.GetIcongray();
    _achieved=APlayer.GetAchieved();
    _unlockTime=APlayer.GetUnlocktime();
    _percent=APercent.GetPercent();
    _statusGlobal="success";
    _statusPlayer="success";
    _statusPercent="success";
}
SAchievement::SAchievement(){

}

void SAchievement::Set(SAchievementGlobal AGlobal, SAchievementPlayer APlayer, SAchievementPercentage APercent){
    _apiName=AGlobal.GetApiname();
    _defaultValue=AGlobal.GetDefaultvalue();
    _displayName=AGlobal.GetDisplayname();
    _hidden=AGlobal.GetHidden();
    _description=AGlobal.GetDescription();
    _icon=AGlobal.GetIcon();
    _iconGray=AGlobal.GetIcongray();
    _achieved=APlayer.GetAchieved();
    _unlockTime=APlayer.GetUnlocktime();
    _percent=APercent.GetPercent();
    _statusGlobal="success";
    _statusPlayer="success";
    _statusPercent="success";
}

void SAchievement::SetGlobal(SAchievementGlobal AGlobal){
    if(_apiName==""||_apiName==AGlobal.GetApiname()){
        _apiName=AGlobal.GetApiname();
        _defaultValue=AGlobal.GetDefaultvalue();
        _displayName=AGlobal.GetDisplayname();
        _hidden=AGlobal.GetHidden();
        _description=AGlobal.GetDescription();
        _icon=AGlobal.GetIcon();
        _iconGray=AGlobal.GetIcongray();
        _statusGlobal="success";
    } else
        _statusGlobal="error: apiname is incorrect";
}
void SAchievement::SetPlayer(SAchievementPlayer APlayer){
    if(_apiName==""||_apiName==APlayer.GetApiname()){
        _apiName=APlayer.GetApiname();
        _achieved=APlayer.GetAchieved();
        _unlockTime=APlayer.GetUnlocktime();
        _statusPlayer="success";
    } else
        _statusPlayer="error: apiname is incorrect";
}
void SAchievement::SetPercent(SAchievementPercentage APercent){
    if(_apiName==""||_apiName==APercent.GetApiname()){
        _apiName=APercent.GetApiname();
        _percent=APercent.GetPercent();
        _statusPercent="success";
    } else
        _statusPercent="error: apiname is incorrect";
}

SAchievement::SAchievement(const SAchievement & ANewAchievement){
    _apiName=ANewAchievement._apiName;
    _defaultValue=ANewAchievement._defaultValue;
    _displayName=ANewAchievement._displayName;
    _hidden=ANewAchievement._hidden;
    _description=ANewAchievement._description;
    _icon=ANewAchievement._icon;
    _iconGray=ANewAchievement._iconGray;
    _achieved=ANewAchievement._achieved;
    _unlockTime=ANewAchievement._unlockTime;
    _percent=ANewAchievement._percent;
    _statusGlobal=ANewAchievement._statusGlobal;
    _statusPlayer=ANewAchievement._statusPlayer;
    _statusPercent=ANewAchievement._statusPercent;
}
SAchievement & SAchievement::operator=(const SAchievement & ANewAchievement){
    _apiName=ANewAchievement._apiName;
    _defaultValue=ANewAchievement._defaultValue;
    _displayName=ANewAchievement._displayName;
    _hidden=ANewAchievement._hidden;
    _description=ANewAchievement._description;
    _icon=ANewAchievement._icon;
    _iconGray=ANewAchievement._iconGray;
    _achieved=ANewAchievement._achieved;
    _unlockTime=ANewAchievement._unlockTime;
    _percent=ANewAchievement._percent;
    _statusGlobal=ANewAchievement._statusGlobal;
    _statusPlayer=ANewAchievement._statusPlayer;
    _statusPercent=ANewAchievement._statusPercent;
    return *this;
}
