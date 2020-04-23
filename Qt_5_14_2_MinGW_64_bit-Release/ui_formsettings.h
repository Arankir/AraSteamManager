/********************************************************************************
** Form generated from reading UI file 'formsettings.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMSETTINGS_H
#define UI_FORMSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormSettings
{
public:
    QGridLayout *gridLayout_7;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QRadioButton *RadioButtonDarkTheme;
    QRadioButton *RadioButtonLightTheme;
    QRadioButton *RadioButtonCustomTheme;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_5;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QLineEdit *LineEditFindGame;
    QPushButton *ButtonFindGame;
    QHBoxLayout *horizontalLayout_3;
    QFrame *FrameProfilesHideGames;
    QTableWidget *TableWidgetGames;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *RadioButtonLanguageEnglish;
    QRadioButton *RadioButtonLanguageRussian;
    QCheckBox *CheckBoxVisibleHiddenGames;
    QCheckBox *CheckBoxVisibleProfileInfo;
    QCheckBox *CheckBoxSaveImage;
    QLabel *labelIcons8;

    void setupUi(QWidget *FormSettings)
    {
        if (FormSettings->objectName().isEmpty())
            FormSettings->setObjectName(QString::fromUtf8("FormSettings"));
        FormSettings->resize(617, 629);
        QFont font;
        font.setFamily(QString::fromUtf8("Ebrima"));
        FormSettings->setFont(font);
        gridLayout_7 = new QGridLayout(FormSettings);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(FormSettings);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        RadioButtonDarkTheme = new QRadioButton(tab);
        RadioButtonDarkTheme->setObjectName(QString::fromUtf8("RadioButtonDarkTheme"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RadioButtonDarkTheme->sizePolicy().hasHeightForWidth());
        RadioButtonDarkTheme->setSizePolicy(sizePolicy);

        gridLayout->addWidget(RadioButtonDarkTheme, 0, 0, 1, 1);

        RadioButtonLightTheme = new QRadioButton(tab);
        RadioButtonLightTheme->setObjectName(QString::fromUtf8("RadioButtonLightTheme"));
        sizePolicy.setHeightForWidth(RadioButtonLightTheme->sizePolicy().hasHeightForWidth());
        RadioButtonLightTheme->setSizePolicy(sizePolicy);

        gridLayout->addWidget(RadioButtonLightTheme, 0, 1, 1, 1);

        RadioButtonCustomTheme = new QRadioButton(tab);
        RadioButtonCustomTheme->setObjectName(QString::fromUtf8("RadioButtonCustomTheme"));
        RadioButtonCustomTheme->setEnabled(false);
        sizePolicy.setHeightForWidth(RadioButtonCustomTheme->sizePolicy().hasHeightForWidth());
        RadioButtonCustomTheme->setSizePolicy(sizePolicy);
        RadioButtonCustomTheme->setText(QString::fromUtf8("\320\241\320\262\320\276\321\217 \321\202\320\265\320\274\320\260 (\320\222 \321\200\320\260\320\267\321\200\320\260\320\261\320\276\321\202\320\272\320\265)"));

        gridLayout->addWidget(RadioButtonCustomTheme, 0, 2, 1, 1);

        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setTitle(QString::fromUtf8("GroupBox"));
        gridLayout_3 = new QGridLayout(groupBox_4);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pushButton_5 = new QPushButton(groupBox_4);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setEnabled(false);
        pushButton_5->setText(QString::fromUtf8("\320\235\320\260\321\201\321\202\321\200\320\276\320\270\321\202\321\214"));

        gridLayout_3->addWidget(pushButton_5, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_4, 2, 0, 1, 3);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_5 = new QVBoxLayout(tab_2);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        LineEditFindGame = new QLineEdit(tab_2);
        LineEditFindGame->setObjectName(QString::fromUtf8("LineEditFindGame"));

        horizontalLayout->addWidget(LineEditFindGame);

        ButtonFindGame = new QPushButton(tab_2);
        ButtonFindGame->setObjectName(QString::fromUtf8("ButtonFindGame"));

        horizontalLayout->addWidget(ButtonFindGame);


        verticalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        FrameProfilesHideGames = new QFrame(tab_2);
        FrameProfilesHideGames->setObjectName(QString::fromUtf8("FrameProfilesHideGames"));
        FrameProfilesHideGames->setMinimumSize(QSize(100, 0));
        FrameProfilesHideGames->setFrameShape(QFrame::StyledPanel);
        FrameProfilesHideGames->setFrameShadow(QFrame::Raised);

        horizontalLayout_3->addWidget(FrameProfilesHideGames);

        TableWidgetGames = new QTableWidget(tab_2);
        if (TableWidgetGames->columnCount() < 4)
            TableWidgetGames->setColumnCount(4);
        TableWidgetGames->setObjectName(QString::fromUtf8("TableWidgetGames"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(TableWidgetGames->sizePolicy().hasHeightForWidth());
        TableWidgetGames->setSizePolicy(sizePolicy1);
        TableWidgetGames->setRowCount(0);
        TableWidgetGames->setColumnCount(4);

        horizontalLayout_3->addWidget(TableWidgetGames);


        verticalLayout_5->addLayout(horizontalLayout_3);

        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        RadioButtonLanguageEnglish = new QRadioButton(groupBox);
        RadioButtonLanguageEnglish->setObjectName(QString::fromUtf8("RadioButtonLanguageEnglish"));
        RadioButtonLanguageEnglish->setText(QString::fromUtf8("English"));

        verticalLayout->addWidget(RadioButtonLanguageEnglish);

        RadioButtonLanguageRussian = new QRadioButton(groupBox);
        RadioButtonLanguageRussian->setObjectName(QString::fromUtf8("RadioButtonLanguageRussian"));
        RadioButtonLanguageRussian->setText(QString::fromUtf8("\320\240\321\203\321\201\321\201\320\272\320\270\320\271"));

        verticalLayout->addWidget(RadioButtonLanguageRussian);


        verticalLayout_5->addWidget(groupBox);

        CheckBoxVisibleHiddenGames = new QCheckBox(tab_2);
        CheckBoxVisibleHiddenGames->setObjectName(QString::fromUtf8("CheckBoxVisibleHiddenGames"));

        verticalLayout_5->addWidget(CheckBoxVisibleHiddenGames);

        CheckBoxVisibleProfileInfo = new QCheckBox(tab_2);
        CheckBoxVisibleProfileInfo->setObjectName(QString::fromUtf8("CheckBoxVisibleProfileInfo"));

        verticalLayout_5->addWidget(CheckBoxVisibleProfileInfo);

        CheckBoxSaveImage = new QCheckBox(tab_2);
        CheckBoxSaveImage->setObjectName(QString::fromUtf8("CheckBoxSaveImage"));

        verticalLayout_5->addWidget(CheckBoxSaveImage);

        labelIcons8 = new QLabel(tab_2);
        labelIcons8->setObjectName(QString::fromUtf8("labelIcons8"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ebrima"));
        font1.setPointSize(10);
        labelIcons8->setFont(font1);
        labelIcons8->setWordWrap(true);
        labelIcons8->setOpenExternalLinks(true);
        labelIcons8->setTextInteractionFlags(Qt::TextBrowserInteraction);

        verticalLayout_5->addWidget(labelIcons8);

        tabWidget->addTab(tab_2, QString());

        gridLayout_7->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(FormSettings);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(FormSettings);
    } // setupUi

    void retranslateUi(QWidget *FormSettings)
    {
        FormSettings->setWindowTitle(QCoreApplication::translate("FormSettings", "Form", nullptr));
        RadioButtonDarkTheme->setText(QCoreApplication::translate("FormSettings", "\320\242\321\221\320\274\320\275\320\260\321\217 \321\202\320\265\320\274\320\260", nullptr));
        RadioButtonLightTheme->setText(QCoreApplication::translate("FormSettings", "\320\241\320\262\320\265\321\202\320\273\320\260\321\217 \321\202\320\265\320\274\320\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("FormSettings", "  \320\242\320\265\320\274\320\260  ", nullptr));
        ButtonFindGame->setText(QCoreApplication::translate("FormSettings", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        groupBox->setTitle(QCoreApplication::translate("FormSettings", "Language", nullptr));
        CheckBoxVisibleHiddenGames->setText(QCoreApplication::translate("FormSettings", "\320\237\321\200\320\270 \320\277\320\276\320\270\321\201\320\272\320\265 \320\277\320\276 \320\270\320\263\321\200\320\260\320\274 \320\276\321\202\320\276\320\261\321\200\320\260\320\266\320\260\321\202\321\214 \321\201\320\272\321\200\321\213\321\202\321\213\320\265 \320\270\320\263\321\200\321\213", nullptr));
        CheckBoxVisibleProfileInfo->setText(QCoreApplication::translate("FormSettings", "\320\237\320\276\320\272\320\260\320\267\321\213\320\262\320\260\321\202\321\214 \320\264\320\276\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214\320\275\321\203\321\216 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\216 \320\277\321\200\320\276\321\204\320\270\320\273\321\217", nullptr));
        CheckBoxSaveImage->setText(QCoreApplication::translate("FormSettings", "\320\220\320\262\321\202\320\276\320\274\320\260\321\202\320\270\321\207\320\265\321\201\320\272\320\270 \321\201\320\276\321\205\321\200\320\260\320\275\321\217\321\202\321\214 \320\272\320\260\321\200\321\202\320\270\320\275\320\272\320\270 \320\275\320\260 \320\272\320\276\320\274\320\277\321\214\321\216\321\202\320\265\321\200\320\265 (\320\264\320\273\321\217 \320\261\320\276\320\273\320\265\320\265 \320\261\321\213\321\201\321\202\321\200\320\276\320\271 \320\267\320\260\320\263\321\200\321\203\320\267\320\272\320\270)", nullptr));
        labelIcons8->setText(QCoreApplication::translate("FormSettings", "<html><head/><body><p>\320\230\320\272\320\276\320\275\320\272\320\270 \320\264\320\273\321\217 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\321\217 \320\261\321\213\320\273\320\270 \320\277\321\200\320\265\320\264\320\276\321\201\321\202\320\260\320\262\320\273\320\265\320\275\321\213 \321\201\320\260\320\271\321\202\320\276\320\274 <a href=https://icons8.ru/icons>https://icons8.ru/icons</a></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("FormSettings", "  \320\237\321\200\320\276\321\207\320\270\320\265 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270  ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormSettings: public Ui_FormSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSETTINGS_H
