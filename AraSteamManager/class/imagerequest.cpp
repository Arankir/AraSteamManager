#include "imagerequest.h"

ImageRequest::ImageRequest(QString AUrl, int ARow, QString ASave, bool AAutoSave, QObject *parent) : QObject(parent){
    _manager = new QNetworkAccessManager();
    connect(_manager,&QNetworkAccessManager::finished,this,&ImageRequest::OnResultGet);
    _answer="";
    _url=AUrl;
    _row=ARow;
    _save=ASave;
    _autosave=AAutoSave;
    switch (_setting.GetSaveimages()) {
        case 0:{
            LoadImage(AUrl,ARow);
            break;
            }
        case 1:{
            LoadImage(AUrl,ARow,ASave,AAutoSave);
            break;
            }
        default:{
            LoadImage(AUrl,ARow);
            break;
            }
        }
}

ImageRequest::ImageRequest(){
    _manager = new QNetworkAccessManager();
    connect(_manager,&QNetworkAccessManager::finished,this,&ImageRequest::OnResultGet);
    _answer="";
}

void ImageRequest::Get(QString AUrl){
    QUrl url(AUrl);
    QNetworkRequest request;
    request.setUrl(url);
    _manager->get(request);
}

void ImageRequest::LoadImage(QString AUrl, int ARow, QString ASave, bool AAutoSave){
    _url=AUrl;
    _row=ARow;
    _save=ASave;
    _autosave=AAutoSave;
    _manager->get(QNetworkRequest(QUrl(AUrl)));
}

void ImageRequest::OnResultGet(QNetworkReply *AReply){
    if(!AReply->error()){
        _answer=AReply->readAll();
        if(_autosave){
            _setting.CreateFile(_save);
            QPixmap pixmap;
            pixmap.loadFromData(_answer);
            pixmap.save(_save);
        }
    }
    emit s_finished(this);
}

ImageRequest::~ImageRequest(){
    disconnect(_manager,&QNetworkAccessManager::finished,this,&ImageRequest::OnResultGet);
    delete _manager;
}
