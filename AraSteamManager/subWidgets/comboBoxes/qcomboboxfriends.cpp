#include "qcomboboxfriends.h"
#include <QLineEdit>
#include <QEvent>

const int c_searchIndex = 0;

ComboBoxFriends::ComboBoxFriends(QWidget *aParent):
                                QComboBox(aParent),
                                mListWidget(new QListWidget(this)),
                                mLineEdit(new QLineEdit(this)) {
    addFilterWidgets();
    mLineEdit->setReadOnly(true);
    mLineEdit->installEventFilter(this);

    setModel(mListWidget->model());
    setView(mListWidget);
    setLineEdit(mLineEdit);

    unselected();

    connect(this, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &ComboBoxFriends::itemClicked);
}

void ComboBoxFriends::clear() {
    mListWidget->clear();
    addFilterWidgets();
    unselected();
}

void ComboBoxFriends::addFilterWidgets() {
    QListWidgetItem* curItem = new QListWidgetItem(mListWidget);
    mListWidget->addItem(curItem);

    mSearchBar = new QLineEdit(this);
    mSearchBar->setPlaceholderText(tr("Поиск.."));
    mSearchBar->setClearButtonEnabled(true);
    connect(mSearchBar, &QLineEdit::textChanged, this, &ComboBoxFriends::onSearch);

    mListWidget->setItemWidget(curItem, mSearchBar);
}

void ComboBoxFriends::unselected() {
    QComboBox::setCurrentIndex(0);
    QComboBox::setCurrentText(tr("Выбрать профиль"));
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

void ComboBoxFriends::addItem(const SProfile &steamFriend) {
    QListWidgetFriend *item = new  QListWidgetFriend(steamFriend);
    item->setText(steamFriend.personaName());
    item->setIcon(steamFriend.pixmapAvatar());
    mListWidget->addItem(item);
}

void ComboBoxFriends::sort(Qt::SortOrder aOrder) {
    mListWidget->sortItems(aOrder);
}

int ComboBoxFriends::count() const {
    int count = mListWidget->count() - mCountFilterWidgets;// Do not count the search bar
    if(count < 0) {
        count = 0;
    }
    return count;
}

void ComboBoxFriends::setCurrentText(const QString &aText) {
    Q_UNUSED(aText);
}

void ComboBoxFriends::onSearch(const QString &aSearchString) {
    for(int i = mCountFilterWidgets; i < mListWidget->count(); ++i) {
//TODO конфликтует с другим фильтром
        mListWidget->item(i)->setHidden(mListWidget->item(i)->text().toLower().indexOf(aSearchString.toLower(), 0) == -1);
    }
}

void ComboBoxFriends::itemClicked(int aIndex) {
    static bool isClicked = false;
    if (!isClicked) {
        isClicked = true;
        if(aIndex >= mCountFilterWidgets) {
            auto steamFriend = dynamic_cast<QListWidgetFriend*>(mListWidget->item(aIndex));
            if (steamFriend) {
                unselected();
                auto profile = steamFriend->_steamFriend;
//                mListWidget->removeItemWidget(steamFriend);
                delete mListWidget->takeItem(aIndex);
                mListWidget->scrollToItem(mListWidget->item(0));
                QComboBox::hidePopup();
                emit s_friendClicked(profile);
            }
        }
        isClicked = false;
    }
}

bool ComboBoxFriends::eventFilter(QObject* aObject, QEvent* aEvent) {
    if(aObject == mLineEdit && aEvent->type() == QEvent::MouseButtonRelease) {
        showPopup();
        return false;
    }
    return false;
}

void ComboBoxFriends::wheelEvent(QWheelEvent *aWheelEvent) {
    // Do not handle the wheel event
    Q_UNUSED(aWheelEvent);
}

void ComboBoxFriends::keyPressEvent(QKeyEvent* aEvent) {
    // Do not handle key event
    Q_UNUSED(aEvent);
}
