#ifndef FORMFRIENDS_H
#define FORMFRIENDS_H

#include <QWidget>
#include <QFile>
#include <QStandardItem>
#include "class/Network/requestimage.h"
#include "class/steamapi/Sfriends.h"
#include "class/Threads/threading.h"
#include "class/settings.h"
#include "class/favorites.h"
#include "class/filter.h"
#include "subwidget/qbuttonwithdata.h"
#include <QtAlgorithms>
#include <QAction>
#include <QMenu>
#include <QToolButton>

namespace Ui {
class FormFriends;
}

class FormFriends : public QWidget {
    Q_OBJECT

public slots:
    void changeEvent(QEvent *event);
    void progressLoading(int p,int row);
    void updateSettings();

    void pullTable(int aTo, int aDo);
    void onTablePulled();
    void createThread();
public:
    explicit FormFriends(const QString &id, SFriends &Friends, QWidget *parent = nullptr);
    ~FormFriends();

signals:
    void s_friendsLoaded(int progress, int row);
    void s_finish();
    void s_return_to_profile(QWidget*);
    void s_go_to_profile(const QString &id, ProfileUrlType type);

private slots:
    void initComponents(SFriends &aFriends);
    void closeEvent(QCloseEvent *event);
    void retranslate();
    void setIcons();
    void updateHiddenRows();
    void friendToUi();

    void buttonFriendGoTo_Clicked();
    void buttonFriendFavorite_Clicked();

    void checkBoxOpenProfile_StateChanged(int arg1);
    void lineEditName_TextChanged(const QString &arg1);
    void buttonFind_Clicked();
    void comboBoxStatus_Activated(int index);
    void checkBoxFavorites_StateChanged(int arg1);

    void tableWidgetFriends_CellClicked(int row, int col);
    void tableWidgetFriends_CellDoubleClicked(int row, int column);

//    QTableWidgetItem *getState(QString aGameExtraInfo, int aPersonaState);
//    QTableWidgetItem *getPrivacy(int aCommunityVisibilityState);
//    void updateButtonsPages(bool aFirst, QString aFirstText, bool aLabelDots1, bool aBack2, QString aBack2Text, bool aBack, QString aBackText, bool aCurrent, QString aCurrentText, bool aNext, QString aNextText, bool aNext2, QString aNext2Text, bool aLabelDots2, bool aLast, QString aLastText);
//    void buttonPageFirst_Clicked();
//    void buttonPageBack2_Clicked();
//    void buttonPageBack_Clicked();
//    void buttonPageNext_Clicked();
//    void buttonPageNext2_Clicked();
//    void buttonPageLast_Clicked();
//    void calculateButtonPages();
private:
    Ui::FormFriends *ui;
    QString _id;
    bool _blockedLoad = false;
    QList<QPair<SFriend, SProfile>> _friends;
    QList<QPair<SFriend*, SProfile*>> _visibleFriends;
    Settings _setting;
    Favorites _favorites;
    Filter _filter;
    QString _currentFriend;
    int _currentFriendIndex = -1;
    int _currentPage = 0;

    //QVector<RequestData*> _request;
    int _numRequests = 0;
    int _numNow = 0;


};

#endif // FORMFRIENDS_H
