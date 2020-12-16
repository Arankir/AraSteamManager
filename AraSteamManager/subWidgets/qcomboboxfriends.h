#pragma once

#include <QComboBox>
#include <QCheckBox>
#include <QListWidget>
#include "classes/steamApi/structures/sfriends.h"
#include "./items/qlistwidgetfriend.h"

class ComboBoxFriends : public QComboBox {
    Q_OBJECT

public:
    ComboBoxFriends(QWidget *parent = nullptr);
    void addItem(SProfile &steamFriend, FriendType type);
    int count() const;
    void hidePopup() override;

signals:
    void selectionChanged();

public slots:
    void clear();

protected:
    void wheelEvent(QWheelEvent *wheelEvent) override;
    bool eventFilter(QObject *object, QEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    void onSearch(const QString &searchString);
    void onAllFriends(int state);
    void itemClicked(int index);

    QListWidget *mListWidget;
    QLineEdit *mLineEdit;
    QLineEdit *mSearchBar;
    QCheckBox *mAllFriends;
};
