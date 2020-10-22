#ifndef QCOMBOBOXWITHDATA_H
#define QCOMBOBOXWITHDATA_H

#include <QComboBox>

class QComboBoxWithData : public QComboBox
{
public:
    QComboBoxWithData(QWidget *parent = nullptr) : QComboBox(parent) {};
    void addData(QString title, QString data);
    QString getData(QString title);
    QString getData(int index);

private:
    QVector<QPair<QString, QString>> _data;
};

#endif // QCOMBOBOXWITHDATA_H
