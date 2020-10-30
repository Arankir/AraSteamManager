/********************************************************************************
** Form generated from reading UI file 'formachievementwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMACHIEVEMENTWIDGET_H
#define UI_FORMACHIEVEMENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormAchievementWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *LabelIcon;
    QLabel *LabelTitle;

    void setupUi(QWidget *FormAchievementWidget)
    {
        if (FormAchievementWidget->objectName().isEmpty())
            FormAchievementWidget->setObjectName(QString::fromUtf8("FormAchievementWidget"));
        FormAchievementWidget->resize(533, 50);
        horizontalLayout = new QHBoxLayout(FormAchievementWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        LabelIcon = new QLabel(FormAchievementWidget);
        LabelIcon->setObjectName(QString::fromUtf8("LabelIcon"));
        LabelIcon->setMinimumSize(QSize(32, 32));
        LabelIcon->setMaximumSize(QSize(32, 32));
        LabelIcon->setText(QString::fromUtf8(""));

        horizontalLayout->addWidget(LabelIcon);

        LabelTitle = new QLabel(FormAchievementWidget);
        LabelTitle->setObjectName(QString::fromUtf8("LabelTitle"));
        LabelTitle->setText(QString::fromUtf8(""));
        LabelTitle->setWordWrap(true);

        horizontalLayout->addWidget(LabelTitle);


        retranslateUi(FormAchievementWidget);

        QMetaObject::connectSlotsByName(FormAchievementWidget);
    } // setupUi

    void retranslateUi(QWidget *FormAchievementWidget)
    {
        FormAchievementWidget->setWindowTitle(QCoreApplication::translate("FormAchievementWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormAchievementWidget: public Ui_FormAchievementWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMACHIEVEMENTWIDGET_H
