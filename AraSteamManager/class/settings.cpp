#include "settings.h"

const QString c_language="Language=";
const QString c_theme="Theme=";
const QString c_saveImages="SaveImages=";
const QString c_myProfile="MyProfile=";
const QString c_visibleHiddenGames="VisibleHiddenGames=";
const QString c_visibleProfileInfo="VisibleProfileInfo=";

Settings::Settings(QObject *parent) : QObject(parent){
    CreateFile(_pathSettings);
    if(QFile::exists(_pathSettings)){
        QFile settings(_pathSettings);
        if (settings.open(QIODevice::ReadOnly)){
            QStringList settingList;
            while(!settings.atEnd()){
                settingList << QString::fromLocal8Bit(settings.readLine()).remove("\r\n").remove("\n");
            }
            foreach (QString setting, settingList) {
                if(setting.indexOf(c_myProfile,0)!=-1){
                    _myProfile=setting.mid(setting.indexOf(c_myProfile,0)+c_myProfile.length(),setting.length());
                    }
                if(setting.indexOf(c_theme,0)!=-1){
                    _theme=setting.mid(setting.indexOf(c_theme,0)+c_theme.length(),setting.length()).toInt();
                    }
                if(setting.indexOf(c_language,0)!=-1){
                    _language=setting.mid(setting.indexOf(c_language,0)+c_language.length(),setting.length()).toInt();
                    }
                if(setting.indexOf(c_saveImages,0)!=-1){
                    _saveImages=setting.mid(setting.indexOf(c_saveImages,0)+c_saveImages.length(),setting.length()).toInt();
                    }
                if(setting.indexOf(c_visibleHiddenGames,0)!=-1){
                    _visibleHiddenGames=setting.mid(setting.indexOf(c_visibleHiddenGames,0)+c_visibleHiddenGames.length(),setting.length()).toInt();
                    }
                if(setting.indexOf(c_visibleProfileInfo,0)!=-1){
                    _visibleProfileInfo=setting.mid(setting.indexOf(c_visibleProfileInfo,0)+c_visibleProfileInfo.length(),setting.length()).toInt()!=0;
                    }
            }
            _status=StatusValue::success;
            settings.close();
        } else {
            _status=StatusValue::error;
            _error="file is already open";
        }
    } else {
        _status=StatusValue::error;
        _error="file not found";
    }
}

bool Settings::SetMyProfile(QString a_myProfiles){
    _myProfile=a_myProfiles;
    return SaveSettings();
}
bool Settings::SetLanguage(int a_language){
    _language=a_language;
    return SaveSettings();
}
bool Settings::SetTheme(int a_theme){
    _theme=a_theme;
    return SaveSettings();
}
bool Settings::SetSaveimage(int a_saveImage){
    _saveImages=a_saveImage;
    return SaveSettings();
}
bool Settings::SetVisibleHiddenGames(int a_visibleHiddenGames){
    _visibleHiddenGames=a_visibleHiddenGames;
    return SaveSettings();
}
bool Settings::SetVisibleProfileInfo(bool a_visibleProfileInfo){
    _visibleProfileInfo=a_visibleProfileInfo;
    return SaveSettings();
}

bool Settings::SaveSettings(){
    CreateFile(_pathSettings);
    QFile file(_pathSettings);
    if(!QFile::exists(_pathSettings))
        SetDefault();
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream writeStream(&file);
        writeStream << c_language+QString::number(_language)<<"\n";
        writeStream << c_theme+QString::number(_theme)<<"\n";
        writeStream << c_saveImages+QString::number(_saveImages)<<"\n";
        writeStream << c_myProfile+_myProfile<<"\n";
        writeStream << c_visibleHiddenGames+QString::number(_visibleHiddenGames)<<"\n";
        writeStream << c_visibleProfileInfo+QString::number(_visibleProfileInfo?1:0);
        file.close();
        return true;
    } else {
        _status=StatusValue::error;
        _error="file is already open";
        return false;
    }
}

void Settings::SetDefault(){
    CreateFile(_pathSettings);
    QFile file(_pathSettings);
    if(!QFile::exists(_pathSettings)){
        file.open(QIODevice::WriteOnly);
                //дефолтные данные
        file.close();
    }
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
bool Settings::LoadSettings(){
    CreateFile(_pathSettings);
    if(QFile::exists(_pathSettings)){
        QFile settings(_pathSettings);
        if (settings.open(QIODevice::ReadOnly)){
            QStringList settingList;
            while(!settings.atEnd()){
                settingList << QString::fromLocal8Bit(settings.readLine()).remove("\r\n").remove("\n");
            }
            foreach (QString setting, settingList) {
                if(setting.indexOf(c_myProfile,0)!=-1){
                    _myProfile=setting.mid(setting.indexOf(c_myProfile,0)+c_myProfile.length(),setting.length());
                    }
                if(setting.indexOf(c_theme,0)!=-1){
                    _theme=setting.mid(setting.indexOf(c_theme,0)+c_theme.length(),setting.length()).toInt();
                    }
                if(setting.indexOf(c_language,0)!=-1){
                    _language=setting.mid(setting.indexOf(c_language,0)+c_language.length(),setting.length()).toInt();
                    }
                if(setting.indexOf(c_saveImages,0)!=-1){
                    _saveImages=setting.mid(setting.indexOf(c_saveImages,0)+c_saveImages.length(),setting.length()).toInt();
                    }
                if(setting.indexOf(c_visibleHiddenGames,0)!=-1){
                    _visibleHiddenGames=setting.mid(setting.indexOf(c_visibleHiddenGames,0)+c_visibleHiddenGames.length(),setting.length()).toInt();
                    }
                if(setting.indexOf(c_visibleProfileInfo,0)!=-1){
                    _visibleProfileInfo=setting.mid(setting.indexOf(c_visibleProfileInfo,0)+c_visibleProfileInfo.length(),setting.length()).toInt()!=0;
                    }
            }
            _status=StatusValue::success;
            settings.close();
            return true;
        } else {
            _status=StatusValue::error;
            _error="file is already open";
            return false;
        }
    } else {
        _status=StatusValue::error;
        _error="file not found";
        return false;
    }
}

