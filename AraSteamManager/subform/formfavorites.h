#ifndef FORMFAVORITES_H
#define FORMFAVORITES_H

#include <QWidget>
#include <class/favorites.h>
#include <class/steamapi/Sfriends.h>
#include <class/steamapi/Sprofile.h>
#include <class/steamapi/Sgames.h>
#include <class/steamapi/Sachievements.h>
#include <class/filter.h>
#include <class/settings.h>
#include <class/imagerequest.h>

namespace Ui {
class FormFavorites;
}

class FormFavorites : public QWidget
{
    Q_OBJECT

public:
    explicit FormFavorites(QWidget *parent = nullptr);
    ~FormFavorites();

public slots:
    void InitComponents();
    void FriendLoad(SProfile*);
    void OnResultImage(ImageRequest*);

signals:
    void s_return_to_profile(QWidget*);

private slots:
    void on_pushButton_clicked();

private:
    Ui::FormFavorites *ui;
    Favorites _games;
    Favorites _friends;
    Favorites _achievements;
    Filter _filter;
    Settings _setting;

    QVector<ImageRequest*> _request;
    int _numRequests=0;
    int _numNow=0;

};

#endif // FORMFAVORITES_H
