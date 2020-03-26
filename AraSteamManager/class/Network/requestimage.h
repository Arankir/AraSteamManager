#ifndef REQUESTIMAGE_H
#define REQUESTIMAGE_H

#include <QObject>
#include <QLabel>
#include <QMovie>
#include <class/Network/requestdata.h>

class RequestImage : public QObject
{
    Q_OBJECT
public:
    explicit RequestImage(QLabel *label, QString url, QString save="", bool autosave=false, QObject *parent = nullptr);

signals:
    void s_loadComplete();

private slots:
    void OnLoad(RequestData*);

private:
    QLabel *_label;
    QString _save;
    bool _autosave;
};

#endif // REQUESTIMAGE_H
