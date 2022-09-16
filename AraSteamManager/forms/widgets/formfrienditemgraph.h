#ifndef FORMFRIENDITEMGRAPH_H
#define FORMFRIENDITEMGRAPH_H

#include <QWidget>
#include <QListWidgetItem>
#include "classes/common/settings.h"
#include "classes/steamApi/structures/sfriends.h"
//#include "./formreachedfilter.h"

namespace Ui {
class FormFriendItemGraph;
}

class FormFriendItemGraph : public QWidget {
    Q_OBJECT

public:
    explicit FormFriendItemGraph(const SProfile &profile, const QColor &color, QListWidgetItem *parent = nullptr);
    ~FormFriendItemGraph();
    void setColor(const QColor &color);
    void setIcons();

    QListWidgetItem *item();
    SProfile *profile();

signals:
    void s_delete();

private:
    Ui::FormFriendItemGraph *ui;
    QListWidgetItem *item_ = nullptr;
    SProfile *profile_ = nullptr;
    QColor color_;
};

#endif // FORMFRIENDITEMCOMPARE_H
