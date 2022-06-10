#ifndef REQUESTIMAGE_H
#define REQUESTIMAGE_H

#include <QObject>
#include <QLabel>
#include <QMovie>

#include "classes/network/requestdata.h"

class RequestImage : public QObject {
    Q_OBJECT
public:
    RequestImage(const QString &url, const QString &save = "", const bool &autosave = false, const bool &parallel = true, QObject *parent = nullptr);

    QPixmap pixmap() const {return pixmap_;}
    QString error() {return error_;}

signals:
    void s_finished(RequestImage*);

protected slots:
    virtual void onLoad(RequestData*);

protected:
    QString savePath_;
    bool isAutoSave_;
    QPixmap pixmap_;
    QString error_;

};

class RequestImageToLabel : public QObject {
    Q_OBJECT
public:
    RequestImageToLabel(QLabel *label, const QString &url, const QString &save = "", const bool &autosave = false, const bool &parallel = true, QObject *parent = nullptr);
    RequestImageToLabel(QLabel *label, const QString &url, const bool &parallel, QObject *parent = nullptr): RequestImageToLabel(label, url, "", false, parallel, parent) {;}
    RequestImageToLabel(QLabel *label, const QString &url, QObject *parent): RequestImageToLabel(label, url, "", false, true, parent) {;}

private slots:
    void onLoad();

private:
    QLabel *label_;
    RequestImage *request_;

};
#endif // REQUESTIMAGE_H
