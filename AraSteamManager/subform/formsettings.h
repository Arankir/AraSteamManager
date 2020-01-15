#ifndef FORMSETTINGS_H
#define FORMSETTINGS_H

#include <QWidget>
#include <QMessageBox>
#include <QDebug>
#include <QFormLayout>
#include <QPair>
#include <QTranslator>
#include <class/settings.h>
#include <class/imagerequest.h>
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

private slots:
    void InitComponents();
    void changeEvent(QEvent *event);

    void on_RadioButtonLanguageEnglish_clicked();

    void on_RadioButtonLanguageRussian_clicked();

    void on_CheckBoxVisibleHiddenGames_stateChanged(int arg1);

    void on_RadioButtonDarkTheme_clicked();

    void on_RadioButtonLightTheme_clicked();

    void RadiobuttonHiddenGamesClicked();

    void OnResultImage(ImageRequest *);
    void AchievementsClicked();
    void HideClicked();
    void Retranslate();

private:
    Ui::FormSettings *ui;
    QString _theme="white";
    Settings _setting;
    QVector<QPair<QString,QList<QString>>> _hiddenGames;
};


#endif // FORMSETTINGS_H
