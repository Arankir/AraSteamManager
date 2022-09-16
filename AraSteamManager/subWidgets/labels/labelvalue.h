#ifndef LABELVALUE_H
#define LABELVALUE_H

#include <QLabel>
#include <QObject>

class LabelValue : public QLabel {
    Q_OBJECT
public:
    LabelValue(QWidget *aParent = nullptr);
    LabelValue(const QString &aText, QWidget *aParent = nullptr);
};

#endif // LABELVALUE_H
