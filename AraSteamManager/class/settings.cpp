#include "settings.h"


Settings::Settings(QObject *a_parent) : Settings(QRect(),a_parent){}
Settings::Settings(QRect a_geometry, QObject *parent) : QObject(parent),_settings(new QSettings("Arankir","SteamAchievementsStatistic")),_screen(a_geometry){}

void Settings::CustomGeometry(QRect a_geometry){
    _screen=a_geometry;
}

void Settings::SetMainWindowParams(QRect a_geometry){
    _settings->setValue(c_mainWindowHeight,a_geometry.height());
    _settings->setValue(c_mainWindowWidth,a_geometry.width());
    _settings->setValue(c_mainWindowX,a_geometry.x());
    _settings->setValue(c_mainWindowY,a_geometry.y());
    _settings->setValue(c_mainWindowPercentX,a_geometry.x()/_screen.width());
    _settings->setValue(c_mainWindowPercentY,a_geometry.y()/_screen.height());
}
void Settings::SetMainWindowPos(QPoint a_pos){
    _settings->setValue(c_mainWindowX,a_pos.x());
    _settings->setValue(c_mainWindowY,a_pos.y());
    _settings->setValue(c_mainWindowPercentX,a_pos.x()/_screen.width());
    _settings->setValue(c_mainWindowPercentY,a_pos.y()/_screen.height());
}
void Settings::SetMainWindowGeometry(QSize a_size){
    _settings->setValue(c_mainWindowHeight,a_size.height());
    _settings->setValue(c_mainWindowWidth,a_size.width());
}

void Settings::SetAchievementContainerParams(QRect a_geometry){
    _settings->setValue(c_achievementContainerHeight,a_geometry.height());
    _settings->setValue(c_achievementContainerWidth,a_geometry.width());
    _settings->setValue(c_achievementContainerX,a_geometry.x());
    _settings->setValue(c_achievementContainerY,a_geometry.y());
    _settings->setValue(c_achievementContainerPercentX,a_geometry.x()/_screen.width());
    _settings->setValue(c_achievementContainerPercentY,a_geometry.y()/_screen.height());
}

void Settings::SyncronizeSettings(){
    _settings->sync();
}

bool Settings::CreateFile(QString a_paths){
    bool exist=true;
    QString pathNow="";
    while(a_paths.length()>0){
        if(a_paths.indexOf("/",0)>-1){
            QString dir=a_paths.mid(0,a_paths.indexOf("/",0));
            a_paths=a_paths.mid(a_paths.indexOf("/",0)+1, a_paths.length());
            if(!QDir(pathNow+dir).exists()){
                QDir().mkdir(pathNow+dir);
                exist=false;
            }
            pathNow+=dir+"/";
        } else {
            a_paths="";
        }
    }
    return exist;
}
