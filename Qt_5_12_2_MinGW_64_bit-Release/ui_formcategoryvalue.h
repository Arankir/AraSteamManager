/********************************************************************************
** Form generated from reading UI file 'formcategoryvalue.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormCategoryValue
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *LabelPosition;
    QLineEdit *LineEditTitle;
    QCheckBox *CheckBoxVisible;
    QPushButton *ButtonUp;
    QPushButton *ButtonDown;
    QPushButton *ButtonSelect;
    QPushButton *ButtonUnSelect;
    QPushButton *ButtonDelete;

    void setupUi(QWidget *FormCategoryValue)
    {
        if (FormCategoryValue->objectName().isEmpty())
            FormCategoryValue->setObjectName(QString::fromUtf8("FormCategoryValue"));
        FormCategoryValue->resize(588, 24);
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

        horizontalLayout->addWidget(LabelPosition);

        LineEditTitle = new QLineEdit(FormCategoryValue);
        LineEditTitle->setObjectName(QString::fromUtf8("LineEditTitle"));

        horizontalLayout->addWidget(LineEditTitle);

        CheckBoxVisible = new QCheckBox(FormCategoryValue);
        CheckBoxVisible->setObjectName(QString::fromUtf8("CheckBoxVisible"));
        CheckBoxVisible->setChecked(true);

        horizontalLayout->addWidget(CheckBoxVisible);

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
        FormCategoryValue->setWindowTitle(QApplication::translate("FormCategoryValue", "Form", nullptr));
        LabelPosition->setText(QApplication::translate("FormCategoryValue", "Pos", nullptr));
        CheckBoxVisible->setText(QApplication::translate("FormCategoryValue", "Visible", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormCategoryValue: public Ui_FormCategoryValue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCATEGORYVALUE_H
