#include "requestimage.h"

RequestImage::RequestImage(QLabel *a_label, QString a_url, QString a_save, bool a_autosave, QObject *a_parent):QObject(a_parent),_label(a_label),_save(a_save),_autosave(a_autosave){
    RequestData *image = new RequestData(a_url,true,this);
    if(_label!=nullptr){
        _label->setMovie(new QMovie("://loading.gif"));
        _label->movie()->setScaledSize(_label->size());
        _label->movie()->start();
        connect(image,SIGNAL(s_finished(RequestData*)),this,SLOT(OnLoadToLabel(RequestData*)));
    } else {
        connect(image,SIGNAL(s_finished(RequestData*)),this,SLOT(OnLoadPixmap(RequestData*)));
    }
}
RequestImage::RequestImage(QLabel *a_label, QString a_url, QObject *a_parent):RequestImage(a_label,a_url,"",false,a_parent){}
RequestImage::RequestImage(QString a_url, QString a_save, bool a_autosave, QObject *a_parent):RequestImage(nullptr,a_url,a_save,a_autosave,a_parent){}

QPixmap RequestImage::GetPixmap(){
    return _pixmap;
}

void RequestImage::OnLoadToLabel(RequestData *a_image){
    QPixmap pix;
    pix.loadFromData(a_image->GetAnswer());
    if(_setting.GetSaveImages()==1&&_autosave){
        _setting.CreateFile(_save);
        pix.save(_save);
    }
    _label->movie()->stop();
    _label->setPixmap(pix);
    //emit s_loadComplete();
    this->deleteLater();
}

void RequestImage::OnLoadPixmap(RequestData *a_image){
    QPixmap pix;
    pix.loadFromData(a_image->GetAnswer());
    if(_setting.GetSaveImages()==1&&_autosave){
        _setting.CreateFile(_save);
        pix.save(_save);
    }
    _pixmap=pix;
    emit s_loadComplete(this);
}
