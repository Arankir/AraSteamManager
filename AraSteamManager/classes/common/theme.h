#ifndef THEME_H
#define THEME_H

#include <QColor>
#include <QGradient>

struct ThemeColor {
    QColor color;
    QGradient *gradient = nullptr;
    void setColor(const QColor&, QGradient *gradient = nullptr);
    void setColor(const QString&);
    QColor getColor();
    QString getString();
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
    Theme &setPathIcons(const QString&);
    QString getPathIcons();
    static Theme getCurrentTheme();

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
