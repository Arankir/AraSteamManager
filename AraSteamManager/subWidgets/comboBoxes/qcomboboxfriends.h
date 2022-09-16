#ifndef COMBOBOXFRIENDS_H
#define COMBOBOXFRIENDS_H
#pragma once

#include <QComboBox>
#include "classes/steamApi/structures/sfriends.h"
#include "../items/qlistwidgetfriend.h"

class ComboBoxFriends : public QComboBox {
    Q_OBJECT

public:
    ComboBoxFriends(QWidget *parent = nullptr);
    void addItem(const SProfile &profile);
    void setCurrentText(const QString &text);
    int count() const;
    void hidePopup() override;

    void sort(const Qt::SortOrder &order);
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

    int countStaticWidgets_ = 1;
    QListWidget *listWidgetItems_;
    QLineEdit *lineEditText_;

private:
    void onSearch(const QString &searchString);
    void itemClicked(const int &index);
    void unselected();

    QLineEdit *lineEditSearch_;
};

#endif // COMBOBOXFRIENDS_H
