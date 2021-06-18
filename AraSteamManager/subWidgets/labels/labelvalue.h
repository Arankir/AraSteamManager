#ifndef LABELVALUE_H
#define LABELVALUE_H

#include <QLabel>
#include <QObject>

class LabelValue : public QLabel
{
    Q_OBJECT
public:
    LabelValue(QWidget *parent = nullptr): QLabel(parent) {};
};

#endif // LABELVALUE_H
