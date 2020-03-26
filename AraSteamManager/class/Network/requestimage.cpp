#include "requestimage.h"

RequestImage::RequestImage(QLabel *a_label, QString a_url, QString a_save, bool a_autosave, QObject *a_parent){
    _label=a_label;
    _save=a_save;
    _autosave=a_autosave;
    _label->setMovie(new QMovie("://loading.gif"));
    _label->movie()->setScaledSize(_label->size());
    _label->movie()->start();
    RequestData *image = new RequestData(a_url,-1,a_save,a_autosave,this);
    connect(image,SIGNAL(s_finished(RequestData*)),this,SLOT(OnLoad(RequestData*)));
}

void RequestImage::OnLoad(RequestData *a_image){
    QPixmap pix;
    pix.loadFromData(a_image->GetAnswer());
    _label->movie()->stop();
    _label->setPixmap(pix);
    emit s_loadComplete();
    this->deleteLater();
}
