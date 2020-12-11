#ifndef QCHECKBOXWITHDATA_H
#define QCHECKBOXWITHDATA_H

#include <QCheckBox>

class QCheckBoxWithData : public QCheckBox
{
public:
    QCheckBoxWithData();
    QCheckBoxWithData(const QString &text, QWidget *parent = nullptr) : QCheckBox(text, parent) {};
    QCheckBoxWithData(QWidget *parent = nullptr) : QCheckBox(parent) {};
    void addData(QString title, QString data);
    void clearData();
    QString getData(QString title) const;
    QString getData(int index) const;

private:
    QVector<QPair<QString, QString>> _data;
};

#endif // QCHECKBOXWITHDATA_H
