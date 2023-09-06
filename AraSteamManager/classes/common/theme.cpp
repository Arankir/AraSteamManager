#include "theme.h"
#include "./settings.h"
#include "./generalfunctions.h"

#include <QFontDatabase>
#include <QDir>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

Theme::Theme() {

}

Theme::~Theme()
{
//    qDebug() << text.color << text.getGradient();
//    qDebug() << disabledBackground.color << disabledBackground.getGradient();
//    qDebug() << disabled.color << disabled.getGradient();
//    qDebug() << hover.color << hover.getGradient();
//    qDebug() << border.color << border.getGradient();
//    qDebug() << alternate.color << alternate.getGradient();
//    qDebug() << background.color << background.getGradient();
//    qDebug() << backgroundSelectedItem.color << backgroundSelectedItem.getGradient();
//    qDebug() << backgroundSecond.color << backgroundSecond.getGradient();
//    qDebug() << backgroundProgressbar.color << backgroundProgressbar.getGradient();
//    qDebug() << backgroundBadProgressbar.color << backgroundBadProgressbar.getGradient();
//    qDebug() << backgroundProgressbarProgress.color << backgroundProgressbarProgress.getGradient();
//    qDebug() << selected.color << selected.getGradient();
//    qDebug() << headerForm.color << headerForm.getGradient();
//    qDebug() << backgroundItem.color << backgroundItem.getGradient();
//    qDebug() << backgroundAlternateItem.color << backgroundAlternateItem.getGradient();
//    qDebug() << forItemHover.color << forItemHover.getGradient();
//    qDebug() << mainProfileBackground.color << mainProfileBackground.getGradient();
//    qDebug() << mainBackground.color << mainBackground.getGradient() << mainBackground.getGradient()->stops();
//    qDebug() << pathIcons;
//    qDebug() << pathImages;
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

QJsonObject Theme::toJson() {
    QJsonObject object;
    object["text"] = text.toJson();
    object["disabledBackground"] = disabledBackground.toJson();
    object["disabled"] = disabled.toJson();
    object["hover"] = hover.toJson();
    object["border"] = border.toJson();
    object["alternate"] = alternate.toJson();
    object["background"] = background.toJson();
    object["backgroundSelectedItem"] = backgroundSelectedItem.toJson();
    object["backgroundSecond"] = backgroundSecond.toJson();
    object["backgroundProgressbar"] = backgroundProgressbar.toJson();
    object["backgroundBadProgressbar"] = backgroundBadProgressbar.toJson();
    object["backgroundProgressbarProgress"] = backgroundProgressbarProgress.toJson();
    object["selected"] = selected.toJson();
    object["headerForm"] = headerForm.toJson();
    object["backgroundItem"] = backgroundItem.toJson();
    object["backgroundAlternateItem"] = backgroundAlternateItem.toJson();
    object["forItemHover"] = forItemHover.toJson();
    object["mainProfileBackground"] = mainProfileBackground.toJson();
    object["mainBackground"] = mainBackground.toJson();
    object["pathIcons"] = pathIcons;
    object["pathImages"] = pathImages;
    return object;
}

void Theme::fromJson(const QJsonObject &aObject) {
    text.fromJson(aObject.value("text").toObject());
    disabledBackground.fromJson(aObject.value("disabledBackground").toObject());
    disabled.fromJson(aObject.value("disabled").toObject());
    hover.fromJson(aObject.value("hover").toObject());
    border.fromJson(aObject.value("border").toObject());
    alternate.fromJson(aObject.value("alternate").toObject());
    background.fromJson(aObject.value("background").toObject());
    backgroundSelectedItem.fromJson(aObject.value("backgroundSelectedItem").toObject());
    backgroundSecond.fromJson(aObject.value("backgroundSecond").toObject());
    backgroundProgressbar.fromJson(aObject.value("backgroundProgressbar").toObject());
    backgroundBadProgressbar.fromJson(aObject.value("backgroundBadProgressbar").toObject());
    backgroundProgressbarProgress.fromJson(aObject.value("backgroundProgressbarProgress").toObject());
    selected.fromJson(aObject.value("selected").toObject());
    headerForm.fromJson(aObject.value("headerForm").toObject());
    backgroundItem.fromJson(aObject.value("backgroundItem").toObject());
    backgroundAlternateItem.fromJson(aObject.value("backgroundAlternateItem").toObject());
    forItemHover.fromJson(aObject.value("forItemHover").toObject());
    mainProfileBackground.fromJson(aObject.value("mainProfileBackground").toObject());
    mainBackground.fromJson(aObject.value("mainBackground").toObject());
    pathIcons = aObject.value("pathIcons").toString();
    pathImages = aObject.value("pathImages").toString();
}

bool Theme::save(const QString &aPath) {
    return saveFile(aPath, QJsonDocument(toJson()).toJson());
}

void Theme::load(const QString &aPath) {
    QByteArray array;
    if (readFile(aPath, array)) {
        fromJson(QJsonDocument::fromJson(array).object());
    }
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
        Theme currentTheme;
        currentTheme.load(Paths::documents() + "theme\\custom.json");
        return currentTheme;
    }
    }
}

ThemeColor::~ThemeColor() {
    //TODO Утечка памяти
    //Когда создаются градиенты, используются объекты, они удаляются и ломают градиент в теме, из-за чего программа крашится если ее удалять так
//    if (gradient) {
//        delete gradient;
//    }
}

void ThemeColor::setColor(const QColor &aColor, QGradient *aGradient) {
    color = aColor;
    if (gradient) {
        delete gradient;
    }
    gradient = aGradient;
}

void ThemeColor::setGradient(QGradient aGradient) {
    if (aGradient.type() != QGradient::NoGradient) {
        gradient = new QGradient(aGradient);
        float red = 0, green = 0, blue = 0, alpha = 0;
        int count = 0;
        for (auto stop: aGradient.stops()) {
            QColor stopColor = stop.second;
            red += stopColor.redF();
            green += stopColor.greenF();
            blue += stopColor.blueF();
            alpha += stopColor.alphaF();
            ++count;
        }
        red /= count;
        green /= count;
        blue /= count;
        alpha /= count;
        color = QColor(red * 255, green * 255, blue * 255, alpha * 255);
    } else {
        gradient = nullptr;
        color = QColor(0, 0, 0);
    }
}

QColor ThemeColor::getColor() {
    return color;
}

QGradient *ThemeColor::getGradient() {
    return gradient;
}

void ThemeColor::setString(const QString &aColor) {
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

QString ThemeColor::getString() {
    if (gradient) {
        QStringList stops;
        for (const auto &stop: gradient->stops().toList()) {
            stops.append(QString("stop: %1 %2").arg(QString::number(stop.first), stop.second.name(QColor::NameFormat::HexArgb)));
        }
        if (gradient->type() == QGradient::RadialGradient) {
            QRadialGradient *curGradient = static_cast<QRadialGradient*>(gradient);
            return QString("qradialgradient(spread:pad, cx:%1, cy:%2, radius: %3, fx:%4, fy:%5, %6)").arg(
                        QString::number(curGradient->center().x()),
                        QString::number(curGradient->center().y()),
                        QString::number(curGradient->radius()),
                        QString::number(curGradient->focalPoint().x()),
                        QString::number(curGradient->focalPoint().y()),
                        stops.join(", "));
        }
        if (gradient->type() == QGradient::LinearGradient) {
            QLinearGradient *curGradient = static_cast<QLinearGradient*>(gradient);
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
        QGradientStops stops = gradient->stops();
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
        QGradientStops stops = gradient->stops();
        for (auto &stop: stops) {
            stop.second = Theme::swapParts(stop.second, part1, part2);
        }
        gradient->setStops(stops);
    }
    color = Theme::swapParts(color, part1, part2);
    return *this;
}

ThemeColor &ThemeColor::alternateColor(const QColor &newColor) {
    color.setHslF(newColor.hslHueF(), color.hslSaturationF(), color.lightnessF());
    //gradient
    if (gradient) {
        QGradientStops stops = gradient->stops();
        for (auto &stop: stops) {
            stop.second.setHslF(newColor.hslHueF(), stop.second.hslSaturationF(), stop.second.lightnessF());
        }
        gradient->setStops(stops);
    }
    return *this;
}

QJsonObject ThemeColor::toJson() {
    QJsonObject object;
    object["color"] = color.name(QColor::NameFormat::HexArgb);
    if (gradient) {
        QJsonObject jGradient;
        jGradient["type"] = gradient->type();
        jGradient["spread"] = gradient->spread();
        QJsonArray gradientStops;
        for (auto oneStop: gradient->stops()) {
            QJsonObject gradientStop;
            gradientStop["pos"] = oneStop.first;
            gradientStop["color"] = oneStop.second.name(QColor::NameFormat::HexArgb);
            gradientStops << gradientStop;
        }
        if (gradient->type() == QGradient::RadialGradient) {
            QRadialGradient *curGradient = static_cast<QRadialGradient*>(gradient);
            jGradient["cx"] = curGradient->center().x();
            jGradient["cy"] = curGradient->center().y();
            jGradient["radius"] = curGradient->radius();
            jGradient["fx"] = curGradient->focalPoint().x();
            jGradient["fy"] = curGradient->focalPoint().y();
        }
        if (gradient->type() == QGradient::LinearGradient) {
            QLinearGradient *curGradient = static_cast<QLinearGradient*>(gradient);
            jGradient["x1"] = curGradient->start().x();
            jGradient["y1"] = curGradient->start().y();
            jGradient["x2"] = curGradient->finalStop().x();
            jGradient["y2"] = curGradient->finalStop().y();
        }
        jGradient["stops"] = gradientStops;
        object["gradient"] = jGradient;
    }
    return object;
}

void ThemeColor::fromJson(const QJsonObject &aObject) {
    color = aObject.value("color").toString();
    if (aObject.value("gradient") != QJsonValue::Undefined) {
        QJsonObject jGradient = aObject.value("gradient").toObject();
//        QGradientStops stops;
//        for (QJsonValue jStop: jGradient.value("stops").toArray()) {
//            stops << QGradientStop(jStop.toObject().value("pos").toDouble(), QColor(jStop.toObject().value("color").toString()));
//        }

        switch (static_cast<QGradient::Type>(jGradient.value("type").toInt())) {
        case QGradient::LinearGradient: {
            int x1, y1, x2, y2;
            x1 = jGradient.value("x1").toDouble();
            y1 = jGradient.value("y1").toDouble();
            x2 = jGradient.value("x2").toDouble();
            y2 = jGradient.value("y2").toDouble();
            QLinearGradient *newGradient = new QLinearGradient(x1, y1, x2, y2);
//            newGradient->setStart(jGradient.value("x1").toDouble(), jGradient.value("y1").toDouble());
//            newGradient->setFinalStop(jGradient.value("x2").toDouble(), jGradient.value("y2").toDouble());
            newGradient->setSpread(static_cast<QGradient::Spread>(jGradient.value("spread").toInt()));
            for (QJsonValue jStop: jGradient.value("stops").toArray()) {
                double pos = jStop.toObject().value("pos").toDouble();
                QColor color = QColor(jStop.toObject().value("color").toString());
                newGradient->setColorAt(pos, color);
            }
//            newGradient->setStops(stops);
            gradient = newGradient;
            break;
        }
        case QGradient::RadialGradient: {
            double cx = jGradient.value("cx").toDouble();
            double cy = jGradient.value("cy").toDouble();
            double redius = jGradient.value("radius").toDouble();
            double fx = jGradient.value("fx").toDouble();
            double fy = jGradient.value("fy").toDouble();
            QRadialGradient newGradient(cx, cy, redius, fx, fy);
//            newGradient->setCenter(jGradient.value("cx").toDouble(), jGradient.value("cy").toDouble());
//            newGradient->setRadius(jGradient.value("radius").toDouble());
//            newGradient->setFocalPoint(jGradient.value("fx").toDouble(), jGradient.value("fy").toDouble());
            newGradient.setSpread(static_cast<QGradient::Spread>(jGradient.value("spread").toInt()));
            for (QJsonValue jStop: jGradient.value("stops").toArray()) {
                double pos = jStop.toObject().value("pos").toDouble();
                QColor color = QColor(jStop.toObject().value("color").toString());
                newGradient.setColorAt(pos, color);
            }
//            newGradient->setStops(stops);
            setGradient(newGradient);
            break;
        }
        default: {
            gradient = nullptr;
        }
        }
    } else {
        gradient = nullptr;
    }
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

//    qss = textFromFile(":/theme/baseColor.qss").arg(currentTheme.text.getString(),
//                                                    currentTheme.hover.getString(),
//                                                    currentTheme.border.getString(),
//                                                    currentTheme.background.getString(),
//                                                    combineColor(currentTheme.background.getColor(), 0.8, Qt::black, 0.2).name(QColor::NameFormat::HexArgb),//currentTheme.disabled.getString(),
//                                                    currentTheme.backgroundSecond.getString(),
//                                                    combineColor(currentTheme.backgroundSecond.getColor(), 0.65, Qt::black, 0.35).name(QColor::NameFormat::HexArgb),//currentTheme.disabledBackground.getString(),
//                                                    currentTheme.alternate.getString(),
//                                                    currentTheme.backgroundSelectedItem.getString(),
//                                                    currentTheme.backgroundProgressbar.getString(),
//                                                    currentTheme.backgroundProgressbarProgress.getString(),
//                                                    currentTheme.headerForm.setAlpha(255 * 0.5).getString(),//View background + Profile frame background
//                                                    currentTheme.headerForm.setAlpha(255).getString(),//Freeze row background
//                                                    currentTheme.backgroundItem.setAlpha(255 * 0.5).getString(),//items background
//                                                    currentTheme.forItemHover.setAlpha(255 * 0.5).getString(),//hovered items background
//                                                    currentTheme.headerForm.setAlpha(255 * 0.8).getString(),//Modal frame background
//                                                    currentTheme.mainProfileBackground.setAlpha(255 * 0.5).getString(),//Profile info 2 background
//                                                    currentTheme.backgroundItem.setAlpha(255 * 0.8).getString(),//categories frame background
//                                                    currentTheme.headerForm.setAlpha(255 * 0.7).getString(),//Main window header background
//                                                    currentTheme.mainBackground.getString());

    qss += textFromFile(":/theme/baseIcons.qss").arg(currentTheme.pathIcons);
    qss += textFromFile(":/theme/globalTheme.qss").arg(currentTheme.text.getString(),
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
                                                       currentTheme.mainBackground.getString());
    qss += " "
    "* { "
        "font-family:  " + defaultFont() + "; "
    "} ";

    return qss;
}

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
    theme.backgroundSelectedItem.setGradient(gr1);
    theme.backgroundSecond.setGradient(gr2);
    theme.backgroundProgressbar.setColor(QColor(93, 170, 224));
    theme.backgroundBadProgressbar.setColor(QColor(228, 75, 75));
    theme.backgroundProgressbarProgress.setColor(QColor(56, 101, 132));
    theme.selected.setColor(QColor(135, 182, 255));
    theme.headerForm.setColor(QColor(30, 41, 59));
    theme.backgroundItem.setColor(QColor(23, 26, 33));
    theme.backgroundAlternateItem.setColor(QColor(29, 32, 39));
    theme.forItemHover.setColor(QColor(43, 46, 53));
    theme.mainProfileBackground.setColor(QColor(37, 60, 94));
    theme.mainBackground.setGradient(gr3);
    theme.pathIcons = (":/theme/iconsBlueTheme/");
    theme.pathImages = ("://white/");
    return theme;
}

Theme whiteTheme() {
    QRadialGradient gr1(0.5, 0.5, 0.9, 0.4, 0.5);
    gr1.setColorAt(0, QColor("#ffffff"));
    gr1.setColorAt(1, QColor("#d9d9d9"));

    Theme theme;
    theme.text.setColor(QColor(15, 15, 15));
    theme.disabledBackground.setColor(QColor(135, 135, 135));
    theme.disabled.setColor(QColor(135, 135, 135));
    theme.hover.setColor(QColor(235, 155, 95));
    theme.border.setColor(QColor(100, 100, 100));
    theme.alternate.setColor(QColor(230, 220, 210));
    theme.background.setColor(QColor(236, 236, 236));
    theme.backgroundSelectedItem.setColor(QColor(244, 244, 244, 255 * 0.7));
    theme.backgroundSecond.setColor(QColor(175, 160, 150));
    theme.backgroundProgressbar.setColor(QColor(199, 144, 123));
    theme.backgroundBadProgressbar.setColor(QColor(228, 75, 75));
    theme.backgroundProgressbarProgress.setColor(QColor(199 * 1.2, 144 * 1.2, 123 * 1.2));
    theme.selected.setColor(QColor(120, 73, 0));
    theme.headerForm.setColor(QColor(200, 200, 200));
    theme.backgroundItem.setColor(QColor(244, 244, 244));
    theme.backgroundAlternateItem.setColor(QColor(226, 223, 216));
    theme.forItemHover.setColor(QColor(244, 244, 244));
    theme.mainProfileBackground.setColor(QColor(185, 185, 185));
    theme.mainBackground.setGradient(gr1);
    theme.pathIcons = (":/theme/iconsWhiteTheme/");
    theme.pathImages = ("://black/");
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
    theme.mainBackground.setGradient(gr1);
    theme.pathIcons = (":/theme/iconsBlackTheme/");
    theme.pathImages = ("://white/");
    return theme;
}

Theme orangeTheme() {
    Theme theme = blueTheme();
    theme.swapPartsAllColors(PartColor::red, PartColor::blue);
    theme.pathIcons = (":/theme/iconsBlackTheme/");
    theme.pathImages = ("://white/");
    return theme;
}

Theme crimsonTheme() {
    Theme theme = blueTheme();
    theme.swapPartsAllColors(PartColor::red, PartColor::blue).swapPartsAllColors(PartColor::green, PartColor::blue);
    theme.pathIcons = (":/theme/iconsBlackTheme/");
    theme.pathImages = ("://white/");
    return theme;
}

Theme limeTheme() {
    Theme theme = blueTheme();
    theme.swapPartsAllColors(PartColor::red, PartColor::blue).swapPartsAllColors(PartColor::green, PartColor::red);
    theme.pathIcons = (":/theme/iconsBlackTheme/");
    theme.pathImages = ("://white/");
    return theme;
}

Theme purpleTheme() {
    Theme theme = blueTheme();
    theme.swapPartsAllColors(PartColor::red, PartColor::green);
    theme.pathIcons = (":/theme/iconsBlackTheme/");
    theme.pathImages = ("://white/");
    return theme;
}

Theme greenTheme() {
    Theme theme = blueTheme();
    theme.swapPartsAllColors(PartColor::green, PartColor::blue);
    theme.pathIcons = (":/theme/iconsBlackTheme/");
    theme.pathImages = ("://white/");
    return theme;
}

Theme customTheme(const QColor &aNewColor) {
    Theme blue = blueTheme();
    blue.text                           .alternateColor(aNewColor);
    blue.disabledBackground             .alternateColor(aNewColor);
    blue.disabled                       .alternateColor(aNewColor);
    blue.hover                          .alternateColor(aNewColor);
    blue.border                         .alternateColor(aNewColor);
    blue.alternate                      .alternateColor(aNewColor);
    blue.background                     .alternateColor(aNewColor);
    blue.backgroundSelectedItem         .alternateColor(aNewColor);
    blue.backgroundSecond               .alternateColor(aNewColor);
    blue.backgroundProgressbar          .alternateColor(aNewColor);
    blue.backgroundBadProgressbar       .alternateColor(aNewColor);
    blue.backgroundProgressbarProgress  .alternateColor(aNewColor);
    blue.selected                       .alternateColor(aNewColor);
    blue.headerForm                     .alternateColor(aNewColor);
    blue.backgroundItem                 .alternateColor(aNewColor);
    blue.backgroundAlternateItem        .alternateColor(aNewColor);
    blue.forItemHover                   .alternateColor(aNewColor);
    blue.mainProfileBackground          .alternateColor(aNewColor);
    blue.mainBackground                 .alternateColor(aNewColor);
    QDir().mkpath(Paths::documents() + "theme");
    Theme::createIcons(Paths::documents() + "theme/", aNewColor);
    blue.pathIcons = (Paths::documents() + "theme/");
    return blue;
}

QImage convertImage(const QImage &aImage, const QColor &aColor) {
    QImage im(aImage.size(), aImage.format());
    for (int x = 0; x < aImage.width(); ++x) {
        for (int y = 0; y < aImage.height(); ++y) {
            QColor oldColor = aImage.pixelColor(x, y);
            QColor newColor = QColor::fromHsl(aColor.hslHue(),
                                               255,
                                               100,
                                               oldColor.alpha());
            im.setPixelColor(x, y, newColor);
        }
    }
    return im;
}

QStringList getImagesFromDir(const QDir &directory) {
    QStringList list = directory.entryList(QStringList("*.png"));
    QStringList result;
    for (const QString &file: list) {
        result << directory.absolutePath() + "/" + file;
    }
    for (const QString &dir: directory.entryList(QDir::Dirs)) {
        if (dir != "." && dir != "..") {
            result << getImagesFromDir(directory.absolutePath() + "/" + dir);
        }
    }
    return result;
}

void Theme::createIcons(const QString &aPath, const QColor &aNewColor) {
    QDir directory(blackTheme().pathIcons);

    QStringList anotherColor;
    anotherColor << "arrow_down_focus.png" << "arrow_down_pressed.png"
                 << "arrow_left_focus.png" << "arrow_left_pressed.png"
                 << "arrow_right_focus.png" << "arrow_right_pressed.png"
                 << "arrow_up_focus.png" << "arrow_up_pressed.png"
                 << "branch_closed_focus.png" << "branch_closed_pressed.png"
                 << "branch_end_focus.png" << "branch_end_pressed.png"
                 << "branch_line_focus.png" << "branch_line_pressed.png"
                 << "branch_more_focus.png" << "branch_more_pressed.png"
                 << "branch_open_focus.png" << "branch_open_pressed.png"
                 << "checkbox_checked_hover.png" << "checkbox_checked_pressed.png"
                 << "checkbox_indeterminate_hover.png" << "checkbox_indeterminate_pressed.png"
                 << "checkbox_unchecked_hover.png" << "checkbox_unchecked_pressed.png"
                 << "line_horizontal_focus.png" << "line_horizontal_pressed.png"
                 << "line_vertical_focus.png" << "line_vertical_pressed.png"
                 << "radio_checked_focus.png" << "radio_checked_pressed.png"
                 << "radio_unchecked_focus.png" << "radio_unchecked_pressed.png"
                 << "radiobutton_checked_hover.png" << "radiobutton_checked_press.png"
                 << "radiobutton_unchecked_hover.png" << "radiobutton_unchecked_press.png"
                 << "toolbar_move_horizontal_focus.png" << "toolbar_move_horizontal_pressed.png"
                 << "toolbar_move_vertical_focus.png" << "toolbar_move_vertical_pressed.png"
                 << "toolbar_separator_horizontal_focus.png" << "toolbar_separator_horizontal_pressed.png"
                 << "toolbar_separator_vertical_focus.png" << "toolbar_separator_vertical_pressed.png"
                 << "window_close_focus.png" << "window_close_pressed.png"
                 << "window_grip_focus.png" << "window_grip_pressed.png"
                 << "window_minimize_focus.png" << "window_minimize_pressed.png"
                 << "window_undock_focus.png" << "window_undock_pressed.png";

    QStringList imagesList = getImagesFromDir(directory);

    for (const QString &file: imagesList) {
        QImage image;
        QString fileName = file;
        fileName = fileName.remove(directory.absolutePath() + "/");
        if (anotherColor.indexOf(fileName) > -1) {
           image = convertImage(QImage(file), aNewColor);
        } else {
           image = QImage(file);
        }

        QDir().mkpath(aPath + "/");
//        createDir(aPath + "/" + fileName);
        image.save(aPath + "/" + fileName);
    }

}
