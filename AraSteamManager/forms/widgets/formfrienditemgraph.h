#ifndef FORMFRIENDITEMGRAPH_H
#define FORMFRIENDITEMGRAPH_H

#include <QWidget>
#include <QListWidgetItem>
#include "classes/common/settings.h"
#include "classes/steamApi/structures/sfriends.h"
#include "./formreachedfilter.h"

namespace Ui {
class FormFriendItemGraph;
}

class FormFriendItemGraph : public QWidget {
    Q_OBJECT

public:
    explicit FormFriendItemGraph(const SProfile &steamFriend, const QColor &color, QListWidgetItem *parent = nullptr);
    ~FormFriendItemGraph();
    void setColor(const QColor &aColor);
    void setIcons();

    QListWidgetItem *item() {return _item;}
    SProfile *steamProfile() {return _steamProfile;}

signals:
    void s_delete();

private:
    Ui::FormFriendItemGraph *ui;
    QListWidgetItem *_item = nullptr;
    SProfile *_steamProfile = nullptr;
    QColor _color;
};

#endif // FORMFRIENDITEMCOMPARE_H
