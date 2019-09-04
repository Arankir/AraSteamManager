#include "settings.h"

Settings::Settings(QObject *parent) : QObject(parent)
{
    if(QFile::exists("Files/Settings.txt")){
        QFile settings("Files/Settings.txt");
        if (settings.open(QIODevice::ReadOnly)){
            QStringList setting;
            while(!settings.atEnd()){
                setting << QString::fromLocal8Bit(settings.readLine()).remove("\r\n").remove("\n");
            }
            while (!setting.isEmpty()) {
                QString sett=setting.takeAt(0);
                if(sett.indexOf("MyProfile=",0)!=-1){
                    MyProfile=sett.mid(sett.indexOf("MyProfile=",0)+10,sett.length());
                    }
                if(sett.indexOf("Theme=",0)!=-1){
                    theme=sett.mid(sett.indexOf("Theme=",0)+6,sett.length()).toInt();
                    }
                if(sett.indexOf("Language=",0)!=-1){
                    language=sett.mid(sett.indexOf("Language=",0)+9,sett.length()).toInt();
                    }
                if(sett.indexOf("SaveImages=",0)!=-1){
                    SaveImages=sett.mid(sett.indexOf("SaveImages=",0)+11,sett.length()).toInt();
                    }
                }
            status="success";
            settings.close();
        } else
            status="error: file is already open";
    } else
        status="error: file not found";
}

QString Settings::GetMyProfile(){
    return MyProfile;
}

int Settings::GetLanguage(){
    return language;
}

int Settings::GetTheme(){
    return theme;
}

int Settings::GetSaveimages(){
    return SaveImages;
}

QString Settings::GetStatus(){
    return status;
}

bool Settings::SetMyProfile(QString MyProfiles){
    QFile file("Files/Settings.txt");
    if(!QFile::exists("Files/Settings.txt"))
    {
    SetDefault();
    }
    if (!file.open(QIODevice::ReadOnly))
    {
        status="error: file is already open";
        return false;
    } else {
        MyProfile=MyProfiles;
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream writeStream(&file);
        writeStream << "Language="+QString::number(language)<<'\r'<<'\n';
        writeStream << "Theme="+QString::number(theme)<<'\r'<<'\n';
        writeStream << "SaveImages="+QString::number(SaveImages)<<'\r'<<'\n';
        writeStream << "Language="+MyProfile<<'\r'<<'\n';
        file.close();
        return true;
    }
}

bool Settings::SetLanguage(int Language){
    QFile file("Files/Settings.txt");
    if(!QFile::exists("Files/Settings.txt"))
    {
    SetDefault();
    }
    if (!file.open(QIODevice::ReadOnly))
    {
        status="error: file is already open";
        return false;
    } else {
        language=Language;
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream writeStream(&file);
        writeStream << "Language="+QString::number(language)<<'\r'<<'\n';
        writeStream << "Theme="+QString::number(theme)<<'\r'<<'\n';
        writeStream << "SaveImages="+QString::number(SaveImages)<<'\r'<<'\n';
        writeStream << "Language="+MyProfile<<'\r'<<'\n';
        file.close();
        return true;
    }
}

bool Settings::SetTheme(int Theme){
    QFile file("Files/Settings.txt");
    if(!QFile::exists("Files/Settings.txt"))
    {
    SetDefault();
    }
    if (!file.open(QIODevice::ReadOnly))
    {
        status="error: file is already open";
        return false;
    } else {
        theme=Theme;
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream writeStream(&file);
        writeStream << "Language="+QString::number(language)<<'\r'<<'\n';
        writeStream << "Theme="+QString::number(theme)<<'\r'<<'\n';
        writeStream << "SaveImages="+QString::number(SaveImages)<<'\r'<<'\n';
        writeStream << "Language="+MyProfile<<'\r'<<'\n';
        file.close();
        return true;
    }
}

bool Settings::SetSaveimage(int SaveImage){
    QFile file("Files/Settings.txt");
    if(!QFile::exists("Files/Settings.txt"))
    {
    SetDefault();
    }
    if (!file.open(QIODevice::ReadOnly))
    {
        status="error: file is already open";
        return false;
    } else {
        SaveImages=SaveImage;
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream writeStream(&file);
        writeStream << "Language="+QString::number(language)<<'\r'<<'\n';
        writeStream << "Theme="+QString::number(theme)<<'\r'<<'\n';
        writeStream << "SaveImages="+QString::number(SaveImages)<<'\r'<<'\n';
        writeStream << "Language="+MyProfile<<'\r'<<'\n';
        file.close();
        return true;
    }
}

void Settings::SetDefault(){
    QFile file("Files/Settings.txt");
    if(!QFile::exists("Files/Settings.txt"))
    {
    file.open(QIODevice::WriteOnly);
            //дефолтные данные
    file.close();
    }
}
