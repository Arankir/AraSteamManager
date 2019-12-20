#include "Sachievement.h"

SAchievement::SAchievement(SAchievementGlobal Aglobal, SAchievementPlayer Aplayer, SAchievementPercentage Apercent, QObject *parent) : QObject(parent){
    _apiName=Aglobal.GetApiname();
    _defaultValue=Aglobal.GetDefaultvalue();
    _displayName=Aglobal.GetDisplayname();
    _hidden=Aglobal.GetHidden();
    _description=Aglobal.GetDescription();
    _icon=Aglobal.GetIcon();
    _iconGray=Aglobal.GetIcongray();
    _achieved=Aplayer.GetAchieved();
    _unlockTime=Aplayer.GetUnlocktime();
    _percent=Apercent.GetPercent();
    _statusGlobal="success";
    _statusPlayer="success";
    _statusPercent="success";
}
SAchievement::SAchievement(){

}

void SAchievement::Set(SAchievementGlobal Aglobal, SAchievementPlayer Aplayer, SAchievementPercentage Apercent){
    _apiName=Aglobal.GetApiname();
    _defaultValue=Aglobal.GetDefaultvalue();
    _displayName=Aglobal.GetDisplayname();
    _hidden=Aglobal.GetHidden();
    _description=Aglobal.GetDescription();
    _icon=Aglobal.GetIcon();
    _iconGray=Aglobal.GetIcongray();
    _achieved=Aplayer.GetAchieved();
    _unlockTime=Aplayer.GetUnlocktime();
    _percent=Apercent.GetPercent();
    _statusGlobal="success";
    _statusPlayer="success";
    _statusPercent="success";
}

void SAchievement::SetGlobal(SAchievementGlobal Aglobal){
    if(_apiName==""||_apiName==Aglobal.GetApiname()){
        _apiName=Aglobal.GetApiname();
        _defaultValue=Aglobal.GetDefaultvalue();
        _displayName=Aglobal.GetDisplayname();
        _hidden=Aglobal.GetHidden();
        _description=Aglobal.GetDescription();
        _icon=Aglobal.GetIcon();
        _iconGray=Aglobal.GetIcongray();
        _statusGlobal="success";
    } else
        _statusGlobal="error: apiname is incorrect";
}
void SAchievement::SetPlayer(SAchievementPlayer Aplayer){
    if(_apiName==""||_apiName==Aplayer.GetApiname()){
        _apiName=Aplayer.GetApiname();
        _achieved=Aplayer.GetAchieved();
        _unlockTime=Aplayer.GetUnlocktime();
        _statusPlayer="success";
    } else
        _statusPlayer="error: apiname is incorrect";
}
void SAchievement::SetPercent(SAchievementPercentage Apercent){
    if(_apiName==""||_apiName==Apercent.GetApiname()){
        _apiName=Apercent.GetApiname();
        _percent=Apercent.GetPercent();
        _statusPercent="success";
    } else
        _statusPercent="error: apiname is incorrect";
}

SAchievement::SAchievement(const SAchievement & AnewAchievement){
    _apiName=AnewAchievement._apiName;
    _defaultValue=AnewAchievement._defaultValue;
    _displayName=AnewAchievement._displayName;
    _hidden=AnewAchievement._hidden;
    _description=AnewAchievement._description;
    _icon=AnewAchievement._icon;
    _iconGray=AnewAchievement._iconGray;
    _achieved=AnewAchievement._achieved;
    _unlockTime=AnewAchievement._unlockTime;
    _percent=AnewAchievement._percent;
    _statusGlobal=AnewAchievement._statusGlobal;
    _statusPlayer=AnewAchievement._statusPlayer;
    _statusPercent=AnewAchievement._statusPercent;
}
SAchievement & SAchievement::operator=(const SAchievement & AnewAchievement){
    _apiName=AnewAchievement._apiName;
    _defaultValue=AnewAchievement._defaultValue;
    _displayName=AnewAchievement._displayName;
    _hidden=AnewAchievement._hidden;
    _description=AnewAchievement._description;
    _icon=AnewAchievement._icon;
    _iconGray=AnewAchievement._iconGray;
    _achieved=AnewAchievement._achieved;
    _unlockTime=AnewAchievement._unlockTime;
    _percent=AnewAchievement._percent;
    _statusGlobal=AnewAchievement._statusGlobal;
    _statusPlayer=AnewAchievement._statusPlayer;
    _statusPercent=AnewAchievement._statusPercent;
    return *this;
}
