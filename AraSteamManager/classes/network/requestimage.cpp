#include "requestimage.h"
#include "classes/common/settings.h"
#include "classes/common/generalfunctions.h"

#include <QDir>

RequestImage::RequestImage(const QString &aUrl, const QString &aSave, const bool &aAutoSave, const bool &aParallel, QObject *aParent): QObject(aParent),
savePath_(aSave), isAutoSave_(aAutoSave) {
    RequestData *image = new RequestData(aUrl, aParallel, this);
    if (aParallel) {
        connect(image, SIGNAL(s_finished(RequestData*)), this, SLOT(onLoad(RequestData*)));
    } else {
        onLoad(image);
    }
}

void RequestImage::onLoad(RequestData *aImage) {
    pixmap_.loadFromData(aImage->reply());
    if (Settings::saveImages() == 1 && isAutoSave_) {
        QString dir = savePath_;
        if (dir.lastIndexOf("/") < dir.length() - 1 && dir.lastIndexOf("\\") < dir.length() - 1) {
            dir = dir.first(std::max(savePath_.lastIndexOf("/"), dir.lastIndexOf("\\")) + 1);
        }
        QDir().mkpath(dir);
//        createDir(_save);
        pixmap_.save(savePath_);
    }
    error_ = aImage->error();
    emit s_finished(this);
}


RequestImageToLabel::RequestImageToLabel(QLabel *aLabel, const QString &aUrl, const QString &aSave,
                                         const bool &aAutosave, const bool &aParallel, QObject *aParent):
    QObject{aParent}, label_{aLabel}, request_{new RequestImage{aUrl, aSave, aAutosave, aParallel, this}} {
    connect(request_, &RequestImage::s_finished, this, &RequestImageToLabel::onLoad);
    if (label_ != nullptr) {
        label_->setMovie(new QMovie("://loading.gif"));
        label_->movie()->setScaledSize(label_->size());
        label_->movie()->start();
    }
}

void RequestImageToLabel::onLoad() {
    if (label_ != nullptr) {
        if (label_->movie()) {
            if (label_->movie()->state() == QMovie::MovieState::Running) {
                label_->movie()->stop();
            }
        }
        label_->setPixmap(request_->pixmap());
    }
    request_->deleteLater();
    this->deleteLater();
}
