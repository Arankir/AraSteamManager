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
    CreateFile("Files/Settings.txt");
    QFile file("Files/Settings.txt");
    if(!QFile::exists("Files/Settings.txt"))
    {
    SetDefault();
    }
    if (!file.open(QIODevice::ReadOnly))
    {
        _status=StatusValue::error;
        _error="file is already open";
        return false;
    } else {
        file.close();
        _myProfile=a_myProfiles;
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream writeStream(&file);
        writeStream << "Language="+QString::number(_language)<<"\n";
        writeStream << "Theme="+QString::number(_theme)<<"\n";
        writeStream << "SaveImages="+QString::number(_saveImages)<<"\n";
        writeStream << "MyProfile="+_myProfile<<"\n";
        writeStream << "VisibleHiddenGames="+QString::number(_visibleHiddenGames);
        file.close();
        return true;
    }
}
bool Settings::SetLanguage(int a_language){
    CreateFile("Files/Settings.txt");
    QFile file("Files/Settings.txt");
    if(!QFile::exists("Files/Settings.txt"))
    {
    SetDefault();
    }
    if (!file.open(QIODevice::ReadOnly))
    {
        _status=StatusValue::error;
        _error="file is already open";
        return false;
    } else {
        file.close();
        _language=a_language;
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream writeStream(&file);
        writeStream << "Language="+QString::number(_language)<<"\n";
        writeStream << "Theme="+QString::number(_theme)<<"\n";
        writeStream << "SaveImages="+QString::number(_saveImages)<<"\n";
        writeStream << "MyProfile="+_myProfile<<"\n";
        writeStream << "VisibleHiddenGames="+QString::number(_visibleHiddenGames);
        file.close();
        return true;
    }
}
bool Settings::SetTheme(int a_theme){
    CreateFile("Files/Settings.txt");
    QFile file("Files/Settings.txt");
    if(!QFile::exists("Files/Settings.txt"))
    {
    SetDefault();
    }
    if (!file.open(QIODevice::ReadOnly))
    {
        _status=StatusValue::error;
        _error="file is already open";
        return false;
    } else {
        file.close();
        _theme=a_theme;
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream writeStream(&file);
        writeStream << "Language="+QString::number(_language)<<"\n";
        writeStream << "Theme="+QString::number(_theme)<<"\n";
        writeStream << "SaveImages="+QString::number(_saveImages)<<"\n";
        writeStream << "MyProfile="+_myProfile<<"\n";
        writeStream << "VisibleHiddenGames="+QString::number(_visibleHiddenGames);
        file.close();
        return true;
    }
}
bool Settings::SetSaveimage(int a_saveImage){
    CreateFile("Files/Settings.txt");
    QFile file("Files/Settings.txt");
    if(!QFile::exists("Files/Settings.txt"))
    {
    SetDefault();
    }
    if (!file.open(QIODevice::ReadOnly))
    {
        _status=StatusValue::error;
        _error="file is already open";
        return false;
    } else {
        file.close();
        _saveImages=a_saveImage;
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream writeStream(&file);
        writeStream << "Language="+QString::number(_language)<<"\n";
        writeStream << "Theme="+QString::number(_theme)<<"\n";
        writeStream << "SaveImages="+QString::number(_saveImages)<<"\n";
        writeStream << "MyProfile="+_myProfile<<"\n";
        writeStream << "VisibleHiddenGames="+QString::number(_visibleHiddenGames);
        file.close();
        return true;
    }
}
bool Settings::SetVisibleHiddenGames(int a_visibleHiddenGames){
    CreateFile("Files/Settings.txt");
    QFile file("Files/Settings.txt");
    if(!QFile::exists("Files/Settings.txt"))
    {
    SetDefault();
    }
    if (!file.open(QIODevice::ReadOnly))
    {
        _status=StatusValue::error;
        _error="file is already open";
        return false;
    } else {
        file.close();
        _visibleHiddenGames=a_visibleHiddenGames;
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream writeStream(&file);
        writeStream << "Language="+QString::number(_language)<<"\n";
        writeStream << "Theme="+QString::number(_theme)<<"\n";
        writeStream << "SaveImages="+QString::number(_saveImages)<<"\n";
        writeStream << "MyProfile="+_myProfile<<"\n";
        writeStream << "VisibleHiddenGames="+QString::number(_visibleHiddenGames);
        file.close();
        return true;
    }
}
void Settings::SetDefault(){
    CreateFile("Files/Settings.txt");
    QFile file("Files/Settings.txt");
    if(!QFile::exists("Files/Settings.txt"))
    {
    file.open(QIODevice::WriteOnly);
            //дефолтные данные
    file.close();
    }
}

bool Settings::CreateFile(QString a_paths){
    bool exist=true;
    QString savenow=a_paths;
    QString path="";
    while(savenow.length()>0){
        if(savenow.indexOf("/",0)>-1){
            QString dir=savenow.mid(0,savenow.indexOf("/",0));
            savenow=savenow.mid(savenow.indexOf("/",0)+1, savenow.length());
            if(!QDir(path+dir).exists()){
                QDir().mkdir(path+dir);
                exist=false;
            }
            path+=dir+"/";
        } else {
            savenow="";
        }
    }
    return exist;
}
