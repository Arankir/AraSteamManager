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
    _statusGlobal=StatusValue::success;
    _statusPlayer=StatusValue::success;
    _statusPercent=StatusValue::success;
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
    _statusGlobal=StatusValue::success;
    _statusPlayer=StatusValue::success;
    _statusPercent=StatusValue::success;
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
        _statusGlobal=StatusValue::success;
    } else {
        _statusGlobal=StatusValue::error;
        _errorGlobal="apiname is incorrect";
    }
}
void SAchievement::SetPlayer(SAchievementPlayer Aplayer){
    if(_apiName==""||_apiName==Aplayer.GetApiname()){
        _apiName=Aplayer.GetApiname();
        _achieved=Aplayer.GetAchieved();
        _unlockTime=Aplayer.GetUnlocktime();
        _statusPlayer=StatusValue::success;
    } else {
        _statusPlayer=StatusValue::error;
        _errorPlayer="apiname is incorrect";
    }
}
void SAchievement::SetPercent(SAchievementPercentage Apercent){
    if(_apiName==""||_apiName==Apercent.GetApiname()){
        _apiName=Apercent.GetApiname();
        _percent=Apercent.GetPercent();
        _statusPercent=StatusValue::success;
    } else {
        _statusPercent=StatusValue::error;
        _errorPercent="apiname is incorrect";
    }
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
    _errorGlobal=AnewAchievement._errorGlobal;
    _errorPlayer=AnewAchievement._errorPlayer;
    _errorPercent=AnewAchievement._errorPercent;
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
    _errorGlobal=AnewAchievement._errorGlobal;
    _errorPlayer=AnewAchievement._errorPlayer;
    _errorPercent=AnewAchievement._errorPercent;
    return *this;
}
