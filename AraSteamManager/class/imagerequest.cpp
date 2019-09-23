#include "imagerequest.h"

ImageRequest::ImageRequest(int is , QString Saves, QObject *parent) : QObject(parent){
    manager = new QNetworkAccessManager();
    QByteArray answer="";
    i=is;
    Save=Saves;
}

ImageRequest::ImageRequest(){
    manager = new QNetworkAccessManager();
    QByteArray answer="";
}

void ImageRequest::Get(QString str){
    QUrl url(str);
    connect(manager,&QNetworkAccessManager::finished,this,&ImageRequest::OnResultGet);
    QNetworkRequest request;
    request.setUrl(url);
    manager->get(request);
}

void ImageRequest::LoadImage(QString url, int column, QString save, bool autosave){
    i=column;
    Save=save;
    Autosave=autosave;
    connect(manager,&QNetworkAccessManager::finished,this,&ImageRequest::OnResultGet);
    manager->get(QNetworkRequest(QUrl(url)));
}

void ImageRequest::OnResultGet(QNetworkReply *reply){
    disconnect(manager,&QNetworkAccessManager::finished,this,&ImageRequest::OnResultGet);
    if(!reply->error()){
        answer=reply->readAll();
        if(Autosave){
            QString savenow=Save;
            QString path="images/";
            while(savenow.length()>0){
                if(savenow.indexOf("/",0)>-1){
                    QString dir=savenow.mid(0,savenow.indexOf("/",0));
                    savenow=savenow.mid(savenow.indexOf("/",0)+1, savenow.length());
                    if(!QDir(path+dir).exists()){
                        QDir().mkdir(path+dir);
                    }
                    path+=dir;
                } else {
                    savenow="";
                }
            }
            QPixmap pixmap;
            pixmap.loadFromData(answer);
            pixmap.save(Save+".png", "PNG");
        }
    }
    emit onReady(this);
}

ImageRequest::~ImageRequest(){
    delete manager;
}
