#ifndef THEME_H
#define THEME_H

#include <QColor>
#include <QGradient>

enum class PartColor {
    red,
    green,
    blue,
    alpha
};

struct ThemeColor {
    QColor color;
    QGradient *gradient = nullptr;

    ~ThemeColor();

    void setColor(const QColor&, QGradient *gradient = nullptr);
    void setGradient(QGradient gradient);
    QColor getColor();
    QGradient *getGradient();
    void setString(const QString&);
    QString getString();
    ThemeColor &setAlpha(int alpha);

    ThemeColor &swapPartColor(PartColor part1, PartColor part2);
    ThemeColor &alternateColor(const QColor &newColor);

    QJsonObject toJson();
    void fromJson(const QJsonObject &);
};

struct Theme {
    Theme() {};

    ThemeColor text;
    ThemeColor disabledBackground;
    ThemeColor disabled;
    ThemeColor hover;
    ThemeColor border;
    ThemeColor alternate;
    ThemeColor background;
    ThemeColor backgroundSelectedItem;
    ThemeColor backgroundSecond;
    ThemeColor backgroundProgressbar;
    ThemeColor backgroundBadProgressbar;
    ThemeColor backgroundProgressbarProgress;
    ThemeColor selected;
    ThemeColor headerForm;
    ThemeColor backgroundItem;
    ThemeColor backgroundAlternateItem;
    ThemeColor forItemHover;
    ThemeColor mainProfileBackground;
    ThemeColor mainBackground;
    QString    pathIcons;
    QString    pathImages;

    Theme &swapPartsAllColors(PartColor part1, PartColor part2);

    QJsonObject toJson();
    void fromJson(const QJsonObject&);

    bool save(const QString &path);
    void load(const QString &path);

    static Theme getCurrentTheme();
    static QString qssTheme();
    static QString defaultFont();

    static QColor combineColor(const QColor &aColor1, double aPercent1, const QColor &aColor2, double aPercent2);
    static QColor swapParts(const QColor &color, PartColor part1, PartColor part2);

public:
    static void createIcons(const QString &aPath, const QColor &aNewColor);
};

Theme blueTheme();
Theme whiteTheme();
Theme blackTheme();
Theme orangeTheme();
Theme crimsonTheme();
Theme limeTheme();
Theme purpleTheme();
Theme greenTheme();
Theme customTheme(const QColor &aNewColor);

#endif // THEME_H
