#include "imagerequest.h"

ImageRequest::ImageRequest(QString Aurl, int Arow, QString Asave, bool AautoSave, QObject *parent) : QObject(parent){
    _manager = new QNetworkAccessManager();
    connect(_manager,&QNetworkAccessManager::finished,this,&ImageRequest::OnResultGet);
    _answer="";
    _url=Aurl;
    _row=Arow;
    _save=Asave;
    _autosave=AautoSave;
    switch (_setting.GetSaveimages()) {
        case 0:{
            LoadImage(Aurl,Arow);
            break;
            }
        case 1:{
            LoadImage(Aurl,Arow,Asave,AautoSave);
            break;
            }
        default:{
            LoadImage(Aurl,Arow);
            break;
            }
        }
}

ImageRequest::ImageRequest(){
    _manager = new QNetworkAccessManager();
    connect(_manager,&QNetworkAccessManager::finished,this,&ImageRequest::OnResultGet);
    _answer="";
}

void ImageRequest::Get(QString Aurl){
    QUrl url(Aurl);
    QNetworkRequest request;
    request.setUrl(url);
    _manager->get(request);
}

void ImageRequest::LoadImage(QString Aurl, int Arow, QString Asave, bool AautoSave){
    _url=Aurl;
    _row=Arow;
    _save=Asave;
    _autosave=AautoSave;
    _manager->get(QNetworkRequest(QUrl(Aurl)));
}

void ImageRequest::OnResultGet(QNetworkReply *Areply){
    if(!Areply->error()){
        _answer=Areply->readAll();
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
