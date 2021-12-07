#include "theme.h"
#include "./settings.h"
#include <QRegularExpression>

Theme blueTheme() {
    QLinearGradient gr1(0, -2, 0, 1);
    gr1.setColorAt(0, QColor(38, 146, 255));
    gr1.setColorAt(1, QColor(21, 50, 87));

    QLinearGradient gr2(-1, -1, 2, 2);
    gr2.setColorAt(0, QColor(57, 152, 236));
    gr2.setColorAt(1, QColor(35, 95, 207));

    QRadialGradient gr3(0.5, 0.5, 0.9, 0.4, 0.5);
    gr3.setColorAt(0, QColor(18, 69, 124));
    gr3.setColorAt(1, QColor(25, 37, 61));

    Theme theme;
    theme.text.setColor(QColor(221, 221, 221));
    theme.disabledBackground.setColor(QColor(56, 94, 127));
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
    theme.setPathImages("://white/");
    return theme;
}

Theme whiteTheme() {
    QLinearGradient gr1(0, 0, 0, 1);
    gr1.setColorAt(0, QColor("E1E1E1"));
    gr1.setColorAt(0.4, QColor("DDDDDD"));
    gr1.setColorAt(0.5, QColor("D8D8D8"));
    gr1.setColorAt(1, QColor("D3D3D3"));

    QRadialGradient gr2(0.5, 0.5, 0.9, 0.4, 0.5);
    gr2.setColorAt(0, QColor("ffffff"));
    gr2.setColorAt(1, QColor("777777"));

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
    theme.setPathImages("://black/");
    return theme;
}

Theme blackTheme() {
    QRadialGradient gr1(0.5, 0.5, 0.9, 0.4, 0.5);
    gr1.setColorAt(0, QColor("000000"));
    gr1.setColorAt(1, QColor("252525"));

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
    theme.setPathImages("://white/");
    return theme;
}

Theme orangeTheme() {
    Theme theme = blueTheme();
    theme.swapPartsAllColors(PartColor::red, PartColor::blue);
    theme.setPathIcons(":/theme/iconsBlackTheme/");
    theme.setPathImages("://white/");
    return theme;
}

Theme crimsonTheme() {
    Theme theme = blueTheme();
    theme.swapPartsAllColors(PartColor::red, PartColor::blue).swapPartsAllColors(PartColor::green, PartColor::blue);
//    QLinearGradient gr1(0, -2, 0, 1);
//    gr1.setColorAt(0, QColor(255, 38, 146));
//    gr1.setColorAt(1, QColor(87, 21, 50));

//    QLinearGradient gr2(-1, -1, 2, 2);
//    gr2.setColorAt(0, QColor(236, 57, 152));
//    gr2.setColorAt(1, QColor(207, 35, 95));

//    QRadialGradient gr3(0.5, 0.5, 0.9, 0.4, 0.5);
//    gr3.setColorAt(0, QColor(124, 18, 69));
//    gr3.setColorAt(1, QColor(61, 25, 37));

//    Theme theme;
//    theme.text.setColor(QColor(221, 221, 221));
//    theme.disabledBackground.setColor(QColor(110, 20, 80));
//    theme.disabled.setColor(QColor(120, 120, 120));
//    theme.hover.setColor(QColor(210, 20, 140));
//    theme.border.setColor(QColor(75, 50, 65));
//    theme.alternate.setColor(QColor(45, 25, 35));
//    theme.background.setColor(QColor(62, 19, 36));
//    theme.backgroundSelectedItem.setColor(QColor(255, 38, 146), gr1);
//    theme.backgroundSecond.setColor(QColor(236, 57, 152), gr2);
//    theme.backgroundProgressbar.setColor(QColor(224, 93, 170));
//    theme.backgroundBadProgressbar.setColor(QColor(75, 228, 75));
//    theme.backgroundProgressbarProgress.setColor(QColor(132, 56, 101));
//    theme.selected.setColor(QColor(255, 135, 182));
//    theme.headerForm.setColor(QColor(59, 30, 41));
//    theme.backgroundItem.setColor(QColor(33, 23, 26));
//    theme.backgroundAlternateItem.setColor(QColor(39, 29, 32));
//    theme.forItemHover.setColor(QColor(53, 43, 46));
//    theme.mainProfileBackground.setColor(QColor(94, 37, 60));
//    theme.mainBackground.setColor(QColor(124, 18, 69), gr3);
    theme.setPathIcons(":/theme/iconsBlackTheme/");
    theme.setPathImages("://white/");
    return theme;
}

Theme limeTheme() {
    Theme theme = blueTheme();
    theme.swapPartsAllColors(PartColor::red, PartColor::blue).swapPartsAllColors(PartColor::green, PartColor::red);
//    QLinearGradient gr1(0, -2, 0, 1);
//    gr1.setColorAt(0, QColor(146, 255, 38));
//    gr1.setColorAt(1, QColor(50, 87, 21));

//    QLinearGradient gr2(-1, -1, 2, 2);
//    gr2.setColorAt(0, QColor(152, 206, 57));
//    gr2.setColorAt(1, QColor(95, 177, 35));

//    QRadialGradient gr3(0.5, 0.5, 0.9, 0.4, 0.5);
//    gr3.setColorAt(0, QColor(69, 124, 18));
//    gr3.setColorAt(1, QColor(37, 61, 25));

//    Theme theme;
//    theme.text.setColor(QColor(221, 221, 221));
//    theme.disabledBackground.setColor(QColor(80, 110, 20));
//    theme.disabled.setColor(QColor(120, 120, 120));
//    theme.hover.setColor(QColor(140, 210, 20));
//    theme.border.setColor(QColor(65, 75, 50));
//    theme.alternate.setColor(QColor(35, 45, 25));
//    theme.background.setColor(QColor(36, 62, 19));
//    theme.backgroundSelectedItem.setColor(QColor(146, 255, 38), gr1);
//    theme.backgroundSecond.setColor(QColor(152, 206, 57), gr2);
//    theme.backgroundProgressbar.setColor(QColor(170, 224, 93));
//    theme.backgroundBadProgressbar.setColor(QColor(75, 75, 228));
//    theme.backgroundProgressbarProgress.setColor(QColor(101, 132, 56));
//    theme.selected.setColor(QColor(182, 255, 135));
//    theme.headerForm.setColor(QColor(41, 59, 30));
//    theme.backgroundItem.setColor(QColor(26, 33, 23));
//    theme.backgroundAlternateItem.setColor(QColor(32, 39, 29));
//    theme.forItemHover.setColor(QColor(46, 53, 43));
//    theme.mainProfileBackground.setColor(QColor(60, 94, 37));
//    theme.mainBackground.setColor(QColor(69, 124, 18), gr3);
    theme.setPathIcons(":/theme/iconsBlackTheme/");
    theme.setPathImages("://white/");
    return theme;
}

Theme purpleTheme() {
    Theme theme = blueTheme();
    theme.swapPartsAllColors(PartColor::red, PartColor::green);
//    QLinearGradient gr1(0, -2, 0, 1);
//    gr1.setColorAt(0, QColor(146, 38, 255));
//    gr1.setColorAt(1, QColor(50, 21, 87));

//    QLinearGradient gr2(-1, -1, 2, 2);
//    gr2.setColorAt(0, QColor(152, 57, 236));
//    gr2.setColorAt(1, QColor(95, 35, 207));

//    QRadialGradient gr3(0.5, 0.5, 0.9, 0.4, 0.5);
//    gr3.setColorAt(0, QColor(69, 18, 124));
//    gr3.setColorAt(1, QColor(37, 25, 61));

//    Theme theme;
//    theme.text.setColor(QColor(221, 221, 221));
//    theme.disabledBackground.setColor(QColor(80, 20, 110));
//    theme.disabled.setColor(QColor(120, 120, 120));
//    theme.hover.setColor(QColor(140, 20, 210));
//    theme.border.setColor(QColor(65, 50, 75));
//    theme.alternate.setColor(QColor(35, 25, 45));
//    theme.background.setColor(QColor(36, 19, 62));
//    theme.backgroundSelectedItem.setColor(QColor(146, 38, 255), gr1);
//    theme.backgroundSecond.setColor(QColor(152, 57, 236), gr2);
//    theme.backgroundProgressbar.setColor(QColor(170, 93, 224));
//    theme.backgroundBadProgressbar.setColor(QColor(75, 228, 75));
//    theme.backgroundProgressbarProgress.setColor(QColor(101, 56, 132));
//    theme.selected.setColor(QColor(182, 135, 255));
//    theme.headerForm.setColor(QColor(41, 30, 59));
//    theme.backgroundItem.setColor(QColor(26, 23, 33));
//    theme.backgroundAlternateItem.setColor(QColor(32, 29, 39));
//    theme.forItemHover.setColor(QColor(46, 43, 53));
//    theme.mainProfileBackground.setColor(QColor(60, 37, 94));
//    theme.mainBackground.setColor(QColor(69, 18, 124), gr3);
    theme.setPathIcons(":/theme/iconsBlackTheme/");
    theme.setPathImages("://white/");
    return theme;
}

Theme greenTheme() {
    Theme theme = blueTheme();
    theme.swapPartsAllColors(PartColor::green, PartColor::blue);
//    QLinearGradient gr1(0, -2, 0, 1);
//    gr1.setColorAt(0, QColor(38, 255, 146));
//    gr1.setColorAt(1, QColor(21, 87, 50));

//    QLinearGradient gr2(-1, -1, 2, 2);
//    gr2.setColorAt(0, QColor(57, 206, 152));
//    gr2.setColorAt(1, QColor(35, 177, 95));

//    QRadialGradient gr3(0.5, 0.5, 0.9, 0.4, 0.5);
//    gr3.setColorAt(0, QColor(18, 124, 69));
//    gr3.setColorAt(1, QColor(25, 61, 37));

//    Theme theme;
//    theme.text.setColor(QColor(221, 221, 221));
//    theme.disabledBackground.setColor(QColor(20, 110, 80));
//    theme.disabled.setColor(QColor(120, 120, 120));
//    theme.hover.setColor(QColor(20, 210, 140));
//    theme.border.setColor(QColor(50, 75, 65));
//    theme.alternate.setColor(QColor(25, 45, 35));
//    theme.background.setColor(QColor(19, 62, 36));
//    theme.backgroundSelectedItem.setColor(QColor(38, 255, 146), gr1);
//    theme.backgroundSecond.setColor(QColor(57, 206, 152), gr2);
//    theme.backgroundProgressbar.setColor(QColor(93, 224, 170));
//    theme.backgroundBadProgressbar.setColor(QColor(228, 75, 75));
//    theme.backgroundProgressbarProgress.setColor(QColor(56, 132, 101));
//    theme.selected.setColor(QColor(135, 255, 182));
//    theme.headerForm.setColor(QColor(30, 59, 41));
//    theme.backgroundItem.setColor(QColor(23, 33, 26));
//    theme.backgroundAlternateItem.setColor(QColor(29, 39, 32));
//    theme.forItemHover.setColor(QColor(43, 53, 46));
//    theme.mainProfileBackground.setColor(QColor(37, 94, 60));
//    theme.mainBackground.setColor(QColor(18, 124, 69), gr3);
    theme.setPathIcons(":/theme/iconsBlackTheme/");
    theme.setPathImages("://white/");
    return theme;
}

Theme &Theme::setPathIcons(const QString &aPath) {
    pathIcons = aPath;
    return *this;
}

QString Theme::getPathIcons() {
    return pathIcons;
}

Theme &Theme::setPathImages(const QString &aPath) {
    pathImages = aPath;
    return *this;
}

QString Theme::getPathImages() {
    return pathImages;
}

Theme &Theme::swapPartsAllColors(PartColor part1, PartColor part2) {
    text.swapPartColor(part1, part2);
    disabledBackground.swapPartColor(part1, part2);
    disabled.swapPartColor(part1, part2);
    hover.swapPartColor(part1, part2);
    border.swapPartColor(part1, part2);
    alternate.swapPartColor(part1, part2);
    background.swapPartColor(part1, part2);
    backgroundSelectedItem.swapPartColor(part1, part2);
    backgroundSecond.swapPartColor(part1, part2);
    backgroundProgressbar.swapPartColor(part1, part2);
    backgroundBadProgressbar.swapPartColor(part1, part2);
    backgroundProgressbarProgress.swapPartColor(part1, part2);
    selected.swapPartColor(part1, part2);
    headerForm.swapPartColor(part1, part2);
    backgroundItem.swapPartColor(part1, part2);
    backgroundAlternateItem.swapPartColor(part1, part2);
    forItemHover.swapPartColor(part1, part2);
    mainProfileBackground.swapPartColor(part1, part2);
    mainBackground.swapPartColor(part1, part2);
    return *this;
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
            for (const auto &stop: gradient->stops().toList()) {
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
            for (const auto &stop: gradient->stops().toList()) {
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

ThemeColor::~ThemeColor() {
    if (gradient) {
        delete gradient;
    }
}

void ThemeColor::setColor(const QColor &aColor, QGradient aGradient) {
    color = aColor;
    if (aGradient.type() != QGradient::NoGradient) {
        gradient = new QGradient(aGradient);
    }
}

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
            QColor col("------");
            for (const QString &stop: qAsConst(list)) {
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
            QColor col("------");
            for (const QString &stop: qAsConst(list)) {
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
        for (const auto &stop: gradient->stops().toList()) {
            stops.append(QString("stop: %1 %2").arg(QString::number(stop.first), stop.second.name(QColor::NameFormat::HexArgb)));
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
    return color.name(QColor::NameFormat::HexArgb);
}

ThemeColor &ThemeColor::setAlpha(int aAlpha) {
    if (gradient) {
        auto stops = gradient->stops();
        for (auto &stop: stops) {
            stop.second.setAlpha(aAlpha);
        }
        gradient->setStops(stops);
    }
    color.setAlpha(aAlpha);
    return *this;
}

ThemeColor &ThemeColor::swapPartColor(PartColor part1, PartColor part2) {
    if (gradient) {
        auto stops = gradient->stops();
        for (auto &stop: stops) {
            stop.second = Theme::swapParts(stop.second, part1, part2);
        }
        gradient->setStops(stops);
    }
    color = Theme::swapParts(color, part1, part2);
    return *this;
}

QColor Theme::combineColor(const QColor &aColor1, double aPercent1, const QColor &aColor2, double aPercent2) {
    double combinePercent = aPercent1 + aPercent2;
    QColor combineColor;
    combineColor.setRed(aColor1.red() * (aPercent1 / (combinePercent / 100) / 100) + aColor2.red() * (aPercent2 / (combinePercent / 100) / 100));
    combineColor.setGreen(aColor1.green() * (aPercent1 / (combinePercent / 100) / 100) + aColor2.green() * (aPercent2 / (combinePercent / 100) / 100));
    combineColor.setBlue(aColor1.blue() * (aPercent1 / (combinePercent / 100) / 100) + aColor2.blue() * (aPercent2 / (combinePercent / 100) / 100));
    combineColor.setAlpha(aColor1.alpha());
    return combineColor;
}

QColor Theme::swapParts(const QColor &aColor, PartColor aPart1, PartColor aPart2) {
    int colorPart1 = 0, colorPart2 = 0;
    QColor result(aColor);
    switch (aPart1) {
    case PartColor::red: {
        colorPart1 = aColor.red();
        break;
    }
    case PartColor::green: {
        colorPart1 = aColor.green();
        break;
    }
    case PartColor::blue: {
        colorPart1 = aColor.blue();
        break;
    }
    case PartColor::alpha: {
        colorPart1 = aColor.alpha();
        break;
    }
    }
    switch (aPart2) {
    case PartColor::red: {
        colorPart2 = aColor.red();
        result.setRed(colorPart1);
        break;
    }
    case PartColor::green: {
        colorPart2 = aColor.green();
        result.setGreen(colorPart1);
        break;
    }
    case PartColor::blue: {
        colorPart2 = aColor.blue();
        result.setBlue(colorPart1);
        break;
    }
    case PartColor::alpha: {
        colorPart2 = aColor.alpha();
        result.setAlpha(colorPart1);
        break;
    }
    }
    switch (aPart1) {
    case PartColor::red: {
        result.setRed(colorPart2);
        break;
    }
    case PartColor::green: {
        result.setGreen(colorPart2);
        break;
    }
    case PartColor::blue: {
        result.setBlue(colorPart2);
        break;
    }
    case PartColor::alpha: {
        result.setAlpha(colorPart2);
        break;
    }
    }
    return result;
}
//
QString defaultFontPath() {
    return "://JosefinSans-Italic-VariableFont_wght.ttf";
//    return "://DancingScript-VariableFont_wght.ttf";
//    return "://Comfortaa-VariableFont_wght.ttf";
}

QString Theme::defaultFont() {
    static int id = QFontDatabase::addApplicationFont(defaultFontPath());
    static QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    return family;
}

QString textFromFile(const QString &aFile) {
    QString result;
    QFile file(aFile);
    file.open(QFile::ReadOnly);
    result = QString(file.readAll());
    file.close();
    return result;
}

QString Theme::qssTheme() {
    QString qss;
    Theme currentTheme = Theme::getCurrentTheme();

//    qDebug() << "text=" << currentTheme.text.getString() <<
//            "\ntext=" << combineColor(currentTheme.backgroundSecond.getColor(), 0.7, Qt::black, 0.3).name() <<
//            "\ndisabled=" << currentTheme.disabled.getString() <<
//            "\nhover=" << currentTheme.hover.getString() <<
//            "\nborder=" << currentTheme.border.getString() <<
//            "\nalternate=" << currentTheme.alternate.getString() <<
//            "\nbackground=" << currentTheme.background.getString() <<
//            "\nbackgroundSelectedItem=" << currentTheme.backgroundSelectedItem.getString() <<
//            "\nbackgroundSecond=" << currentTheme.backgroundSecond.getString() <<
//            "\nbackgroundProgressbar=" << currentTheme.backgroundProgressbar.getString() <<
//            "\nbackgroundBadProgressbar=" << currentTheme.backgroundBadProgressbar.getString() <<
//            "\nbackgroundProgressbarProgress=" << currentTheme.backgroundProgressbarProgress.getString() <<
//            "\nselected=" << currentTheme.selected.getString() <<
//            "\nheaderForm=" << currentTheme.headerForm.setAlpha(255 * 0.5).getString() <<
//            "\nheaderForm=" << currentTheme.headerForm.setAlpha(255).getString() <<
//            "\nbackgroundItem=" << currentTheme.backgroundItem.setAlpha(255 * 0.5).getString() <<
//            "\nbackgroundItem=" << currentTheme.backgroundItem.setAlpha(255 * 0.8).getString() <<
//            "\nheaderForm=" << currentTheme.headerForm.setAlpha(255 * 0.8).getString() <<
//            "\nheaderForm=" << currentTheme.headerForm.setAlpha(255 * 0.7).getString() <<
//            "\nforItemHover=" << currentTheme.forItemHover.setAlpha(255 * 0.5).getString() <<
//            "\nmainProfileBackground=" << currentTheme.mainProfileBackground.setAlpha(255 * 0.5).getString() <<
//            "\nmainBackground=" << currentTheme.mainBackground.getString();

    qss = textFromFile(":/theme/baseColor.qss").arg(currentTheme.text.getString(),
                                                    currentTheme.hover.getString(),
                                                    currentTheme.border.getString(),
                                                    currentTheme.background.getString(),
                                                    combineColor(currentTheme.background.getColor(), 0.8, Qt::black, 0.2).name(QColor::NameFormat::HexArgb),//currentTheme.disabled.getString(),
                                                    currentTheme.backgroundSecond.getString(),
                                                    combineColor(currentTheme.backgroundSecond.getColor(), 0.65, Qt::black, 0.35).name(QColor::NameFormat::HexArgb),//currentTheme.disabledBackground.getString(),
                                                    currentTheme.alternate.getString(),
                                                    currentTheme.backgroundSelectedItem.getString(),
                                                    currentTheme.backgroundProgressbar.getString(),
                                                    currentTheme.backgroundProgressbarProgress.getString(),
                                                    currentTheme.headerForm.setAlpha(255 * 0.5).getString(),//View background + Profile frame background
                                                    currentTheme.headerForm.setAlpha(255).getString(),//Freeze row background
                                                    currentTheme.backgroundItem.setAlpha(255 * 0.5).getString(),//items background
                                                    currentTheme.forItemHover.setAlpha(255 * 0.5).getString(),//hovered items background
                                                    currentTheme.headerForm.setAlpha(255 * 0.8).getString(),//Modal frame background
                                                    currentTheme.mainProfileBackground.setAlpha(255 * 0.5).getString(),//Profile info 2 background
                                                    currentTheme.backgroundItem.setAlpha(255 * 0.8).getString(),//categories frame background
                                                    currentTheme.headerForm.setAlpha(255 * 0.7).getString(),//Main window header background
                                                    //11currentTheme.backgroundBadProgressbar.getString(),//
                                                    //13currentTheme.selected.getString(),//
                                              //14QString(QString::number(currentTheme.headerForm.getColor().red()) + ", " + QString::number(currentTheme.headerForm.getColor().green()) + ", " + QString::number(currentTheme.headerForm.getColor().blue())),
                                              //15QString(QString::number(currentTheme.backgroundItem.getColor().red()) + ", " + QString::number(currentTheme.backgroundItem.getColor().green()) + ", " + QString::number(currentTheme.backgroundItem.getColor().blue())),
                                              //16QString(QString::number(currentTheme.backgroundAlternateItem.getColor().red()) + ", " + QString::number(currentTheme.backgroundAlternateItem.getColor().green()) + ", " + QString::number(currentTheme.backgroundAlternateItem.getColor().blue())),
                                              //17QString(QString::number(currentTheme.forItemHover.getColor().red()) + ", " + QString::number(currentTheme.forItemHover.getColor().green()) + ", " + QString::number(currentTheme.forItemHover.getColor().blue())),
                                              //18QString(QString::number(currentTheme.mainProfileBackground.getColor().red()) + ", " + QString::number(currentTheme.mainProfileBackground.getColor().green()) + ", " + QString::number(currentTheme.mainProfileBackground.getColor().blue())),
                                                    currentTheme.mainBackground.getString());

    qss += textFromFile(":/theme/baseIcons.qss").arg(currentTheme.getPathIcons());
    qss += textFromFile(":/theme/globalTheme.qss");
    qss += " "
    "* { "
        "font-family:  " + defaultFont() + "; "
    "} ";

    return qss;
}
