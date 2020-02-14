#include "settings.h"

Settings::Settings(QObject *parent) : QObject(parent){
    CreateFile("Files/Settings.txt");
    if(QFile::exists("Files/Settings.txt")){
        QFile settings("Files/Settings.txt");
        if (settings.open(QIODevice::ReadOnly)){
            QStringList settingList;
            while(!settings.atEnd()){
                settingList << QString::fromLocal8Bit(settings.readLine()).remove("\r\n").remove("\n");
            }
            foreach (QString setting, settingList) {
                if(setting.indexOf("MyProfile=",0)!=-1){
                    _myProfile=setting.mid(setting.indexOf("MyProfile=",0)+10,setting.length());
                    }
                if(setting.indexOf("Theme=",0)!=-1){
                    _theme=setting.mid(setting.indexOf("Theme=",0)+6,setting.length()).toInt();
                    }
                if(setting.indexOf("Language=",0)!=-1){
                    _language=setting.mid(setting.indexOf("Language=",0)+9,setting.length()).toInt();
                    }
                if(setting.indexOf("SaveImages=",0)!=-1){
                    _saveImages=setting.mid(setting.indexOf("SaveImages=",0)+11,setting.length()).toInt();
                    }
                if(setting.indexOf("VisibleHiddenGames=",0)!=-1){
                    _visibleHiddenGames=setting.mid(setting.indexOf("VisibleHiddenGames=",0)+19,setting.length()).toInt();
                    }
                if(setting.indexOf("VisibleProfileInfo=",0)!=-1){
                    _visibleProfileInfo=setting.mid(setting.indexOf("VisibleProfileInfo=",0)+19,setting.length()).toInt()!=0;
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
    CreateFile("Files/Settings.txt");
    QFile file("Files/Settings.txt");
    if(!QFile::exists("Files/Settings.txt"))
        SetDefault();
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream writeStream(&file);
        writeStream << "Language="+QString::number(_language)<<"\n";
        writeStream << "Theme="+QString::number(_theme)<<"\n";
        writeStream << "SaveImages="+QString::number(_saveImages)<<"\n";
        writeStream << "MyProfile="+_myProfile<<"\n";
        writeStream << "VisibleHiddenGames="+QString::number(_visibleHiddenGames)<<"\n";
        writeStream << "VisibleProfileInfo="+QString::number(_visibleProfileInfo?1:0);
        file.close();
        return true;
    } else {
        _status=StatusValue::error;
        _error="file is already open";
        return false;
    }
}

void Settings::SetDefault(){
    CreateFile("Files/Settings.txt");
    QFile file("Files/Settings.txt");
    if(!QFile::exists("Files/Settings.txt")){
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
    CreateFile("Files/Settings.txt");
    if(QFile::exists("Files/Settings.txt")){
        QFile settings("Files/Settings.txt");
        if (settings.open(QIODevice::ReadOnly)){
            QStringList settingList;
            while(!settings.atEnd()){
                settingList << QString::fromLocal8Bit(settings.readLine()).remove("\r\n").remove("\n");
            }
            foreach (QString setting, settingList) {
                if(setting.indexOf("MyProfile=",0)!=-1){
                    _myProfile=setting.mid(setting.indexOf("MyProfile=",0)+10,setting.length());
                    }
                if(setting.indexOf("Theme=",0)!=-1){
                    _theme=setting.mid(setting.indexOf("Theme=",0)+6,setting.length()).toInt();
                    }
                if(setting.indexOf("Language=",0)!=-1){
                    _language=setting.mid(setting.indexOf("Language=",0)+9,setting.length()).toInt();
                    }
                if(setting.indexOf("SaveImages=",0)!=-1){
                    _saveImages=setting.mid(setting.indexOf("SaveImages=",0)+11,setting.length()).toInt();
                    }
                if(setting.indexOf("VisibleHiddenGames=",0)!=-1){
                    _visibleHiddenGames=setting.mid(setting.indexOf("VisibleHiddenGames=",0)+19,setting.length()).toInt();
                    }
                if(setting.indexOf("VisibleProfileInfo=",0)!=-1){
                    _visibleProfileInfo=setting.mid(setting.indexOf("VisibleProfileInfo=",0)+19,setting.length()).toInt()!=0;
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

