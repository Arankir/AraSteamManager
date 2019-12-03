#ifndef FORMSETTINGS_H
#define FORMSETTINGS_H

#include <QWidget>
#include <QMessageBox>
#include <QDebug>
#include <class/settings.h>

namespace Ui {
class FormSettings;
}

class FormSettings : public QWidget
{
    Q_OBJECT

public:
    explicit FormSettings(QWidget *parent = nullptr);
    ~FormSettings();

private slots:
    void InitComponents();

    void on_RadioButtonLanguageEnglish_clicked();

    void on_RadioButtonLanguageRussian_clicked();

private:
    Ui::FormSettings *ui;
    Settings Setting;
};

#endif // FORMSETTINGS_H
