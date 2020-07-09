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

class FormSettings : public QWidget {
    Q_OBJECT

public:
    explicit FormSettings(QWidget *parent = nullptr);
    ~FormSettings();

signals:
    void s_return_to_profile(QWidget*);
    void s_updateSettings();

private slots:
    void changeEvent(QEvent *event);
    void initComponents();

    void radioButtonLanguageEnglish_Clicked();
    void radioButtonLanguageRussian_Clicked();

    void radioButtonDarkTheme_Clicked();
    void radioButtonLightTheme_Clicked();

    void radioButtonHiddenGames_Clicked();

    void achievementsClicked();
    void hideClicked();
    void retranslate();

    void checkBoxVisibleHiddenGames_StateChanged(int arg1);
    void checkBoxSaveImage_StateChanged(int arg1);

    void slideProfileSize_ValueChanged(int value);

private:
    Ui::FormSettings *ui;
    QString _theme = "white";
    Settings _setting;
    QVector<QPair<QString,QList<QString>>> _hiddenGames;
};


#endif // FORMSETTINGS_H
