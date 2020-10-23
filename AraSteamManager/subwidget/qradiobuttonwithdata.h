#ifndef QRADIOBUTTONWITHDATA_H
#define QRADIOBUTTONWITHDATA_H

#include <QRadioButton>

enum class ReachedType {
    all,
    reached,
    notReached,
    none
};

class QRadioButtonWithData : public QRadioButton {
public:
    QRadioButtonWithData(const QString &text, QWidget *parent = nullptr): QRadioButton(text, parent) {}
    QRadioButtonWithData(QWidget *parent = nullptr): QRadioButton(parent) {}
    void addData(QString title, QString data);
    QString getData(QString title) const;
    QString getData(int index) const;

    void setReachedType(ReachedType type) {_type = type;}
    ReachedType getReachedType() {return _type;}


private:
    QVector<QPair<QString, QString>> _data;
    ReachedType _type = ReachedType::none;
};

#endif // QRADIOBUTTONWITHDATA_H
