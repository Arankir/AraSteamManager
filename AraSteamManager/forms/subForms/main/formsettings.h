#ifndef FORMSETTINGS_H
#define FORMSETTINGS_H

#include <QMessageBox>
#include <QDebug>
#include <QFormLayout>
#include <QPair>
#include <QTranslator>
#include "classes/network/requestimage.h"
#include "classes/steamApi/structures/sprofile.h"
#include "classes/steamApi/structures/sgames.h"
#include "subWidgets/withData/qbuttonwithdata.h"
#include "subWidgets/withData/qradiobuttonwithdata.h"

namespace Ui {
class FormSettings;
}

class FormSettings : public QWidget {
    Q_OBJECT

public:
    explicit FormSettings(QWidget *parent = nullptr);
    ~FormSettings();
    bool isInit();
    bool isLoaded();

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

    void comboBoxMaxTableRows(int index);
private:
    Ui::FormSettings *ui;
    Settings _setting;
    QVector<QPair<QString,QList<QString>>> _hiddenGames;
};


#endif // FORMSETTINGS_H
