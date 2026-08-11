#ifndef FORMSETTINGS_H
#define FORMSETTINGS_H

#include "form.h"

namespace Ui {
class FormSettings;
}

class FormSettings : public Form {
    Q_OBJECT

public:
    explicit FormSettings(QWidget *parent = nullptr);
    void update();
    ~FormSettings();
    void init();
    bool isInit();
    bool isLoaded();

private slots:
    void retranslate() override;
    void updateSettings(QFlags<changedSettings>) override;
    void updateIcons() override;

private:
    Ui::FormSettings *ui;

    bool isInit_ = false;
};


#endif // FORMSETTINGS_H
