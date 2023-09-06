#ifndef FORMFRIENDITEMCOMPARE_H
#define FORMFRIENDITEMCOMPARE_H

#include <QWidget>
#include <QListWidgetItem>
#include "classes/common/settings.h"
#include "classes/steamApi/structures/sfriends.h"
#include "subWidgets/withData/buttonreachedtype.h"

namespace Ui {
class FormFriendItemCompare;
}

class FormFriendItemCompare : public QWidget {
    Q_OBJECT

public:
    explicit FormFriendItemCompare(const SProfile &profile, QListWidgetItem *parent = nullptr);
    ~FormFriendItemCompare();
    void setPercent(const double &percent);
    void setHiddenFilter(bool hidden);
    void setFilterValue(const ReachedType &type);
    bool isFilterHidden();

    void setIcons();
    QListWidgetItem *item();
    SProfile *steamProfile();

signals:
    void s_delete();
    void s_filterChanged(SProfile *profile, const ReachedType &type);

private:
    Ui::FormFriendItemCompare *ui;
    QListWidgetItem *item_ = nullptr;
    SProfile *profile_ = nullptr;
};

#endif // FORMFRIENDITEMCOMPARE_H
