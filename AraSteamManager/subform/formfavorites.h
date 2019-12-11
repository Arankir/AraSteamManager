#ifndef FORMFAVORITES_H
#define FORMFAVORITES_H

#include <QWidget>
#include <class/favorites.h>
#include <class/steamapi/Sfriend.h>
#include <class/steamapi/Sprofile.h>
#include <class/steamapi/Sgames.h>
#include <class/steamapi/Sachievements.h>
#include <class/filter.h>
#include <class/imagerequest.h>

namespace Ui {
class FormFavorites;
}

class FormFavorites : public QWidget
{
    Q_OBJECT

public:
    explicit FormFavorites(QString key, QWidget *parent = nullptr);
    ~FormFavorites();

public slots:
    void InitComponents();
    void FriendLoad(SProfile*);
    void OnResultImage(ImageRequest*);

signals:
    void return_to_profile();

private slots:
    void on_pushButton_clicked();

private:
    Ui::FormFavorites *ui;
    QString key;
    Favorites games;
    Favorites friends;
    Favorites achievements;

    QVector<ImageRequest*> request;
    int numrequests=0;
    int numnow=0;

    Filter filter;
};

#endif // FORMFAVORITES_H
