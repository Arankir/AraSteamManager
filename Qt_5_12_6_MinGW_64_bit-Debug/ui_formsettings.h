/********************************************************************************
** Form generated from reading UI file 'formsettings.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
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
    QLabel *labelIcons8;
    QWidget *tab_3;
    QGridLayout *gridLayout_9;
    QGroupBox *groupBox_9;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_16;
    QLabel *label_17;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_14;
    QGroupBox *groupBox_10;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_22;
    QLabel *label_24;
    QGroupBox *groupBox_11;
    QVBoxLayout *verticalLayout_14;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_8;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_18;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_12;
    QLabel *label;
    QLabel *label_3;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_27;

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

        gridLayout->addWidget(RadioButtonCustomTheme, 0, 2, 1, 1);

        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_3 = new QGridLayout(groupBox_4);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pushButton_5 = new QPushButton(groupBox_4);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setEnabled(false);

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

        verticalLayout->addWidget(RadioButtonLanguageEnglish);

        RadioButtonLanguageRussian = new QRadioButton(groupBox);
        RadioButtonLanguageRussian->setObjectName(QString::fromUtf8("RadioButtonLanguageRussian"));

        verticalLayout->addWidget(RadioButtonLanguageRussian);


        verticalLayout_5->addWidget(groupBox);

        CheckBoxVisibleHiddenGames = new QCheckBox(tab_2);
        CheckBoxVisibleHiddenGames->setObjectName(QString::fromUtf8("CheckBoxVisibleHiddenGames"));

        verticalLayout_5->addWidget(CheckBoxVisibleHiddenGames);

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
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_9 = new QGridLayout(tab_3);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        groupBox_9 = new QGroupBox(tab_3);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        verticalLayout_12 = new QVBoxLayout(groupBox_9);
        verticalLayout_12->setSpacing(1);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(1, 1, 1, 1);
        label_19 = new QLabel(groupBox_9);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        verticalLayout_12->addWidget(label_19);

        label_20 = new QLabel(groupBox_9);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        verticalLayout_12->addWidget(label_20);

        label_21 = new QLabel(groupBox_9);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        verticalLayout_12->addWidget(label_21);


        gridLayout_9->addWidget(groupBox_9, 0, 1, 1, 1);

        groupBox_7 = new QGroupBox(tab_3);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        verticalLayout_8 = new QVBoxLayout(groupBox_7);
        verticalLayout_8->setSpacing(1);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(1, 1, 1, 1);
        label_16 = new QLabel(groupBox_7);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        verticalLayout_8->addWidget(label_16);

        label_17 = new QLabel(groupBox_7);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        verticalLayout_8->addWidget(label_17);


        gridLayout_9->addWidget(groupBox_7, 1, 1, 1, 1);

        groupBox_6 = new QGroupBox(tab_3);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        verticalLayout_6 = new QVBoxLayout(groupBox_6);
        verticalLayout_6->setSpacing(1);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(1, 1, 1, 1);
        label_14 = new QLabel(groupBox_6);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        verticalLayout_6->addWidget(label_14);


        gridLayout_9->addWidget(groupBox_6, 2, 1, 1, 1);

        groupBox_10 = new QGroupBox(tab_3);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        verticalLayout_13 = new QVBoxLayout(groupBox_10);
        verticalLayout_13->setSpacing(1);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(1, 1, 1, 1);
        label_22 = new QLabel(groupBox_10);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        verticalLayout_13->addWidget(label_22);

        label_24 = new QLabel(groupBox_10);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        verticalLayout_13->addWidget(label_24);


        gridLayout_9->addWidget(groupBox_10, 3, 1, 1, 1);

        groupBox_11 = new QGroupBox(tab_3);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        verticalLayout_14 = new QVBoxLayout(groupBox_11);
        verticalLayout_14->setSpacing(1);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        verticalLayout_14->setContentsMargins(1, 1, 1, 1);

        gridLayout_9->addWidget(groupBox_11, 4, 1, 1, 1);

        groupBox_2 = new QGroupBox(tab_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setSpacing(1);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(1, 1, 1, 1);

        gridLayout_9->addWidget(groupBox_2, 5, 1, 1, 1);

        groupBox_8 = new QGroupBox(tab_3);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        verticalLayout_11 = new QVBoxLayout(groupBox_8);
        verticalLayout_11->setSpacing(1);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(1, 1, 1, 1);
        label_18 = new QLabel(groupBox_8);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        verticalLayout_11->addWidget(label_18);


        gridLayout_9->addWidget(groupBox_8, 4, 0, 2, 1);

        groupBox_5 = new QGroupBox(tab_3);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        verticalLayout_4 = new QVBoxLayout(groupBox_5);
        verticalLayout_4->setSpacing(1);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(1, 1, 1, 1);
        label_12 = new QLabel(groupBox_5);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_4->addWidget(label_12);

        label = new QLabel(groupBox_5);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_4->addWidget(label);

        label_3 = new QLabel(groupBox_5);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_4->addWidget(label_3);


        gridLayout_9->addWidget(groupBox_5, 2, 0, 2, 1);

        groupBox_3 = new QGroupBox(tab_3);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_9 = new QVBoxLayout(groupBox_3);
        verticalLayout_9->setSpacing(1);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(1, 1, 1, 1);
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_9->addWidget(label_8);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_9->addWidget(label_9);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_9->addWidget(label_2);

        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_9->addWidget(label_4);

        label_27 = new QLabel(groupBox_3);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        verticalLayout_9->addWidget(label_27);


        gridLayout_9->addWidget(groupBox_3, 0, 0, 2, 1);

        tabWidget->addTab(tab_3, QString());

        gridLayout_7->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(FormSettings);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(FormSettings);
    } // setupUi

    void retranslateUi(QWidget *FormSettings)
    {
        FormSettings->setWindowTitle(QApplication::translate("FormSettings", "Form", nullptr));
        RadioButtonDarkTheme->setText(QApplication::translate("FormSettings", "\320\242\321\221\320\274\320\275\320\260\321\217 \321\202\320\265\320\274\320\260", nullptr));
        RadioButtonLightTheme->setText(QApplication::translate("FormSettings", "\320\241\320\262\320\265\321\202\320\273\320\260\321\217 \321\202\320\265\320\274\320\260", nullptr));
        RadioButtonCustomTheme->setText(QApplication::translate("FormSettings", "\320\241\320\262\320\276\321\217 \321\202\320\265\320\274\320\260 (\320\222 \321\200\320\260\320\267\321\200\320\260\320\261\320\276\321\202\320\272\320\265)", nullptr));
        groupBox_4->setTitle(QApplication::translate("FormSettings", "GroupBox", nullptr));
        pushButton_5->setText(QApplication::translate("FormSettings", "\320\235\320\260\321\201\321\202\321\200\320\276\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("FormSettings", "  \320\242\320\265\320\274\320\260  ", nullptr));
        ButtonFindGame->setText(QApplication::translate("FormSettings", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        groupBox->setTitle(QApplication::translate("FormSettings", "Language", nullptr));
        RadioButtonLanguageEnglish->setText(QApplication::translate("FormSettings", "English", nullptr));
        RadioButtonLanguageRussian->setText(QApplication::translate("FormSettings", "\320\240\321\203\321\201\321\201\320\272\320\270\320\271", nullptr));
        CheckBoxVisibleHiddenGames->setText(QApplication::translate("FormSettings", "\320\237\321\200\320\270 \320\277\320\276\320\270\321\201\320\272\320\265 \320\277\320\276 \320\270\320\263\321\200\320\260\320\274 \320\276\321\202\320\276\320\261\321\200\320\260\320\266\320\260\321\202\321\214 \321\201\320\272\321\200\321\213\321\202\321\213\320\265 \320\270\320\263\321\200\321\213", nullptr));
        labelIcons8->setText(QApplication::translate("FormSettings", "<html><head/><body><p>\320\230\320\272\320\276\320\275\320\272\320\270 \320\264\320\273\321\217 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\321\217 \320\261\321\213\320\273\320\270 \320\277\321\200\320\265\320\264\320\276\321\201\321\202\320\260\320\262\320\273\320\265\320\275\321\213 \321\201\320\260\320\271\321\202\320\276\320\274 <a href=https://icons8.ru/icons>https://icons8.ru/icons</a></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("FormSettings", "  \320\237\321\200\320\276\321\207\320\270\320\265 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270  ", nullptr));
        groupBox_9->setTitle(QApplication::translate("FormSettings", "\320\230\320\267\320\261\321\200\320\260\320\275\320\275\320\276\320\265", nullptr));
        label_19->setText(QApplication::translate("FormSettings", "\320\237\320\265\321\200\320\265\321\205\320\276\320\264 \320\272 \320\270\320\267\320\261\321\200\320\260\320\275\320\275\321\213\320\274 \320\270\320\263\321\200\320\260\320\274", nullptr));
        label_20->setText(QApplication::translate("FormSettings", "\320\237\320\265\321\200\320\265\321\205\320\276\320\264 \320\272 \320\270\320\267\320\261\321\200\320\260\320\275\320\275\321\213\320\274 \320\264\321\200\321\203\320\267\321\214\321\217\320\274", nullptr));
        label_21->setText(QApplication::translate("FormSettings", "\320\237\320\265\321\200\320\265\321\205\320\276\320\264 \320\272 \320\270\320\267\320\261\321\200\320\260\320\275\320\275\321\213\320\274 \320\264\320\276\321\201\321\202\320\270\320\266\320\265\320\275\320\270\321\217\320\274", nullptr));
        groupBox_7->setTitle(QApplication::translate("FormSettings", "\320\224\320\276\321\201\321\202\320\270\320\266\320\265\320\275\320\270\321\217", nullptr));
        label_16->setText(QApplication::translate("FormSettings", "\321\200\320\265\320\264\320\270\320\267\320\260\320\271\320\275", nullptr));
        label_17->setText(QApplication::translate("FormSettings", "\320\267\320\260\320\274\320\265\321\202\320\272\320\270 \320\272 \320\264\320\276\321\201\321\202\320\270\320\266\320\265\320\275\320\270\321\217\320\274 \320\270 \320\270\320\263\321\200\320\260\320\274", nullptr));
        groupBox_6->setTitle(QApplication::translate("FormSettings", "\320\230\320\263\321\200\321\213", nullptr));
        label_14->setText(QApplication::translate("FormSettings", "\320\223\321\200\321\203\320\277\320\277\321\213 \320\270\320\263\321\200", nullptr));
        groupBox_10->setTitle(QApplication::translate("FormSettings", "\320\237\321\200\320\276\321\207\320\265\320\265", nullptr));
        label_22->setText(QApplication::translate("FormSettings", "\320\240\320\265\321\201\320\260\320\271\320\267 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\276\320\262 \320\277\321\200\320\270 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\270 \320\276\320\272\320\275\320\260", nullptr));
        label_24->setText(QApplication::translate("FormSettings", "\320\235\320\260\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \321\201\320\270\321\201\321\202\320\265\320\274\321\203 \320\273\320\276\320\263\320\276\320\262 \320\264\320\273\321\217 \320\272\321\200\320\260\321\210\320\265\320\271", nullptr));
        groupBox_11->setTitle(QApplication::translate("FormSettings", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\320\270", nullptr));
        groupBox_2->setTitle(QApplication::translate("FormSettings", "\320\241\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265", nullptr));
        groupBox_8->setTitle(QApplication::translate("FormSettings", "\320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260", nullptr));
        label_18->setText(QApplication::translate("FormSettings", "\320\241\321\200\320\260\320\262\320\275\320\270\321\202\321\214 \321\201 \320\264\321\200\321\203\320\267\321\214\321\217\320\274\320\270", nullptr));
        groupBox_5->setTitle(QApplication::translate("FormSettings", "\320\224\321\200\321\203\320\267\321\214\321\217", nullptr));
        label_12->setText(QApplication::translate("FormSettings", "\320\223\321\200\321\203\320\277\320\277\321\213 \320\264\321\200\321\203\320\267\320\265\320\271", nullptr));
        label->setText(QApplication::translate("FormSettings", "\320\270\321\201\320\277\321\200\320\260\320\262\320\270\321\202\321\214 \320\261\320\260\320\263 \321\201 \320\272\320\275\320\276\320\277\320\272\320\276\320\271 \"\320\270\320\267\320\261\321\200\320\260\320\275\320\275\321\213\320\265\" \320\277\321\200\320\270 \320\276\321\202\321\201\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\275\320\276\320\271 \321\202\320\260\320\261\320\273\320\270\321\206\320\265", nullptr));
        label_3->setText(QApplication::translate("FormSettings", "\321\201\320\264\320\265\320\273\320\260\321\202\321\214 \320\277\320\276\320\273\320\276\321\201\321\203 \320\267\320\260\320\263\321\200\321\203\320\267\320\272\320\270 \320\277\321\200\320\270 \320\277\320\265\321\200\320\265\321\205\320\276\320\264\320\265 \320\275\320\260 \320\277\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
        groupBox_3->setTitle(QApplication::translate("FormSettings", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        label_8->setText(QApplication::translate("FormSettings", "\320\224\320\260\320\275\320\275\321\213\320\265 \320\264\320\273\321\217 \320\264\320\276\320\275\320\260\321\202\320\276\320\262", nullptr));
        label_9->setText(QApplication::translate("FormSettings", "\320\244\320\276\321\200\320\274\320\260\321\202 \320\264\320\260\321\202", nullptr));
        label_2->setText(QApplication::translate("FormSettings", "\320\222\321\213\320\263\321\200\321\203\320\267\320\272\320\260 \320\275\320\260\321\201\321\202\321\200\320\276\320\265\320\272, \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\320\271, \320\277\321\200\320\276\321\207\320\265\320\263\320\276", nullptr));
        label_4->setText(QApplication::translate("FormSettings", "\320\241\320\261\321\200\320\276\321\201 \320\272 \320\267\320\260\320\262\320\276\320\264\321\201\320\272\320\270\320\274 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260\320\274", nullptr));
        label_27->setText(QApplication::translate("FormSettings", "\320\230\321\201\320\277\321\200\320\260\320\262\320\270\321\202\321\214 \320\277\321\200\320\276\320\261\320\273\320\265\320\274\321\203 \321\201 \320\275\320\265\321\200\320\265\321\201\320\260\320\271\320\267\321\217\321\211\320\265\320\271\321\201\321\217 ScrollArea \321\201 \321\204\320\260\320\271\320\273\320\260\320\274\320\270 \321\201\320\272\321\200\321\213\321\202\321\213\321\205 \320\270\320\263\321\200", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("FormSettings", "  \320\237\320\273\320\260\320\275\321\213 (\320\237\320\276\321\202\320\276\320\274 \321\203\320\264\320\260\320\273\321\216)  ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormSettings: public Ui_FormSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSETTINGS_H
