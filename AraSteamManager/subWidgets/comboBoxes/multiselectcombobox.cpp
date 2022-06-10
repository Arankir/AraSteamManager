
#include "multiselectcombobox.h"
#include <QLineEdit>
#include <QCheckBox>
#include <QEvent>
#include "classes/common/generalfunctions.h"

namespace {
    const int scSearchBarIndex = 0;
}

MultiSelectComboBox::MultiSelectComboBox(QWidget *aParent) :
    QComboBox(aParent),
    listWidget_(new QListWidget(this)),
    lineEdit_(new QLineEdit(this)),
    searchBar_(new QLineEdit(this))
{
    QListWidgetItem* curItem = new QListWidgetItem(listWidget_);
    searchBar_->setPlaceholderText(tr("Search.."));
    searchBar_->setClearButtonEnabled(true);
    listWidget_->addItem(curItem);
    listWidget_->setItemWidget(curItem, searchBar_);

    lineEdit_->setReadOnly(true);
    lineEdit_->installEventFilter(this);

    setModel(listWidget_->model());
    setView(listWidget_);
    setLineEdit(lineEdit_);

    connect(searchBar_, &QLineEdit::textChanged, this, &MultiSelectComboBox::onSearch);
    connect(this, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &MultiSelectComboBox::itemClicked);
}

void MultiSelectComboBox::hidePopup() {
    int width = this->width();
    int height = listWidget_->height();
    int x = QCursor::pos().x() - mapToGlobal(geometry().topLeft()).x() + geometry().x();
    int y = QCursor::pos().y() - mapToGlobal(geometry().topLeft()).y() + geometry().y();
    if (x >= 0 && x <= width &&
        y >= 0 && y <= height + this->height() &&
        x >= lineEdit_->x() &&
        y >= lineEdit_->y()) {
        // Item was clicked, do not hide popup
    } else {
        QComboBox::hidePopup();
    }
}

QString MultiSelectComboBox::getCurrentText() {
    QString selectedData("");
    int count = listWidget_->count();

    for (int i = 1; i < count; ++i) {
        QWidget *widget = listWidget_->itemWidget(listWidget_->item(i));
        QCheckBox *checkBox = static_cast<QCheckBox *>(widget);

        if (checkBox->isChecked()) {
            selectedData.append(checkBox->text()).append(";");
        }
    }
    if (selectedData.endsWith(";")) {
        selectedData.remove(selectedData.count() - 1, 1);
    }
    return selectedData;
}

void MultiSelectComboBox::stateChanged(int aState) {
    Q_UNUSED(aState);
    QString selectedData = getCurrentText();
    if (!selectedData.isEmpty()) {
        lineEdit_->setText(selectedData);
    } else {
        lineEdit_->setText(tr("Не выбрано"));
    }

    lineEdit_->setToolTip(textToToolTip(selectedData, ";"));
    emit selectionChanged();
}

void MultiSelectComboBox::addItem(const QString& aText, const QVariant& aUserData) {
    Q_UNUSED(aUserData);
    QListWidgetItem* listWidgetItem = new QListWidgetItem(listWidget_);
    QCheckBox* checkBox = new QCheckBox(this);
    checkBox->setText(aText);
    listWidget_->addItem(listWidgetItem);
    listWidget_->setItemWidget(listWidgetItem, checkBox);
    connect(checkBox, &QCheckBox::stateChanged, this, &MultiSelectComboBox::stateChanged);
}

QStringList MultiSelectComboBox::currentText() {
    QStringList emptyStringList;
    if(!lineEdit_->text().isEmpty()) {
        emptyStringList = getCurrentText().split(';');
    }
    return emptyStringList;
}

void MultiSelectComboBox::addItems(const QStringList& aTexts) {
    for(const auto &string: aTexts) {
        addItem(string);
    }
}

int MultiSelectComboBox::count() const {
    int count = listWidget_->count() - 1;// Do not count the search bar
    if(count < 0) {
        count = 0;
    }
    return count;
}

void MultiSelectComboBox::onSearch(const QString& aSearchString) {
    for(int i = 1; i < listWidget_->count(); ++i) {
        QCheckBox* checkBox = static_cast<QCheckBox*>(listWidget_->itemWidget(listWidget_->item(i)));
        listWidget_->item(i)->setHidden(!checkBox->text().contains(aSearchString, Qt::CaseInsensitive));
    }
}

void MultiSelectComboBox::itemClicked(int aIndex) {
    if(aIndex != scSearchBarIndex) { // 0 means the search bar
        QWidget* widget = listWidget_->itemWidget(listWidget_->item(aIndex));
        QCheckBox *checkBox = static_cast<QCheckBox *>(widget);
        checkBox->setChecked(!checkBox->isChecked());
    }
}

void MultiSelectComboBox::SetSearchBarPlaceHolderText(const QString& aPlaceHolderText) {
    searchBar_->setPlaceholderText(aPlaceHolderText);
}

void MultiSelectComboBox::SetPlaceHolderText(const QString& aPlaceHolderText) {
    lineEdit_->setPlaceholderText(aPlaceHolderText);
}

void MultiSelectComboBox::clear() {
    listWidget_->clear();
    QListWidgetItem* curItem = new QListWidgetItem(listWidget_);
    searchBar_ = new QLineEdit(this);
    searchBar_->setPlaceholderText(tr("Search.."));
    searchBar_->setClearButtonEnabled(true);
    listWidget_->addItem(curItem);
    listWidget_->setItemWidget(curItem, searchBar_);

    connect(searchBar_, &QLineEdit::textChanged, this, &MultiSelectComboBox::onSearch);
}

void MultiSelectComboBox::wheelEvent(QWheelEvent *aWheelEvent) {
    // Do not handle the wheel event
    Q_UNUSED(aWheelEvent);
}

bool MultiSelectComboBox::eventFilter(QObject* aObject, QEvent* aEvent) {
    if(aObject == lineEdit_ && aEvent->type() == QEvent::MouseButtonRelease) {
        showPopup();
        return false;
    }
    return false;
}

void MultiSelectComboBox::keyPressEvent(QKeyEvent* aEvent) {
    // Do not handle key event
    Q_UNUSED(aEvent);
}

void MultiSelectComboBox::setCurrentText(const QString& aText) {
    Q_UNUSED(aText);
}

void MultiSelectComboBox::setCurrentText(const QStringList& aText) {
    int count = listWidget_->count();

    for (int i = 1; i < count; ++i) {
        QWidget* widget = listWidget_->itemWidget(listWidget_->item(i));
        QCheckBox* checkBox = static_cast<QCheckBox*>(widget);
        QString checkBoxString = checkBox->text();
        if(aText.contains(checkBoxString)) {
            checkBox->setChecked(true);
        }
    }
}

void MultiSelectComboBox::ResetSelection() {
    int count = listWidget_->count();

    for (int i = 1; i < count; ++i) {
        QWidget *widget = listWidget_->itemWidget(listWidget_->item(i));
        QCheckBox *checkBox = static_cast<QCheckBox *>(widget);
        checkBox->setChecked(false);
    }
}
