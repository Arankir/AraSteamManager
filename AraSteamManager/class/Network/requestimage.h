#ifndef REQUESTIMAGE_H
#define REQUESTIMAGE_H

#include <QObject>
#include <QLabel>
#include <QMovie>
#include <class/Network/requestdata.h>
#include <class/settings.h>

class RequestImage : public QObject
{
    Q_OBJECT
public:
    explicit RequestImage(QLabel *label, QString url, QString save="", bool autosave=false, QObject *parent = nullptr);
    RequestImage(QString url, QString save="", bool autosave=false, QObject *parent = nullptr);
    QPixmap GetPixmap();
    void SetIndex(int a_index) {_index=a_index;}
    int GetIndex() {return _index;}

signals:
    void s_loadComplete(RequestImage*);

public slots:
    void OnLoadToLabel(RequestData*);
    void OnLoadPixmap(RequestData*);

private:
    QLabel *_label;
    QString _save;
    bool _autosave;
    Settings _setting;
    QPixmap _pixmap;
    int _index;
};

#endif // REQUESTIMAGE_H
