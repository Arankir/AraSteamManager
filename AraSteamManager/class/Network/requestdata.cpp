#include "requestdata.h"

RequestData::RequestData(QString a_url, bool a_parallel, QObject *a_parent): QObject(a_parent), _answer(""),_url(a_url){
    _manager = new QNetworkAccessManager();
    connect(_manager,&QNetworkAccessManager::finished,this,&RequestData::OnResultGet);
    if(!a_url.isEmpty())
        Get(a_url,a_parallel);
}
RequestData::RequestData(QObject *a_parent):RequestData("",true,a_parent){}

void RequestData::Get(QString a_url, bool a_parallel){
    _manager->get(QNetworkRequest(QUrl(a_url)));
    if(!a_parallel){
        QEventLoop loop;
        connect(_manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
        loop.exec();
        disconnect(_manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    }
}

void RequestData::OnResultGet(QNetworkReply *a_reply){
    if(!a_reply->error()){
        _answer=a_reply->readAll();
    }
    emit s_finished(this);
}

RequestData::~RequestData(){
    disconnect(_manager,&QNetworkAccessManager::finished,this,&RequestData::OnResultGet);
    delete _manager;
}
