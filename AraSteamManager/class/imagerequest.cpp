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
            QString savenow=Save;
            QString path="";
            while(savenow.length()>0){
                if(savenow.indexOf("/",0)>-1){
                    QString dir=savenow.mid(0,savenow.indexOf("/",0));
                    savenow=savenow.mid(savenow.indexOf("/",0)+1, savenow.length());
                    qDebug()<<"Сохранить картинку в "<< dir<<savenow;
                    if(!QDir(path+dir).exists()){
                        QDir().mkdir(path+dir);
                    }
                    path+=dir+"/";
                } else {
                    savenow="";
                }
            }
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
