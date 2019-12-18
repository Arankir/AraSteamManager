#ifndef FORMSETTINGS_H
#define FORMSETTINGS_H

#include <QWidget>
#include <QMessageBox>
#include <QDebug>
#include <QVBoxLayout>
#include <QPair>
#include <class/settings.h>
#include <class/steamapi/Sprofile.h>

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

    void on_CheckBoxVisibleHiddenGames_stateChanged(int arg1);

    void on_RadioButtonDarkTheme_clicked();

    void on_RadioButtonLightTheme_clicked();

    void RadiobuttonHiddenGamesClicked();

private:
    Ui::FormSettings *ui;
    Settings _setting;
    QVector<QPair<QString,QList<QString>>> _hiddenGames;
};


#endif // FORMSETTINGS_H
