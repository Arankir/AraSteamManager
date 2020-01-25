#include "Sachievements.h"

SAchievementGlobal::SAchievementGlobal(QJsonObject Aachievement, QObject *parent) : QObject(parent){
    _apiName=Aachievement.value("name").toString();
    _defaultValue=Aachievement.value("defaultvalue").toInt();
    _displayName=Aachievement.value("displayName").toString();
    _hidden=Aachievement.value("hidden").toInt();
    _description=Aachievement.value("description").toString();
    _icon=Aachievement.value("icon").toString();
    _iconGray=Aachievement.value("icongray").toString();
}
SAchievementGlobal::SAchievementGlobal(){

}
void SAchievementGlobal::Set(QJsonObject Aachievement){
    _apiName=Aachievement.value("name").toString();
    _defaultValue=Aachievement.value("defaultvalue").toInt();
    _displayName=Aachievement.value("displayName").toString();
    _hidden=Aachievement.value("hidden").toInt();
    _description=Aachievement.value("description").toString();
    _icon=Aachievement.value("icon").toString();
    _iconGray=Aachievement.value("icongray").toString();
}
SAchievementGlobal::SAchievementGlobal( const SAchievementGlobal & AnewAchievements){
    _apiName=AnewAchievements._apiName;
    _defaultValue=AnewAchievements._defaultValue;
    _displayName=AnewAchievements._displayName;
    _hidden=AnewAchievements._hidden;
    _description=AnewAchievements._description;
    _icon=AnewAchievements._icon;
    _iconGray=AnewAchievements._iconGray;
}
SAchievementGlobal & SAchievementGlobal::operator=(const SAchievementGlobal & AnewAchievements) {
    _apiName=AnewAchievements._apiName;
    _defaultValue=AnewAchievements._defaultValue;
    _displayName=AnewAchievements._displayName;
    _hidden=AnewAchievements._hidden;
    _description=AnewAchievements._description;
    _icon=AnewAchievements._icon;
    _iconGray=AnewAchievements._iconGray;
    return *this;
}

SAchievementPercentage::SAchievementPercentage(QJsonObject Aachievement, QObject *parent) : QObject(parent){
    _apiName=Aachievement.value("name").toString();
    _percent=Aachievement.value("percent").toDouble();
}
SAchievementPercentage::SAchievementPercentage(){

}
void SAchievementPercentage::Set(QJsonObject Aachievement){
    _apiName=Aachievement.value("name").toString();
    _percent=Aachievement.value("percent").toDouble();
}
SAchievementPercentage::SAchievementPercentage(const SAchievementPercentage & AnewAchievement){
    _apiName=AnewAchievement._apiName;
    _percent=AnewAchievement._percent;
}
SAchievementPercentage & SAchievementPercentage::operator=(const SAchievementPercentage & AnewAchievement){
    _apiName=AnewAchievement._apiName;
    _percent=AnewAchievement._percent;
    return *this;
}

SAchievementPlayer::SAchievementPlayer(QJsonObject Aachievement, QObject *parent) : QObject(parent){
    _apiName=Aachievement.value("apiname").toString();
    _achieved=Aachievement.value("achieved").toInt();
    _unlockTime=QDateTime::fromSecsSinceEpoch(Aachievement.value("unlocktime").toInt(),Qt::LocalTime);
}
SAchievementPlayer::SAchievementPlayer(){

}
void SAchievementPlayer::Set(QJsonObject Aachievement){
    _apiName=Aachievement.value("apiname").toString();
    _achieved=Aachievement.value("achieved").toInt();
    _unlockTime=QDateTime::fromSecsSinceEpoch(Aachievement.value("unlocktime").toInt(),Qt::LocalTime);
}
SAchievementPlayer::SAchievementPlayer( const SAchievementPlayer & AnewAchievement){
    _apiName=AnewAchievement._apiName;
    _achieved=AnewAchievement._achieved;
    _unlockTime=AnewAchievement._unlockTime;
}
SAchievementPlayer & SAchievementPlayer::operator=(const SAchievementPlayer & AnewAchievement) {
    _apiName=AnewAchievement._apiName;
    _achieved=AnewAchievement._achieved;
    _unlockTime=AnewAchievement._unlockTime;
    return *this;
}

SAchievementsGlobal::SAchievementsGlobal(QString Aappid, QObject *parent) : QObject(parent){
    _manager = new QNetworkAccessManager();
    connect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsGlobal::Load);
    _appid=Aappid;
    _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUserStats/GetSchemaForGame/v2/?key="+_setting.GetKey()+"&appid="+Aappid+"&l="+tr("russian")));
}
SAchievementsGlobal::SAchievementsGlobal(QJsonDocument Aachievements){
    _manager = new QNetworkAccessManager();
    if(Aachievements.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().size()>0){
        _gameName=Aachievements.object().value("game").toObject().value("gameName").toString();
        _gameVersion=Aachievements.object().value("game").toObject().value("gameVersion").toString();
        _achievements.resize(Aachievements.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().size());
        for (int i=0;i<_achievements.size();i++)
             _achievements[i]=SAchievementGlobal(Aachievements.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().at(i).toObject());
        _status=StatusValue::success;
    }
    else {
        _status=StatusValue::error;
        _error="game is not exist";
    }
}
SAchievementsGlobal::SAchievementsGlobal(){
    _manager = new QNetworkAccessManager();
}
SAchievementsGlobal::~SAchievementsGlobal(){
    delete _manager;
}
void SAchievementsGlobal::Set(QString Aappid){
    connect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsGlobal::Load);
    _appid=Aappid;
    _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUserStats/GetSchemaForGame/v2/?key="+_setting.GetKey()+"&appid="+Aappid+"&l="+tr("russian")));
}
void SAchievementsGlobal::Set(QJsonDocument Aachievements){
    Clear();
    if(Aachievements.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().size()>0){
        _gameName=Aachievements.object().value("game").toObject().value("gameName").toString();
        _gameVersion=Aachievements.object().value("game").toObject().value("gameVersion").toString();
        _achievements.resize(Aachievements.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().size());
        for (int i=0;i<_achievements.size();i++)
             _achievements[i]=SAchievementGlobal(Aachievements.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().at(i).toObject());
        _status=StatusValue::success;
    }
    else {
        _status=StatusValue::error;
        _error="game is not exist";
    }
}
void SAchievementsGlobal::Load(QNetworkReply *Areply){
    disconnect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsGlobal::Load);
    QJsonDocument localAchievements = QJsonDocument::fromJson(Areply->readAll());
    Areply->deleteLater();
    Set(localAchievements);
    emit s_finished(*this);
    emit s_finished();
}
void SAchievementsGlobal::Update(){
    Set(_appid);
}
void SAchievementsGlobal::Clear(){
    _achievements.clear();
}
SAchievementsGlobal::SAchievementsGlobal(const SAchievementsGlobal & AnewAchievements){
    _achievements=AnewAchievements._achievements;
    _appid=AnewAchievements._appid;
    _gameName=AnewAchievements._gameName;
    _gameVersion=AnewAchievements._gameVersion;
    _status=AnewAchievements._status;
    _error=AnewAchievements._error;
    _manager = new QNetworkAccessManager;
}
SAchievementsGlobal & SAchievementsGlobal::operator=(const SAchievementsGlobal & AnewAchievements){
    delete _manager;
    _achievements=AnewAchievements._achievements;
    _appid=AnewAchievements._appid;
    _gameName=AnewAchievements._gameName;
    _gameVersion=AnewAchievements._gameVersion;
    _status=AnewAchievements._status;
    _error=AnewAchievements._error;
    _manager = new QNetworkAccessManager;
    return *this;
}
SAchievementGlobal &SAchievementsGlobal::operator[](const int &Aindex){
    return _achievements[Aindex];
}

SAchievementsPercentage::SAchievementsPercentage(QString Aappid, QObject *parent) : QObject(parent){
    _manager = new QNetworkAccessManager();
    connect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsPercentage::Load);
    _appid=Aappid;
    _manager->get(QNetworkRequest("https://api.steampowered.com/ISteamUserStats/GetGlobalAchievementPercentagesForApp/v1/?key="+_setting.GetKey()+"&gameid="+Aappid));
}
SAchievementsPercentage::SAchievementsPercentage(QJsonDocument Aachievements){
    _manager = new QNetworkAccessManager();
    if(Aachievements.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().size()>0){
        _achievements.resize(Aachievements.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().size());
        for (int i=0;i<_achievements.size();i++)
             _achievements[i]=SAchievementPercentage(Aachievements.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().at(i).toObject());
        _status=StatusValue::success;
    }
    else {
        _status=StatusValue::error;
        _error="game is not exist";
    }
}
SAchievementsPercentage::SAchievementsPercentage(){
    _manager = new QNetworkAccessManager();
}
SAchievementsPercentage::~SAchievementsPercentage(){
    delete _manager;
}
void SAchievementsPercentage::Set(QString Aappid){
    connect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsPercentage::Load);
    _appid=Aappid;
    _manager->get(QNetworkRequest("https://api.steampowered.com/ISteamUserStats/GetGlobalAchievementPercentagesForApp/v1/?key="+_setting.GetKey()+"&gameid="+Aappid));
}
void SAchievementsPercentage::Set(QJsonDocument Aachievements){
    Clear();
    if(Aachievements.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().size()>0){
        _achievements.resize(Aachievements.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().size());
        for (int i=0;i<_achievements.size();i++)
             _achievements[i]=SAchievementPercentage(Aachievements.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().at(i).toObject());
        _status=StatusValue::success;
    }
    else {
        _status=StatusValue::error;
        _error="game is not exist";
    }
}
void SAchievementsPercentage::Load(QNetworkReply *Areply){
    disconnect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsPercentage::Load);
    QJsonDocument localAchievements = QJsonDocument::fromJson(Areply->readAll());
    Areply->deleteLater();
    Set(localAchievements);
    emit s_finished(*this);
    emit s_finished();
}
void SAchievementsPercentage::Update(){
    Set(_appid);
}
void SAchievementsPercentage::Clear(){
    _achievements.clear();
}
SAchievementsPercentage::SAchievementsPercentage( const SAchievementsPercentage & AnewAchievements){
    _achievements=AnewAchievements._achievements;
    _appid=AnewAchievements._appid;
    _status=AnewAchievements._status;
    _error=AnewAchievements._error;
    _manager = new QNetworkAccessManager;
}
SAchievementsPercentage & SAchievementsPercentage::operator=(const SAchievementsPercentage & AnewAchievements) {
    delete _manager;
    _achievements=AnewAchievements._achievements;
    _appid=AnewAchievements._appid;
    _status=AnewAchievements._status;
    _error=AnewAchievements._error;
    _manager = new QNetworkAccessManager;
    return *this;
}
SAchievementPercentage &SAchievementsPercentage::operator[](const int &Aindex){
    return _achievements[Aindex];
}

SAchievementsPlayer::SAchievementsPlayer(QString Aappid, QString Aid, QObject *parent) : QObject(parent){
    _manager = new QNetworkAccessManager();
    connect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsPlayer::Load);
    _appid=Aappid;
    _id=Aid;
    _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUserStats/GetPlayerAchievements/v0001/?key="+_setting.GetKey()+"&appid="+Aappid+"&steamid="+Aid));
}
SAchievementsPlayer::SAchievementsPlayer(QJsonDocument Aachievements){
    _manager = new QNetworkAccessManager();
    if(Aachievements.object().value("playerstats").toObject().value("achievements").toArray().size()>0){
        _appid=Aachievements.object().value("playerstats").toObject().value("steamID").toString();
        _gameName=Aachievements.object().value("playerstats").toObject().value("gameName").toString();
        _achievements.resize(Aachievements.object().value("playerstats").toObject().value("achievements").toArray().size());
        for (int i=0;i<_achievements.size();i++)
             _achievements[i]=SAchievementPlayer(Aachievements.object().value("playerstats").toObject().value("achievements").toArray().at(i).toObject());
        _status=StatusValue::success;
    }
    else {
        _status=StatusValue::error;
        _error="profile is not exist";
    }
}
SAchievementsPlayer::SAchievementsPlayer(){
    _manager = new QNetworkAccessManager();
}
SAchievementsPlayer::~SAchievementsPlayer(){
    delete _manager;
}
void SAchievementsPlayer::Set(QString Aappid, QString Aid){
    connect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsPlayer::Load);
    _appid=Aappid;
    _id=Aid;
    _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUserStats/GetPlayerAchievements/v0001/?key="+_setting.GetKey()+"&appid="+Aappid+"&steamid="+Aid));
}
void SAchievementsPlayer::Set(QJsonDocument Aachievements){
    Clear();
    if(Aachievements.object().value("playerstats").toObject().value("achievements").toArray().size()>0){
        _appid=Aachievements.object().value("playerstats").toObject().value("steamID").toString();
        _gameName=Aachievements.object().value("playerstats").toObject().value("gameName").toString();
        _achievements.resize(Aachievements.object().value("playerstats").toObject().value("achievements").toArray().size());
        for (int i=0;i<_achievements.size();i++)
             _achievements[i]=SAchievementPlayer(Aachievements.object().value("playerstats").toObject().value("achievements").toArray().at(i).toObject());
        _status=StatusValue::success;
    }
    else {
        _status=StatusValue::error;
        _error="profile is not exist";
    }
}
void SAchievementsPlayer::Load(QNetworkReply *Areply){
    disconnect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsPlayer::Load);
    QJsonDocument localAchievements = QJsonDocument::fromJson(Areply->readAll());
    Areply->deleteLater();
    Set(localAchievements);
    emit s_finished(*this);
    emit s_finished();
}
void SAchievementsPlayer::Update(){
    Set(_appid,_id);
}
void SAchievementsPlayer::Clear(){
    _achievements.clear();
}
SAchievementsPlayer::SAchievementsPlayer( const SAchievementsPlayer & AnewAchievements){
    _achievements=AnewAchievements._achievements;
    _appid=AnewAchievements._appid;
    _id=AnewAchievements._id;
    _gameName=AnewAchievements._gameName;
    _status=AnewAchievements._status;
    _error=AnewAchievements._error;
    _index=AnewAchievements._index;
    _manager = new QNetworkAccessManager;
}
SAchievementsPlayer & SAchievementsPlayer::operator=(const SAchievementsPlayer & AnewAchievements) {
    delete _manager;
    _achievements=AnewAchievements._achievements;
    _appid=AnewAchievements._appid;
    _id=AnewAchievements._id;
    _gameName=AnewAchievements._gameName;
    _status=AnewAchievements._status;
    _error=AnewAchievements._error;
    _index=AnewAchievements._index;
    _manager = new QNetworkAccessManager;
    return *this;
}
SAchievementPlayer &SAchievementsPlayer::operator[](const int &Aindex){
    return _achievements[Aindex];
}

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
const bool &SAchievement::operator<(const SAchievement &Aachievement){
    static const bool b=_displayName.toLower()<Aachievement._displayName.toLower();
    return b;
}

SAchievements::SAchievements(QString Aappid, QString Aid, QObject *parent) : QObject(parent){
    _appid=Aappid;
    _id=Aid;
    SAchievementsGlobal *Global = new SAchievementsGlobal(Aappid);
    connect(Global,SIGNAL(s_finished(SAchievementsGlobal)),this,SLOT(Set(SAchievementsGlobal)));
    SAchievementsPlayer *Player = new SAchievementsPlayer(Aappid,Aid);
    connect(Player,SIGNAL(s_finished(SAchievementsPlayer)),this,SLOT(Set(SAchievementsPlayer)));
    SAchievementsPercentage *Percent = new SAchievementsPercentage(Aappid);
    connect(Percent,SIGNAL(s_finished(SAchievementsPercentage)),this,SLOT(Set(SAchievementsPercentage)));
}
SAchievements::SAchievements(SAchievementsGlobal Aglobal, SAchievementsPlayer Aplayer, SAchievementsPercentage Apercent){
    qDebug()<<"Set All Achievements data";
    _percent=Apercent;
    _statusPercent=StatusValue::success;
    _global=Aglobal;
    _statusGlobal=StatusValue::success;
    _player=Aplayer;
    _statusPlayer=StatusValue::success;
    SAchievementsGlobal localGlobal = _global;
    SAchievementsPlayer localPlayer = _player;
    SAchievementsPercentage localPercent = _percent;
    for(int i=0;i<localPercent.GetCount();i++){
        for(int j=0;j<localPlayer.GetCount();j++){
            if(localPercent[i].GetApiname()==localPlayer[j].GetApiname()){
                SAchievement achievement;
                achievement.SetPercent(localPercent[i]);
                achievement.SetPlayer(localPlayer[j]);
                achievement.SetGlobal(localGlobal[j]);
                localPlayer.Delete(j);
                localGlobal.Delete(j);
                _finish.push_back(achievement);
                break;
            }
        }
    }
    _statusFinish=StatusValue::success;
    emit s_finished();
}
void SAchievements::Set(QString Aappid, QString Aid){
    _appid=Aappid;
    _id=Aid;
    SAchievementsGlobal *Global = new SAchievementsGlobal(Aappid);
    connect(Global,SIGNAL(s_finished(SAchievementsGlobal)),this,SLOT(Set(SAchievementsGlobal)));
    SAchievementsPlayer *Player = new SAchievementsPlayer(Aappid,Aid);
    connect(Player,SIGNAL(s_finished(SAchievementsPlayer)),this,SLOT(Set(SAchievementsPlayer)));
    SAchievementsPercentage *Percent = new SAchievementsPercentage(Aappid);
    connect(Percent,SIGNAL(s_finished(SAchievementsPercentage)),this,SLOT(Set(SAchievementsPercentage)));
}
void SAchievements::SetIDs(QString Aappid, QString Aid){
    _appid=Aappid;
    _id=Aid;
}
void SAchievements::Set(SAchievementsGlobal Aglobal, SAchievementsPlayer Aplayer, SAchievementsPercentage Apercent){
    Set(Apercent);
    Set(Aglobal);
    Set(Aplayer);
}
void SAchievements::Set(SAchievementsPlayer Aplayer){
    qDebug()<<"Player set";
    _player=Aplayer;
    _statusPlayer=StatusValue::success;
    if(_statusGlobal==StatusValue::success&&_statusPlayer==StatusValue::success&&_statusPercent==StatusValue::success){
        SetFinish();
    }
}
void SAchievements::Set(SAchievementsGlobal Aglobal){
    qDebug()<<"Global set";
    _global=Aglobal;
    _statusGlobal=StatusValue::success;
    if(_statusGlobal==StatusValue::success&&_statusPlayer==StatusValue::success&&_statusPercent==StatusValue::success){
        SetFinish();
    }
}
void SAchievements::Set(SAchievementsPercentage Apercent){
    qDebug()<<"Percent set";
    _percent=Apercent;
    _statusPercent=StatusValue::success;
    if(_statusGlobal==StatusValue::success&&_statusPlayer==StatusValue::success&&_statusPercent==StatusValue::success){
        SetFinish();
    }
}
void SAchievements::SetFinish(){
    qDebug()<<"Finish set";
    Clear();
    SAchievementsGlobal localGlobal = _global;
    SAchievementsPlayer localPlayer = _player;
    SAchievementsPercentage localPercent = _percent;
    for(int i=0;i<localPercent.GetCount();i++){
        for(int j=0;j<localPlayer.GetCount();j++){
            if(localPercent[i].GetApiname()==localPlayer[j].GetApiname()){
                SAchievement achievement;
                achievement.SetPercent(localPercent[i]);
                achievement.SetPlayer(localPlayer[j]);
                achievement.SetGlobal(localGlobal[j]);
                localPlayer.Delete(j);
                localGlobal.Delete(j);
                _finish.push_back(achievement);
                break;
            }
        }
    }
    _statusFinish=StatusValue::success;
    emit s_finished();
}
void SAchievements::Update(){
    qDebug()<<_appid<<_id;
    _statusGlobal=StatusValue::none;
    _statusPlayer=StatusValue::none;
    _statusPercent=StatusValue::none;
    _statusFinish=StatusValue::none;
    Set(_appid,_id);
}
void SAchievements::Clear(){
    _finish.clear();
}
void SAchievements::Sort(){
    //Переделать нормально
    std::list<SAchievement> list = _finish.toList().toStdList();
    list.sort();
    _finish=QVector<SAchievement>::fromList(QList<SAchievement>::fromStdList(list));
}
SAchievements::SAchievements(const SAchievements & AnewAchievements){
    _finish=AnewAchievements._finish;
    _global=AnewAchievements._global;
    _player=AnewAchievements._player;
    _percent=AnewAchievements._percent;
    _statusGlobal=AnewAchievements._statusGlobal;
    _statusPlayer=AnewAchievements._statusPlayer;
    _statusPercent=AnewAchievements._statusPercent;
    _statusFinish=AnewAchievements._statusFinish;
    _errorGlobal=AnewAchievements._errorGlobal;
    _errorPlayer=AnewAchievements._errorPlayer;
    _errorPercent=AnewAchievements._errorPercent;
    _errorFinish=AnewAchievements._errorFinish;
    _id=AnewAchievements._id;
    _appid=AnewAchievements._appid;
    _gameName=AnewAchievements._gameName;
    _gameVersion=AnewAchievements._gameVersion;
}
SAchievements & SAchievements::operator=(const SAchievements & AnewAchievements){
    _finish=AnewAchievements._finish;
    _global=AnewAchievements._global;
    _player=AnewAchievements._player;
    _percent=AnewAchievements._percent;
    _statusGlobal=AnewAchievements._statusGlobal;
    _statusPlayer=AnewAchievements._statusPlayer;
    _statusPercent=AnewAchievements._statusPercent;
    _statusFinish=AnewAchievements._statusFinish;
    _errorGlobal=AnewAchievements._errorGlobal;
    _errorPlayer=AnewAchievements._errorPlayer;
    _errorPercent=AnewAchievements._errorPercent;
    _errorFinish=AnewAchievements._errorFinish;
    _id=AnewAchievements._id;
    _appid=AnewAchievements._appid;
    _gameName=AnewAchievements._gameName;
    _gameVersion=AnewAchievements._gameVersion;
    return *this;
}
SAchievement &SAchievements::operator[](const int &Aindex){
    return _finish[Aindex];
}
