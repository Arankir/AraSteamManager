#ifndef SETTINGS_H
#define SETTINGS_H

#include <QMainWindow>
#include <QObject>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <class/statusvalue.h>


class ThemePushButton{
public:
    QString background[3];
    ThemePushButton(QString Abg1, QString Abg2, QString Abg3){
        background[0]=Abg1;
        background[1]=Abg2;
        background[2]=Abg3;
    }
};
class ThemeProgressBar{
public:
    QString border;
    QString borderRadius;
    QString chunkBackgroundColor;
    QString chunkBorderBottomRightRadius;
    QString chunkBorderBottomLeftRadius;
    QString chunkBorderTopRightRadius;
    QString chunkBorderTopLeftRadius;

    ThemeProgressBar(QString Aborder, QString AborderRadius, QString AbackgroundColor, QString AborderBottomRightRadius,
                     QString AborderBottomLeftRadius, QString AborderTopRightRadius, QString AborderTopLeftRadius){
        border=Aborder;
        borderRadius=AborderRadius;
        SetChunk(AbackgroundColor,AborderBottomRightRadius,AborderBottomLeftRadius,AborderTopRightRadius,AborderTopLeftRadius);
    }
    void SetChunk(QString AbackgroundColor, QString AborderBottomRightRadius, QString AborderBottomLeftRadius,
                  QString AborderTopRightRadius, QString AborderTopLeftRadius){
        chunkBackgroundColor=AbackgroundColor;
        chunkBorderBottomRightRadius=AborderBottomRightRadius;
        chunkBorderBottomLeftRadius=AborderBottomLeftRadius;
        chunkBorderTopRightRadius=AborderTopRightRadius;
        chunkBorderTopLeftRadius=AborderTopLeftRadius;
    }
};
class ThemeRadioButton{
public:
    QString indicatorBorderRadius;
    QString indicatorUncheckedBackgroundColor;
    QString indicatorUncheckedBorder;
    QString indicatorCheckedBackgroundColor;
    QString indicatorCheckedBorder;
    QString hoverBackgroundColor[3];
    ThemeRadioButton(QString AborderRadius, QString AuncheckedBackgroundColor,
                     QString AuncheckedBorder, QString AcheckedBackgroundColor, QString AcheckedBorder,
                     QString Abg1, QString Abg2, QString Abg3){
        SetIndicator(AborderRadius,AuncheckedBackgroundColor,AuncheckedBorder,AcheckedBackgroundColor,AcheckedBorder);
        SetHover(Abg1,Abg2,Abg3);
    }
    void SetIndicator(QString AborderRadius, QString AuncheckedBackgroundColor,
                      QString AuncheckedBorder, QString AcheckedBackgroundColor, QString AcheckedBorder){
        indicatorBorderRadius=AborderRadius;
        SetIndicatorUnchecked(AuncheckedBackgroundColor,AuncheckedBorder);
        SetIndicatorChecked(AcheckedBackgroundColor,AcheckedBorder);
    }
    void SetIndicatorUnchecked(QString AbackgroundColor, QString Aborder){
        indicatorUncheckedBackgroundColor=AbackgroundColor;
        indicatorUncheckedBorder=Aborder;
    }
    void SetIndicatorChecked(QString AbackgroundColor, QString Aborder){
        indicatorCheckedBackgroundColor=AbackgroundColor;
        indicatorCheckedBorder=Aborder;
    }
    void SetHover(QString Abg1, QString Abg2, QString Abg3){
        hoverBackgroundColor[0]=Abg1;
        hoverBackgroundColor[1]=Abg2;
        hoverBackgroundColor[2]=Abg3;
    }
};
class ThemeTabBar{
public:
    QString tabBorder;
    QString tabBorderBottomColor;
    QString tabBorderTopLeftRadius;
    QString tabBorderTopRightRadius;
    QString selectedBackground[3];
    QString selectedBorderColor;
    QString selectedBorderBottomColor;
    QString hoverBackground[3];

    ThemeTabBar(QString Aborder, QString AborderBottomColor, QString AborderTopLeftRadius, QString AborderTopRightRadius,
                QString Asbg1, QString Asbg2, QString Asbg3, QString AselectedBorderColor, QString AselectedBorderBottomColor,
                QString Ahbg1, QString Ahbg2, QString Ahbg3){
        SetTab(Aborder,AborderBottomColor,AborderTopLeftRadius,AborderTopRightRadius,
               Asbg1,Asbg2,Asbg3,AselectedBorderColor,AselectedBorderBottomColor,
               Ahbg1,Ahbg2,Ahbg3);
    }
    void SetTab(QString Aborder, QString AborderBottomColor, QString AborderTopLeftRadius, QString AborderTopRightRadius,
                QString Asbg1, QString Asbg2, QString Asbg3, QString AselectedBorderColor, QString AselectedBorderBottomColor,
                QString Ahbg1, QString Ahbg2, QString Ahbg3){
        tabBorder=Aborder;
        tabBorderBottomColor=AborderBottomColor;
        tabBorderTopLeftRadius=AborderTopLeftRadius;
        tabBorderTopRightRadius=AborderTopRightRadius;
        SetSelected(Asbg1,Asbg2,Asbg3,AselectedBorderColor,AselectedBorderBottomColor);
        SetHover(Ahbg1,Ahbg2,Ahbg3);
    }
    void SetSelected(QString Abg1, QString Abg2, QString Abg3, QString AselectedBorderColor, QString AselectedBorderBottomColor){
        selectedBackground[0]=Abg1;
        selectedBackground[1]=Abg2;
        selectedBackground[2]=Abg3;
        selectedBorderColor=AselectedBorderColor;
        selectedBorderBottomColor=AselectedBorderBottomColor;
    }
    void SetHover(QString Abg1, QString Abg2, QString Abg3){
        hoverBackground[0]=Abg1;
        hoverBackground[1]=Abg2;
        hoverBackground[2]=Abg3;
    }
};
class ThemeCheckBox{
public:
    QString background[3];
    ThemeCheckBox(QString Abg1, QString Abg2, QString Abg3){
        background[0]=Abg1;
        background[1]=Abg2;
        background[2]=Abg3;
    }
};
class ThemeComboBox{
    public:
        QString border;
        QString borderRadius;
        QString background[3];
        QString color;
        QString hoverBackgroundColor[3];
        QString abstractViewBackgroundColor;
        QString abstractViewColor;
        QString abstractViewSelectionBackgroundColor;
        QString abstractViewSelectionColor;
        QString abstractViewHoverBackgroundColor[3];
        ThemeComboBox(QString Aborder, QString AborderRadius, QString Abg1, QString Abg2, QString Abg3, QString Acolor,
                      QString Ahbg1, QString Ahbg2, QString Ahbg3, QString AabackgroundColor, QString Aacolor,
                      QString AaselectionBackgroundColor,
                      QString AaselectionColor, QString Aabg1, QString Aabg2, QString Aabg3){
            border=Aborder;
            borderRadius=AborderRadius;
            background[0]=Abg1;
            background[1]=Abg2;
            background[2]=Abg3;
            color=Acolor;
            SetHover(Ahbg1, Ahbg2, Ahbg3);
            SetAbstractView(AabackgroundColor, Aacolor, AaselectionBackgroundColor, AaselectionColor, Aabg1, Aabg2, Aabg3);
        }
        void SetHover(QString Abg1, QString Abg2, QString Abg3){
            background[0]=Abg1;
            background[1]=Abg2;
            background[2]=Abg3;
        }
        void SetAbstractView(QString AbackgroundColor, QString Acolor, QString AselectionBackgroundColor,
                             QString AselectionColor, QString Abg1, QString Abg2, QString Abg3){
            abstractViewBackgroundColor=AbackgroundColor;
            abstractViewColor=Acolor;
            abstractViewSelectionBackgroundColor=AselectionBackgroundColor;
            abstractViewSelectionColor=AselectionColor;
            SetAbstractViewHover(Abg1,Abg2,Abg3);
        }
        void SetAbstractViewHover(QString Abg1, QString Abg2, QString Abg3){
            abstractViewHoverBackgroundColor[0]=Abg1;
            abstractViewHoverBackgroundColor[1]=Abg2;
            abstractViewHoverBackgroundColor[2]=Abg3;
        }
    };


class Settings : public QObject
{
    Q_OBJECT
public:
    explicit Settings(QObject *parent = nullptr);
    bool SetMyProfile(QString MyProfiles);
    bool SetLanguage(int Language);
    bool SetTheme(int Theme);
    bool SetSaveimage(int SaveImage);
    bool SetVisibleHiddenGames(int VisibleHiddenGames);
    void SetDefault();
    QString GetMyProfile() {return _myProfile;}
    int GetLanguage() {return _language;}
    int GetTheme() {return _theme;}
    int GetSaveimages() {return _saveImages;}
    StatusValue GetStatus() {return _status;}
    QString GetError() {return _error;}
    int GetVisibleHiddenGames() {return _visibleHiddenGames;}
    QString GetKey() {return _key;}
    bool CreateFile(QString path);

signals:

public slots:

private:
    QString _myProfile="";
    int _language=1;
    int _theme=1;
    int _saveImages=0;
    int _visibleHiddenGames=0;
    StatusValue _status=StatusValue::none;
    QString _error="";
    QString _key="3826BF60403D15613B4B0381DAB7A7BD";
};

#endif // SETTINGS_H
