#ifndef FORMSETTINGS_H
#define FORMSETTINGS_H

#include <QWidget>
#include <QMessageBox>
#include <QDebug>
#include <QFormLayout>
#include <QPair>
#include <QTranslator>
#include <class/settings.h>
#include <class/Network/requestimage.h>
#include <class/steamapi/Sprofile.h>
#include <class/steamapi/Sgames.h>
#include <subwidget/qbuttonwithdata.h>
#include <subwidget/qradiobuttonwithdata.h>

namespace Ui {
class FormSettings;
}

class FormSettings : public QWidget
{
    Q_OBJECT

public:
    explicit FormSettings(QWidget *parent = nullptr);
    ~FormSettings();

signals:
    void s_return_to_profile(QWidget*);
    void s_updateSettings();

private slots:
    void changeEvent(QEvent *event);
    void InitComponents();

    void RadioButtonLanguageEnglish_Clicked();
    void RadioButtonLanguageRussian_Clicked();

    void RadioButtonDarkTheme_Clicked();
    void RadioButtonLightTheme_Clicked();

    void RadioButtonHiddenGames_Clicked();

    void AchievementsClicked();
    void HideClicked();
    void Retranslate();

    void CheckBoxVisibleHiddenGames_StateChanged(int arg1);
    void CheckBoxSaveImage_StateChanged(int arg1);

    void SlideProfileSize_ValueChanged(int value);

private:
    Ui::FormSettings *ui;
    QString _theme="white";
    Settings _setting;
    QVector<QPair<QString,QList<QString>>> _hiddenGames;
};


#endif // FORMSETTINGS_H
