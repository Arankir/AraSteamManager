#include "imagerequest.h"

ImageRequest::ImageRequest(QString url, int row, QString save, bool autosave, QObject *parent) : QObject(parent){
    manager = new QNetworkAccessManager();
    connect(manager,&QNetworkAccessManager::finished,this,&ImageRequest::OnResultGet);
    answer="";
    Url=url;
    i=row;
    Save=save;
    Autosave=autosave;
    switch (Setting.GetSaveimages()) {
        case 0:{
            LoadImage(url,row);
            break;
            }
        case 1:{
            LoadImage(url,row,save,autosave);
            break;
            }
        default:{
            LoadImage(url,row);
            break;
            }
        }
}

ImageRequest::ImageRequest(){
    manager = new QNetworkAccessManager();
    connect(manager,&QNetworkAccessManager::finished,this,&ImageRequest::OnResultGet);
    answer="";
}

void ImageRequest::Get(QString str){
    QUrl url(str);
    QNetworkRequest request;
    request.setUrl(url);
    manager->get(request);
}

void ImageRequest::LoadImage(QString url, int column, QString save, bool autosave){
    Url=url;
    i=column;
    Save=save;
    Autosave=autosave;
    manager->get(QNetworkRequest(QUrl(url)));
}

void ImageRequest::OnResultGet(QNetworkReply *reply){
    if(!reply->error()){
        answer=reply->readAll();
        if(Autosave){
            Setting.CreateFile(Save);
            QPixmap pixmap;
            pixmap.loadFromData(answer);
            pixmap.save(Save);
        }
    }
    emit onReady(this);
}

ImageRequest::~ImageRequest(){
    disconnect(manager,&QNetworkAccessManager::finished,this,&ImageRequest::OnResultGet);
    delete manager;
}
