#ifndef QBUTTONWITHDATA_H
#define QBUTTONWITHDATA_H

#include <QPushButton>

class QButtonWithData : public QPushButton
{
public:
    QButtonWithData(const QString& text, QWidget* parent = 0 ):QPushButton(text,parent){};
    void AddData(QString Title, QString Data);
    QString GetData(QString Title);
    QString GetData(int index);

private:
    QVector<QPair<QString,QString>> _data;
};

#endif // QBUTTONWITHDATA_H
