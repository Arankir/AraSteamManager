#include "Sachievements.h"

#define SAchievementGlobalStart {
SAchievementGlobal::SAchievementGlobal(QJsonObject a_achievement, QObject *parent) : QObject(parent){
    _apiName=a_achievement.value("name").toString();
    _defaultValue=a_achievement.value("defaultvalue").toInt();
    _displayName=a_achievement.value("displayName").toString();
    _hidden=a_achievement.value("hidden").toInt();
    _description=a_achievement.value("description").toString();
    _icon=a_achievement.value("icon").toString();
    _iconGray=a_achievement.value("icongray").toString();
}
SAchievementGlobal::SAchievementGlobal(){

}
void SAchievementGlobal::Set(QJsonObject a_achievement){
    _apiName=a_achievement.value("name").toString();
    _defaultValue=a_achievement.value("defaultvalue").toInt();
    _displayName=a_achievement.value("displayName").toString();
    _hidden=a_achievement.value("hidden").toInt();
    _description=a_achievement.value("description").toString();
    _icon=a_achievement.value("icon").toString();
    _iconGray=a_achievement.value("icongray").toString();
}
SAchievementGlobal::SAchievementGlobal( const SAchievementGlobal & a_newAchievements){
    _apiName=a_newAchievements._apiName;
    _defaultValue=a_newAchievements._defaultValue;
    _displayName=a_newAchievements._displayName;
    _hidden=a_newAchievements._hidden;
    _description=a_newAchievements._description;
    _icon=a_newAchievements._icon;
    _iconGray=a_newAchievements._iconGray;
}
SAchievementGlobal & SAchievementGlobal::operator=(const SAchievementGlobal & a_newAchievements) {
    _apiName=a_newAchievements._apiName;
    _defaultValue=a_newAchievements._defaultValue;
    _displayName=a_newAchievements._displayName;
    _hidden=a_newAchievements._hidden;
    _description=a_newAchievements._description;
    _icon=a_newAchievements._icon;
    _iconGray=a_newAchievements._iconGray;
    return *this;
}
#define SAchievementGlobalEnd }
#define SAchievementPercentageStart {
SAchievementPercentage::SAchievementPercentage(QJsonObject a_achievement, QObject *parent) : QObject(parent){
    _apiName=a_achievement.value("name").toString();
    _percent=a_achievement.value("percent").toDouble();
}
SAchievementPercentage::SAchievementPercentage(){

}
void SAchievementPercentage::Set(QJsonObject a_achievement){
    _apiName=a_achievement.value("name").toString();
    _percent=a_achievement.value("percent").toDouble();
}
SAchievementPercentage::SAchievementPercentage(const SAchievementPercentage & a_newAchievement){
    _apiName=a_newAchievement._apiName;
    _percent=a_newAchievement._percent;
}
SAchievementPercentage & SAchievementPercentage::operator=(const SAchievementPercentage & a_newAchievement){
    _apiName=a_newAchievement._apiName;
    _percent=a_newAchievement._percent;
    return *this;
}
#define SAchievementPercentageEnd }
#define SAchievementPlayerStart {
SAchievementPlayer::SAchievementPlayer(QJsonObject a_achievement, QObject *parent) : QObject(parent){
    _apiName=a_achievement.value("apiname").toString();
    _achieved=a_achievement.value("achieved").toInt();
    _unlockTime=QDateTime::fromSecsSinceEpoch(a_achievement.value("unlocktime").toInt(),Qt::LocalTime);
}
SAchievementPlayer::SAchievementPlayer(){

}
void SAchievementPlayer::Set(QJsonObject a_achievement){
    _apiName=a_achievement.value("apiname").toString();
    _achieved=a_achievement.value("achieved").toInt();
    _unlockTime=QDateTime::fromSecsSinceEpoch(a_achievement.value("unlocktime").toInt(),Qt::LocalTime);
}
SAchievementPlayer::SAchievementPlayer( const SAchievementPlayer & a_newAchievement){
    _apiName=a_newAchievement._apiName;
    _achieved=a_newAchievement._achieved;
    _unlockTime=a_newAchievement._unlockTime;
}
SAchievementPlayer & SAchievementPlayer::operator=(const SAchievementPlayer & a_newAchievement) {
    _apiName=a_newAchievement._apiName;
    _achieved=a_newAchievement._achieved;
    _unlockTime=a_newAchievement._unlockTime;
    return *this;
}
#define SAchievementPlayerEnd }
#define SAchievementsGlobalStart {
SAchievementsGlobal::SAchievementsGlobal(QString a_appid, bool parallel, QObject *parent) : QObject(parent){
    _manager = new QNetworkAccessManager();
    connect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsGlobal::Load);
    _appid=a_appid;
    _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUserStats/GetSchemaForGame/v2/?key="+_setting.GetKey()+"&appid="+a_appid+"&l="+tr("russian")));
    if(!parallel){
        QEventLoop loop;
        connect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        loop.exec();
        disconnect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
     }
}
SAchievementsGlobal::SAchievementsGlobal(QJsonDocument a_achievements){
    _manager = new QNetworkAccessManager();
    if(a_achievements.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().size()>0){
        _gameName=a_achievements.object().value("game").toObject().value("gameName").toString();
        _gameVersion=a_achievements.object().value("game").toObject().value("gameVersion").toString();
        _achievements.resize(a_achievements.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().size());
        for (int i=0;i<_achievements.size();i++)
             _achievements[i]=SAchievementGlobal(a_achievements.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().at(i).toObject());
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
void SAchievementsGlobal::Set(QString a_appid){
    connect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsGlobal::Load);
    _appid=a_appid;
    _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUserStats/GetSchemaForGame/v2/?key="+_setting.GetKey()+"&appid="+a_appid+"&l="+tr("russian")));
}
void SAchievementsGlobal::Set(QJsonDocument a_achievements){
    Clear();
    if(a_achievements.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().size()>0){
        _gameName=a_achievements.object().value("game").toObject().value("gameName").toString();
        _gameVersion=a_achievements.object().value("game").toObject().value("gameVersion").toString();
        _achievements.resize(a_achievements.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().size());
        for (int i=0;i<_achievements.size();i++)
             _achievements[i]=SAchievementGlobal(a_achievements.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().at(i).toObject());
        _status=StatusValue::success;
    }
    else {
        _status=StatusValue::error;
        _error="game is not exist";
    }
}
void SAchievementsGlobal::Load(QNetworkReply *a_reply){
    disconnect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsGlobal::Load);
    QJsonDocument localAchievements = QJsonDocument::fromJson(a_reply->readAll());
    a_reply->deleteLater();
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
SAchievementsGlobal::SAchievementsGlobal(const SAchievementsGlobal & a_newAchievements){
    _achievements=a_newAchievements._achievements;
    _appid=a_newAchievements._appid;
    _gameName=a_newAchievements._gameName;
    _gameVersion=a_newAchievements._gameVersion;
    _status=a_newAchievements._status;
    _error=a_newAchievements._error;
    _manager = new QNetworkAccessManager;
}
SAchievementsGlobal & SAchievementsGlobal::operator=(const SAchievementsGlobal & a_newAchievements){
    delete _manager;
    _achievements=a_newAchievements._achievements;
    _appid=a_newAchievements._appid;
    _gameName=a_newAchievements._gameName;
    _gameVersion=a_newAchievements._gameVersion;
    _status=a_newAchievements._status;
    _error=a_newAchievements._error;
    _manager = new QNetworkAccessManager;
    return *this;
}
SAchievementGlobal &SAchievementsGlobal::operator[](const int &a_index){
    return _achievements[a_index];
}
#define SAchievementsGlobalEnd }
#define SAchievementsPercentageStart {
SAchievementsPercentage::SAchievementsPercentage(QString a_appid, bool parallel, QObject *parent) : QObject(parent){
    _manager = new QNetworkAccessManager();
    connect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsPercentage::Load);
    _appid=a_appid;
    _manager->get(QNetworkRequest("https://api.steampowered.com/ISteamUserStats/GetGlobalAchievementPercentagesForApp/v1/?key="+_setting.GetKey()+"&gameid="+a_appid));
    if(!parallel){
        QEventLoop loop;
        connect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        loop.exec();
        disconnect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
     }
}
SAchievementsPercentage::SAchievementsPercentage(QJsonDocument a_achievements){
    _manager = new QNetworkAccessManager();
    if(a_achievements.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().size()>0){
        _achievements.resize(a_achievements.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().size());
        for (int i=0;i<_achievements.size();i++)
             _achievements[i]=SAchievementPercentage(a_achievements.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().at(i).toObject());
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
void SAchievementsPercentage::Set(QString a_appid){
    connect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsPercentage::Load);
    _appid=a_appid;
    _manager->get(QNetworkRequest("https://api.steampowered.com/ISteamUserStats/GetGlobalAchievementPercentagesForApp/v1/?key="+_setting.GetKey()+"&gameid="+a_appid));
}
void SAchievementsPercentage::Set(QJsonDocument a_achievements){
    Clear();
    if(a_achievements.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().size()>0){
        _achievements.resize(a_achievements.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().size());
        for (int i=0;i<_achievements.size();i++)
             _achievements[i]=SAchievementPercentage(a_achievements.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().at(i).toObject());
        _status=StatusValue::success;
    }
    else {
        _status=StatusValue::error;
        _error="game is not exist";
    }
}
void SAchievementsPercentage::Load(QNetworkReply *a_reply){
    disconnect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsPercentage::Load);
    QJsonDocument localAchievements = QJsonDocument::fromJson(a_reply->readAll());
    a_reply->deleteLater();
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
SAchievementsPercentage::SAchievementsPercentage( const SAchievementsPercentage & a_newAchievements){
    _achievements=a_newAchievements._achievements;
    _appid=a_newAchievements._appid;
    _status=a_newAchievements._status;
    _error=a_newAchievements._error;
    _manager = new QNetworkAccessManager;
}
SAchievementsPercentage & SAchievementsPercentage::operator=(const SAchievementsPercentage & a_newAchievements) {
    delete _manager;
    _achievements=a_newAchievements._achievements;
    _appid=a_newAchievements._appid;
    _status=a_newAchievements._status;
    _error=a_newAchievements._error;
    _manager = new QNetworkAccessManager;
    return *this;
}
SAchievementPercentage &SAchievementsPercentage::operator[](const int &a_index){
    return _achievements[a_index];
}
#define SAchievementsPercentageEnd }
#define SAchievementsPlayerStart {
SAchievementsPlayer::SAchievementsPlayer(QString a_appid, QString a_id, bool parallel, QObject *parent) : QObject(parent){
    _manager = new QNetworkAccessManager();
    connect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsPlayer::Load);
    _appid=a_appid;
    _id=a_id;
    _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUserStats/GetPlayerAchievements/v0001/?key="+_setting.GetKey()+"&appid="+a_appid+"&steamid="+a_id));
    if(!parallel){
        QEventLoop loop;
        connect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        loop.exec();
        disconnect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
     }
}
SAchievementsPlayer::SAchievementsPlayer(QJsonDocument a_achievements){
    _manager = new QNetworkAccessManager();
    if(a_achievements.object().value("playerstats").toObject().value("achievements").toArray().size()>0){
        _appid=a_achievements.object().value("playerstats").toObject().value("steamID").toString();
        _gameName=a_achievements.object().value("playerstats").toObject().value("gameName").toString();
        _achievements.resize(a_achievements.object().value("playerstats").toObject().value("achievements").toArray().size());
        for (int i=0;i<_achievements.size();i++)
             _achievements[i]=SAchievementPlayer(a_achievements.object().value("playerstats").toObject().value("achievements").toArray().at(i).toObject());
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
void SAchievementsPlayer::Set(QString a_appid, QString a_id){
    connect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsPlayer::Load);
    _appid=a_appid;
    _id=a_id;
    _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUserStats/GetPlayerAchievements/v0001/?key="+_setting.GetKey()+"&appid="+a_appid+"&steamid="+a_id));
}
void SAchievementsPlayer::Set(QJsonDocument a_achievements){
    Clear();
    if(a_achievements.object().value("playerstats").toObject().value("achievements").toArray().size()>0){
        _appid=a_achievements.object().value("playerstats").toObject().value("steamID").toString();
        _gameName=a_achievements.object().value("playerstats").toObject().value("gameName").toString();
        _achievements.resize(a_achievements.object().value("playerstats").toObject().value("achievements").toArray().size());
        for (int i=0;i<_achievements.size();i++)
             _achievements[i]=SAchievementPlayer(a_achievements.object().value("playerstats").toObject().value("achievements").toArray().at(i).toObject());
        _status=StatusValue::success;
    }
    else {
        _status=StatusValue::error;
        _error="profile is not exist";
    }
}
void SAchievementsPlayer::Load(QNetworkReply *a_reply){
    disconnect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsPlayer::Load);
    QJsonDocument localAchievements = QJsonDocument::fromJson(a_reply->readAll());
    a_reply->deleteLater();
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
SAchievementsPlayer::SAchievementsPlayer( const SAchievementsPlayer & a_newAchievements){
    _achievements=a_newAchievements._achievements;
    _appid=a_newAchievements._appid;
    _id=a_newAchievements._id;
    _gameName=a_newAchievements._gameName;
    _status=a_newAchievements._status;
    _error=a_newAchievements._error;
    _index=a_newAchievements._index;
    _manager = new QNetworkAccessManager;
}
SAchievementsPlayer & SAchievementsPlayer::operator=(const SAchievementsPlayer & a_newAchievements) {
    delete _manager;
    _achievements=a_newAchievements._achievements;
    _appid=a_newAchievements._appid;
    _id=a_newAchievements._id;
    _gameName=a_newAchievements._gameName;
    _status=a_newAchievements._status;
    _error=a_newAchievements._error;
    _index=a_newAchievements._index;
    _manager = new QNetworkAccessManager;
    return *this;
}
SAchievementPlayer &SAchievementsPlayer::operator[](const int &a_index){
    return _achievements[a_index];
}
#define SAchievementsPlayerEnd }
#define SAchievementStart {
SAchievement::SAchievement(SAchievementGlobal a_global, SAchievementPlayer a_player, SAchievementPercentage a_percent, QObject *parent) : QObject(parent){
    _apiName=a_global.GetApiname();
    _defaultValue=a_global.GetDefaultvalue();
    _displayName=a_global.GetDisplayname();
    _hidden=a_global.GetHidden();
    _description=a_global.GetDescription();
    _icon=a_global.GetIcon();
    _iconGray=a_global.GetIcongray();
    _achieved=a_player.GetAchieved();
    _unlockTime=a_player.GetUnlocktime();
    _percent=a_percent.GetPercent();
    _statusGlobal=StatusValue::success;
    _statusPlayer=StatusValue::success;
    _statusPercent=StatusValue::success;
}
SAchievement::SAchievement(){

}
void SAchievement::Set(SAchievementGlobal a_global, SAchievementPlayer a_player, SAchievementPercentage a_percent){
    _apiName=a_global.GetApiname();
    _defaultValue=a_global.GetDefaultvalue();
    _displayName=a_global.GetDisplayname();
    _hidden=a_global.GetHidden();
    _description=a_global.GetDescription();
    _icon=a_global.GetIcon();
    _iconGray=a_global.GetIcongray();
    _achieved=a_player.GetAchieved();
    _unlockTime=a_player.GetUnlocktime();
    _percent=a_percent.GetPercent();
    _statusGlobal=StatusValue::success;
    _statusPlayer=StatusValue::success;
    _statusPercent=StatusValue::success;
}
void SAchievement::SetGlobal(SAchievementGlobal a_global){
    if(_apiName==""||_apiName==a_global.GetApiname()){
        _apiName=a_global.GetApiname();
        _defaultValue=a_global.GetDefaultvalue();
        _displayName=a_global.GetDisplayname();
        _hidden=a_global.GetHidden();
        _description=a_global.GetDescription();
        _icon=a_global.GetIcon();
        _iconGray=a_global.GetIcongray();
        _statusGlobal=StatusValue::success;
    } else {
        _statusGlobal=StatusValue::error;
        _errorGlobal="apiname is incorrect";
    }
}
void SAchievement::SetPlayer(SAchievementPlayer a_player){
    if(_apiName==""||_apiName==a_player.GetApiname()){
        _apiName=a_player.GetApiname();
        _achieved=a_player.GetAchieved();
        _unlockTime=a_player.GetUnlocktime();
        _statusPlayer=StatusValue::success;
    } else {
        _statusPlayer=StatusValue::error;
        _errorPlayer="apiname is incorrect";
    }
}
void SAchievement::SetPercent(SAchievementPercentage a_percent){
    if(_apiName==""||_apiName==a_percent.GetApiname()){
        _apiName=a_percent.GetApiname();
        _percent=a_percent.GetPercent();
        _statusPercent=StatusValue::success;
    } else {
        _statusPercent=StatusValue::error;
        _errorPercent="apiname is incorrect";
    }
}
SAchievement::SAchievement(const SAchievement & a_newAchievement){
    _apiName=a_newAchievement._apiName;
    _defaultValue=a_newAchievement._defaultValue;
    _displayName=a_newAchievement._displayName;
    _hidden=a_newAchievement._hidden;
    _description=a_newAchievement._description;
    _icon=a_newAchievement._icon;
    _iconGray=a_newAchievement._iconGray;
    _achieved=a_newAchievement._achieved;
    _unlockTime=a_newAchievement._unlockTime;
    _percent=a_newAchievement._percent;
    _statusGlobal=a_newAchievement._statusGlobal;
    _statusPlayer=a_newAchievement._statusPlayer;
    _statusPercent=a_newAchievement._statusPercent;
    _errorGlobal=a_newAchievement._errorGlobal;
    _errorPlayer=a_newAchievement._errorPlayer;
    _errorPercent=a_newAchievement._errorPercent;
}
SAchievement & SAchievement::operator=(const SAchievement & a_newAchievement){
    _apiName=a_newAchievement._apiName;
    _defaultValue=a_newAchievement._defaultValue;
    _displayName=a_newAchievement._displayName;
    _hidden=a_newAchievement._hidden;
    _description=a_newAchievement._description;
    _icon=a_newAchievement._icon;
    _iconGray=a_newAchievement._iconGray;
    _achieved=a_newAchievement._achieved;
    _unlockTime=a_newAchievement._unlockTime;
    _percent=a_newAchievement._percent;
    _statusGlobal=a_newAchievement._statusGlobal;
    _statusPlayer=a_newAchievement._statusPlayer;
    _statusPercent=a_newAchievement._statusPercent;
    _errorGlobal=a_newAchievement._errorGlobal;
    _errorPlayer=a_newAchievement._errorPlayer;
    _errorPercent=a_newAchievement._errorPercent;
    return *this;
}
const bool &SAchievement::operator<(const SAchievement &a_achievement){
    static const bool b=_displayName.toLower()<a_achievement._displayName.toLower();
    return b;
}
#define SAchievementEnd }
#define SAchievementsStart {
SAchievements::SAchievements(QString a_appid, QString a_id, QObject *parent) : QObject(parent){
    _appid=a_appid;
    _id=a_id;
    SAchievementsGlobal *Global = new SAchievementsGlobal(a_appid);
    connect(Global,SIGNAL(s_finished(SAchievementsGlobal)),this,SLOT(Set(SAchievementsGlobal)));
    SAchievementsPlayer *Player = new SAchievementsPlayer(a_appid,a_id);
    connect(Player,SIGNAL(s_finished(SAchievementsPlayer)),this,SLOT(Set(SAchievementsPlayer)));
    SAchievementsPercentage *Percent = new SAchievementsPercentage(a_appid);
    connect(Percent,SIGNAL(s_finished(SAchievementsPercentage)),this,SLOT(Set(SAchievementsPercentage)));
}
SAchievements::SAchievements(SAchievementsGlobal a_global, SAchievementsPlayer a_player, SAchievementsPercentage a_percent){
    qDebug()<<"Set All Achievements data";
    _percent=a_percent;
    _statusPercent=StatusValue::success;
    _global=a_global;
    _statusGlobal=StatusValue::success;
    _player=a_player;
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
void SAchievements::Set(QString a_appid, QString a_id){
    _appid=a_appid;
    _id=a_id;
    SAchievementsGlobal *Global = new SAchievementsGlobal(a_appid);
    connect(Global,SIGNAL(s_finished(SAchievementsGlobal)),this,SLOT(Set(SAchievementsGlobal)));
    SAchievementsPlayer *Player = new SAchievementsPlayer(a_appid,a_id);
    connect(Player,SIGNAL(s_finished(SAchievementsPlayer)),this,SLOT(Set(SAchievementsPlayer)));
    SAchievementsPercentage *Percent = new SAchievementsPercentage(a_appid);
    connect(Percent,SIGNAL(s_finished(SAchievementsPercentage)),this,SLOT(Set(SAchievementsPercentage)));
}
void SAchievements::Set(SAchievementsGlobal a_global, SAchievementsPlayer a_player, SAchievementsPercentage a_percent){
    Set(a_percent);
    Set(a_global);
    Set(a_player);
}
void SAchievements::Set(SAchievementsPlayer a_player){
    qDebug()<<"Player set";
    _player=a_player;
    _statusPlayer=StatusValue::success;
    if(_statusGlobal==StatusValue::success&&_statusPlayer==StatusValue::success&&_statusPercent==StatusValue::success){
        SetFinish();
    }
}
void SAchievements::Set(SAchievementsGlobal a_global){
    qDebug()<<"Global set";
    _global=a_global;
    _statusGlobal=StatusValue::success;
    if(_statusGlobal==StatusValue::success&&_statusPlayer==StatusValue::success&&_statusPercent==StatusValue::success){
        SetFinish();
    }
}
void SAchievements::Set(SAchievementsPercentage a_percent){
    qDebug()<<"Percent set";
    _percent=a_percent;
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
    _statusGlobal=StatusValue::none;
    _statusPlayer=StatusValue::none;
    _statusPercent=StatusValue::none;
    _statusFinish=StatusValue::none;
    SAchievementsGlobal *Global = new SAchievementsGlobal(_appid);
    connect(Global,SIGNAL(s_finished(SAchievementsGlobal)),this,SLOT(Set(SAchievementsGlobal)));
    SAchievementsPlayer *Player = new SAchievementsPlayer(_appid,_id);
    connect(Player,SIGNAL(s_finished(SAchievementsPlayer)),this,SLOT(Set(SAchievementsPlayer)));
    SAchievementsPercentage *Percent = new SAchievementsPercentage(_appid);
    connect(Percent,SIGNAL(s_finished(SAchievementsPercentage)),this,SLOT(Set(SAchievementsPercentage)));
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
SAchievements::SAchievements(const SAchievements & a_newAchievements){
    _finish=a_newAchievements._finish;
    _global=a_newAchievements._global;
    _player=a_newAchievements._player;
    _percent=a_newAchievements._percent;
    _statusGlobal=a_newAchievements._statusGlobal;
    _statusPlayer=a_newAchievements._statusPlayer;
    _statusPercent=a_newAchievements._statusPercent;
    _statusFinish=a_newAchievements._statusFinish;
    _errorGlobal=a_newAchievements._errorGlobal;
    _errorPlayer=a_newAchievements._errorPlayer;
    _errorPercent=a_newAchievements._errorPercent;
    _errorFinish=a_newAchievements._errorFinish;
    _id=a_newAchievements._id;
    _appid=a_newAchievements._appid;
    _gameName=a_newAchievements._gameName;
    _gameVersion=a_newAchievements._gameVersion;
}
SAchievements & SAchievements::operator=(const SAchievements & a_newAchievements){
    _finish=a_newAchievements._finish;
    _global=a_newAchievements._global;
    _player=a_newAchievements._player;
    _percent=a_newAchievements._percent;
    _statusGlobal=a_newAchievements._statusGlobal;
    _statusPlayer=a_newAchievements._statusPlayer;
    _statusPercent=a_newAchievements._statusPercent;
    _statusFinish=a_newAchievements._statusFinish;
    _errorGlobal=a_newAchievements._errorGlobal;
    _errorPlayer=a_newAchievements._errorPlayer;
    _errorPercent=a_newAchievements._errorPercent;
    _errorFinish=a_newAchievements._errorFinish;
    _id=a_newAchievements._id;
    _appid=a_newAchievements._appid;
    _gameName=a_newAchievements._gameName;
    _gameVersion=a_newAchievements._gameVersion;
    return *this;
}
SAchievement &SAchievements::operator[](const int &a_index){
    return _finish[a_index];
}
#define SAchievementsEnd }
