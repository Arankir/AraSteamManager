#include "qcomboboxfriends.h"
#include <QLineEdit>
#include <QEvent>

const int c_searchIndex = 0;

ComboBoxFriends::ComboBoxFriends(QWidget *aParent):
                                QComboBox(aParent),
                                listWidgetItems_(new QListWidget(this)),
                                lineEditText_(new QLineEdit(this)) {
    addFilterWidgets();
    lineEditText_->setReadOnly(true);
    lineEditText_->installEventFilter(this);

    setModel(listWidgetItems_->model());
    setView(listWidgetItems_);
    setLineEdit(lineEditText_);

    unselected();

    connect(this, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &ComboBoxFriends::itemClicked);
}

void ComboBoxFriends::clear() {
    listWidgetItems_->clear();
    addFilterWidgets();
    unselected();
}

void ComboBoxFriends::addFilterWidgets() {
    QListWidgetItem* curItem = new QListWidgetItem(listWidgetItems_);
    listWidgetItems_->addItem(curItem);

    lineEditSearch_ = new QLineEdit(this);
    lineEditSearch_->setPlaceholderText(tr("Поиск.."));
    lineEditSearch_->setClearButtonEnabled(true);
    connect(lineEditSearch_, &QLineEdit::textChanged, this, &ComboBoxFriends::onSearch);

    listWidgetItems_->setItemWidget(curItem, lineEditSearch_);
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
        y <= this->height() + listWidgetItems_->height()) {
        // Item was clicked, do not hide popup
    } else {
        listWidgetItems_->scrollToItem(listWidgetItems_->item(0));
        QComboBox::hidePopup();
    }
}

void ComboBoxFriends::addItem(const SProfile &steamFriend) {
    QListWidgetFriend *item = new  QListWidgetFriend(steamFriend);
    item->setText(steamFriend.personaName());
    item->setIcon(steamFriend.pixmapAvatar());
    listWidgetItems_->addItem(item);
}

void ComboBoxFriends::sort(const Qt::SortOrder &order) {
    listWidgetItems_->sortItems(order);
}

int ComboBoxFriends::count() const {
    int count = listWidgetItems_->count() - countStaticWidgets_;// Do not count the search bar
    if(count < 0) {
        count = 0;
    }
    return count;
}

void ComboBoxFriends::setCurrentText(const QString &aText) {
    Q_UNUSED(aText);
}

void ComboBoxFriends::onSearch(const QString &aSearchString) {
    for(int i = countStaticWidgets_; i < listWidgetItems_->count(); ++i) {
//TODO конфликтует с другим фильтром
        listWidgetItems_->item(i)->setHidden(listWidgetItems_->item(i)->text().toLower().indexOf(aSearchString.toLower(), 0) == -1);
    }
}

void ComboBoxFriends::itemClicked(const int &aIndex) {
    static bool isClicked = false;
    if (!isClicked) {
        isClicked = true;
        if(aIndex >= countStaticWidgets_) {
            auto steamFriend = dynamic_cast<QListWidgetFriend*>(listWidgetItems_->item(aIndex));
            if (steamFriend) {
                unselected();
                auto profile = steamFriend->_steamFriend;
//                mListWidget->removeItemWidget(steamFriend);
                delete listWidgetItems_->takeItem(aIndex);
                listWidgetItems_->scrollToItem(listWidgetItems_->item(0));
                QComboBox::hidePopup();
                emit s_friendClicked(profile);
            }
        }
        isClicked = false;
    }
}

bool ComboBoxFriends::eventFilter(QObject* aObject, QEvent* aEvent) {
    if(aObject == lineEditText_ && aEvent->type() == QEvent::MouseButtonRelease) {
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
