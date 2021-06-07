/********************************************************************************
** Form generated from reading UI file 'formreachedfilter.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMREACHEDFILTER_H
#define UI_FORMREACHEDFILTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormReachedFilter
{
public:
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *LabelReached;
    QHBoxLayout *horizontalLayout;
    QRadioButton *RadioButtonReached;
    QVBoxLayout *verticalLayout_2;
    QLabel *LabelAll;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *RadioButtonAll;
    QVBoxLayout *verticalLayout_3;
    QLabel *LabelNotReached;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *RadioButtonNotReached;

    void setupUi(QWidget *FormReachedFilter)
    {
        if (FormReachedFilter->objectName().isEmpty())
            FormReachedFilter->setObjectName(QString::fromUtf8("FormReachedFilter"));
        FormReachedFilter->resize(66, 38);
        horizontalLayout_4 = new QHBoxLayout(FormReachedFilter);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        LabelReached = new QLabel(FormReachedFilter);
        LabelReached->setObjectName(QString::fromUtf8("LabelReached"));

        verticalLayout->addWidget(LabelReached);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        RadioButtonReached = new QRadioButton(FormReachedFilter);
        RadioButtonReached->setObjectName(QString::fromUtf8("RadioButtonReached"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RadioButtonReached->sizePolicy().hasHeightForWidth());
        RadioButtonReached->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(RadioButtonReached);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_4->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        LabelAll = new QLabel(FormReachedFilter);
        LabelAll->setObjectName(QString::fromUtf8("LabelAll"));

        verticalLayout_2->addWidget(LabelAll);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        RadioButtonAll = new QRadioButton(FormReachedFilter);
        RadioButtonAll->setObjectName(QString::fromUtf8("RadioButtonAll"));
        sizePolicy.setHeightForWidth(RadioButtonAll->sizePolicy().hasHeightForWidth());
        RadioButtonAll->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(RadioButtonAll);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        LabelNotReached = new QLabel(FormReachedFilter);
        LabelNotReached->setObjectName(QString::fromUtf8("LabelNotReached"));

        verticalLayout_3->addWidget(LabelNotReached);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        RadioButtonNotReached = new QRadioButton(FormReachedFilter);
        RadioButtonNotReached->setObjectName(QString::fromUtf8("RadioButtonNotReached"));
        sizePolicy.setHeightForWidth(RadioButtonNotReached->sizePolicy().hasHeightForWidth());
        RadioButtonNotReached->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(RadioButtonNotReached);


        verticalLayout_3->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(FormReachedFilter);

        QMetaObject::connectSlotsByName(FormReachedFilter);
    } // setupUi

    void retranslateUi(QWidget *FormReachedFilter)
    {
        FormReachedFilter->setWindowTitle(QCoreApplication::translate("FormReachedFilter", "Form", nullptr));
#if QT_CONFIG(tooltip)
        LabelReached->setToolTip(QCoreApplication::translate("FormReachedFilter", "\320\237\320\276\320\273\321\203\321\207\320\265\320\275\320\276", nullptr));
#endif // QT_CONFIG(tooltip)
        LabelReached->setText(QString());
        RadioButtonReached->setText(QString());
#if QT_CONFIG(tooltip)
        LabelAll->setToolTip(QCoreApplication::translate("FormReachedFilter", "\320\222\321\201\320\265", nullptr));
#endif // QT_CONFIG(tooltip)
        LabelAll->setText(QString());
        RadioButtonAll->setText(QString());
#if QT_CONFIG(tooltip)
        LabelNotReached->setToolTip(QCoreApplication::translate("FormReachedFilter", "\320\235\320\265 \320\277\320\276\320\273\321\203\321\207\320\265\320\275\320\276", nullptr));
#endif // QT_CONFIG(tooltip)
        LabelNotReached->setText(QString());
        RadioButtonNotReached->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FormReachedFilter: public Ui_FormReachedFilter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMREACHEDFILTER_H
