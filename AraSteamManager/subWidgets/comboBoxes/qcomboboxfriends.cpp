#include "qcomboboxfriends.h"
#include <QLineEdit>
#include <QEvent>

namespace {
    const int c_searchIndex     = 0;
    const int c_allFriendsIndex = 1;
}

ComboBoxFriends::ComboBoxFriends(QWidget *aParent):
                                QComboBox(aParent),
                                mListWidget(new QListWidget(this)),
                                mLineEdit(new QLineEdit(this)),
                                mSearchBar(new QLineEdit(this)),
                                mAllFriends(new QCheckBox(this)) {
    addFilterWidgets();
    mLineEdit->setReadOnly(true);
    mLineEdit->installEventFilter(this);

    setModel(mListWidget->model());
    setView(mListWidget);
    setLineEdit(mLineEdit);

    QComboBox::setCurrentText(tr("Добавить друга"));

    connect(this, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &ComboBoxFriends::itemClicked);
}

void ComboBoxFriends::addFilterWidgets() {
    QListWidgetItem* curItem = new QListWidgetItem(mListWidget);
    mSearchBar->setPlaceholderText(tr("Поиск.."));
    mSearchBar->setClearButtonEnabled(true);
    mListWidget->addItem(curItem);
    mListWidget->setItemWidget(curItem, mSearchBar);

    QListWidgetItem* curItem2 = new QListWidgetItem(mListWidget);
    mAllFriends->setText(tr("Все друзья"));
    mListWidget->addItem(curItem2);
    mListWidget->setItemWidget(curItem2, mAllFriends);

    connect(mSearchBar,     &QLineEdit::textChanged,    this, &ComboBoxFriends::onSearch);
    connect(mAllFriends,    &QCheckBox::stateChanged,   this, &ComboBoxFriends::onAllFriends);
}

void ComboBoxFriends::hidePopup() {
    int x = QCursor::pos().x() - mapToGlobal(geometry().topLeft()).x() + geometry().x();
    int y = QCursor::pos().y() - mapToGlobal(geometry().topLeft()).y() + geometry().y();
    if (x >= 0 &&
        x <= this->width() &&
        y >= this->height() &&
        y <= this->height() + mListWidget->height()) {
        // Item was clicked, do not hide popup
    } else {
        mListWidget->scrollToItem(mListWidget->item(0));
        QComboBox::hidePopup();
    }
}

void ComboBoxFriends::addItem(SProfile &steamFriend, FriendType type) {
    QListWidgetFriend *item = new  QListWidgetFriend(&steamFriend, type);
    item->setText(steamFriend.personaName());
    item->setIcon(steamFriend.pixmapAvatar());
    mListWidget->addItem(item);
    onAllFriends(static_cast<int>(mAllFriends->isChecked()) * 2);
}

int ComboBoxFriends::count() const {
    int count = mListWidget->count() - 2;// Do not count the search bar
    if(count < 0) {
        count = 0;
    }
    return count;
}

void ComboBoxFriends::setCurrentText(const QString &aText) {
    Q_UNUSED(aText);
}

void ComboBoxFriends::onSearch(const QString &aSearchString) {
    for(int i = 2; i < mListWidget->count(); ++i) {
//TODO конфликтует с другим фильтром
        mListWidget->item(i)->setHidden(mListWidget->item(i)->text().toLower().indexOf(aSearchString.toLower(), 0) == -1);
    }
}

void ComboBoxFriends::onAllFriends(int aState) {
    switch (aState) {
    case 0: {
        for(int i = 2; i < mListWidget->count(); ++i) {
            auto steamFriend = dynamic_cast<QListWidgetFriend*>(mListWidget->item(i));
            if (steamFriend) {
                mListWidget->item(i)->setHidden(steamFriend->_type != FriendType::haveGame);
            }
        }
        break;
    }
    case 2: {
        for (int i = 2; i < mListWidget->count(); ++i) {
            mListWidget->item(i)->setHidden(false);
        }
        break;
    }
    }
}

void ComboBoxFriends::itemClicked(int aIndex) {
    if((aIndex != c_searchIndex) && (aIndex != c_allFriendsIndex)) {
        //Обработка друга (добавить колонку, убрать из этого списка, поместить в лист в выбранными друзьями)
        auto steamFriend = dynamic_cast<QListWidgetFriend*>(mListWidget->item(aIndex));
        if (steamFriend) {
            emit s_friendClicked(*(steamFriend->_steamFriend));
            delete mListWidget->item(aIndex);
        }
    }
    QComboBox::setCurrentIndex(0);
    QComboBox::setCurrentText(tr("Добавить друга"));
}

void ComboBoxFriends::clear() {
    mListWidget->clear();
    addFilterWidgets();
}

void ComboBoxFriends::wheelEvent(QWheelEvent *aWheelEvent) {
    // Do not handle the wheel event
    Q_UNUSED(aWheelEvent);
}

bool ComboBoxFriends::eventFilter(QObject* aObject, QEvent* aEvent) {
    if(aObject == mLineEdit && aEvent->type() == QEvent::MouseButtonRelease) {
        showPopup();
        return false;
    }
    return false;
}

void ComboBoxFriends::keyPressEvent(QKeyEvent* aEvent) {
    // Do not handle key event
    Q_UNUSED(aEvent);
}
