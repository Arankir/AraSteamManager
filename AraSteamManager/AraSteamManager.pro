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
DEFINES += QT_DEPRECATED_WARNINGS  QT_MESSAGELOGCONTEXT #Названия функций в релизном билде

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    classes/achievements/categoriesgame.cpp \
    classes/common/comments.cpp \
    classes/common/favorites.cpp \
    classes/common/myfilter.cpp \
    classes/common/settings.cpp \
    classes/games/groupsgames.cpp \
    classes/games/hiddengames.cpp \
    classes/network/requestdata.cpp \
    classes/network/requestimage.cpp \
    classes/notMine/donutbreakdownchart.cpp \
    classes/notMine/freezetablewidget.cpp \
    classes/notMine/mainslice.cpp \
    classes/notMine/multiselectcombobox.cpp \
    classes/steamApi/sapi.cpp \
    classes/steamApi/structures/sachievements.cpp \
    classes/steamApi/structures/sbans.cpp \
    classes/steamApi/structures/sfriends.cpp \
    classes/steamApi/structures/sgames.cpp \
    classes/steamApi/structures/slevels.cpp \
    classes/steamApi/structures/sprofile.cpp \
    classes/threads/thread/threadachievements.cpp \
    classes/threads/thread/threadfriends.cpp \
    classes/threads/thread/threadgames.cpp \
    classes/threads/thread/threadstatistics.cpp \
    classes/threads/threading.cpp \
    forms/formcommentsinteractions.cpp \
    forms/formcontainerachievements.cpp \
    forms/formgroupsgamesinteractions.cpp \
    forms/formmain.cpp \
    forms/mainwindow.cpp \
    forms/subForms/achievements/formachievements.cpp \
    forms/subForms/achievements/formcategoriesedit.cpp \
    forms/subForms/achievements/formcompareprofilefilter.cpp \
    forms/subForms/achievements/formfriendscompare.cpp \
    forms/subForms/achievements/formtablesheaders.cpp \
    forms/subForms/main/formfavorites.cpp \
    forms/subForms/main/formfriends.cpp \
    forms/subForms/main/formgames.cpp \
    forms/subForms/main/formprofile.cpp \
    forms/subForms/main/formsettings.cpp \
    forms/subForms/main/formstatistics.cpp \
    frameless.cpp \
    framelesswindow.cpp \
        main.cpp \
    subWidgets/items/qlistwidgetachievement.cpp \
    subWidgets/items/qlistwidgetfriend.cpp \
    subWidgets/models/listachievementsmodel.cpp \
    subWidgets/qcomboboxfriends.cpp \
    subWidgets/qlistwidgetachievements.cpp \
    subWidgets/withData/qbuttonwithdata.cpp \
    subWidgets/withData/qcheckboxwithdata.cpp \
    subWidgets/withData/qcomboboxwithdata.cpp \
    subWidgets/withData/qradiobuttonwithdata.cpp \

HEADERS += \
    classes/achievements/categoriesgame.h \
    classes/common/comments.h \
    classes/common/favorites.h \
    classes/common/myfilter.h \
    classes/common/settings.h \
    classes/games/groupsgames.h \
    classes/games/hiddengames.h \
    classes/network/requestdata.h \
    classes/network/requestimage.h \
    classes/notMine/donutbreakdownchart.h \
    classes/notMine/freezetablewidget.h \
    classes/notMine/mainslice.h \
    classes/notMine/multiselectcombobox.h \
    classes/steamApi/sapi.h \
    classes/steamApi/structures/sachievements.h \
    classes/steamApi/structures/sbans.h \
    classes/steamApi/structures/sfriends.h \
    classes/steamApi/structures/sgames.h \
    classes/steamApi/structures/slevels.h \
    classes/steamApi/structures/sprofile.h \
    classes/threads/thread/threadachievements.h \
    classes/threads/thread/threadfriends.h \
    classes/threads/thread/threadgames.h \
    classes/threads/thread/threadstatistics.h \
    classes/threads/threading.h \
    forms/formcommentsinteractions.h \
    forms/formcontainerachievements.h \
    forms/formgroupsgamesinteractions.h \
    forms/formmain.h \
    forms/mainwindow.h \
    forms/subForms/achievements/formachievements.h \
    forms/subForms/achievements/formcategoriesedit.h \
    forms/subForms/achievements/formcompareprofilefilter.h \
    forms/subForms/achievements/formfriendscompare.h \
    forms/subForms/achievements/formtablesheaders.h \
    forms/subForms/main/formfavorites.h \
    forms/subForms/main/formfriends.h \
    forms/subForms/main/formgames.h \
    forms/subForms/main/formprofile.h \
    forms/subForms/main/formsettings.h \
    forms/subForms/main/formstatistics.h \
    frameless.h \
    framelesswindow.h \
    subWidgets/items/qlistwidgetachievement.h \
    subWidgets/items/qlistwidgetfriend.h \
    subWidgets/models/listachievementsmodel.h \
    subWidgets/qcomboboxfriends.h \
    subWidgets/qlistwidgetachievements.h \
    subWidgets/withData/qbuttonwithdata.h \
    subWidgets/withData/qcheckboxwithdata.h \
    subWidgets/withData/qcomboboxwithdata.h \
    subWidgets/withData/qradiobuttonwithdata.h \

FORMS += \
    forms/formcommentsinteractions.ui \
    forms/formcontainerachievements.ui \
    forms/formgroupsgamesinteractions.ui \
    forms/formmain.ui \
    forms/mainwindow.ui \
    forms/subForms/achievements/formachievements.ui \
    forms/subForms/achievements/formachievementscategoriesedit.ui \
    forms/subForms/achievements/formachievementsfriendscompare.ui \
    forms/subForms/achievements/formcompareprofilefilter.ui \
    forms/subForms/achievements/formtablesheaders.ui \
    forms/subForms/main/formfavorites.ui \
    forms/subForms/main/formfriends.ui \
    forms/subForms/main/formgames.ui \
    forms/subForms/main/formprofile.ui \
    forms/subForms/main/formsettings.ui \
    forms/subForms/main/formstatistics.ui \
    framelesswindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images/resimg.qrc \
    languages/lang.qrc \
    themes/thm.qrc

DISTFILES +=

RC_ICONS = SAS.ico
