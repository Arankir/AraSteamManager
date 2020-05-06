/********************************************************************************
** Form generated from reading UI file 'formcategoryvalue.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMCATEGORYVALUE_H
#define UI_FORMCATEGORYVALUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormCategoryValue
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *LabelPosition;
    QLineEdit *LineEditTitle;
    QSpacerItem *horizontalSpacer;
    QCheckBox *CheckBoxVisible;
    QPushButton *ButtonReverse;
    QPushButton *ButtonUp;
    QPushButton *ButtonDown;
    QPushButton *ButtonSelect;
    QPushButton *ButtonUnSelect;
    QPushButton *ButtonDelete;

    void setupUi(QWidget *FormCategoryValue)
    {
        if (FormCategoryValue->objectName().isEmpty())
            FormCategoryValue->setObjectName(QString::fromUtf8("FormCategoryValue"));
        FormCategoryValue->resize(588, 25);
        QFont font;
        font.setFamily(QString::fromUtf8("Ebrima"));
        FormCategoryValue->setFont(font);
        horizontalLayout = new QHBoxLayout(FormCategoryValue);
        horizontalLayout->setSpacing(1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(1, 1, 1, 1);
        LabelPosition = new QLabel(FormCategoryValue);
        LabelPosition->setObjectName(QString::fromUtf8("LabelPosition"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LabelPosition->sizePolicy().hasHeightForWidth());
        LabelPosition->setSizePolicy(sizePolicy);
        LabelPosition->setText(QString::fromUtf8("Pos"));

        horizontalLayout->addWidget(LabelPosition);

        LineEditTitle = new QLineEdit(FormCategoryValue);
        LineEditTitle->setObjectName(QString::fromUtf8("LineEditTitle"));

        horizontalLayout->addWidget(LineEditTitle);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        CheckBoxVisible = new QCheckBox(FormCategoryValue);
        CheckBoxVisible->setObjectName(QString::fromUtf8("CheckBoxVisible"));
        CheckBoxVisible->setChecked(true);

        horizontalLayout->addWidget(CheckBoxVisible);

        ButtonReverse = new QPushButton(FormCategoryValue);
        ButtonReverse->setObjectName(QString::fromUtf8("ButtonReverse"));

        horizontalLayout->addWidget(ButtonReverse);

        ButtonUp = new QPushButton(FormCategoryValue);
        ButtonUp->setObjectName(QString::fromUtf8("ButtonUp"));

        horizontalLayout->addWidget(ButtonUp);

        ButtonDown = new QPushButton(FormCategoryValue);
        ButtonDown->setObjectName(QString::fromUtf8("ButtonDown"));

        horizontalLayout->addWidget(ButtonDown);

        ButtonSelect = new QPushButton(FormCategoryValue);
        ButtonSelect->setObjectName(QString::fromUtf8("ButtonSelect"));

        horizontalLayout->addWidget(ButtonSelect);

        ButtonUnSelect = new QPushButton(FormCategoryValue);
        ButtonUnSelect->setObjectName(QString::fromUtf8("ButtonUnSelect"));

        horizontalLayout->addWidget(ButtonUnSelect);

        ButtonDelete = new QPushButton(FormCategoryValue);
        ButtonDelete->setObjectName(QString::fromUtf8("ButtonDelete"));

        horizontalLayout->addWidget(ButtonDelete);


        retranslateUi(FormCategoryValue);

        QMetaObject::connectSlotsByName(FormCategoryValue);
    } // setupUi

    void retranslateUi(QWidget *FormCategoryValue)
    {
        FormCategoryValue->setWindowTitle(QCoreApplication::translate("FormCategoryValue", "Form", nullptr));
        CheckBoxVisible->setText(QCoreApplication::translate("FormCategoryValue", "Visible", nullptr));
        ButtonReverse->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FormCategoryValue: public Ui_FormCategoryValue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCATEGORYVALUE_H
