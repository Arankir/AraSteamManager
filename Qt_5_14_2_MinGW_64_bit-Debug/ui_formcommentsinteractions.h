/********************************************************************************
** Form generated from reading UI file 'formcommentsinteractions.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMCOMMENTSINTERACTIONS_H
#define UI_FORMCOMMENTSINTERACTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormCommentsInteractions
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *LabelGameTitle;
    QSpacerItem *horizontalSpacer;
    QLabel *LabelProfileName;
    QFrame *FrameAchievement;
    QVBoxLayout *verticalLayout;
    QLabel *LabelAchievementTitle;
    QLabel *LabelAchievementDescription;
    QLabel *LabelAchievementAchieved;
    QTextEdit *TextEditComment;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *ButtonCancel;
    QPushButton *ButtonApply;

    void setupUi(QWidget *FormCommentsInteractions)
    {
        if (FormCommentsInteractions->objectName().isEmpty())
            FormCommentsInteractions->setObjectName(QString::fromUtf8("FormCommentsInteractions"));
        FormCommentsInteractions->resize(605, 513);
        verticalLayout_2 = new QVBoxLayout(FormCommentsInteractions);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        LabelGameTitle = new QLabel(FormCommentsInteractions);
        LabelGameTitle->setObjectName(QString::fromUtf8("LabelGameTitle"));

        horizontalLayout->addWidget(LabelGameTitle);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        LabelProfileName = new QLabel(FormCommentsInteractions);
        LabelProfileName->setObjectName(QString::fromUtf8("LabelProfileName"));

        horizontalLayout->addWidget(LabelProfileName);


        verticalLayout_2->addLayout(horizontalLayout);

        FrameAchievement = new QFrame(FormCommentsInteractions);
        FrameAchievement->setObjectName(QString::fromUtf8("FrameAchievement"));
        FrameAchievement->setFrameShape(QFrame::StyledPanel);
        FrameAchievement->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(FrameAchievement);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        LabelAchievementTitle = new QLabel(FrameAchievement);
        LabelAchievementTitle->setObjectName(QString::fromUtf8("LabelAchievementTitle"));

        verticalLayout->addWidget(LabelAchievementTitle);

        LabelAchievementDescription = new QLabel(FrameAchievement);
        LabelAchievementDescription->setObjectName(QString::fromUtf8("LabelAchievementDescription"));

        verticalLayout->addWidget(LabelAchievementDescription);

        LabelAchievementAchieved = new QLabel(FrameAchievement);
        LabelAchievementAchieved->setObjectName(QString::fromUtf8("LabelAchievementAchieved"));

        verticalLayout->addWidget(LabelAchievementAchieved);


        verticalLayout_2->addWidget(FrameAchievement);

        TextEditComment = new QTextEdit(FormCommentsInteractions);
        TextEditComment->setObjectName(QString::fromUtf8("TextEditComment"));

        verticalLayout_2->addWidget(TextEditComment);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        ButtonCancel = new QPushButton(FormCommentsInteractions);
        ButtonCancel->setObjectName(QString::fromUtf8("ButtonCancel"));

        horizontalLayout_2->addWidget(ButtonCancel);

        ButtonApply = new QPushButton(FormCommentsInteractions);
        ButtonApply->setObjectName(QString::fromUtf8("ButtonApply"));

        horizontalLayout_2->addWidget(ButtonApply);


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(FormCommentsInteractions);

        QMetaObject::connectSlotsByName(FormCommentsInteractions);
    } // setupUi

    void retranslateUi(QWidget *FormCommentsInteractions)
    {
        FormCommentsInteractions->setWindowTitle(QCoreApplication::translate("FormCommentsInteractions", "Form", nullptr));
        LabelGameTitle->setText(QCoreApplication::translate("FormCommentsInteractions", "Game", nullptr));
        LabelProfileName->setText(QCoreApplication::translate("FormCommentsInteractions", "Profile", nullptr));
        LabelAchievementTitle->setText(QCoreApplication::translate("FormCommentsInteractions", "Title", nullptr));
        LabelAchievementDescription->setText(QCoreApplication::translate("FormCommentsInteractions", "Description", nullptr));
        LabelAchievementAchieved->setText(QCoreApplication::translate("FormCommentsInteractions", "Achieved", nullptr));
        ButtonCancel->setText(QCoreApplication::translate("FormCommentsInteractions", "Cancel", nullptr));
        ButtonApply->setText(QCoreApplication::translate("FormCommentsInteractions", "Apply", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormComments: public Ui_FormCommentsInteractions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCOMMENTSINTERACTIONS_H
