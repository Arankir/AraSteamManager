#ifndef FORMFRIENDITEMCOMPARE_H
#define FORMFRIENDITEMCOMPARE_H

#include <QWidget>
#include <QListWidgetItem>
#include "classes/common/settings.h"
#include "classes/steamApi/structures/sfriends.h"
#include "./formreachedfilter.h"

namespace Ui {
class FormFriendItemCompare;
}

class FormFriendItemCompare : public QWidget {
    Q_OBJECT

public:
    explicit FormFriendItemCompare(SProfile &steamFriend, QListWidgetItem *parent = nullptr);
    ~FormFriendItemCompare();
    void setPercent(const double &aPercent);
    void setHiddenFilter(const bool &aHidden);
    void setFilterValue(const ReachedType &type);
    bool isFilterHidden();

    void setIcons();
    QListWidgetItem *item() {return _item;}
    SProfile *steamProfile() {return _steamProfile;}

signals:
    void s_delete();
    void s_filterChanged(SProfile *profile, const ReachedType &type);

private:
    Ui::FormFriendItemCompare *ui;
    QListWidgetItem *_item = nullptr;
    SProfile *_steamProfile = nullptr;
};

#endif // FORMFRIENDITEMCOMPARE_H
