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
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormReachedFilter
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *LabelReached;
    QLabel *LabelAll;
    QLabel *LabelNotReached;
    QSlider *Slider;

    void setupUi(QWidget *FormReachedFilter)
    {
        if (FormReachedFilter->objectName().isEmpty())
            FormReachedFilter->setObjectName(QString::fromUtf8("FormReachedFilter"));
        FormReachedFilter->resize(84, 30);
        QFont font;
        font.setFamily(QString::fromUtf8("Ebrima"));
        FormReachedFilter->setFont(font);
        verticalLayout = new QVBoxLayout(FormReachedFilter);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        LabelReached = new QLabel(FormReachedFilter);
        LabelReached->setObjectName(QString::fromUtf8("LabelReached"));
        LabelReached->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        horizontalLayout->addWidget(LabelReached);

        LabelAll = new QLabel(FormReachedFilter);
        LabelAll->setObjectName(QString::fromUtf8("LabelAll"));
        LabelAll->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        horizontalLayout->addWidget(LabelAll);

        LabelNotReached = new QLabel(FormReachedFilter);
        LabelNotReached->setObjectName(QString::fromUtf8("LabelNotReached"));
        LabelNotReached->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        horizontalLayout->addWidget(LabelNotReached);


        verticalLayout->addLayout(horizontalLayout);

        Slider = new QSlider(FormReachedFilter);
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
#if QT_CONFIG(tooltip)
        LabelAll->setToolTip(QCoreApplication::translate("FormReachedFilter", "\320\222\321\201\320\265", nullptr));
#endif // QT_CONFIG(tooltip)
        LabelAll->setText(QString());
#if QT_CONFIG(tooltip)
        LabelNotReached->setToolTip(QCoreApplication::translate("FormReachedFilter", "\320\235\320\265 \320\277\320\276\320\273\321\203\321\207\320\265\320\275\320\276", nullptr));
#endif // QT_CONFIG(tooltip)
        LabelNotReached->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FormReachedFilter: public Ui_FormReachedFilter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMREACHEDFILTER_H
