#ifndef REQUESTIMAGE_H
#define REQUESTIMAGE_H

#include <QObject>
#include <QLabel>
#include <QMovie>
#include <QUrl>

#include "classes/network/requestdata.h"

class RequestImage : public QObject {
    Q_OBJECT
public:
    RequestImage(const QUrl &url, const QString &save = "", bool autosave = false, bool parallel = true, QObject *parent = nullptr);

    QPixmap pixmap() const;
    QString error();

signals:
    void s_finished(RequestImage*);

protected slots:
    virtual void onLoad(RequestData*);

protected:
    QString savePath_;
    bool isAutoSave_;
    QPixmap pixmap_;
    QString error_;

    QMetaObject::Connection cnct_;

};

class RequestImageToLabel : public QObject {
    Q_OBJECT
public:
    RequestImageToLabel(QLabel *label, const QString &url, const QString &save = "", bool autosave = false, bool parallel = true, QObject *parent = nullptr);
    RequestImageToLabel(QLabel *label, const QString &url, bool parallel, QObject *parent = nullptr);
    RequestImageToLabel(QLabel *label, const QString &url, QObject *parent);

private slots:
    void onLoad();

private:
    QLabel *label_;
    RequestImage *request_;

};

QImage loadImage(QImage &aImage, const QUrl &aUrl, const QString &aSavePath, const QSize &aSize);
QImage loadImage(const QUrl &aUrl, const QString &aSavePath, const QSize &aSize);

#endif // REQUESTIMAGE_H
