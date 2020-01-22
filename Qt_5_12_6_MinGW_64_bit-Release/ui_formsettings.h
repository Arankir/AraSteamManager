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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
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
    QGridLayout *gridLayout_6;
    QRadioButton *RadioButtonDarkTheme;
    QRadioButton *RadioButtonLightTheme;
    QGroupBox *GroupBoxDarkTheme;
    QVBoxLayout *verticalLayout_5;
    QComboBox *comboBox;
    QScrollArea *scrollArea_5;
    QWidget *scrollAreaWidgetContents_7;
    QGridLayout *gridLayout;
    QCheckBox *checkBox_8;
    QRadioButton *radioButton;
    QPushButton *pushButton;
    QCheckBox *checkBox;
    QLineEdit *lineEdit;
    QRadioButton *radioButton_7;
    QScrollArea *scrollArea_6;
    QWidget *scrollAreaWidgetContents_8;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_2;
    QCheckBox *checkBox_2;
    QRadioButton *radioButton_2;
    QCheckBox *checkBox_7;
    QRadioButton *radioButton_8;
    QGroupBox *GroupBoxWhiteTheme;
    QVBoxLayout *verticalLayout_7;
    QScrollArea *scrollArea_7;
    QWidget *scrollAreaWidgetContents_9;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_3;
    QCheckBox *checkBox_3;
    QRadioButton *radioButton_9;
    QCheckBox *checkBox_9;
    QRadioButton *radioButton_3;
    QScrollArea *scrollArea_8;
    QWidget *scrollAreaWidgetContents_10;
    QGridLayout *gridLayout_5;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit_4;
    QCheckBox *checkBox_4;
    QRadioButton *radioButton_4;
    QCheckBox *checkBox_10;
    QRadioButton *radioButton_10;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_5;
    QRadioButton *RadioButtonCustomTheme;
    QWidget *tab_2;
    QGridLayout *gridLayout_8;
    QHBoxLayout *horizontalLayout_2;
    QScrollArea *ScrollAreaProfilesHideGames;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout;
    QLineEdit *LineEditFindGame;
    QPushButton *ButtonFindGame;
    QTableWidget *TableWidgetGames;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *RadioButtonLanguageEnglish;
    QRadioButton *RadioButtonLanguageRussian;
    QCheckBox *CheckBoxVisibleHiddenGames;
    QLabel *label_10;
    QWidget *tab_3;
    QGridLayout *gridLayout_9;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_13;
    QGroupBox *groupBox_11;
    QVBoxLayout *verticalLayout_14;
    QLabel *label_23;
    QLabel *label_26;
    QGroupBox *groupBox_9;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_14;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_12;
    QLabel *label;
    QLabel *label_3;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_16;
    QLabel *label_17;
    QGroupBox *groupBox_10;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_22;
    QLabel *label_24;
    QGroupBox *groupBox_8;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_18;
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
        FormSettings->resize(1034, 629);
        gridLayout_7 = new QGridLayout(FormSettings);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(FormSettings);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_6 = new QGridLayout(tab);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        RadioButtonDarkTheme = new QRadioButton(tab);
        RadioButtonDarkTheme->setObjectName(QString::fromUtf8("RadioButtonDarkTheme"));

        gridLayout_6->addWidget(RadioButtonDarkTheme, 0, 0, 1, 1);

        RadioButtonLightTheme = new QRadioButton(tab);
        RadioButtonLightTheme->setObjectName(QString::fromUtf8("RadioButtonLightTheme"));

        gridLayout_6->addWidget(RadioButtonLightTheme, 0, 1, 1, 1);

        GroupBoxDarkTheme = new QGroupBox(tab);
        GroupBoxDarkTheme->setObjectName(QString::fromUtf8("GroupBoxDarkTheme"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GroupBoxDarkTheme->sizePolicy().hasHeightForWidth());
        GroupBoxDarkTheme->setSizePolicy(sizePolicy);
        GroupBoxDarkTheme->setMaximumSize(QSize(16777215, 250));
        verticalLayout_5 = new QVBoxLayout(GroupBoxDarkTheme);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        comboBox = new QComboBox(GroupBoxDarkTheme);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout_5->addWidget(comboBox);

        scrollArea_5 = new QScrollArea(GroupBoxDarkTheme);
        scrollArea_5->setObjectName(QString::fromUtf8("scrollArea_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollArea_5->sizePolicy().hasHeightForWidth());
        scrollArea_5->setSizePolicy(sizePolicy1);
        scrollArea_5->setWidgetResizable(true);
        scrollAreaWidgetContents_7 = new QWidget();
        scrollAreaWidgetContents_7->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_7"));
        scrollAreaWidgetContents_7->setGeometry(QRect(0, 0, 463, 94));
        gridLayout = new QGridLayout(scrollAreaWidgetContents_7);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        checkBox_8 = new QCheckBox(scrollAreaWidgetContents_7);
        checkBox_8->setObjectName(QString::fromUtf8("checkBox_8"));
        sizePolicy.setHeightForWidth(checkBox_8->sizePolicy().hasHeightForWidth());
        checkBox_8->setSizePolicy(sizePolicy);
        checkBox_8->setChecked(true);

        gridLayout->addWidget(checkBox_8, 2, 0, 1, 1);

        radioButton = new QRadioButton(scrollAreaWidgetContents_7);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setChecked(true);

        gridLayout->addWidget(radioButton, 2, 1, 1, 1);

        pushButton = new QPushButton(scrollAreaWidgetContents_7);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(25, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/white/program/white/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        checkBox = new QCheckBox(scrollAreaWidgetContents_7);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        sizePolicy.setHeightForWidth(checkBox->sizePolicy().hasHeightForWidth());
        checkBox->setSizePolicy(sizePolicy);

        gridLayout->addWidget(checkBox, 1, 0, 1, 1);

        lineEdit = new QLineEdit(scrollAreaWidgetContents_7);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setMinimumSize(QSize(25, 0));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        radioButton_7 = new QRadioButton(scrollAreaWidgetContents_7);
        radioButton_7->setObjectName(QString::fromUtf8("radioButton_7"));
        radioButton_7->setChecked(false);

        gridLayout->addWidget(radioButton_7, 1, 1, 1, 1);

        scrollArea_5->setWidget(scrollAreaWidgetContents_7);

        verticalLayout_5->addWidget(scrollArea_5);

        scrollArea_6 = new QScrollArea(GroupBoxDarkTheme);
        scrollArea_6->setObjectName(QString::fromUtf8("scrollArea_6"));
        sizePolicy1.setHeightForWidth(scrollArea_6->sizePolicy().hasHeightForWidth());
        scrollArea_6->setSizePolicy(sizePolicy1);
        scrollArea_6->setWidgetResizable(true);
        scrollAreaWidgetContents_8 = new QWidget();
        scrollAreaWidgetContents_8->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_8"));
        scrollAreaWidgetContents_8->setGeometry(QRect(0, 0, 463, 94));
        gridLayout_4 = new QGridLayout(scrollAreaWidgetContents_8);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        pushButton_2 = new QPushButton(scrollAreaWidgetContents_8);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setMinimumSize(QSize(25, 0));
        pushButton_2->setIcon(icon);

        gridLayout_4->addWidget(pushButton_2, 0, 0, 1, 1);

        lineEdit_2 = new QLineEdit(scrollAreaWidgetContents_8);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy);
        lineEdit_2->setMinimumSize(QSize(25, 0));

        gridLayout_4->addWidget(lineEdit_2, 0, 1, 1, 1);

        checkBox_2 = new QCheckBox(scrollAreaWidgetContents_8);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setEnabled(false);
        sizePolicy.setHeightForWidth(checkBox_2->sizePolicy().hasHeightForWidth());
        checkBox_2->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(checkBox_2, 1, 0, 1, 1);

        radioButton_2 = new QRadioButton(scrollAreaWidgetContents_8);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setEnabled(false);

        gridLayout_4->addWidget(radioButton_2, 1, 1, 1, 1);

        checkBox_7 = new QCheckBox(scrollAreaWidgetContents_8);
        checkBox_7->setObjectName(QString::fromUtf8("checkBox_7"));
        checkBox_7->setEnabled(false);
        sizePolicy.setHeightForWidth(checkBox_7->sizePolicy().hasHeightForWidth());
        checkBox_7->setSizePolicy(sizePolicy);
        checkBox_7->setChecked(true);

        gridLayout_4->addWidget(checkBox_7, 2, 0, 1, 1);

        radioButton_8 = new QRadioButton(scrollAreaWidgetContents_8);
        radioButton_8->setObjectName(QString::fromUtf8("radioButton_8"));
        radioButton_8->setEnabled(false);
        radioButton_8->setChecked(true);

        gridLayout_4->addWidget(radioButton_8, 2, 1, 1, 1);

        scrollArea_6->setWidget(scrollAreaWidgetContents_8);

        verticalLayout_5->addWidget(scrollArea_6);


        gridLayout_6->addWidget(GroupBoxDarkTheme, 1, 0, 1, 1);

        GroupBoxWhiteTheme = new QGroupBox(tab);
        GroupBoxWhiteTheme->setObjectName(QString::fromUtf8("GroupBoxWhiteTheme"));
        sizePolicy.setHeightForWidth(GroupBoxWhiteTheme->sizePolicy().hasHeightForWidth());
        GroupBoxWhiteTheme->setSizePolicy(sizePolicy);
        GroupBoxWhiteTheme->setMaximumSize(QSize(16777215, 250));
        verticalLayout_7 = new QVBoxLayout(GroupBoxWhiteTheme);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        scrollArea_7 = new QScrollArea(GroupBoxWhiteTheme);
        scrollArea_7->setObjectName(QString::fromUtf8("scrollArea_7"));
        sizePolicy1.setHeightForWidth(scrollArea_7->sizePolicy().hasHeightForWidth());
        scrollArea_7->setSizePolicy(sizePolicy1);
        scrollArea_7->setWidgetResizable(true);
        scrollAreaWidgetContents_9 = new QWidget();
        scrollAreaWidgetContents_9->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_9"));
        scrollAreaWidgetContents_9->setGeometry(QRect(0, 0, 495, 112));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents_9);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton_3 = new QPushButton(scrollAreaWidgetContents_9);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setMinimumSize(QSize(25, 0));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/black/program/black/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon1);

        gridLayout_2->addWidget(pushButton_3, 0, 0, 1, 1);

        lineEdit_3 = new QLineEdit(scrollAreaWidgetContents_9);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        sizePolicy.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy);
        lineEdit_3->setMinimumSize(QSize(25, 0));

        gridLayout_2->addWidget(lineEdit_3, 0, 1, 1, 1);

        checkBox_3 = new QCheckBox(scrollAreaWidgetContents_9);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        sizePolicy.setHeightForWidth(checkBox_3->sizePolicy().hasHeightForWidth());
        checkBox_3->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(checkBox_3, 1, 0, 1, 1);

        radioButton_9 = new QRadioButton(scrollAreaWidgetContents_9);
        radioButton_9->setObjectName(QString::fromUtf8("radioButton_9"));
        radioButton_9->setChecked(false);

        gridLayout_2->addWidget(radioButton_9, 1, 1, 1, 1);

        checkBox_9 = new QCheckBox(scrollAreaWidgetContents_9);
        checkBox_9->setObjectName(QString::fromUtf8("checkBox_9"));
        sizePolicy.setHeightForWidth(checkBox_9->sizePolicy().hasHeightForWidth());
        checkBox_9->setSizePolicy(sizePolicy);
        checkBox_9->setChecked(true);

        gridLayout_2->addWidget(checkBox_9, 2, 0, 1, 1);

        radioButton_3 = new QRadioButton(scrollAreaWidgetContents_9);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setChecked(true);

        gridLayout_2->addWidget(radioButton_3, 2, 1, 1, 1);

        scrollArea_7->setWidget(scrollAreaWidgetContents_9);

        verticalLayout_7->addWidget(scrollArea_7);

        scrollArea_8 = new QScrollArea(GroupBoxWhiteTheme);
        scrollArea_8->setObjectName(QString::fromUtf8("scrollArea_8"));
        sizePolicy1.setHeightForWidth(scrollArea_8->sizePolicy().hasHeightForWidth());
        scrollArea_8->setSizePolicy(sizePolicy1);
        scrollArea_8->setWidgetResizable(true);
        scrollAreaWidgetContents_10 = new QWidget();
        scrollAreaWidgetContents_10->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_10"));
        scrollAreaWidgetContents_10->setGeometry(QRect(0, 0, 495, 111));
        gridLayout_5 = new QGridLayout(scrollAreaWidgetContents_10);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        pushButton_4 = new QPushButton(scrollAreaWidgetContents_10);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        pushButton_4->setMinimumSize(QSize(25, 0));
        pushButton_4->setIcon(icon1);

        gridLayout_5->addWidget(pushButton_4, 0, 0, 1, 1);

        lineEdit_4 = new QLineEdit(scrollAreaWidgetContents_10);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy);
        lineEdit_4->setMinimumSize(QSize(25, 0));

        gridLayout_5->addWidget(lineEdit_4, 0, 1, 1, 1);

        checkBox_4 = new QCheckBox(scrollAreaWidgetContents_10);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setEnabled(false);
        sizePolicy.setHeightForWidth(checkBox_4->sizePolicy().hasHeightForWidth());
        checkBox_4->setSizePolicy(sizePolicy);

        gridLayout_5->addWidget(checkBox_4, 1, 0, 1, 1);

        radioButton_4 = new QRadioButton(scrollAreaWidgetContents_10);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        radioButton_4->setEnabled(false);

        gridLayout_5->addWidget(radioButton_4, 1, 1, 1, 1);

        checkBox_10 = new QCheckBox(scrollAreaWidgetContents_10);
        checkBox_10->setObjectName(QString::fromUtf8("checkBox_10"));
        checkBox_10->setEnabled(false);
        sizePolicy.setHeightForWidth(checkBox_10->sizePolicy().hasHeightForWidth());
        checkBox_10->setSizePolicy(sizePolicy);
        checkBox_10->setChecked(true);

        gridLayout_5->addWidget(checkBox_10, 2, 0, 1, 1);

        radioButton_10 = new QRadioButton(scrollAreaWidgetContents_10);
        radioButton_10->setObjectName(QString::fromUtf8("radioButton_10"));
        radioButton_10->setEnabled(false);
        radioButton_10->setChecked(true);

        gridLayout_5->addWidget(radioButton_10, 2, 1, 1, 1);

        scrollArea_8->setWidget(scrollAreaWidgetContents_10);

        verticalLayout_7->addWidget(scrollArea_8);


        gridLayout_6->addWidget(GroupBoxWhiteTheme, 1, 1, 1, 1);

        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_3 = new QGridLayout(groupBox_4);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pushButton_5 = new QPushButton(groupBox_4);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setEnabled(false);

        gridLayout_3->addWidget(pushButton_5, 0, 0, 1, 1);


        gridLayout_6->addWidget(groupBox_4, 3, 0, 1, 2);

        RadioButtonCustomTheme = new QRadioButton(tab);
        RadioButtonCustomTheme->setObjectName(QString::fromUtf8("RadioButtonCustomTheme"));
        RadioButtonCustomTheme->setEnabled(false);

        gridLayout_6->addWidget(RadioButtonCustomTheme, 2, 0, 1, 2);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_8 = new QGridLayout(tab_2);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        ScrollAreaProfilesHideGames = new QScrollArea(tab_2);
        ScrollAreaProfilesHideGames->setObjectName(QString::fromUtf8("ScrollAreaProfilesHideGames"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(ScrollAreaProfilesHideGames->sizePolicy().hasHeightForWidth());
        ScrollAreaProfilesHideGames->setSizePolicy(sizePolicy2);
        ScrollAreaProfilesHideGames->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 68, 439));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy3);
        ScrollAreaProfilesHideGames->setWidget(scrollAreaWidgetContents);

        horizontalLayout_2->addWidget(ScrollAreaProfilesHideGames);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        LineEditFindGame = new QLineEdit(tab_2);
        LineEditFindGame->setObjectName(QString::fromUtf8("LineEditFindGame"));

        horizontalLayout->addWidget(LineEditFindGame);

        ButtonFindGame = new QPushButton(tab_2);
        ButtonFindGame->setObjectName(QString::fromUtf8("ButtonFindGame"));

        horizontalLayout->addWidget(ButtonFindGame);


        verticalLayout_10->addLayout(horizontalLayout);

        TableWidgetGames = new QTableWidget(tab_2);
        if (TableWidgetGames->columnCount() < 4)
            TableWidgetGames->setColumnCount(4);
        TableWidgetGames->setObjectName(QString::fromUtf8("TableWidgetGames"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(TableWidgetGames->sizePolicy().hasHeightForWidth());
        TableWidgetGames->setSizePolicy(sizePolicy4);
        TableWidgetGames->setColumnCount(4);

        verticalLayout_10->addWidget(TableWidgetGames);


        horizontalLayout_2->addLayout(verticalLayout_10);


        gridLayout_8->addLayout(horizontalLayout_2, 0, 0, 1, 1);

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


        gridLayout_8->addWidget(groupBox, 1, 0, 1, 1);

        CheckBoxVisibleHiddenGames = new QCheckBox(tab_2);
        CheckBoxVisibleHiddenGames->setObjectName(QString::fromUtf8("CheckBoxVisibleHiddenGames"));

        gridLayout_8->addWidget(CheckBoxVisibleHiddenGames, 2, 0, 1, 1);

        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        QFont font;
        font.setPointSize(10);
        label_10->setFont(font);
        label_10->setWordWrap(true);
        label_10->setOpenExternalLinks(true);
        label_10->setTextInteractionFlags(Qt::TextBrowserInteraction);

        gridLayout_8->addWidget(label_10, 3, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_9 = new QGridLayout(tab_3);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        groupBox_2 = new QGroupBox(tab_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setSpacing(1);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(1, 1, 1, 1);
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_3->addWidget(label_13);


        gridLayout_9->addWidget(groupBox_2, 0, 1, 1, 1);

        groupBox_11 = new QGroupBox(tab_3);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        verticalLayout_14 = new QVBoxLayout(groupBox_11);
        verticalLayout_14->setSpacing(1);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        verticalLayout_14->setContentsMargins(1, 1, 1, 1);
        label_23 = new QLabel(groupBox_11);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setWordWrap(true);

        verticalLayout_14->addWidget(label_23);

        label_26 = new QLabel(groupBox_11);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        verticalLayout_14->addWidget(label_26);


        gridLayout_9->addWidget(groupBox_11, 1, 1, 1, 1);

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


        gridLayout_9->addWidget(groupBox_9, 2, 0, 1, 1);

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


        gridLayout_9->addWidget(groupBox_5, 3, 0, 1, 1);

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


        gridLayout_9->addWidget(groupBox_7, 3, 1, 1, 1);

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


        gridLayout_9->addWidget(groupBox_10, 4, 0, 1, 1);

        groupBox_8 = new QGroupBox(tab_3);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        verticalLayout_11 = new QVBoxLayout(groupBox_8);
        verticalLayout_11->setSpacing(1);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(1, 1, 1, 1);
        label_18 = new QLabel(groupBox_8);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        verticalLayout_11->addWidget(label_18);


        gridLayout_9->addWidget(groupBox_8, 4, 1, 1, 1);

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

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FormSettings);
    } // setupUi

    void retranslateUi(QWidget *FormSettings)
    {
        FormSettings->setWindowTitle(QApplication::translate("FormSettings", "Form", nullptr));
        RadioButtonDarkTheme->setText(QApplication::translate("FormSettings", "\320\242\321\221\320\274\320\275\320\260\321\217 \321\202\320\265\320\274\320\260", nullptr));
        RadioButtonLightTheme->setText(QApplication::translate("FormSettings", "\320\241\320\262\320\265\321\202\320\273\320\260\321\217 \321\202\320\265\320\274\320\260", nullptr));
        GroupBoxDarkTheme->setTitle(QString());
        comboBox->setItemText(0, QApplication::translate("FormSettings", "123", nullptr));
        comboBox->setItemText(1, QApplication::translate("FormSettings", "12", nullptr));
        comboBox->setItemText(2, QApplication::translate("FormSettings", "1", nullptr));

        checkBox_8->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        radioButton->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        pushButton->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        checkBox->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        lineEdit->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        radioButton_7->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        pushButton_2->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        lineEdit_2->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        checkBox_2->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        radioButton_2->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        checkBox_7->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        radioButton_8->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        GroupBoxWhiteTheme->setTitle(QString());
        pushButton_3->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        lineEdit_3->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        checkBox_3->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        radioButton_9->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        checkBox_9->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        radioButton_3->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        pushButton_4->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        lineEdit_4->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        checkBox_4->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        radioButton_4->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        checkBox_10->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        radioButton_10->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        groupBox_4->setTitle(QApplication::translate("FormSettings", "GroupBox", nullptr));
        pushButton_5->setText(QApplication::translate("FormSettings", "\320\235\320\260\321\201\321\202\321\200\320\276\320\270\321\202\321\214", nullptr));
        RadioButtonCustomTheme->setText(QApplication::translate("FormSettings", "\320\241\320\262\320\276\321\217 \321\202\320\265\320\274\320\260 (\320\222 \321\200\320\260\320\267\321\200\320\260\320\261\320\276\321\202\320\272\320\265)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("FormSettings", "\320\242\320\265\320\274\320\260", nullptr));
        ButtonFindGame->setText(QApplication::translate("FormSettings", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        groupBox->setTitle(QApplication::translate("FormSettings", "Language", nullptr));
        RadioButtonLanguageEnglish->setText(QApplication::translate("FormSettings", "English", nullptr));
        RadioButtonLanguageRussian->setText(QApplication::translate("FormSettings", "\320\240\321\203\321\201\321\201\320\272\320\270\320\271", nullptr));
        CheckBoxVisibleHiddenGames->setText(QApplication::translate("FormSettings", "\320\237\321\200\320\270 \320\277\320\276\320\270\321\201\320\272\320\265 \320\277\320\276 \320\270\320\263\321\200\320\260\320\274 \320\276\321\202\320\276\320\261\321\200\320\260\320\266\320\260\321\202\321\214 \321\201\320\272\321\200\321\213\321\202\321\213\320\265 \320\270\320\263\321\200\321\213", nullptr));
        label_10->setText(QApplication::translate("FormSettings", "<html><head/><body><p>\320\230\320\272\320\276\320\275\320\272\320\270 \320\264\320\273\321\217 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\321\217 \320\261\321\213\320\273\320\270 \320\277\321\200\320\265\320\264\320\276\321\201\321\202\320\260\320\262\320\273\320\265\320\275\321\213 \321\201\320\260\320\271\321\202\320\276\320\274 <a href=https://icons8.ru/icons>https://icons8.ru/icons</a></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("FormSettings", "\320\237\321\200\320\276\321\207\320\270\320\265 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        groupBox_2->setTitle(QApplication::translate("FormSettings", "\320\241\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265", nullptr));
        label_13->setText(QApplication::translate("FormSettings", "\320\277\320\276\320\264\320\263\321\200\321\203\320\267\320\272\320\260 \320\264\320\276\321\201\321\202\320\270\320\266\320\265\320\275\320\270\320\271 \320\264\321\200\321\203\320\267\320\265\320\271 \320\262 \320\276\321\202\320\264\320\265\320\273\321\214\320\275\320\276\320\274 \320\277\320\276\321\202\320\276\320\272\320\265", nullptr));
        groupBox_11->setTitle(QApplication::translate("FormSettings", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\320\270", nullptr));
        label_23->setText(QApplication::translate("FormSettings", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\262\320\276\320\267\320\274\320\276\320\266\320\275\320\276\321\201\321\202\321\214 \321\203\320\275\320\270\320\272\320\260\320\273\321\214\320\275\321\213\321\205 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\271", nullptr));
        label_26->setText(QApplication::translate("FormSettings", "\320\230\320\275\320\262\320\265\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\264\320\276\321\201\321\202\320\270\320\266\320\265\320\275\320\270\321\217 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217", nullptr));
        groupBox_9->setTitle(QApplication::translate("FormSettings", "\320\230\320\267\320\261\321\200\320\260\320\275\320\275\320\276\320\265", nullptr));
        label_19->setText(QApplication::translate("FormSettings", "\320\237\320\265\321\200\320\265\321\205\320\276\320\264 \320\272 \320\270\320\267\320\261\321\200\320\260\320\275\320\275\321\213\320\274 \320\270\320\263\321\200\320\260\320\274", nullptr));
        label_20->setText(QApplication::translate("FormSettings", "\320\237\320\265\321\200\320\265\321\205\320\276\320\264 \320\272 \320\270\320\267\320\261\321\200\320\260\320\275\320\275\321\213\320\274 \320\264\321\200\321\203\320\267\321\214\321\217\320\274", nullptr));
        label_21->setText(QApplication::translate("FormSettings", "\320\237\320\265\321\200\320\265\321\205\320\276\320\264 \320\272 \320\270\320\267\320\261\321\200\320\260\320\275\320\275\321\213\320\274 \320\264\320\276\321\201\321\202\320\270\320\266\320\265\320\275\320\270\321\217\320\274", nullptr));
        groupBox_6->setTitle(QApplication::translate("FormSettings", "\320\230\320\263\321\200\321\213", nullptr));
        label_14->setText(QApplication::translate("FormSettings", "\320\223\321\200\321\203\320\277\320\277\321\213 \320\270\320\263\321\200", nullptr));
        groupBox_5->setTitle(QApplication::translate("FormSettings", "\320\224\321\200\321\203\320\267\321\214\321\217", nullptr));
        label_12->setText(QApplication::translate("FormSettings", "\320\223\321\200\321\203\320\277\320\277\321\213 \320\264\321\200\321\203\320\267\320\265\320\271", nullptr));
        label->setText(QApplication::translate("FormSettings", "\320\270\321\201\320\277\321\200\320\260\320\262\320\270\321\202\321\214 \320\261\320\260\320\263 \321\201 \320\272\320\275\320\276\320\277\320\272\320\276\320\271 \"\320\270\320\267\320\261\321\200\320\260\320\275\320\275\321\213\320\265\" \320\277\321\200\320\270 \320\276\321\202\321\201\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\275\320\276\320\271 \321\202\320\260\320\261\320\273\320\270\321\206\320\265", nullptr));
        label_3->setText(QApplication::translate("FormSettings", "\321\201\320\264\320\265\320\273\320\260\321\202\321\214 \320\277\320\276\320\273\320\276\321\201\321\203 \320\267\320\260\320\263\321\200\321\203\320\267\320\272\320\270 \320\277\321\200\320\270 \320\277\320\265\321\200\320\265\321\205\320\276\320\264\320\265 \320\275\320\260 \320\277\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
        groupBox_7->setTitle(QApplication::translate("FormSettings", "\320\224\320\276\321\201\321\202\320\270\320\266\320\265\320\275\320\270\321\217", nullptr));
        label_16->setText(QApplication::translate("FormSettings", "\321\200\320\265\320\264\320\270\320\267\320\260\320\271\320\275", nullptr));
        label_17->setText(QApplication::translate("FormSettings", "\320\267\320\260\320\274\320\265\321\202\320\272\320\270 \320\272 \320\264\320\276\321\201\321\202\320\270\320\266\320\265\320\275\320\270\321\217\320\274 \320\270 \320\270\320\263\321\200\320\260\320\274", nullptr));
        groupBox_10->setTitle(QApplication::translate("FormSettings", "\320\237\321\200\320\276\321\207\320\265\320\265", nullptr));
        label_22->setText(QApplication::translate("FormSettings", "\320\240\320\265\321\201\320\260\320\271\320\267 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\276\320\262 \320\277\321\200\320\270 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\270 \320\276\320\272\320\275\320\260", nullptr));
        label_24->setText(QApplication::translate("FormSettings", "\320\235\320\260\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \321\201\320\270\321\201\321\202\320\265\320\274\321\203 \320\273\320\276\320\263\320\276\320\262 \320\264\320\273\321\217 \320\272\321\200\320\260\321\210\320\265\320\271", nullptr));
        groupBox_8->setTitle(QApplication::translate("FormSettings", "\320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260", nullptr));
        label_18->setText(QApplication::translate("FormSettings", "\320\241\321\200\320\260\320\262\320\275\320\270\321\202\321\214 \321\201 \320\264\321\200\321\203\320\267\321\214\321\217\320\274\320\270", nullptr));
        groupBox_3->setTitle(QApplication::translate("FormSettings", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        label_8->setText(QApplication::translate("FormSettings", "\320\224\320\260\320\275\320\275\321\213\320\265 \320\264\320\273\321\217 \320\264\320\276\320\275\320\260\321\202\320\276\320\262", nullptr));
        label_9->setText(QApplication::translate("FormSettings", "\320\244\320\276\321\200\320\274\320\260\321\202 \320\264\320\260\321\202", nullptr));
        label_2->setText(QApplication::translate("FormSettings", "\320\222\321\213\320\263\321\200\321\203\320\267\320\272\320\260 \320\275\320\260\321\201\321\202\321\200\320\276\320\265\320\272, \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\320\271, \320\277\321\200\320\276\321\207\320\265\320\263\320\276", nullptr));
        label_4->setText(QApplication::translate("FormSettings", "\320\241\320\261\321\200\320\276\321\201 \320\272 \320\267\320\260\320\262\320\276\320\264\321\201\320\272\320\270\320\274 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260\320\274", nullptr));
        label_27->setText(QApplication::translate("FormSettings", "\320\230\321\201\320\277\321\200\320\260\320\262\320\270\321\202\321\214 \320\277\321\200\320\276\320\261\320\273\320\265\320\274\321\203 \321\201 \320\275\320\265\321\200\320\265\321\201\320\260\320\271\320\267\321\217\321\211\320\265\320\271\321\201\321\217 ScrollArea \321\201 \321\204\320\260\320\271\320\273\320\260\320\274\320\270 \321\201\320\272\321\200\321\213\321\202\321\213\321\205 \320\270\320\263\321\200", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("FormSettings", "\320\237\320\273\320\260\320\275\321\213 (\320\237\320\276\321\202\320\276\320\274 \321\203\320\264\320\260\320\273\321\216)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormSettings: public Ui_FormSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSETTINGS_H
