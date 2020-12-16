#ifndef FORMFAVORITES_H
#define FORMFAVORITES_H

#include <QWidget>
#include "classes/common/favorites.h"
#include "classes/steamApi/structures/sfriends.h"
#include "classes/steamApi/structures/sprofile.h"
#include "classes/steamApi/structures/sgames.h"
#include "classes/steamApi/structures/sachievements.h"
#include "classes/common/myfilter.h"
#include "classes/network/requestimage.h"

namespace Ui {
class FormFavorites;
}

class FormFavorites : public QWidget {
    Q_OBJECT

public slots:
    bool isInit();
    bool isLoaded();
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
    void initComponents();
    void changeEvent(QEvent *event);
    void on_pushButton_clicked();

private:
    Ui::FormFavorites *ui;
//    Favorites _games;
//    Favorites _friends;
//    Favorites _achievements;
    Favorites _favorites;
    MyFilter _filter;
    //Settings _setting;

    QString _iconsColor;

    //QVector<RequestData*> _request;
    int _numRequests = 0;
    int _numNow = 0;

};

#endif // FORMFAVORITES_H
