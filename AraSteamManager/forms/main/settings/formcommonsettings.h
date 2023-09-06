#ifndef FORMCOMMONSETTINGS_H
#define FORMCOMMONSETTINGS_H

#include <QWidget>
#include "form.h"

namespace Ui {
class FormCommonSettings;
}

class FormCommonSettings : public Form {
    Q_OBJECT

public:
    explicit FormCommonSettings(QWidget *parent = nullptr);
    void update();
    ~FormCommonSettings();

private slots:
    void init();
    void retranslate() override;
    void updateSettings(QFlags<changedSettings>) override;
    void updateIcons() override;

    void slideProfileSize_ValueChanged(int value);

    void comboBoxThemeIndexChanged(int index);
    void comboBoxLanguageIndexChanged(int index);

private:
    Ui::FormCommonSettings *ui;
};

#endif // FORMCOMMONSETTINGS_H
