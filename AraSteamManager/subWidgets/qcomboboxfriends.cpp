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
    QListWidgetItem* curItem = new QListWidgetItem(mListWidget);
    mSearchBar->setPlaceholderText(tr("Поиск.."));
    mSearchBar->setClearButtonEnabled(true);
    mListWidget->addItem(curItem);
    mListWidget->setItemWidget(curItem, mSearchBar);

    QListWidgetItem* curItem2 = new QListWidgetItem(mListWidget);
    mAllFriends->setText(tr("Все друзья"));
    mListWidget->addItem(curItem2);
    mListWidget->setItemWidget(curItem2, mAllFriends);

    mLineEdit->setText(tr("Добавить друга"));
    mLineEdit->setReadOnly(true);
    mLineEdit->installEventFilter(this);

    setModel(mListWidget->model());
    setView(mListWidget);
    setLineEdit(mLineEdit);

    connect(mSearchBar,     &QLineEdit::textChanged,                                        this, &ComboBoxFriends::onSearch);
    connect(mAllFriends,    &QCheckBox::stateChanged,                                       this, &ComboBoxFriends::onAllFriends);
    connect(this,           static_cast<void (QComboBox::*)(int)>(&QComboBox::activated),   this, &ComboBoxFriends::itemClicked);
}

void ComboBoxFriends::hidePopup() {
    int x = QCursor::pos().x() - mapToGlobal(geometry().topLeft()).x() + geometry().x();
    int y = QCursor::pos().y() - mapToGlobal(geometry().topLeft()).y() + geometry().y();
    if (x >= 0 &&
        x <= this->width() &&
        y >= this->height() &&
        y <= this->height() + mListWidget->height()) {
        // Item was clicked, do not hide popup
        qDebug() << mListWidget->itemWidget(mListWidget->item(0)) << mListWidget->itemWidget(mListWidget->item(1));
        mListWidget->itemWidget(mListWidget->item(0))->setVisible(true);
        mListWidget->itemWidget(mListWidget->item(1))->setVisible(false);
        mListWidget->itemWidget(mListWidget->item(1))->setVisible(true);
    } else {
        QComboBox::hidePopup();
    }
}

void ComboBoxFriends::addItem(SProfile &steamFriend, FriendType type) {
    QListWidgetFriend *item = new  QListWidgetFriend(&steamFriend, type);
    item->setText(steamFriend._personaName);
    item->setIcon(steamFriend.getPixmapAvatar());
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

void ComboBoxFriends::onSearch(const QString &aSearchString) {
    for(int i = 2; i < mListWidget->count(); ++i) {
        //Поиск и отображение только нужных друзей
        qDebug() << aSearchString;
//        QCheckBox* checkBox = static_cast<QCheckBox*>(mListWidget->itemWidget(mListWidget->item(i)));
//        if(checkBox->text().contains(aSearchString, Qt::CaseInsensitive)) {
//            mListWidget->item(i)->setHidden(false);
//        } else {
//            mListWidget->item(i)->setHidden(true);
//        }
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

        }
    }
}

void ComboBoxFriends::clear() {
    mListWidget->clear();
    QListWidgetItem* curItem = new QListWidgetItem(mListWidget);
    mSearchBar = new QLineEdit(this);
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
