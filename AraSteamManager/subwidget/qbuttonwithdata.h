#ifndef QBUTTONWITHDATA_H
#define QBUTTONWITHDATA_H

#include <QPushButton>

class QButtonWithData : public QPushButton
{
public:
    QButtonWithData(const QString &text, QWidget *parent = 0) : QPushButton(text, parent) {};
    QButtonWithData(QWidget *parent = 0) : QPushButton(parent) {};
    void addData(QString title, QString data);
    QString getData(QString title) const;
    QString getData(int index) const;

private:
    QVector<QPair<QString, QString>> _data;
};

#endif // QBUTTONWITHDATA_H
