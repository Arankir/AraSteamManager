#ifndef QCOMBOBOXWITHDATA_H
#define QCOMBOBOXWITHDATA_H

#include <QComboBox>

class QComboBoxWithData : public QComboBox
{
public:
    QComboBoxWithData(QWidget *parent = nullptr):QComboBox(parent){};
    void AddData(QString Title, QString Data);
    QString GetData(QString Title);
    QString GetData(int index);

private:
    QVector<QPair<QString,QString>> _data;
};

#endif // QCOMBOBOXWITHDATA_H
