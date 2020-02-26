#include "settings.h"


Settings::Settings(QObject *parent) : QObject(parent){
    _settings = new QSettings(QDir::currentPath()+"/settings.ini",QSettings::IniFormat);
    _settings->setValue(c_language,_settings->value(c_language,1));
    _settings->setValue(c_theme,_settings->value(c_theme,1));
    _settings->setValue(c_saveImage,_settings->value(c_saveImage,0));
    _settings->setValue(c_myProfile,_settings->value(c_myProfile,"none"));
    _settings->setValue(c_visibleHiddenGames,_settings->value(c_visibleHiddenGames,0));
    _settings->setValue(c_visibleProfileInfo,_settings->value(c_visibleProfileInfo,true));
}

void Settings::SetMyProfile(QString a_myProfiles){
    _settings->setValue(c_myProfile,a_myProfiles);
    _settings->sync();
}
void Settings::SetLanguage(int a_language){
    _settings->setValue(c_language,a_language);
    _settings->sync();
}
void Settings::SetTheme(int a_theme){
    _settings->setValue(c_theme,a_theme);
    _settings->sync();
}
void Settings::SetSaveimage(int a_saveImage){
    _settings->setValue(c_saveImage,a_saveImage);
    _settings->sync();
}
void Settings::SetVisibleHiddenGames(int a_visibleHiddenGames){
    _settings->setValue(c_visibleHiddenGames,a_visibleHiddenGames);
    _settings->sync();
}
void Settings::SetVisibleProfileInfo(bool a_visibleProfileInfo){
    _settings->setValue(c_visibleProfileInfo,a_visibleProfileInfo);
    _settings->sync();
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
