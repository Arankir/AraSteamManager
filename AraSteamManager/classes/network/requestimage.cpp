#include "requestimage.h"

RequestImage::RequestImage(QLabel *aLabel, const QString &aUrl, const QString &aSave, bool aAutoSave, QObject *aParent): QObject(aParent),
_label(aLabel), _save(aSave), _autosave(aAutoSave) {
    RequestData *image = new RequestData(aUrl, true, this);
    connect(image, SIGNAL(s_finished(RequestData*)), this, SLOT(onLoad(RequestData*)));
    if (_label != nullptr) {
        _label->setMovie(new QMovie("://loading.gif"));
        _label->movie()->setScaledSize(_label->size());
        _label->movie()->start();
    }
}

void RequestImage::onLoad(RequestData *aImage) {
    _pixmap.loadFromData(aImage->getReply());
    if (Settings::getSaveImages() == 1 && _autosave) {
        createDir(_save);
        _pixmap.save(_save);
    }
    if (_label != nullptr) {
        if (_label->movie()) {
            if (_label->movie()->state() == QMovie::MovieState::Running) {
                _label->movie()->stop();
            }
        }
        _label->setPixmap(_pixmap);
        //emit s_loadComplete();
        this->deleteLater();
    } else {
        emit s_loadComplete(this);
    }
}

