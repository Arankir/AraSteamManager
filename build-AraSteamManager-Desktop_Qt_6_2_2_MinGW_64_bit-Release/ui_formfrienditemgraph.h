/********************************************************************************
** Form generated from reading UI file 'formfrienditemgraph.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMFRIENDITEMGRAPH_H
#define UI_FORMFRIENDITEMGRAPH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormFriendItemGraph
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *LabelName;
    QSpacerItem *horizontalSpacer;
    QLabel *LabelColor;
    QPushButton *ButtonDelete;

    void setupUi(QWidget *FormFriendItemGraph)
    {
        if (FormFriendItemGraph->objectName().isEmpty())
            FormFriendItemGraph->setObjectName(QString::fromUtf8("FormFriendItemGraph"));
        FormFriendItemGraph->resize(223, 39);
        horizontalLayout = new QHBoxLayout(FormFriendItemGraph);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        LabelName = new QLabel(FormFriendItemGraph);
        LabelName->setObjectName(QString::fromUtf8("LabelName"));

        horizontalLayout->addWidget(LabelName);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        LabelColor = new QLabel(FormFriendItemGraph);
        LabelColor->setObjectName(QString::fromUtf8("LabelColor"));

        horizontalLayout->addWidget(LabelColor);

        ButtonDelete = new QPushButton(FormFriendItemGraph);
        ButtonDelete->setObjectName(QString::fromUtf8("ButtonDelete"));

        horizontalLayout->addWidget(ButtonDelete);


        retranslateUi(FormFriendItemGraph);

        QMetaObject::connectSlotsByName(FormFriendItemGraph);
    } // setupUi

    void retranslateUi(QWidget *FormFriendItemGraph)
    {
        FormFriendItemGraph->setWindowTitle(QCoreApplication::translate("FormFriendItemGraph", "Form", nullptr));
        LabelName->setText(QString());
        LabelColor->setText(QCoreApplication::translate("FormFriendItemGraph", "TextLabel", nullptr));
        ButtonDelete->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FormFriendItemGraph: public Ui_FormFriendItemGraph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMFRIENDITEMGRAPH_H
