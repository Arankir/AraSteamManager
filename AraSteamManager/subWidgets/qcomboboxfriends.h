#pragma once

#include <QComboBox>
#include <QListWidget>
#include "class/steamapi/Sfriends.h"

class ComboBoxFriends : public QComboBox
{
    Q_OBJECT

public:
    ComboBoxFriends(QWidget *parent = nullptr);
    void addItem(const QString &text, const QVariant &userData = QVariant());
    void addItem(SFriend &steamFriend, bool isIncludeGame);
    void addItems(const QStringList &texts);
    QStringList currentText();
    int count() const;
    void hidePopup() override;
    void SetSearchBarPlaceHolderText(const QString &placeHolderText);
    void SetPlaceHolderText(const QString &placeHolderText);
    void ResetSelection();

signals:
    void selectionChanged();

public slots:
    void clear();

protected:
    void wheelEvent(QWheelEvent* aWheelEvent) override;
    bool eventFilter(QObject* aObject, QEvent* aEvent) override;
    void keyPressEvent(QKeyEvent* aEvent) override;

private:
    void stateChanged(int aState);
    void onSearch(const QString& aSearchString);
    void itemClicked(int aIndex);

    QListWidget* mListWidget;
    QLineEdit* mLineEdit;
    QLineEdit* mSearchBar;
};
