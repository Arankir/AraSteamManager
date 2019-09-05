#-------------------------------------------------
#
# Project created by QtCreator 2019-03-26T13:57:12
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AraSteamManager
TEMPLATE = app

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
    class/imagerequest.cpp \
    class/profile.cpp \
    class/settings.cpp \
    class/steamapiachievement.cpp \
    class/steamapiachievementglobal.cpp \
    class/steamapiachievementpercentage.cpp \
    class/steamapiachievementplayer.cpp \
    class/steamapiachievements.cpp \
    class/steamapiachievementsglobal.cpp \
    class/steamapiachievementspercentage.cpp \
    class/steamapiachievementsplayer.cpp \
    class/steamapibans.cpp \
    class/steamapifriend.cpp \
    class/steamapifriends.cpp \
    class/steamapigame.cpp \
    class/steamapigames.cpp \
    class/steamapilevels.cpp \
    class/steamapiprofile.cpp \
    formcompare.cpp \
        main.cpp \
        mainwindow.cpp \
    formgames.cpp \
    formachievements.cpp \
    formfriends.cpp

HEADERS += \
    class/imagerequest.h \
    class/profile.h \
    class/settings.h \
    class/steamapiachievement.h \
    class/steamapiachievementglobal.h \
    class/steamapiachievementpercentage.h \
    class/steamapiachievementplayer.h \
    class/steamapiachievements.h \
    class/steamapiachievementsglobal.h \
    class/steamapiachievementspercentage.h \
    class/steamapiachievementsplayer.h \
    class/steamapibans.h \
    class/steamapifriend.h \
    class/steamapifriends.h \
    class/steamapigame.h \
    class/steamapigames.h \
    class/steamapilevels.h \
    class/steamapiprofile.h \
    formcompare.h \
        mainwindow.h \
    formgames.h \
    formachievements.h \
    formfriends.h

FORMS += \
    formcompare.ui \
        mainwindow.ui \
    formgames.ui \
    formachievements.ui \
    formfriends.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images/res.qrc
