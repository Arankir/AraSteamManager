#include "settings.h"

Settings::Settings(QObject *parent) : QObject(parent){
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
                    myProfile=sett.mid(sett.indexOf("MyProfile=",0)+10,sett.length());
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
                if(sett.indexOf("VisibleHiddenGames=",0)!=-1){
                    visibleHiddenGames=sett.mid(sett.indexOf("VisibleHiddenGames=",0)+19,sett.length()).toInt();
                    }
                }
            status="success";
            settings.close();
        } else
            status="error: file is already open";
    } else
        status="error: file not found";
}

QStringList Settings::GetWords(QString form){
    QString lan;
    switch (language) {
    case 1:{
        lan="ENG";
        break;
        }
    case 5:{
        lan="RU";
        break;
        }
    default:{
        lan="ENG";
    }
    }
    QStringList Language;
    QFile FileLanguage;
    FileLanguage.setFileName(":/"+lan+"/"+lan+"/"+form+".txt");
    if(FileLanguage.open(QIODevice::ReadOnly)){
        while(!FileLanguage.atEnd()){
            Language << QString::fromLocal8Bit(FileLanguage.readLine()).remove("\r\n").remove("\n");
        }
        FileLanguage.close();
    } else
        for(int i=0;i<200;i++){
            Language << "";
        }
    return Language;
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
        file.close();
        myProfile=MyProfiles;
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream writeStream(&file);
        writeStream << "Language="+QString::number(language)<<"\n";
        writeStream << "Theme="+QString::number(theme)<<"\n";
        writeStream << "SaveImages="+QString::number(SaveImages)<<"\n";
        writeStream << "MyProfile="+myProfile<<"\n";
        writeStream << "VisibleHiddenGames="+QString::number(visibleHiddenGames);
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
        file.close();
        language=Language;
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream writeStream(&file);
        writeStream << "Language="+QString::number(language)<<'\n';
        writeStream << "Theme="+QString::number(theme)<<'\n';
        writeStream << "SaveImages="+QString::number(SaveImages)<<'\n';
        writeStream << "MyProfile="+myProfile<<"\n";
        writeStream << "VisibleHiddenGames="+QString::number(visibleHiddenGames);
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
        file.close();
        theme=Theme;
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream writeStream(&file);
        writeStream << "Language="+QString::number(language)<<'\n';
        writeStream << "Theme="+QString::number(theme)<<'\n';
        writeStream << "SaveImages="+QString::number(SaveImages)<<'\n';
        writeStream << "MyProfile="+myProfile<<"\n";
        writeStream << "VisibleHiddenGames="+QString::number(visibleHiddenGames);
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
        file.close();
        SaveImages=SaveImage;
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream writeStream(&file);
        writeStream << "Language="+QString::number(language)<<'\n';
        writeStream << "Theme="+QString::number(theme)<<'\n';
        writeStream << "SaveImages="+QString::number(SaveImages)<<'\n';
        writeStream << "MyProfile="+myProfile<<"\n";
        writeStream << "VisibleHiddenGames="+QString::number(visibleHiddenGames);
        file.close();
        return true;
    }
}
bool Settings::SetVisibleHiddenGames(int VisibleHiddenGames){
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
        file.close();
        visibleHiddenGames=VisibleHiddenGames;
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream writeStream(&file);
        writeStream << "Language="+QString::number(language)<<'\n';
        writeStream << "Theme="+QString::number(theme)<<'\n';
        writeStream << "SaveImages="+QString::number(SaveImages)<<'\n';
        writeStream << "MyProfile="+myProfile<<"\n";
        writeStream << "VisibleHiddenGames="+QString::number(visibleHiddenGames);
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
