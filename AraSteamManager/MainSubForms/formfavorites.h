#ifndef FORMFAVORITES_H
#define FORMFAVORITES_H

#include <QWidget>
#include "class/favorites.h"
#include "class/steamapi/Sfriends.h"
#include "class/steamapi/Sprofile.h"
#include "class/steamapi/Sgames.h"
#include "class/steamapi/Sachievements.h"
#include "class/filter.h"
//#include "class/settings.h"
#include "class/Network/requestimage.h"

namespace Ui {
class FormFavorites;
}

class FormFavorites : public QWidget {
    Q_OBJECT

public slots:
    void initComponents();
    void friendLoad(SProfiles *);

    void updateSettings();
    void setIcons();
    void retranslate();
public:
    explicit FormFavorites(QWidget *parent = nullptr);
    ~FormFavorites();

signals:
    void s_return_to_profile(QWidget*);

private slots:
    void changeEvent(QEvent *event);
    void on_pushButton_clicked();

private:
    Ui::FormFavorites *ui;
//    Favorites _games;
//    Favorites _friends;
//    Favorites _achievements;
    Favorites _favorites;
    Filter _filter;
    //Settings _setting;

    QString _iconsColor;

    //QVector<RequestData*> _request;
    int _numRequests = 0;
    int _numNow = 0;

};

#endif // FORMFAVORITES_H
