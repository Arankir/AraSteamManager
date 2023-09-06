#include "requestimage.h"
#include "classes/common/settings.h"
#include "classes/common/images.h"

#include <QDir>

RequestImage::RequestImage(const QUrl &aUrl, const QString &aSave, bool aAutoSave, bool aParallel, QObject *aParent): QObject(aParent),
savePath_(aSave), isAutoSave_(aAutoSave) {
    RequestData *image = new RequestData(aUrl, aParallel, this);
    if (aParallel) {
        cnct_ = connect(image, SIGNAL(s_finished(RequestData*)), this, SLOT(onLoad(RequestData*)));
    } else {
        onLoad(image);
    }
}

QPixmap RequestImage::pixmap() const {
    return pixmap_;
}

QString RequestImage::error() {
    return error_;
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

    if (cnct_ != QMetaObject::Connection()) {
        disconnect(aImage, SIGNAL(s_finished(RequestData*)), this, SLOT(onLoad(RequestData*)));
    }
    aImage->deleteLater();
    emit s_finished(this);
}


RequestImageToLabel::RequestImageToLabel(QLabel *aLabel, const QString &aUrl, const QString &aSave,
                                         bool aAutosave, bool aParallel, QObject *aParent):
    QObject{aParent}, label_{aLabel}, request_{new RequestImage{aUrl, aSave, aAutosave, aParallel, this}} {
    connect(request_, &RequestImage::s_finished, this, &RequestImageToLabel::onLoad);
    if (label_ != nullptr) {
        label_->setMovie(new QMovie("://loading.gif"));
        label_->movie()->setScaledSize(label_->size());
        label_->movie()->start();
    }
}

RequestImageToLabel::RequestImageToLabel(QLabel *label, const QString &url, bool parallel, QObject *parent):
    RequestImageToLabel(label, url, "", false, parallel, parent) {

}

RequestImageToLabel::RequestImageToLabel(QLabel *label, const QString &url, QObject *parent):
    RequestImageToLabel(label, url, "", false, true, parent) {

}

void RequestImageToLabel::onLoad() {
    disconnect(request_, &RequestImage::s_finished, this, &RequestImageToLabel::onLoad);
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

QImage loadImage(QImage &aImage, const QUrl &aUrl, const QString &aSavePath, const QSize &aSize) {
    if (aImage.isNull()) {
        aImage = loadImage(aUrl, aSavePath, aSize);
    }
    return aImage;
}

QImage loadImage(const QUrl &aUrl, const QString &aSavePath, const QSize &aSize) {
    if (!QFile::exists(aSavePath)) {
        if (aUrl.isValid() && !aUrl.isEmpty()) {
            RequestImage img(aUrl, aSavePath, true, false);
            if (!img.pixmap().isNull()) {
                return img.pixmap().scaled(aSize).toImage();
            } else {
                qDebug() << "image error" << img.error() << aUrl;
            }
        }
    } else {
        return QPixmap(aSavePath).scaled(aSize).toImage();
    }
    return QPixmap(Images::missingImage()).scaled(aSize).toImage();
}
