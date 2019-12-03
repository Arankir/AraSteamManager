#-------------------------------------------------
#
# Project created by QtCreator 2019-03-26T13:57:12
#
#-------------------------------------------------

QT       += core gui network

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
    class/Threads/threadachievements.cpp \
    class/Threads/threadfriends.cpp \
    class/Threads/threadgames.cpp \
    class/Threads/threading.cpp \
    class/filter.cpp \
    class/imagerequest.cpp \
    class/profile.cpp \
    class/settings.cpp \
    class/steamapi/Sachievement.cpp \
    class/steamapi/Sachievementglobal.cpp \
    class/steamapi/Sachievementpercentage.cpp \
    class/steamapi/Sachievementplayer.cpp \
    class/steamapi/Sachievements.cpp \
    class/steamapi/Sachievementsglobal.cpp \
    class/steamapi/Sachievementspercentage.cpp \
    class/steamapi/Sachievementsplayer.cpp \
    class/steamapi/Sbans.cpp \
    class/steamapi/Sfriend.cpp \
    class/steamapi/Sfriends.cpp \
    class/steamapi/Sgame.cpp \
    class/steamapi/Sgames.cpp \
    class/steamapi/Slevels.cpp \
    class/steamapi/Sprofile.cpp \
        main.cpp \
        mainwindow.cpp \
    formachievements.cpp \
    subform/formcategoryvalue.cpp \
    subform/formfavorites.cpp \
    subform/formfriends.cpp \
    subform/formgames.cpp \
    subform/formsettings.cpp \
    subform/formstatistics.cpp

HEADERS += \
    class/Threads/threadachievements.h \
    class/Threads/threadfriends.h \
    class/Threads/threadgames.h \
    class/Threads/threading.h \
    class/filter.h \
    class/imagerequest.h \
    class/profile.h \
    class/settings.h \
    class/steamapi/Sachievement.h \
    class/steamapi/Sachievementglobal.h \
    class/steamapi/Sachievementpercentage.h \
    class/steamapi/Sachievementplayer.h \
    class/steamapi/Sachievements.h \
    class/steamapi/Sachievementsglobal.h \
    class/steamapi/Sachievementspercentage.h \
    class/steamapi/Sachievementsplayer.h \
    class/steamapi/Sbans.h \
    class/steamapi/Sfriend.h \
    class/steamapi/Sfriends.h \
    class/steamapi/Sgame.h \
    class/steamapi/Sgames.h \
    class/steamapi/Slevels.h \
    class/steamapi/Sprofile.h \
        mainwindow.h \
    formachievements.h \
    subform/formcategoryvalue.h \
    subform/formfavorites.h \
    subform/formfriends.h \
    subform/formgames.h \
    subform/formsettings.h \
    subform/formstatistics.h

FORMS += \
        mainwindow.ui \
    formachievements.ui \
    subform/formcategoryvalue.ui \
    subform/formfavorites.ui \
    subform/formfriends.ui \
    subform/formgames.ui \
    subform/formsettings.ui \
    subform/formstatistics.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images/resimg.qrc \
    languages/lang.qrc

DISTFILES +=
