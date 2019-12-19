#ifndef QRADIOBUTTONWITHDATA_H
#define QRADIOBUTTONWITHDATA_H

#include <QRadioButton>

class QRadioButtonWithData : public QRadioButton
{
public:
    QRadioButtonWithData(const QString &text, QWidget *parent = nullptr):QRadioButton(text,parent){};
    QRadioButtonWithData(QWidget *parent = nullptr):QRadioButton(parent){};
    void AddData(QString Title, QString Data);
    QString GetData(QString Title);
    QString GetData(int index);

private:
    QVector<QPair<QString,QString>> _data;
};

#endif // QRADIOBUTTONWITHDATA_H
