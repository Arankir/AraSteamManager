#ifndef QCHECKBOXWITHDATA_H
#define QCHECKBOXWITHDATA_H

#include <QCheckBox>

class QCheckBoxWithData : public QCheckBox
{
public:
    QCheckBoxWithData();
    QCheckBoxWithData(const QString &text, QWidget *parent = nullptr):QCheckBox(text,parent){};
    QCheckBoxWithData(QWidget *parent = nullptr):QCheckBox(parent){};
    void AddData(QString Title, QString Data);
    QString GetData(QString Title);
    QString GetData(int index);

private:
    QVector<QPair<QString,QString>> _data;
};

#endif // QCHECKBOXWITHDATA_H
