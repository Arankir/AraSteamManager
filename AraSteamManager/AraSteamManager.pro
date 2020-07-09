#-------------------------------------------------
#
# Project created by QtCreator 2019-03-26T13:57:12
#
#-------------------------------------------------

QT       += core gui network charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AraSteamManager
TEMPLATE = app
TRANSLATIONS += AraSteamManager_en.ts AraSteamManager_ru.ts
# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    AchievementsSubForms/formachievements.cpp \
    AchievementsSubForms/formcategoryvalue.cpp \
    AchievementsSubForms/formcompareprofilefilter.cpp \
    AchievementsSubForms/formtablesheaders.cpp \
    MainSubForms/formfavorites.cpp \
    MainSubForms/formfriends.cpp \
    MainSubForms/formgames.cpp \
    MainSubForms/formprofile.cpp \
    MainSubForms/formsettings.cpp \
    MainSubForms/formstatistics.cpp \
    class/Network/requestdata.cpp \
    class/Network/requestimage.cpp \
    class/NotMine/donutbreakdownchart.cpp \
    class/NotMine/mainslice.cpp \
    class/Threads/threadachievements.cpp \
    class/Threads/threadfriends.cpp \
    class/Threads/threadgames.cpp \
    class/Threads/threading.cpp \
    class/Threads/threadstatistics.cpp \
    class/categoriesgame.cpp \
    class/favorites.cpp \
    class/filter.cpp \
    class/settings.cpp \
    class/steamapi/Sachievements.cpp \
    class/steamapi/Sbans.cpp \
    class/steamapi/Sfriends.cpp \
    class/steamapi/Sgames.cpp \
    class/steamapi/Slevels.cpp \
    class/steamapi/Sprofile.cpp \
    formcontainerachievements.cpp \
    frameless.cpp \
        main.cpp \
        mainwindow.cpp \
    subwidget/qbuttonwithdata.cpp \
    subwidget/qcheckboxwithdata.cpp \
    subwidget/qcomboboxwithdata.cpp \
    subwidget/qradiobuttonwithdata.cpp

HEADERS += \
    AchievementsSubForms/formachievements.h \
    AchievementsSubForms/formcategoryvalue.h \
    AchievementsSubForms/formcompareprofilefilter.h \
    AchievementsSubForms/formtablesheaders.h \
    MainSubForms/formfavorites.h \
    MainSubForms/formfriends.h \
    MainSubForms/formgames.h \
    MainSubForms/formprofile.h \
    MainSubForms/formsettings.h \
    MainSubForms/formstatistics.h \
    class/Network/requestdata.h \
    class/Network/requestimage.h \
    class/NotMine/donutbreakdownchart.h \
    class/NotMine/mainslice.h \
    class/Threads/threadachievements.h \
    class/Threads/threadfriends.h \
    class/Threads/threadgames.h \
    class/Threads/threading.h \
    class/Threads/threadstatistics.h \
    class/categoriesgame.h \
    class/favorites.h \
    class/filter.h \
    class/settings.h \
    class/statusvalue.h \
    class/steamapi/Sachievements.h \
    class/steamapi/Sbans.h \
    class/steamapi/Sfriends.h \
    class/steamapi/Sgames.h \
    class/steamapi/Slevels.h \
    class/steamapi/Sprofile.h \
    formcontainerachievements.h \
    frameless.h \
        mainwindow.h \
    subwidget/qbuttonwithdata.h \
    subwidget/qcheckboxwithdata.h \
    subwidget/qcomboboxwithdata.h \
    subwidget/qradiobuttonwithdata.h

FORMS += \
    AchievementsSubForms/formachievements.ui \
    AchievementsSubForms/formcategoryvalue.ui \
    AchievementsSubForms/formcompareprofilefilter.ui \
    AchievementsSubForms/formtablesheaders.ui \
    MainSubForms/formfavorites.ui \
    MainSubForms/formfriends.ui \
    MainSubForms/formgames.ui \
    MainSubForms/formprofile.ui \
    MainSubForms/formsettings.ui \
    MainSubForms/formstatistics.ui \
    formcontainerachievements.ui \
        mainwindow.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images/resimg.qrc \
    languages/lang.qrc

DISTFILES +=

RC_ICONS = SAS.ico
