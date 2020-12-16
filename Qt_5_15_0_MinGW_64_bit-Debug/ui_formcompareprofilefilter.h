/********************************************************************************
** Form generated from reading UI file 'formcompareprofilefilter.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMCOMPAREPROFILEFILTER_H
#define UI_FORMCOMPAREPROFILEFILTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormCompareProfileFilter
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *LabelReached;
    QLabel *LabelAll;
    QLabel *LabelNotReached;
    QSlider *Slider;

    void setupUi(QWidget *FormCompareProfileFilter)
    {
        if (FormCompareProfileFilter->objectName().isEmpty())
            FormCompareProfileFilter->setObjectName(QString::fromUtf8("FormCompareProfileFilter"));
        FormCompareProfileFilter->resize(84, 30);
        QFont font;
        font.setFamily(QString::fromUtf8("Ebrima"));
        FormCompareProfileFilter->setFont(font);
        verticalLayout = new QVBoxLayout(FormCompareProfileFilter);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        LabelReached = new QLabel(FormCompareProfileFilter);
        LabelReached->setObjectName(QString::fromUtf8("LabelReached"));
        LabelReached->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        horizontalLayout->addWidget(LabelReached);

        LabelAll = new QLabel(FormCompareProfileFilter);
        LabelAll->setObjectName(QString::fromUtf8("LabelAll"));
        LabelAll->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        horizontalLayout->addWidget(LabelAll);

        LabelNotReached = new QLabel(FormCompareProfileFilter);
        LabelNotReached->setObjectName(QString::fromUtf8("LabelNotReached"));
        LabelNotReached->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        horizontalLayout->addWidget(LabelNotReached);


        verticalLayout->addLayout(horizontalLayout);

        Slider = new QSlider(FormCompareProfileFilter);
        Slider->setObjectName(QString::fromUtf8("Slider"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Slider->sizePolicy().hasHeightForWidth());
        Slider->setSizePolicy(sizePolicy);
        Slider->setMaximum(2);
        Slider->setPageStep(1);
        Slider->setValue(1);
        Slider->setSliderPosition(1);
        Slider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(Slider);


        retranslateUi(FormCompareProfileFilter);

        QMetaObject::connectSlotsByName(FormCompareProfileFilter);
    } // setupUi

    void retranslateUi(QWidget *FormCompareProfileFilter)
    {
        FormCompareProfileFilter->setWindowTitle(QCoreApplication::translate("FormCompareProfileFilter", "Form", nullptr));
#if QT_CONFIG(tooltip)
        LabelReached->setToolTip(QCoreApplication::translate("FormCompareProfileFilter", "\320\237\320\276\320\273\321\203\321\207\320\265\320\275\320\276", nullptr));
#endif // QT_CONFIG(tooltip)
        LabelReached->setText(QString());
#if QT_CONFIG(tooltip)
        LabelAll->setToolTip(QCoreApplication::translate("FormCompareProfileFilter", "\320\222\321\201\320\265", nullptr));
#endif // QT_CONFIG(tooltip)
        LabelAll->setText(QString());
#if QT_CONFIG(tooltip)
        LabelNotReached->setToolTip(QCoreApplication::translate("FormCompareProfileFilter", "\320\235\320\265 \320\277\320\276\320\273\321\203\321\207\320\265\320\275\320\276", nullptr));
#endif // QT_CONFIG(tooltip)
        LabelNotReached->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FormCompareProfileFilter: public Ui_FormCompareProfileFilter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCOMPAREPROFILEFILTER_H
