#ifndef REQUESTIMAGE_H
#define REQUESTIMAGE_H

#include <QObject>
#include <QLabel>
#include <QMovie>
#include "class/Network/requestdata.h"
#include "class/settings.h"

class RequestImage : public QObject
{
    Q_OBJECT
public:
    explicit RequestImage(QLabel *label, const QString &url, const QString &save = "", bool autosave = false, QObject *parent = nullptr);
    explicit RequestImage(QLabel *label, const QString &url, QObject *parent);
    RequestImage(const QString &url, const QString &save = "", bool autosave = false, QObject *parent = nullptr);
    QPixmap getPixmap();
    void setIndex(int aIndex);
    int getIndex();

signals:
    void s_loadComplete(RequestImage*);

private slots:
    void onLoad(RequestData*);

private:
    QLabel *_label;
    QString _save;
    bool _autosave;
    Settings _setting;
    QPixmap _pixmap;
    int _index;
};

#endif // REQUESTIMAGE_H
