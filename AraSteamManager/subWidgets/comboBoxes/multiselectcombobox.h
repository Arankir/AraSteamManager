#ifndef MULTISELECTCOMBOBOX_H
#define MULTISELECTCOMBOBOX_H
#pragma once

#include <QComboBox>
#include <QListWidget>

class MultiSelectComboBox : public QComboBox {
    Q_OBJECT
public:
    MultiSelectComboBox(QWidget *parent = nullptr);
    void addItem(const QString &text, const QVariant &userData = QVariant());
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
    void setCurrentText(const QString &text);
    void setCurrentText(const QStringList &text);

protected:
    void wheelEvent(QWheelEvent *wheelEvent) override;
    bool eventFilter(QObject *object, QEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

    QString getCurrentText();
private:
    void stateChanged(int state);
    void onSearch(const QString &searchString);
    void itemClicked(int index);

    QListWidget* listWidget_;
    QLineEdit* lineEdit_;
    QLineEdit* searchBar_;
};

#endif // MULTISELECTCOMBOBOX_H
