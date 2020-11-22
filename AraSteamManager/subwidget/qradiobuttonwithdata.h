#ifndef QRADIOBUTTONWITHDATA_H
#define QRADIOBUTTONWITHDATA_H

#include <QRadioButton>

class QRadioButtonWithData : public QRadioButton {
public:
    QRadioButtonWithData(const QString &text, QWidget *parent = nullptr): QRadioButton(text, parent) {}
    QRadioButtonWithData(QWidget *parent = nullptr): QRadioButton(parent) {}
    void addData(QString title, QString data);
    QString getData(QString title) const;
    QString getData(int index) const;

private:
    QVector<QPair<QString, QString>> _data;
};

#endif // QRADIOBUTTONWITHDATA_H
