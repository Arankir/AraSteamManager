/********************************************************************************
** Form generated from reading UI file 'formcomparefriends.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMCOMPAREFRIENDS_H
#define UI_FORMCOMPAREFRIENDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "subwidget/freezerowstable.h"

QT_BEGIN_NAMESPACE

class Ui_FormCompareFriends
{
public:
    QHBoxLayout *horizontalLayout_2;
    FreezeRowsTable *tableView;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;

    void setupUi(QWidget *FormCompareFriends)
    {
        if (FormCompareFriends->objectName().isEmpty())
            FormCompareFriends->setObjectName(QString::fromUtf8("FormCompareFriends"));
        FormCompareFriends->resize(766, 419);
        horizontalLayout_2 = new QHBoxLayout(FormCompareFriends);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tableView = new FreezeRowsTable(FormCompareFriends);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        horizontalLayout_2->addWidget(tableView);

        frame = new QFrame(FormCompareFriends);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        scrollArea = new QScrollArea(frame);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 349, 171));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        scrollArea_2 = new QScrollArea(frame);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 349, 170));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        verticalLayout->addWidget(scrollArea_2);


        horizontalLayout_2->addWidget(frame);


        retranslateUi(FormCompareFriends);

        QMetaObject::connectSlotsByName(FormCompareFriends);
    } // setupUi

    void retranslateUi(QWidget *FormCompareFriends)
    {
        FormCompareFriends->setWindowTitle(QCoreApplication::translate("FormCompareFriends", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("FormCompareFriends", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormCompareFriends: public Ui_FormCompareFriends {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCOMPAREFRIENDS_H
