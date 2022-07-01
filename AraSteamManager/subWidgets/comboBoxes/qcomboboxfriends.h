#ifndef COMBOBOXFRIENDS_H
#define COMBOBOXFRIENDS_H
#pragma once

#include <QComboBox>
#include <QCheckBox>
#include <QListWidget>
#include "classes/steamApi/structures/sfriends.h"
#include "../items/qlistwidgetfriend.h"

class ComboBoxFriends : public QComboBox {
    Q_OBJECT

public:
    ComboBoxFriends(QWidget *parent = nullptr);
    void addItem(const SProfile &steamFriend);
    void setCurrentText(const QString &text);
    int count() const;
    void hidePopup() override;

    void sort(Qt::SortOrder aOrder);
signals:
    void s_selectionChanged();
    void s_friendClicked(const SProfile&);

public slots:
    void clear();

protected:
    void wheelEvent(QWheelEvent *wheelEvent) override;
    bool eventFilter(QObject *object, QEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    virtual void addFilterWidgets();

    int mCountFilterWidgets = 1;
    QListWidget *mListWidget;
    QLineEdit *mLineEdit;

private:
    void onSearch(const QString &searchString);
    void itemClicked(int index);
    void unselected();

    QLineEdit *mSearchBar;
};

#endif // COMBOBOXFRIENDS_H
