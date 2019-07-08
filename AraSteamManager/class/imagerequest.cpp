#include "imagerequest.h"

ImageRequest::ImageRequest(int is , QString Saves, QObject *parent) : QObject(parent){
    manager = new QNetworkAccessManager();
    QByteArray answer="";
    i=is;
    Save=Saves;
}

void ImageRequest::Get(QString str){
    QUrl url(str);
    connect(manager,&QNetworkAccessManager::finished,this,&ImageRequest::OnResultGet);
    QNetworkRequest request;
    request.setUrl(url);
    manager->get(request);
}

void ImageRequest::OnResultGet(QNetworkReply *reply){
    if(!reply->error()){
        answer=reply->readAll();
        }
    emit onReady(i,Save,this);
}

ImageRequest::~ImageRequest(){
    delete manager;
}

QByteArray ImageRequest::GetAnswer(){
    return answer;
}
