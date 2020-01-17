#ifndef QRADIOBUTTONWITHDATA_H
#define QRADIOBUTTONWITHDATA_H

#include <QRadioButton>

enum class ReachedType{
    all,
    reached,
    notReached,
    none
};

class QRadioButtonWithData : public QRadioButton
{
public:
    QRadioButtonWithData(const QString &text, QWidget *parent = nullptr):QRadioButton(text,parent){};
    QRadioButtonWithData(QWidget *parent = nullptr):QRadioButton(parent){};
    void AddData(QString Title, QString Data);
    QString GetData(QString Title);
    QString GetData(int index);
    void SetReachedType(ReachedType Aset) {_type=Aset;}
    ReachedType GetReachedType() {return _type;}


private:
    QVector<QPair<QString,QString>> _data;
    ReachedType _type=ReachedType::none;
};

#endif // QRADIOBUTTONWITHDATA_H
