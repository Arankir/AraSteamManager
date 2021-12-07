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

    void setColor(const QColor&, QGradient gradient = QGradient());
    void setColor(const QString&);
    QColor getColor();
    QString getString();
    ThemeColor &setAlpha(int alpha);

    ThemeColor &swapPartColor(PartColor part1, PartColor part2);
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

    QString   pathIcons;
    QString   pathImages;

    Theme &setPathIcons(const QString&);
    QString getPathIcons();

    Theme &setPathImages(const QString&);
    QString getPathImages();

    Theme &swapPartsAllColors(PartColor part1, PartColor part2);

    static Theme getCurrentTheme();
    static QString qssTheme();
    static QString defaultFont();

    static QColor combineColor(const QColor &aColor1, double aPercent1, const QColor &aColor2, double aPercent2);
    static QColor swapParts(const QColor &color, PartColor part1, PartColor part2);

private:
    QString getText(const QColor&, QGradient*);
};

Theme blueTheme();
Theme whiteTheme();
Theme blackTheme();
Theme orangeTheme();
Theme crimsonTheme();
Theme limeTheme();
Theme purpleTheme();
Theme greenTheme();

#endif // THEME_H
