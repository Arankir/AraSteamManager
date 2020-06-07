#include "requestimage.h"

RequestImage::RequestImage(QLabel *aLabel, QString aUrl, QString aSave, bool aAutoSave, QObject *aParent): QObject(aParent),
_label(aLabel), _save(aSave), _autosave(aAutoSave) {
    RequestData *image = new RequestData(aUrl, true, this);
    if (_label != nullptr) {
        _label->setMovie(new QMovie("://loading.gif"));
        _label->movie()->setScaledSize(_label->size());
        _label->movie()->start();
    }
    connect(image, SIGNAL(s_finished(RequestData*)), this, SLOT(onLoad(RequestData*)));
}

RequestImage::RequestImage(QLabel *aLabel, QString aUrl, QObject *aParent): RequestImage(aLabel, aUrl, "", false, aParent) {

}

RequestImage::RequestImage(QString aUrl, QString aSave, bool aAutoSave, QObject *aParent): RequestImage(nullptr, aUrl, aSave, aAutoSave, aParent) {

}

QPixmap RequestImage::getPixmap() {
    return _pixmap;
}

void RequestImage::setIndex(int aIndex) {
    _index = aIndex;
}

int RequestImage::getIndex() {
    return _index;
}

void RequestImage::onLoad(RequestData *aImage) {
    QPixmap loadedImage;
    loadedImage.loadFromData(aImage->getAnswer());
    if (_setting.getSaveImages() == 1 && _autosave) {
        Settings::createDir(_save);
        loadedImage.save(_save);
    }
    if (_label != nullptr) {
        if (_label->movie()->state() == QMovie::MovieState::Running) {
            _label->movie()->stop();
        }
        _label->setPixmap(loadedImage);
        //emit s_loadComplete();
        this->deleteLater();
    } else {
        _pixmap = loadedImage;
        emit s_loadComplete(this);
    }
}

