#include "qcomboboxfriends.h"
#include <QLineEdit>
#include <QCheckBox>
#include <QEvent>

namespace {
    const int c_searchIndex     = 0;
    const int c_allFriendsIndex = 1;
}

ComboBoxFriends::ComboBoxFriends(QWidget *aParent) :
                                QComboBox(aParent),
                                mListWidget(new QListWidget(this)),
                                mLineEdit(new QLineEdit(this)),
                                mSearchBar(new QLineEdit(this)) {
    QListWidgetItem* curItem = new QListWidgetItem(mListWidget);
    mSearchBar->setPlaceholderText(tr("Поиск.."));
    mSearchBar->setClearButtonEnabled(true);
    mListWidget->addItem(curItem);
    mListWidget->setItemWidget(curItem, mSearchBar);

    mLineEdit->setText(tr("Добавить друга"));
    mLineEdit->setReadOnly(true);
    mLineEdit->installEventFilter(this);

    setModel(mListWidget->model());
    setView(mListWidget);
    setLineEdit(mLineEdit);

    connect(mSearchBar, &QLineEdit::textChanged, this, &ComboBoxFriends::onSearch);
    connect(this, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &ComboBoxFriends::itemClicked);
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
        QComboBox::hidePopup();
    }
}

void ComboBoxFriends::stateChanged(int aState) {
    //Удалить эту функцию
    Q_UNUSED(aState);
    QString selectedData("");
    int count = mListWidget->count();

    for (int i = 1; i < count; ++i) {
        QWidget *widget = mListWidget->itemWidget(mListWidget->item(i));
        QCheckBox *checkBox = static_cast<QCheckBox *>(widget);

        if (checkBox->isChecked()) {
            selectedData.append(checkBox->text()).append(";");
        }
    }
    if (selectedData.endsWith(";")) {
        selectedData.remove(selectedData.count() - 1, 1);
    }
    if (!selectedData.isEmpty()) {
        mLineEdit->setText(selectedData);
    } else {
        mLineEdit->clear();
    }

    mLineEdit->setToolTip(selectedData);
    emit selectionChanged();
}

void ComboBoxFriends::addItem(const QString &aText, const QVariant &aUserData) {
    Q_UNUSED(aUserData);
    QListWidgetItem* listWidgetItem = new QListWidgetItem(mListWidget);
    QCheckBox* checkBox = new QCheckBox(this);
    checkBox->setText(aText);
    mListWidget->addItem(listWidgetItem);
    mListWidget->setItemWidget(listWidgetItem, checkBox);
    connect(checkBox, &QCheckBox::stateChanged, this, &ComboBoxFriends::stateChanged);
}

void ComboBoxFriends::addItem(SFriend &aSteamFriend, bool aIsIncludeGame) {
    //Добавление айтема с другом, подключение его к слоту
}

QStringList ComboBoxFriends::currentText() {
    QStringList emptyStringList;
    if(!mLineEdit->text().isEmpty()) {
        emptyStringList = mLineEdit->text().split(';');
    }
    return emptyStringList;
}

void ComboBoxFriends::addItems(const QStringList &aTexts) {
    for(const auto &string: aTexts) {
        addItem(string);
    }
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
        QCheckBox* checkBox = static_cast<QCheckBox*>(mListWidget->itemWidget(mListWidget->item(i)));
        if(checkBox->text().contains(aSearchString, Qt::CaseInsensitive)) {
            mListWidget->item(i)->setHidden(false);
        } else {
            mListWidget->item(i)->setHidden(true);
        }
    }
}

void ComboBoxFriends::itemClicked(int aIndex) {
    if((aIndex != c_searchIndex) && (aIndex != c_allFriendsIndex)) {
        //Обработка друга (добавить колонку, убрать из этого списка, поместить в лист в выбранными друзьями)
        QWidget* widget = mListWidget->itemWidget(mListWidget->item(aIndex));
        QCheckBox *checkBox = static_cast<QCheckBox *>(widget);
        checkBox->setChecked(!checkBox->isChecked());
    }
}

void ComboBoxFriends::SetSearchBarPlaceHolderText(const QString &aPlaceHolderText) {
    mSearchBar->setPlaceholderText(aPlaceHolderText);
}

void ComboBoxFriends::SetPlaceHolderText(const QString &aPlaceHolderText) {
    mLineEdit->setPlaceholderText(aPlaceHolderText);
}

void ComboBoxFriends::clear() {
    mListWidget->clear();
    QListWidgetItem* curItem = new QListWidgetItem(mListWidget);
    mSearchBar = new QLineEdit(this);
    mSearchBar->setPlaceholderText(tr("Поиск.."));
    mSearchBar->setClearButtonEnabled(true);
    mListWidget->addItem(curItem);
    mListWidget->setItemWidget(curItem, mSearchBar);

    connect(mSearchBar, &QLineEdit::textChanged, this, &ComboBoxFriends::onSearch);
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

void ComboBoxFriends::ResetSelection() {
    int count = mListWidget->count();

    for (int i = 2; i < count; ++i) {
        QWidget *widget = mListWidget->itemWidget(mListWidget->item(i));
        QCheckBox *checkBox = static_cast<QCheckBox *>(widget);
        checkBox->setChecked(false);
    }
}
