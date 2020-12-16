/********************************************************************************
** Form generated from reading UI file 'formcomments.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMCOMMENTS_H
#define UI_FORMCOMMENTS_H

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

class Ui_FormComments
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

    void setupUi(QWidget *FormComments)
    {
        if (FormComments->objectName().isEmpty())
            FormComments->setObjectName(QString::fromUtf8("FormComments"));
        FormComments->resize(605, 513);
        verticalLayout_2 = new QVBoxLayout(FormComments);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        LabelGameTitle = new QLabel(FormComments);
        LabelGameTitle->setObjectName(QString::fromUtf8("LabelGameTitle"));

        horizontalLayout->addWidget(LabelGameTitle);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        LabelProfileName = new QLabel(FormComments);
        LabelProfileName->setObjectName(QString::fromUtf8("LabelProfileName"));

        horizontalLayout->addWidget(LabelProfileName);


        verticalLayout_2->addLayout(horizontalLayout);

        FrameAchievement = new QFrame(FormComments);
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

        TextEditComment = new QTextEdit(FormComments);
        TextEditComment->setObjectName(QString::fromUtf8("TextEditComment"));

        verticalLayout_2->addWidget(TextEditComment);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        ButtonCancel = new QPushButton(FormComments);
        ButtonCancel->setObjectName(QString::fromUtf8("ButtonCancel"));

        horizontalLayout_2->addWidget(ButtonCancel);

        ButtonApply = new QPushButton(FormComments);
        ButtonApply->setObjectName(QString::fromUtf8("ButtonApply"));

        horizontalLayout_2->addWidget(ButtonApply);


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(FormComments);

        QMetaObject::connectSlotsByName(FormComments);
    } // setupUi

    void retranslateUi(QWidget *FormComments)
    {
        FormComments->setWindowTitle(QCoreApplication::translate("FormComments", "Form", nullptr));
        LabelGameTitle->setText(QCoreApplication::translate("FormComments", "Game", nullptr));
        LabelProfileName->setText(QCoreApplication::translate("FormComments", "Profile", nullptr));
        LabelAchievementTitle->setText(QCoreApplication::translate("FormComments", "Title", nullptr));
        LabelAchievementDescription->setText(QCoreApplication::translate("FormComments", "Description", nullptr));
        LabelAchievementAchieved->setText(QCoreApplication::translate("FormComments", "Achieved", nullptr));
        ButtonCancel->setText(QCoreApplication::translate("FormComments", "Cancel", nullptr));
        ButtonApply->setText(QCoreApplication::translate("FormComments", "Apply", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormComments: public Ui_FormComments {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCOMMENTS_H
