#include "language.h"

Language::Language(QObject *parent) : QObject(parent)
{

}

QStringList Language::GetLanguage(QString form, int language){
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
    FileLanguage.setFileName("Files/Languages/"+lan+"/"+form+".txt");
    if(FileLanguage.open(QIODevice::ReadOnly)){
        while(!FileLanguage.atEnd()){
            Language << QString::fromLocal8Bit(FileLanguage.readLine()).remove("\r\n").remove("\n");
        }
    } else
        for(int i=0;i<200;i++){
            Language << "";
        }
    return Language;
}
