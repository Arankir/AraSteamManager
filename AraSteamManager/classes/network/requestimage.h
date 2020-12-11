#ifndef REQUESTIMAGE_H
#define REQUESTIMAGE_H

#include <QObject>
#include <QLabel>
#include <QMovie>
#include "classes/network/requestdata.h"

class RequestImage : public QObject
{
    Q_OBJECT
public:
    explicit RequestImage(QLabel *label, const QString &url, const QString &save = "", bool autosave = false, QObject *parent = nullptr);
    explicit RequestImage(QLabel *label, const QString &url, QObject *parent): RequestImage(label, url, "", false, parent) {}
    explicit RequestImage(const QString &url, const QString &save = "", bool autosave = false, QObject *parent = nullptr): RequestImage(nullptr, url, save, autosave, parent) {}

    void setIndex(int index) {_index = index;}

    int getIndex() const {return _index;}
    QPixmap getPixmap() const {return _pixmap;}

signals:
    void s_loadComplete(RequestImage*);

private slots:
    void onLoad(RequestData*);

private:
    QLabel *_label;

    QString _save;
    bool _autosave;
    QPixmap _pixmap;

    int _index;
};

#endif // REQUESTIMAGE_H
