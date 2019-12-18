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
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_6;
    QRadioButton *RadioButtonDarkTheme;
    QRadioButton *RadioButtonLightTheme;
    QGroupBox *GroupBoxDarkTheme;
    QVBoxLayout *verticalLayout_5;
    QScrollArea *scrollArea_5;
    QWidget *scrollAreaWidgetContents_7;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QCheckBox *checkBox;
    QCheckBox *checkBox_8;
    QRadioButton *radioButton_7;
    QRadioButton *radioButton;
    QLineEdit *lineEdit;
    QTableWidget *tableWidget;
    QScrollArea *scrollArea_6;
    QWidget *scrollAreaWidgetContents_8;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_2;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_7;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_8;
    QLineEdit *lineEdit_2;
    QTableWidget *tableWidget_2;
    QGroupBox *GroupBoxWhiteTheme;
    QVBoxLayout *verticalLayout_7;
    QScrollArea *scrollArea_7;
    QWidget *scrollAreaWidgetContents_9;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_3;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_9;
    QRadioButton *radioButton_9;
    QRadioButton *radioButton_3;
    QLineEdit *lineEdit_3;
    QTableWidget *tableWidget_3;
    QScrollArea *scrollArea_8;
    QWidget *scrollAreaWidgetContents_10;
    QGridLayout *gridLayout_5;
    QPushButton *pushButton_4;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_10;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_10;
    QLineEdit *lineEdit_4;
    QTableWidget *tableWidget_4;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_5;
    QRadioButton *RadioButtonCustomTheme;
    QWidget *tab_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_11;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_2;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QLabel *label;
    QLabel *label_7;
    QLabel *label_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *RadioButtonLanguageEnglish;
    QRadioButton *RadioButtonLanguageRussian;
    QCheckBox *CheckBoxVisibleHiddenGames;
    QLabel *label_10;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QScrollArea *ScrollAreaProfilesHideGames;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout;
    QLineEdit *LineEditFindGame;
    QPushButton *ButtonFindGame;
    QTableWidget *TableWidgetGames;

    void setupUi(QWidget *FormSettings)
    {
        if (FormSettings->objectName().isEmpty())
            FormSettings->setObjectName(QString::fromUtf8("FormSettings"));
        FormSettings->resize(1034, 738);
        verticalLayout_2 = new QVBoxLayout(FormSettings);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
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
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GroupBoxDarkTheme->sizePolicy().hasHeightForWidth());
        GroupBoxDarkTheme->setSizePolicy(sizePolicy);
        verticalLayout_5 = new QVBoxLayout(GroupBoxDarkTheme);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        scrollArea_5 = new QScrollArea(GroupBoxDarkTheme);
        scrollArea_5->setObjectName(QString::fromUtf8("scrollArea_5"));
        scrollArea_5->setWidgetResizable(true);
        scrollAreaWidgetContents_7 = new QWidget();
        scrollAreaWidgetContents_7->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_7"));
        scrollAreaWidgetContents_7->setGeometry(QRect(0, 0, 495, 217));
        gridLayout = new QGridLayout(scrollAreaWidgetContents_7);
        gridLayout->setSpacing(1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(scrollAreaWidgetContents_7);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setMinimumSize(QSize(25, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/white/program/white/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        checkBox = new QCheckBox(scrollAreaWidgetContents_7);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        sizePolicy1.setHeightForWidth(checkBox->sizePolicy().hasHeightForWidth());
        checkBox->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(checkBox, 0, 1, 1, 1);

        checkBox_8 = new QCheckBox(scrollAreaWidgetContents_7);
        checkBox_8->setObjectName(QString::fromUtf8("checkBox_8"));
        sizePolicy1.setHeightForWidth(checkBox_8->sizePolicy().hasHeightForWidth());
        checkBox_8->setSizePolicy(sizePolicy1);
        checkBox_8->setChecked(true);

        gridLayout->addWidget(checkBox_8, 0, 2, 1, 1);

        radioButton_7 = new QRadioButton(scrollAreaWidgetContents_7);
        radioButton_7->setObjectName(QString::fromUtf8("radioButton_7"));
        radioButton_7->setChecked(false);

        gridLayout->addWidget(radioButton_7, 0, 3, 1, 1);

        radioButton = new QRadioButton(scrollAreaWidgetContents_7);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setChecked(true);

        gridLayout->addWidget(radioButton, 0, 4, 1, 1);

        lineEdit = new QLineEdit(scrollAreaWidgetContents_7);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        lineEdit->setMinimumSize(QSize(25, 0));

        gridLayout->addWidget(lineEdit, 0, 5, 1, 1);

        tableWidget = new QTableWidget(scrollAreaWidgetContents_7);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        if (tableWidget->rowCount() < 3)
            tableWidget->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy2);
        tableWidget->setRowCount(3);
        tableWidget->setColumnCount(3);

        gridLayout->addWidget(tableWidget, 1, 0, 1, 6);

        scrollArea_5->setWidget(scrollAreaWidgetContents_7);

        verticalLayout_5->addWidget(scrollArea_5);

        scrollArea_6 = new QScrollArea(GroupBoxDarkTheme);
        scrollArea_6->setObjectName(QString::fromUtf8("scrollArea_6"));
        scrollArea_6->setWidgetResizable(true);
        scrollAreaWidgetContents_8 = new QWidget();
        scrollAreaWidgetContents_8->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_8"));
        scrollAreaWidgetContents_8->setGeometry(QRect(0, 0, 495, 217));
        gridLayout_4 = new QGridLayout(scrollAreaWidgetContents_8);
        gridLayout_4->setSpacing(1);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(scrollAreaWidgetContents_8);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setEnabled(false);
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);
        pushButton_2->setMinimumSize(QSize(25, 0));
        pushButton_2->setIcon(icon);

        gridLayout_4->addWidget(pushButton_2, 0, 0, 1, 1);

        checkBox_2 = new QCheckBox(scrollAreaWidgetContents_8);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setEnabled(false);
        sizePolicy1.setHeightForWidth(checkBox_2->sizePolicy().hasHeightForWidth());
        checkBox_2->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(checkBox_2, 0, 1, 1, 1);

        checkBox_7 = new QCheckBox(scrollAreaWidgetContents_8);
        checkBox_7->setObjectName(QString::fromUtf8("checkBox_7"));
        checkBox_7->setEnabled(false);
        sizePolicy1.setHeightForWidth(checkBox_7->sizePolicy().hasHeightForWidth());
        checkBox_7->setSizePolicy(sizePolicy1);
        checkBox_7->setChecked(true);

        gridLayout_4->addWidget(checkBox_7, 0, 2, 1, 1);

        radioButton_2 = new QRadioButton(scrollAreaWidgetContents_8);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setEnabled(false);

        gridLayout_4->addWidget(radioButton_2, 0, 3, 1, 1);

        radioButton_8 = new QRadioButton(scrollAreaWidgetContents_8);
        radioButton_8->setObjectName(QString::fromUtf8("radioButton_8"));
        radioButton_8->setEnabled(false);
        radioButton_8->setChecked(true);

        gridLayout_4->addWidget(radioButton_8, 0, 4, 1, 1);

        lineEdit_2 = new QLineEdit(scrollAreaWidgetContents_8);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEnabled(false);
        sizePolicy1.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy1);
        lineEdit_2->setMinimumSize(QSize(25, 0));

        gridLayout_4->addWidget(lineEdit_2, 0, 5, 1, 1);

        tableWidget_2 = new QTableWidget(scrollAreaWidgetContents_8);
        if (tableWidget_2->columnCount() < 3)
            tableWidget_2->setColumnCount(3);
        if (tableWidget_2->rowCount() < 3)
            tableWidget_2->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_2->setItem(0, 0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_2->setItem(0, 1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_2->setItem(1, 0, __qtablewidgetitem5);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setEnabled(false);
        sizePolicy2.setHeightForWidth(tableWidget_2->sizePolicy().hasHeightForWidth());
        tableWidget_2->setSizePolicy(sizePolicy2);
        tableWidget_2->setRowCount(3);
        tableWidget_2->setColumnCount(3);

        gridLayout_4->addWidget(tableWidget_2, 1, 0, 1, 6);

        scrollArea_6->setWidget(scrollAreaWidgetContents_8);

        verticalLayout_5->addWidget(scrollArea_6);


        gridLayout_6->addWidget(GroupBoxDarkTheme, 1, 0, 1, 1);

        GroupBoxWhiteTheme = new QGroupBox(tab);
        GroupBoxWhiteTheme->setObjectName(QString::fromUtf8("GroupBoxWhiteTheme"));
        sizePolicy.setHeightForWidth(GroupBoxWhiteTheme->sizePolicy().hasHeightForWidth());
        GroupBoxWhiteTheme->setSizePolicy(sizePolicy);
        verticalLayout_7 = new QVBoxLayout(GroupBoxWhiteTheme);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        scrollArea_7 = new QScrollArea(GroupBoxWhiteTheme);
        scrollArea_7->setObjectName(QString::fromUtf8("scrollArea_7"));
        scrollArea_7->setWidgetResizable(true);
        scrollAreaWidgetContents_9 = new QWidget();
        scrollAreaWidgetContents_9->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_9"));
        scrollAreaWidgetContents_9->setGeometry(QRect(0, 0, 495, 217));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents_9);
        gridLayout_2->setSpacing(1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(scrollAreaWidgetContents_9);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);
        pushButton_3->setMinimumSize(QSize(25, 0));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/black/program/black/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon1);

        gridLayout_2->addWidget(pushButton_3, 0, 0, 1, 1);

        checkBox_3 = new QCheckBox(scrollAreaWidgetContents_9);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        sizePolicy1.setHeightForWidth(checkBox_3->sizePolicy().hasHeightForWidth());
        checkBox_3->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(checkBox_3, 0, 1, 1, 1);

        checkBox_9 = new QCheckBox(scrollAreaWidgetContents_9);
        checkBox_9->setObjectName(QString::fromUtf8("checkBox_9"));
        sizePolicy1.setHeightForWidth(checkBox_9->sizePolicy().hasHeightForWidth());
        checkBox_9->setSizePolicy(sizePolicy1);
        checkBox_9->setChecked(true);

        gridLayout_2->addWidget(checkBox_9, 0, 2, 1, 1);

        radioButton_9 = new QRadioButton(scrollAreaWidgetContents_9);
        radioButton_9->setObjectName(QString::fromUtf8("radioButton_9"));
        radioButton_9->setChecked(false);

        gridLayout_2->addWidget(radioButton_9, 0, 3, 1, 1);

        radioButton_3 = new QRadioButton(scrollAreaWidgetContents_9);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setChecked(true);

        gridLayout_2->addWidget(radioButton_3, 0, 4, 1, 1);

        lineEdit_3 = new QLineEdit(scrollAreaWidgetContents_9);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        sizePolicy1.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy1);
        lineEdit_3->setMinimumSize(QSize(25, 0));

        gridLayout_2->addWidget(lineEdit_3, 0, 5, 1, 1);

        tableWidget_3 = new QTableWidget(scrollAreaWidgetContents_9);
        if (tableWidget_3->columnCount() < 3)
            tableWidget_3->setColumnCount(3);
        if (tableWidget_3->rowCount() < 3)
            tableWidget_3->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_3->setItem(0, 0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_3->setItem(0, 1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_3->setItem(1, 0, __qtablewidgetitem8);
        tableWidget_3->setObjectName(QString::fromUtf8("tableWidget_3"));
        sizePolicy2.setHeightForWidth(tableWidget_3->sizePolicy().hasHeightForWidth());
        tableWidget_3->setSizePolicy(sizePolicy2);
        tableWidget_3->setRowCount(3);
        tableWidget_3->setColumnCount(3);

        gridLayout_2->addWidget(tableWidget_3, 1, 0, 1, 6);

        scrollArea_7->setWidget(scrollAreaWidgetContents_9);

        verticalLayout_7->addWidget(scrollArea_7);

        scrollArea_8 = new QScrollArea(GroupBoxWhiteTheme);
        scrollArea_8->setObjectName(QString::fromUtf8("scrollArea_8"));
        scrollArea_8->setWidgetResizable(true);
        scrollAreaWidgetContents_10 = new QWidget();
        scrollAreaWidgetContents_10->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_10"));
        scrollAreaWidgetContents_10->setGeometry(QRect(0, 0, 495, 217));
        gridLayout_5 = new QGridLayout(scrollAreaWidgetContents_10);
        gridLayout_5->setSpacing(1);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        pushButton_4 = new QPushButton(scrollAreaWidgetContents_10);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setEnabled(false);
        sizePolicy1.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy1);
        pushButton_4->setMinimumSize(QSize(25, 0));
        pushButton_4->setIcon(icon1);

        gridLayout_5->addWidget(pushButton_4, 0, 0, 1, 1);

        checkBox_4 = new QCheckBox(scrollAreaWidgetContents_10);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setEnabled(false);
        sizePolicy1.setHeightForWidth(checkBox_4->sizePolicy().hasHeightForWidth());
        checkBox_4->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(checkBox_4, 0, 1, 1, 1);

        checkBox_10 = new QCheckBox(scrollAreaWidgetContents_10);
        checkBox_10->setObjectName(QString::fromUtf8("checkBox_10"));
        checkBox_10->setEnabled(false);
        sizePolicy1.setHeightForWidth(checkBox_10->sizePolicy().hasHeightForWidth());
        checkBox_10->setSizePolicy(sizePolicy1);
        checkBox_10->setChecked(true);

        gridLayout_5->addWidget(checkBox_10, 0, 2, 1, 1);

        radioButton_4 = new QRadioButton(scrollAreaWidgetContents_10);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        radioButton_4->setEnabled(false);

        gridLayout_5->addWidget(radioButton_4, 0, 3, 1, 1);

        radioButton_10 = new QRadioButton(scrollAreaWidgetContents_10);
        radioButton_10->setObjectName(QString::fromUtf8("radioButton_10"));
        radioButton_10->setEnabled(false);
        radioButton_10->setChecked(true);

        gridLayout_5->addWidget(radioButton_10, 0, 4, 1, 1);

        lineEdit_4 = new QLineEdit(scrollAreaWidgetContents_10);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setEnabled(false);
        sizePolicy1.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy1);
        lineEdit_4->setMinimumSize(QSize(25, 0));

        gridLayout_5->addWidget(lineEdit_4, 0, 5, 1, 1);

        tableWidget_4 = new QTableWidget(scrollAreaWidgetContents_10);
        if (tableWidget_4->columnCount() < 3)
            tableWidget_4->setColumnCount(3);
        if (tableWidget_4->rowCount() < 3)
            tableWidget_4->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_4->setItem(0, 0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_4->setItem(0, 1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_4->setItem(1, 0, __qtablewidgetitem11);
        tableWidget_4->setObjectName(QString::fromUtf8("tableWidget_4"));
        tableWidget_4->setEnabled(false);
        tableWidget_4->setRowCount(3);
        tableWidget_4->setColumnCount(3);

        gridLayout_5->addWidget(tableWidget_4, 1, 0, 1, 6);

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
        layoutWidget = new QWidget(tab_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(688, 9, 240, 200));
        verticalLayout_6 = new QVBoxLayout(layoutWidget);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_4->addWidget(label_11);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_4->addWidget(label_6);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_4->addWidget(label_8);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_4->addWidget(label_9);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_4->addWidget(label_2);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_4->addWidget(label_4);


        verticalLayout_6->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font;
        font.setStrikeOut(true);
        label_5->setFont(font);

        verticalLayout_3->addWidget(label_5);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        verticalLayout_3->addWidget(label);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        verticalLayout_3->addWidget(label_7);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        verticalLayout_3->addWidget(label_3);


        verticalLayout_6->addLayout(verticalLayout_3);

        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(9, 9, 89, 87));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        RadioButtonLanguageEnglish = new QRadioButton(groupBox);
        RadioButtonLanguageEnglish->setObjectName(QString::fromUtf8("RadioButtonLanguageEnglish"));

        verticalLayout->addWidget(RadioButtonLanguageEnglish);

        RadioButtonLanguageRussian = new QRadioButton(groupBox);
        RadioButtonLanguageRussian->setObjectName(QString::fromUtf8("RadioButtonLanguageRussian"));

        verticalLayout->addWidget(RadioButtonLanguageRussian);

        CheckBoxVisibleHiddenGames = new QCheckBox(tab_2);
        CheckBoxVisibleHiddenGames->setObjectName(QString::fromUtf8("CheckBoxVisibleHiddenGames"));
        CheckBoxVisibleHiddenGames->setGeometry(QRect(348, 42, 269, 20));
        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 600, 1012, 16));
        QFont font1;
        font1.setPointSize(10);
        label_10->setFont(font1);
        label_10->setWordWrap(true);
        layoutWidget1 = new QWidget(tab_2);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(9, 102, 671, 491));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        ScrollAreaProfilesHideGames = new QScrollArea(layoutWidget1);
        ScrollAreaProfilesHideGames->setObjectName(QString::fromUtf8("ScrollAreaProfilesHideGames"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(ScrollAreaProfilesHideGames->sizePolicy().hasHeightForWidth());
        ScrollAreaProfilesHideGames->setSizePolicy(sizePolicy3);
        ScrollAreaProfilesHideGames->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 109, 487));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy4);
        ScrollAreaProfilesHideGames->setWidget(scrollAreaWidgetContents);

        horizontalLayout_2->addWidget(ScrollAreaProfilesHideGames);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        LineEditFindGame = new QLineEdit(layoutWidget1);
        LineEditFindGame->setObjectName(QString::fromUtf8("LineEditFindGame"));

        horizontalLayout->addWidget(LineEditFindGame);

        ButtonFindGame = new QPushButton(layoutWidget1);
        ButtonFindGame->setObjectName(QString::fromUtf8("ButtonFindGame"));

        horizontalLayout->addWidget(ButtonFindGame);


        verticalLayout_10->addLayout(horizontalLayout);

        TableWidgetGames = new QTableWidget(layoutWidget1);
        if (TableWidgetGames->columnCount() < 4)
            TableWidgetGames->setColumnCount(4);
        TableWidgetGames->setObjectName(QString::fromUtf8("TableWidgetGames"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(TableWidgetGames->sizePolicy().hasHeightForWidth());
        TableWidgetGames->setSizePolicy(sizePolicy5);
        TableWidgetGames->setColumnCount(4);

        verticalLayout_10->addWidget(TableWidgetGames);


        horizontalLayout_2->addLayout(verticalLayout_10);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_2->addWidget(tabWidget);


        retranslateUi(FormSettings);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(FormSettings);
    } // setupUi

    void retranslateUi(QWidget *FormSettings)
    {
        FormSettings->setWindowTitle(QApplication::translate("FormSettings", "Form", nullptr));
        RadioButtonDarkTheme->setText(QApplication::translate("FormSettings", "\320\242\321\221\320\274\320\275\320\260\321\217 \321\202\320\265\320\274\320\260", nullptr));
        RadioButtonLightTheme->setText(QApplication::translate("FormSettings", "\320\241\320\262\320\265\321\202\320\273\320\260\321\217 \321\202\320\265\320\274\320\260", nullptr));
        GroupBoxDarkTheme->setTitle(QString());
        pushButton->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        checkBox->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        checkBox_8->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        radioButton_7->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        radioButton->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        lineEdit->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem = tableWidget->item(0, 0);
        ___qtablewidgetitem->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\2021", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->item(0, 1);
        ___qtablewidgetitem1->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\2022", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->item(1, 0);
        ___qtablewidgetitem2->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\2023", nullptr));
        tableWidget->setSortingEnabled(__sortingEnabled);

        pushButton_2->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        checkBox_2->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        checkBox_7->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        radioButton_2->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        radioButton_8->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        lineEdit_2->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));

        const bool __sortingEnabled1 = tableWidget_2->isSortingEnabled();
        tableWidget_2->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_2->item(0, 0);
        ___qtablewidgetitem3->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\2021", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_2->item(0, 1);
        ___qtablewidgetitem4->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\2022", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_2->item(1, 0);
        ___qtablewidgetitem5->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\2023", nullptr));
        tableWidget_2->setSortingEnabled(__sortingEnabled1);

        GroupBoxWhiteTheme->setTitle(QString());
        pushButton_3->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        checkBox_3->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        checkBox_9->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        radioButton_9->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        radioButton_3->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        lineEdit_3->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));

        const bool __sortingEnabled2 = tableWidget_3->isSortingEnabled();
        tableWidget_3->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_3->item(0, 0);
        ___qtablewidgetitem6->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\2021", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_3->item(0, 1);
        ___qtablewidgetitem7->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\2022", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_3->item(1, 0);
        ___qtablewidgetitem8->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\2023", nullptr));
        tableWidget_3->setSortingEnabled(__sortingEnabled2);

        pushButton_4->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        checkBox_4->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        checkBox_10->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        radioButton_4->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        radioButton_10->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        lineEdit_4->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\202", nullptr));

        const bool __sortingEnabled3 = tableWidget_4->isSortingEnabled();
        tableWidget_4->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_4->item(0, 0);
        ___qtablewidgetitem9->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\2021", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_4->item(0, 1);
        ___qtablewidgetitem10->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\2022", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_4->item(1, 0);
        ___qtablewidgetitem11->setText(QApplication::translate("FormSettings", "\320\242\320\265\320\272\321\201\321\2023", nullptr));
        tableWidget_4->setSortingEnabled(__sortingEnabled3);

        groupBox_4->setTitle(QApplication::translate("FormSettings", "GroupBox", nullptr));
        pushButton_5->setText(QApplication::translate("FormSettings", "\320\235\320\260\321\201\321\202\321\200\320\276\320\270\321\202\321\214", nullptr));
        RadioButtonCustomTheme->setText(QApplication::translate("FormSettings", "\320\241\320\262\320\276\321\217 \321\202\320\265\320\274\320\260 (\320\222 \321\200\320\260\320\267\321\200\320\260\320\261\320\276\321\202\320\272\320\265)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("FormSettings", "\320\242\320\265\320\274\320\260", nullptr));
        label_11->setText(QApplication::translate("FormSettings", "\320\224\320\276\321\201\321\202\320\260\321\202\321\214 \320\270\320\263\321\200\321\203 \320\270\320\267 \321\207\321\201", nullptr));
        label_6->setText(QApplication::translate("FormSettings", "\320\237\320\276\320\274\320\265\320\275\321\217\321\202\321\214 \321\204\320\276\320\275\320\276\320\262\321\203\321\216 \320\272\320\260\321\200\321\202\320\270\320\275\320\272\321\203 ?", nullptr));
        label_8->setText(QApplication::translate("FormSettings", "\320\224\320\260\320\275\320\275\321\213\320\265 \320\264\320\273\321\217 \320\264\320\276\320\275\320\260\321\202\320\276\320\262", nullptr));
        label_9->setText(QApplication::translate("FormSettings", "\320\244\320\276\321\200\320\274\320\260\321\202 \320\264\320\260\321\202", nullptr));
        label_2->setText(QApplication::translate("FormSettings", "\320\222\321\213\320\263\321\200\321\203\320\267\320\272\320\260 \320\275\320\260\321\201\321\202\321\200\320\276\320\265\320\272, \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\320\271, \320\277\321\200\320\276\321\207\320\265\320\263\320\276", nullptr));
        label_4->setText(QApplication::translate("FormSettings", "\320\241\320\261\321\200\320\276\321\201 \320\272 \320\267\320\260\320\262\320\276\320\264\321\201\320\272\320\270\320\274 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260\320\274", nullptr));
        label_5->setText(QApplication::translate("FormSettings", "\320\237\320\276\320\274\320\265\320\275\321\217\321\202\321\214 \321\202\320\265\320\274\321\203", nullptr));
        label->setText(QApplication::translate("FormSettings", "\320\237\320\276\320\274\320\265\320\275\321\217\321\202\321\214 \321\217\320\267\321\213\320\272", nullptr));
        label_7->setText(QApplication::translate("FormSettings", "\320\241\321\201\321\213\320\273\320\272\320\260 \320\275\320\260 icons8", nullptr));
        label_3->setText(QApplication::translate("FormSettings", "\320\237\320\276\320\272\320\260\320\267\321\213\320\262\320\260\321\202\321\214 \320\270\320\273\320\270 \320\275\320\265\321\202 \321\201\320\272\321\200\321\213\321\202\321\213\320\265 \320\270\320\263\321\200\321\213 \320\277\321\200\320\270 \320\277\320\276\320\270\321\201\320\272\320\265", nullptr));
        groupBox->setTitle(QApplication::translate("FormSettings", "Language", nullptr));
        RadioButtonLanguageEnglish->setText(QApplication::translate("FormSettings", "English", nullptr));
        RadioButtonLanguageRussian->setText(QApplication::translate("FormSettings", "\320\240\321\203\321\201\321\201\320\272\320\270\320\271", nullptr));
        CheckBoxVisibleHiddenGames->setText(QApplication::translate("FormSettings", "\320\237\321\200\320\270 \320\277\320\276\320\270\321\201\320\272\320\265 \320\277\320\276 \320\270\320\263\321\200\320\260\320\274 \320\276\321\202\320\276\320\261\321\200\320\260\320\266\320\260\321\202\321\214 \321\201\320\272\321\200\321\213\321\202\321\213\320\265 \320\270\320\263\321\200\321\213", nullptr));
        label_10->setText(QApplication::translate("FormSettings", "<html><head/><body><p>\320\230\320\272\320\276\320\275\320\272\320\270 \320\264\320\273\321\217 \321\215\321\202\320\276\320\263\320\276 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\321\217 \320\261\321\213\320\273\320\270 \320\262\320\267\321\217\321\202\321\213 \320\261\320\265\321\201\320\277\320\273\320\260\321\202\320\275\320\276 \321\201 \321\201\320\260\320\271\321\202\320\260 <span style=\" color:#55aa00;\">https://icons8.ru/icons</span></p></body></html>", nullptr));
        ButtonFindGame->setText(QApplication::translate("FormSettings", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("FormSettings", "\320\237\321\200\320\276\321\207\320\270\320\265 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormSettings: public Ui_FormSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSETTINGS_H
