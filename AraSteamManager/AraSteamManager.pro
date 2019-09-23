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
    class/steamapi/steamapiachievement.cpp \
    class/steamapi/steamapiachievementglobal.cpp \
    class/steamapi/steamapiachievementpercentage.cpp \
    class/steamapi/steamapiachievementplayer.cpp \
    class/steamapi/steamapiachievements.cpp \
    class/steamapi/steamapiachievementsglobal.cpp \
    class/steamapi/steamapiachievementspercentage.cpp \
    class/steamapi/steamapiachievementsplayer.cpp \
    class/steamapi/steamapibans.cpp \
    class/steamapi/steamapifriend.cpp \
    class/steamapi/steamapifriends.cpp \
    class/steamapi/steamapigame.cpp \
    class/steamapi/steamapigames.cpp \
    class/steamapi/steamapilevels.cpp \
    class/steamapi/steamapiprofile.cpp \
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
    class/steamapi/steamapiachievement.h \
    class/steamapi/steamapiachievementglobal.h \
    class/steamapi/steamapiachievementpercentage.h \
    class/steamapi/steamapiachievementplayer.h \
    class/steamapi/steamapiachievements.h \
    class/steamapi/steamapiachievementsglobal.h \
    class/steamapi/steamapiachievementspercentage.h \
    class/steamapi/steamapiachievementsplayer.h \
    class/steamapi/steamapibans.h \
    class/steamapi/steamapifriend.h \
    class/steamapi/steamapifriends.h \
    class/steamapi/steamapigame.h \
    class/steamapi/steamapigames.h \
    class/steamapi/steamapilevels.h \
    class/steamapi/steamapiprofile.h \
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
    images/resimg.qrc \
    languages/restext.qrc

DISTFILES +=
