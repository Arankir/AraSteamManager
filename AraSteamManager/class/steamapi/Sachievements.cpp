#include "Sachievements.h"

#define SAchievementStart {
const bool &SAchievement::operator<(const SAchievement &a_achievement){
    static const bool b=_displayName.toLower()<a_achievement._displayName.toLower();
    return b;
}
#define SAchievementEnd }
#define MultipleAchievements {
#define SAchievementsGlobalStart {
SAchievementsGlobal::SAchievementsGlobal(QString a_appid, bool parallel, QObject *parent) : QObject(parent),_manager(new QNetworkAccessManager()),_appid(a_appid){
    connect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsGlobal::Load);
    _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUserStats/GetSchemaForGame/v2/?key="+_setting.GetKey()+"&appid="+a_appid+"&l="+tr("russian")));
    if(!parallel){
        QEventLoop loop;
        connect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        loop.exec();
        disconnect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
     }
}
SAchievementsGlobal::SAchievementsGlobal(QJsonDocument a_achievements, QObject *parent) : QObject(parent),_manager(new QNetworkAccessManager()){
    Set(a_achievements);
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
        for(int i=0; i<a_achievements.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().size();i++){
            _achievements.append(std::move(SAchievementGlobal(a_achievements.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().at(i).toObject())));
        }
        _status=StatusValue::success;
    }
    else {
        _status=StatusValue::error;
        _error="game is not exist";
    }
}
void SAchievementsGlobal::Load(QNetworkReply *a_reply){
    disconnect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsGlobal::Load);
    Set(QJsonDocument::fromJson(a_reply->readAll()));
    a_reply->deleteLater();
    emit s_finished(*this);
    emit s_finished();
}
void SAchievementsGlobal::Update(){
    Set(_appid);
}
void SAchievementsGlobal::Clear(){
    _achievements.clear();
    _status=StatusValue::none;
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
#define SAchievementsGlobalEnd }
#define SAchievementsPercentageStart {
SAchievementsPercentage::SAchievementsPercentage(QString a_appid, bool parallel, QObject *parent) : QObject(parent),_manager(new QNetworkAccessManager()), _appid(a_appid){
    connect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsPercentage::Load);
    _manager->get(QNetworkRequest("https://api.steampowered.com/ISteamUserStats/GetGlobalAchievementPercentagesForApp/v1/?key="+_setting.GetKey()+"&gameid="+a_appid));
    if(!parallel){
        QEventLoop loop;
        connect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        loop.exec();
        disconnect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
     }
}
SAchievementsPercentage::SAchievementsPercentage(QJsonDocument a_achievements, QObject *parent) : QObject(parent),_manager(new QNetworkAccessManager()){
    Set(a_achievements);
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
        for(int i=0;i<a_achievements.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().size();i++){
            _achievements.append(std::move(SAchievementPercentage(a_achievements.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().at(i).toObject())));
        }
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
    _status=StatusValue::none;
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
#define SAchievementsPercentageEnd }
#define SAchievementsPlayerStart {
SAchievementsPlayer::SAchievementsPlayer(QString a_appid, QString a_id, bool parallel, QObject *parent) : QObject(parent),_manager(new QNetworkAccessManager()), _id(a_id), _appid(a_appid){
    connect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsPlayer::Load);
    _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUserStats/GetPlayerAchievements/v0001/?key="+_setting.GetKey()+"&appid="+a_appid+"&steamid="+a_id));
    if(!parallel){
        QEventLoop loop;
        connect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        loop.exec();
        disconnect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
     }
}
SAchievementsPlayer::SAchievementsPlayer(QJsonDocument a_achievements, QObject *parent) : QObject(parent),_manager(new QNetworkAccessManager()){
    Set(a_achievements);
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
        for(int i=0;i<a_achievements.object().value("playerstats").toObject().value("achievements").toArray().size();i++){
            _achievements.append(std::move(SAchievementPlayer(a_achievements.object().value("playerstats").toObject().value("achievements").toArray().at(i).toObject())));
        }
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
    _status=StatusValue::none;
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
#define SAchievementsPlayerEnd }
#define MultipleAchievementsEnd }
#define SAchievementsStart {
SAchievements::SAchievements(QString a_appid, QString a_id, QObject *parent) : QObject(parent),_id(a_id),_appid(a_appid){
    SAchievementsGlobal *global = new SAchievementsGlobal(a_appid);
    connect(global,SIGNAL(s_finished(SAchievementsGlobal)),this,SLOT(Set(SAchievementsGlobal)));
    SAchievementsPlayer *player = new SAchievementsPlayer(a_appid,a_id);
    connect(player,SIGNAL(s_finished(SAchievementsPlayer)),this,SLOT(Set(SAchievementsPlayer)));
    SAchievementsPercentage *percent = new SAchievementsPercentage(a_appid);
    connect(percent,SIGNAL(s_finished(SAchievementsPercentage)),this,SLOT(Set(SAchievementsPercentage)));
}
SAchievements::SAchievements(SAchievementsGlobal &a_global, SAchievementsPlayer &a_player, SAchievementsPercentage &a_percent, QObject *parent) : QObject(parent),
                    _global(a_global),_player(a_player),_percent(a_percent),_statusGlobal(StatusValue::success),_statusPlayer(StatusValue::success),_statusPercent(StatusValue::success){
    qDebug()<<"Set All Achievements data";
    SetFinish();
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
void SAchievements::Set(SAchievementsGlobal &a_global, SAchievementsPlayer &a_player, SAchievementsPercentage &a_percent){
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
    for(const auto &percent: localPercent){
        int globalIndex=0;
        for(const auto &player: localPlayer){
            const auto &global = localGlobal[globalIndex++];
            if(percent._apiName==player._apiName){
                _finish.push_back(std::move(SAchievement(global,player,percent)));
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
    _statusFinish=StatusValue::none;
}
void SAchievements::Sort(){
    //Переделать нормально
    //std::list<SAchievement> list = _finish.toList().toStdList();
    std::list<SAchievement> list(_finish.begin(),_finish.end());
    list.sort();
    _finish=QList<SAchievement>(list.begin(),list.end());
    //_finish=QVector<SAchievement>::fromList(QList<SAchievement>::fromStdList(list));
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
#define SAchievementsEnd }
