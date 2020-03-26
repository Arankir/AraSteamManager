#include "requestdata.h"

RequestData::RequestData(QString a_url, int a_row, QString a_save, bool a_autoSave, QObject *parent) : QObject(parent){
    _manager = new QNetworkAccessManager();
    connect(_manager,&QNetworkAccessManager::finished,this,&RequestData::OnResultGet);
    _answer="";
    _url=a_url;
    _row=a_row;
    _save=a_save;
    _autosave=a_autoSave;
    switch (_setting.GetSaveImages()) {
        case 0:{
            LoadImage(a_url,a_row);
            break;
            }
        case 1:{
            LoadImage(a_url,a_row,a_save,a_autoSave);
            break;
            }
        default:{
            LoadImage(a_url,a_row);
            break;
            }
    }
}

RequestData::RequestData(QString a_url, bool a_parallel){
    _manager = new QNetworkAccessManager();
    connect(_manager,&QNetworkAccessManager::finished,this,&RequestData::OnResultGet);
    _answer="";
    _url=a_url;
    _autosave=false;
    _save=false;
    _row=-1;
    Get(a_url,a_parallel);
}

RequestData::RequestData(){
    _manager = new QNetworkAccessManager();
    connect(_manager,&QNetworkAccessManager::finished,this,&RequestData::OnResultGet);
    _answer="";
}

void RequestData::Get(QString a_url, bool a_parallel){
    _manager->get(QNetworkRequest(QUrl(a_url)));
    if(!a_parallel){
        QEventLoop loop;
        connect(_manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
        loop.exec();
        disconnect(_manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    }
}

void RequestData::LoadImage(QString a_url, int a_row, QString a_save, bool a_autoSave){
    _url=a_url;
    _row=a_row;
    _save=a_save;
    _autosave=a_autoSave;
    _manager->get(QNetworkRequest(QUrl(a_url)));
}

void RequestData::OnResultGet(QNetworkReply *a_reply){
    if(!a_reply->error()){
        _answer=a_reply->readAll();
        if(_autosave){
            _setting.CreateFile(_save);
            QPixmap pixmap;
            pixmap.loadFromData(_answer);
            pixmap.save(_save);
        }
    }
    emit s_finished(this);
}

RequestData::~RequestData(){
    disconnect(_manager,&QNetworkAccessManager::finished,this,&RequestData::OnResultGet);
    delete _manager;
}
