#ifndef BUTTONREACHEDTYPE_H
#define BUTTONREACHEDTYPE_H

#include <QPushButton>
#include <QDebug>
#include <QMovie>
#include "classes/common/settings.h"
#include "form.h"

enum class ReachedType {
    reached = 0,
    all = 1,
    notReached = 2,
    none
};

class ButtonReachedType : public QPushButton {
    Q_OBJECT
public:
    ButtonReachedType(QWidget *parent = nullptr);
    ~ButtonReachedType();
    void setType(const ReachedType&);

    ReachedType type() const;

public slots:
    void updateSettings(QFlags<changedSettings> aSettings);

signals:
    void s_radioButtonChange(const ReachedType &type);

protected slots:
    void updateIcons();
    void onButtonClick();

    void stateChanged(const ReachedType &aNewType);

private:
    ReachedType type_ = ReachedType::all;
    QMovie *movie_ = nullptr;
};

#endif // BUTTONREACHEDTYPE_H
