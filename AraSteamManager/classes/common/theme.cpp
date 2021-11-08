#include "theme.h"
#include "./settings.h"

Theme blueTheme() {
    QLinearGradient *gr1 = new QLinearGradient(0, -2, 0, 1);
    gr1->setColorAt(0, QColor(38, 146, 255));
    gr1->setColorAt(1, QColor(21, 50, 87));

    QLinearGradient *gr2 = new QLinearGradient(-1, -1, 2, 2);
    gr2->setColorAt(0, QColor(57, 152, 236));
    gr2->setColorAt(1, QColor(35, 95, 207));

    QRadialGradient *gr3 = new QRadialGradient(0.5, 0.5, 0.9, 0.4, 0.5);
    gr3->setColorAt(0, QColor(18, 69, 124));
    gr3->setColorAt(1, QColor(25, 37, 61));

    Theme theme;
    theme.text.setColor(QColor(221, 221, 221));
    theme.disabledBackground.setColor(QColor(20, 80, 110));
    theme.disabled.setColor(QColor(120, 120, 120));
    theme.hover.setColor(QColor(20, 140, 210));
    theme.border.setColor(QColor(50, 65, 75));
    theme.alternate.setColor(QColor(25, 35, 45));
    theme.background.setColor(QColor(19, 36, 62));
    theme.backgroundSelectedItem.setColor(QColor(38, 146, 255), gr1);
    theme.backgroundSecond.setColor(QColor(57, 152, 236), gr2);
    theme.backgroundProgressbar.setColor(QColor(93, 170, 224));
    theme.backgroundBadProgressbar.setColor(QColor(228, 75, 75));
    theme.backgroundProgressbarProgress.setColor(QColor(56, 101, 132));
    theme.selected.setColor(QColor(135, 182, 255));
    theme.headerForm.setColor(QColor(30, 41, 59));
    theme.backgroundItem.setColor(QColor(23, 26, 33));
    theme.backgroundAlternateItem.setColor(QColor(29, 32, 39));
    theme.forItemHover.setColor(QColor(43, 46, 53));
    theme.mainProfileBackground.setColor(QColor(37, 60, 94));
    theme.mainBackground.setColor(QColor(18, 69, 124), gr3);
    theme.setPathIcons(":/theme/iconsBlueTheme/");
    return theme;
}

Theme whiteTheme() {
    QLinearGradient *gr1 = new QLinearGradient(0, 0, 0, 1);
    gr1->setColorAt(0, QColor("E1E1E1"));
    gr1->setColorAt(0.4, QColor("DDDDDD"));
    gr1->setColorAt(0.5, QColor("D8D8D8"));
    gr1->setColorAt(1, QColor("D3D3D3"));

    QRadialGradient *gr2 = new QRadialGradient(0.5, 0.5, 0.9, 0.4, 0.5);
    gr2->setColorAt(0, QColor("ffffff"));
    gr2->setColorAt(1, QColor("777777"));

    Theme theme;
    theme.text.setColor(QColor(15, 15, 25));
    theme.disabledBackground.setColor(QColor(130, 130, 130));
    theme.disabled.setColor(QColor(150, 150, 150));
    theme.hover.setColor(QColor(255, 213, 180));
    theme.border.setColor(QColor(50, 50, 50));
    theme.alternate.setColor(QColor(230, 220, 210));
    theme.background.setColor(QColor(236, 236, 236));
    theme.backgroundSelectedItem.setColor(QColor(110, 110, 110, 255 * 0.7));
    theme.backgroundSecond.setColor(QColor("DDDDDD"), gr1);
    theme.backgroundProgressbar.setColor(QColor(199, 154, 123));
    theme.backgroundBadProgressbar.setColor(QColor(7, 180, 180));
    theme.backgroundProgressbarProgress.setColor(QColor(200, 180, 150));
    theme.selected.setColor(QColor(120, 73, 0));
    theme.headerForm.setColor(QColor(130, 130, 130));
    theme.backgroundItem.setColor(QColor(120, 120, 120));
    theme.backgroundAlternateItem.setColor(QColor(170, 170, 170));
    theme.forItemHover.setColor(QColor(80, 80, 80));
    theme.mainProfileBackground.setColor(QColor(100, 100, 100));
    theme.mainBackground.setColor(QColor(255, 255, 255), gr2);
    theme.setPathIcons(":/theme/iconsWhiteTheme/");
    return theme;
}

Theme blackTheme() {
    QRadialGradient *gr1 = new QRadialGradient(0.5, 0.5, 0.9, 0.4, 0.5);
    gr1->setColorAt(0, QColor("000000"));
    gr1->setColorAt(1, QColor("252525"));

    Theme theme;
    theme.text.setColor(QColor(240, 240, 240));
    theme.disabledBackground.setColor(QColor(120, 120, 120));
    theme.disabled.setColor(QColor(120, 120, 120));
    theme.hover.setColor(QColor(20, 100, 160));
    theme.border.setColor(QColor(60, 60, 60));
    theme.alternate.setColor(QColor(25, 35, 45));
    theme.background.setColor(QColor(19, 19, 19));
    theme.backgroundSelectedItem.setColor(QColor(11, 11, 11, 255 * 0.7));
    theme.backgroundSecond.setColor(QColor(80, 95, 105));
    theme.backgroundProgressbar.setColor(QColor(93, 170, 224));
    theme.backgroundBadProgressbar.setColor(QColor(228, 75, 75));
    theme.backgroundProgressbarProgress.setColor(QColor(56, 101, 132));
    theme.selected.setColor(QColor(135, 182, 255));
    theme.headerForm.setColor(QColor(30, 30, 30));
    theme.backgroundItem.setColor(QColor(11, 11, 11));
    theme.backgroundAlternateItem.setColor(QColor(29, 32, 39));
    theme.forItemHover.setColor(QColor(11, 11, 11));
    theme.mainProfileBackground.setColor(QColor(70, 70, 70));
    theme.mainBackground.setColor(QColor(0, 0, 0), gr1);
    theme.setPathIcons(":/theme/iconsBlackTheme/");
    return theme;
}

Theme orangeTheme() {
    QLinearGradient *gr1 = new QLinearGradient(0, -2, 0, 1);
    gr1->setColorAt(0, QColor(255, 146, 38));
    gr1->setColorAt(1, QColor(87, 50, 21));

    QLinearGradient *gr2 = new QLinearGradient(-1, -1, 2, 2);
    gr2->setColorAt(0, QColor(236, 152, 57));
    gr2->setColorAt(1, QColor(207, 95, 35));

    QRadialGradient *gr3 = new QRadialGradient(0.5, 0.5, 0.9, 0.4, 0.5);
    gr3->setColorAt(0, QColor(124, 69, 18));
    gr3->setColorAt(1, QColor(61, 37, 25));

    Theme theme;
    theme.text.setColor(QColor(221, 221, 221));
    theme.disabledBackground.setColor(QColor(110, 80, 20));
    theme.disabled.setColor(QColor(120, 120, 120));
    theme.hover.setColor(QColor(210, 140, 20));
    theme.border.setColor(QColor(75, 65, 50));
    theme.alternate.setColor(QColor(45, 35, 24));
    theme.background.setColor(QColor(62, 36, 19));
    theme.backgroundSelectedItem.setColor(QColor(255, 146, 38), gr1);
    theme.backgroundSecond.setColor(QColor(236, 152, 57), gr2);
    theme.backgroundProgressbar.setColor(QColor(224, 170, 93));
    theme.backgroundBadProgressbar.setColor(QColor(75, 75, 228));
    theme.backgroundProgressbarProgress.setColor(QColor(132, 101, 56));
    theme.selected.setColor(QColor(255, 182, 135));
    theme.headerForm.setColor(QColor(59, 41, 30));
    theme.backgroundItem.setColor(QColor(33, 26, 23));
    theme.backgroundAlternateItem.setColor(QColor(39, 32, 29));
    theme.forItemHover.setColor(QColor(53, 46, 43));
    theme.mainProfileBackground.setColor(QColor(94, 60, 37));
    theme.mainBackground.setColor(QColor(124, 69, 18), gr3);
    theme.setPathIcons(":/theme/iconsBlackTheme/");
    return theme;
}

Theme crimsonTheme() {
    QLinearGradient *gr1 = new QLinearGradient(0, -2, 0, 1);
    gr1->setColorAt(0, QColor(255, 38, 146));
    gr1->setColorAt(1, QColor(87, 21, 50));

    QLinearGradient *gr2 = new QLinearGradient(-1, -1, 2, 2);
    gr2->setColorAt(0, QColor(236, 57, 152));
    gr2->setColorAt(1, QColor(207, 35, 95));

    QRadialGradient *gr3 = new QRadialGradient(0.5, 0.5, 0.9, 0.4, 0.5);
    gr3->setColorAt(0, QColor(124, 18, 69));
    gr3->setColorAt(1, QColor(61, 25, 37));

    Theme theme;
    theme.text.setColor(QColor(221, 221, 221));
    theme.disabledBackground.setColor(QColor(110, 20, 80));
    theme.disabled.setColor(QColor(120, 120, 120));
    theme.hover.setColor(QColor(210, 20, 140));
    theme.border.setColor(QColor(75, 50, 65));
    theme.alternate.setColor(QColor(45, 25, 35));
    theme.background.setColor(QColor(62, 19, 36));
    theme.backgroundSelectedItem.setColor(QColor(255, 38, 146), gr1);
    theme.backgroundSecond.setColor(QColor(236, 57, 152), gr2);
    theme.backgroundProgressbar.setColor(QColor(224, 93, 170));
    theme.backgroundBadProgressbar.setColor(QColor(75, 228, 75));
    theme.backgroundProgressbarProgress.setColor(QColor(132, 56, 101));
    theme.selected.setColor(QColor(255, 135, 182));
    theme.headerForm.setColor(QColor(59, 30, 41));
    theme.backgroundItem.setColor(QColor(33, 23, 26));
    theme.backgroundAlternateItem.setColor(QColor(39, 29, 32));
    theme.forItemHover.setColor(QColor(53, 43, 46));
    theme.mainProfileBackground.setColor(QColor(94, 37, 60));
    theme.mainBackground.setColor(QColor(124, 18, 69), gr3);
    theme.setPathIcons(":/theme/iconsBlackTheme/");
    return theme;
}

Theme limeTheme() {
    QLinearGradient *gr1 = new QLinearGradient(0, -2, 0, 1);
    gr1->setColorAt(0, QColor(146, 255, 38));
    gr1->setColorAt(1, QColor(50, 87, 21));

    QLinearGradient *gr2 = new QLinearGradient(-1, -1, 2, 2);
    gr2->setColorAt(0, QColor(152, 206, 57));
    gr2->setColorAt(1, QColor(95, 177, 35));

    QRadialGradient *gr3 = new QRadialGradient(0.5, 0.5, 0.9, 0.4, 0.5);
    gr3->setColorAt(0, QColor(69, 124, 18));
    gr3->setColorAt(1, QColor(37, 61, 25));

    Theme theme;
    theme.text.setColor(QColor(221, 221, 221));
    theme.disabledBackground.setColor(QColor(80, 110, 20));
    theme.disabled.setColor(QColor(120, 120, 120));
    theme.hover.setColor(QColor(140, 210, 20));
    theme.border.setColor(QColor(65, 75, 50));
    theme.alternate.setColor(QColor(35, 45, 25));
    theme.background.setColor(QColor(36, 62, 19));
    theme.backgroundSelectedItem.setColor(QColor(146, 255, 38), gr1);
    theme.backgroundSecond.setColor(QColor(152, 206, 57), gr2);
    theme.backgroundProgressbar.setColor(QColor(170, 224, 93));
    theme.backgroundBadProgressbar.setColor(QColor(75, 75, 228));
    theme.backgroundProgressbarProgress.setColor(QColor(101, 132, 56));
    theme.selected.setColor(QColor(182, 255, 135));
    theme.headerForm.setColor(QColor(41, 59, 30));
    theme.backgroundItem.setColor(QColor(26, 33, 23));
    theme.backgroundAlternateItem.setColor(QColor(32, 39, 29));
    theme.forItemHover.setColor(QColor(46, 53, 43));
    theme.mainProfileBackground.setColor(QColor(60, 94, 37));
    theme.mainBackground.setColor(QColor(69, 124, 18), gr3);
    theme.setPathIcons(":/theme/iconsBlackTheme/");
    return theme;
}

Theme purpleTheme() {
    QLinearGradient *gr1 = new QLinearGradient(0, -2, 0, 1);
    gr1->setColorAt(0, QColor(146, 38, 255));
    gr1->setColorAt(1, QColor(50, 21, 87));

    QLinearGradient *gr2 = new QLinearGradient(-1, -1, 2, 2);
    gr2->setColorAt(0, QColor(152, 57, 236));
    gr2->setColorAt(1, QColor(95, 35, 207));

    QRadialGradient *gr3 = new QRadialGradient(0.5, 0.5, 0.9, 0.4, 0.5);
    gr3->setColorAt(0, QColor(69, 18, 124));
    gr3->setColorAt(1, QColor(37, 25, 61));

    Theme theme;
    theme.text.setColor(QColor(221, 221, 221));
    theme.disabledBackground.setColor(QColor(80, 20, 110));
    theme.disabled.setColor(QColor(120, 120, 120));
    theme.hover.setColor(QColor(140, 20, 210));
    theme.border.setColor(QColor(65, 50, 75));
    theme.alternate.setColor(QColor(35, 25, 45));
    theme.background.setColor(QColor(36, 19, 62));
    theme.backgroundSelectedItem.setColor(QColor(146, 38, 255), gr1);
    theme.backgroundSecond.setColor(QColor(152, 57, 236), gr2);
    theme.backgroundProgressbar.setColor(QColor(170, 93, 224));
    theme.backgroundBadProgressbar.setColor(QColor(75, 228, 75));
    theme.backgroundProgressbarProgress.setColor(QColor(101, 56, 132));
    theme.selected.setColor(QColor(182, 135, 255));
    theme.headerForm.setColor(QColor(41, 30, 59));
    theme.backgroundItem.setColor(QColor(26, 23, 33));
    theme.backgroundAlternateItem.setColor(QColor(32, 29, 39));
    theme.forItemHover.setColor(QColor(46, 43, 53));
    theme.mainProfileBackground.setColor(QColor(60, 37, 94));
    theme.mainBackground.setColor(QColor(69, 18, 124), gr3);
    theme.setPathIcons(":/theme/iconsBlackTheme/");
    return theme;
}

Theme greenTheme() {
    QLinearGradient *gr1 = new QLinearGradient(0, -2, 0, 1);
    gr1->setColorAt(0, QColor(38, 255, 146));
    gr1->setColorAt(1, QColor(21, 87, 50));

    QLinearGradient *gr2 = new QLinearGradient(-1, -1, 2, 2);
    gr2->setColorAt(0, QColor(57, 206, 152));
    gr2->setColorAt(1, QColor(35, 177, 95));

    QRadialGradient *gr3 = new QRadialGradient(0.5, 0.5, 0.9, 0.4, 0.5);
    gr3->setColorAt(0, QColor(18, 124, 69));
    gr3->setColorAt(1, QColor(25, 61, 37));

    Theme theme;
    theme.text.setColor(QColor(221, 221, 221));
    theme.disabledBackground.setColor(QColor(20, 110, 80));
    theme.disabled.setColor(QColor(120, 120, 120));
    theme.hover.setColor(QColor(20, 210, 140));
    theme.border.setColor(QColor(50, 75, 65));
    theme.alternate.setColor(QColor(25, 45, 35));
    theme.background.setColor(QColor(19, 62, 36));
    theme.backgroundSelectedItem.setColor(QColor(38, 255, 146), gr1);
    theme.backgroundSecond.setColor(QColor(57, 206, 152), gr2);
    theme.backgroundProgressbar.setColor(QColor(93, 224, 170));
    theme.backgroundBadProgressbar.setColor(QColor(228, 75, 75));
    theme.backgroundProgressbarProgress.setColor(QColor(56, 132, 101));
    theme.selected.setColor(QColor(135, 255, 182));
    theme.headerForm.setColor(QColor(30, 59, 41));
    theme.backgroundItem.setColor(QColor(23, 33, 26));
    theme.backgroundAlternateItem.setColor(QColor(29, 39, 32));
    theme.forItemHover.setColor(QColor(43, 53, 46));
    theme.mainProfileBackground.setColor(QColor(37, 94, 60));
    theme.mainBackground.setColor(QColor(18, 124, 69), gr3);
    theme.setPathIcons(":/theme/iconsBlackTheme/");
    return theme;
}

Theme &Theme::setPathIcons(const QString &aPath) {
    pathIcons = aPath;
    return *this;
}

QString Theme::getPathIcons() {
    return pathIcons;
}

Theme Theme::getCurrentTheme() {
    switch(Settings::theme()) {
    //default: {
        // Настраиваем палитру для цветовых ролей элементов интерфейса
        //    darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
        //    darkPalette.setColor(QPalette::WindowText, Qt::white);
        //    darkPalette.setColor(QPalette::Base, QColor(25, 25, 25));
        //    darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
        //    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
        //    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
        //    darkPalette.setColor(QPalette::Text, Qt::white);
        //    darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
        //    darkPalette.setColor(QPalette::ButtonText, Qt::white);
        //    darkPalette.setColor(QPalette::BrightText, Qt::red);
        //    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
        //    darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
        //    darkPalette.setColor(QPalette::HighlightedText, Qt::black);
        // Устанавливаем данную палитру
            // Для возврата к светлой палитре достаточно
            // будет установить стандартную палитру из темы оформления
            //qApp->setPalette(style()->standardPalette());
    //}
    case 1:{//Синяя
        return blueTheme();
    }
    case 2:{//Белая
        return whiteTheme();
    }
    case 3:{//Черная
        return blackTheme();
    }
    case 4:{//Оранжевая
        return orangeTheme();
    }
    case 5:{//Малиновая
        return crimsonTheme();
    }
    case 6:{//Лаймовая
        return limeTheme();
    }
    case 7:{//Фиолетовая
        return purpleTheme();
    }
    case 8:{//Зеленая
        return greenTheme();
    }
    default: {
        QFile file(Paths::documents() + "theme\\colors.txt");
        file.open(QFile::ReadOnly);

        Theme currentTheme;
        currentTheme.text.setColor                          (QString(file.readLine()).remove("\r").remove("\n"));
        currentTheme.disabledBackground.setColor            (QString(file.readLine()).remove("\r").remove("\n"));
        currentTheme.disabled.setColor                      (QString(file.readLine()).remove("\r").remove("\n"));
        currentTheme.hover.setColor                         (QString(file.readLine()).remove("\r").remove("\n"));
        currentTheme.border.setColor                        (QString(file.readLine()).remove("\r").remove("\n"));
        currentTheme.alternate.setColor                     (QString(file.readLine()).remove("\r").remove("\n"));
        currentTheme.background.setColor                    (QString(file.readLine()).remove("\r").remove("\n"));
        currentTheme.backgroundSelectedItem.setColor        (QString(file.readLine()).remove("\r").remove("\n"));
        currentTheme.backgroundSecond.setColor              (QString(file.readLine()).remove("\r").remove("\n"));
        currentTheme.backgroundProgressbar.setColor         (QString(file.readLine()).remove("\r").remove("\n"));
        currentTheme.backgroundBadProgressbar.setColor      (QString(file.readLine()).remove("\r").remove("\n"));
        currentTheme.backgroundProgressbarProgress.setColor (QString(file.readLine()).remove("\r").remove("\n"));
        currentTheme.selected.setColor                      (QString(file.readLine()).remove("\r").remove("\n"));
        currentTheme.headerForm.setColor                    (QString(file.readLine()).remove("\r").remove("\n"));
        currentTheme.backgroundItem.setColor                (QString(file.readLine()).remove("\r").remove("\n"));
        currentTheme.backgroundAlternateItem.setColor       (QString(file.readLine()).remove("\r").remove("\n"));
        currentTheme.forItemHover.setColor                  (QString(file.readLine()).remove("\r").remove("\n"));
        currentTheme.mainProfileBackground.setColor         (QString(file.readLine()).remove("\r").remove("\n"));
        currentTheme.mainBackground.setColor                (QString(file.readLine()).remove("\r").remove("\n"));
        currentTheme.setPathIcons                           (Paths::documents() + "theme/");
        file.close();
        return currentTheme;
//        QString textColor = QString(file.readLine()).remove("\r").remove("\n");
//        QString labelValue = QString(file.readLine()).remove("\r").remove("\n");
//        QString hoverColor = QString(file.readLine()).remove("\r").remove("\n");
//        QString disabledColor = QString(file.readLine()).remove("\r").remove("\n");
//        QString borderColor = QString(file.readLine()).remove("\r").remove("\n");
//        QString disabeledBorderColor = QString(file.readLine()).remove("\r").remove("\n");
//        QString backgroundColor = QString(file.readLine()).remove("\r").remove("\n");
//        QString disabledBackgroundColor = QString(file.readLine()).remove("\r").remove("\n");
//        QString gradientBackgroundColor = QString(file.readLine()).remove("\r").remove("\n");
//        QString disabledGradientBackgroundColor = QString(file.readLine()).remove("\r").remove("\n");
//        QString handlesBackgroundColor = QString(file.readLine()).remove("\r").remove("\n");
//        QString mainBackground = QString(file.readLine()).remove("\r").remove("\n");
//        QString pathIcons = Paths::documents() + "theme/";
//        file.close();
//        QFile qssColorFile(":/theme/greenTheme.qss");
//        qssColorFile.open(QFile::ReadOnly);
//        qss = QString(qssColorFile.readAll()).arg(textColor,
//                                                  labelValue,
//                                                  hoverColor,
//                                                  disabledColor,
//                                                  borderColor,
//                                                  disabeledBorderColor,
//                                                  backgroundColor,
//                                                  disabledBackgroundColor,
//                                                  gradientBackgroundColor,
//                                                  disabledGradientBackgroundColor,
//                                                  handlesBackgroundColor,
//                                                  mainBackground);
//        QFile qssIconsFile(":/theme/baseIcons.qss");
//        qssIconsFile.open(QFile::ReadOnly);
//        qss += QString(qssIconsFile.readAll()).arg(pathIcons);

//        QFile qssFile(":/theme/globalTheme.qss");
//        qssFile.open(QFile::ReadOnly);
//        qss += qssFile.readAll();
//        qss += " "
//        "* { "
//           "font-family:  " + Settings::defaultFont() + "; "
//        "} ";

//        return qss;
    }
    }
}

QString Theme::getText(const QColor &aColor, QGradient *aGradient) {
    if (aGradient) {
        if (aGradient->type() == QGradient::RadialGradient) {
            auto gradient = static_cast<QRadialGradient*>(aGradient);
            QStringList stops;
            for (auto stop: gradient->stops().toList()) {
                stops.append(QString("stop: %1 %2").arg(QString::number(stop.first), stop.second.name(QColor::HexArgb)));
            }
            return QString("qradialgradient(cx:%1, cy:%2, radius: %3, fx:%4, fy:%5, %6)").arg(
                        QString::number(gradient->center().x()),
                        QString::number(gradient->center().y()),
                        QString::number(gradient->radius()),
                        QString::number(gradient->focalPoint().x()),
                        QString::number(gradient->focalPoint().y()),
                        stops.join(", "));
        }
        if (aGradient->type() == QGradient::LinearGradient) {
            auto gradient = static_cast<QLinearGradient*>(aGradient);
            QStringList stops;
            for (auto stop: gradient->stops().toList()) {
                stops.append(QString("stop: %1 %2").arg(QString::number(stop.first), stop.second.name(QColor::HexArgb)));
            }
            return QString("qlineargradient(x1: %1, y1: %2, x2: %3, y2: %4, %5)").arg(
                        QString::number(gradient->start().x()),
                        QString::number(gradient->start().y()),
                        QString::number(gradient->finalStop().x()),
                        QString::number(gradient->finalStop().y()),
                        stops.join(", "));
        }
    }
    return aColor.name();
}

void ThemeColor::setColor(const QColor &aColor, QGradient *aGradient) {
    color = aColor;
    gradient = aGradient;
}
#include <QRegularExpression>
void ThemeColor::setColor(const QString &aColor) {
    if (aColor.indexOf("qradialgradient") > -1) {
        QRegularExpression regExp("qradialgradient\\(cx:([^,]+), cy:([^,]+), radius: ([^,]+), fx:([^,]+), fy:([^,]+)((, stop: ([^ ]+) (#\\w\\w\\w\\w\\w\\w\\w\\w))+)\\)");
        if (regExp.match(aColor).hasMatch()) {
            QRadialGradient *curGradient = new QRadialGradient(regExp.match(aColor).captured(1).toFloat(),
                                     regExp.match(aColor).captured(2).toFloat(),
                                     regExp.match(aColor).captured(3).toFloat(),
                                     regExp.match(aColor).captured(4).toFloat(),
                                     regExp.match(aColor).captured(5).toFloat());
            QStringList list = regExp.match(aColor).captured(6).split(", ");
            QRegularExpression regExp2("stop: ([^ ]+) (#\\w\\w\\w\\w\\w\\w\\w\\w)");
            QColor col("#------");
            for (const QString &stop: list) {
                if (regExp2.match(stop).hasMatch()) {
                    curGradient->setColorAt(regExp2.match(stop).captured(1).toFloat(), QColor(regExp2.match(stop).captured(2)));
                    if (!col.isValid()) {
                        col.setNamedColor(regExp2.match(stop).captured(2));
                    }
                }
            }
            color = col;
            gradient = curGradient;
            return;
        }
    }
    if (aColor.indexOf("qlineargradient") > -1) {
        QRegularExpression regExp("qlineargradient\\(x1: ([^,]+), y1: ([^,]+), x2: ([^,]+), y2: ([^,]+)((, stop: ([^ ]+) (#\\w\\w\\w\\w\\w\\w\\w\\w))+)\\)");
        if (regExp.match(aColor).hasMatch()) {
            QLinearGradient *curGradient = new QLinearGradient(regExp.match(aColor).captured(1).toFloat(),
                                     regExp.match(aColor).captured(2).toFloat(),
                                     regExp.match(aColor).captured(3).toFloat(),
                                     regExp.match(aColor).captured(4).toFloat());
            QStringList list = regExp.match(aColor).captured(5).split(", ");
            QRegularExpression regExp2("stop: ([^ ]+) (#\\w\\w\\w\\w\\w\\w\\w\\w)");
            QColor col("#------");
            for (const QString &stop: list) {
                if (regExp2.match(stop).hasMatch()) {
                    curGradient->setColorAt(regExp2.match(stop).captured(1).toFloat(), QColor(regExp2.match(stop).captured(2)));
                    if (!col.isValid()) {
                        col.setNamedColor(regExp2.match(stop).captured(2));
                    }
                }
            }
            color = col;
            gradient = curGradient;
            return;
        }
    }
    color = QColor(aColor);
}

QColor ThemeColor::getColor() {
    return color;
}

QString ThemeColor::getString() {
    if (gradient) {
        QStringList stops;
        for (auto stop: gradient->stops().toList()) {
            stops.append(QString("stop: %1 %2").arg(QString::number(stop.first), stop.second.name()));
        }
        if (gradient->type() == QGradient::RadialGradient) {
            auto curGradient = static_cast<QRadialGradient*>(gradient);
            return QString("qradialgradient(spread:pad, cx:%1, cy:%2, radius: %3, fx:%4, fy:%5, %6)").arg(
                        QString::number(curGradient->center().x()),
                        QString::number(curGradient->center().y()),
                        QString::number(curGradient->radius()),
                        QString::number(curGradient->focalPoint().x()),
                        QString::number(curGradient->focalPoint().y()),
                        stops.join(", "));
        }
        if (gradient->type() == QGradient::LinearGradient) {
            auto curGradient = static_cast<QLinearGradient*>(gradient);
            return QString("qlineargradient(spread:pad, x1: %1, y1: %2, x2: %3, y2: %4, %5)").arg(
                        QString::number(curGradient->start().x()),
                        QString::number(curGradient->start().y()),
                        QString::number(curGradient->finalStop().x()),
                        QString::number(curGradient->finalStop().y()),
                        stops.join(", "));
        }
    }
    return color.name();
}
