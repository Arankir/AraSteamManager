#-------------------------------------------------
#
# Project created by QtCreator 2019-03-26T13:57:12
#
#-------------------------------------------------

QT       += core gui network charts concurrent

QMAKE_CXXFLAGS_DEBUG += -pg -no-pie
QMAKE_LFLAGS_DEBUG += -pg -no-pie

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

CONFIG += c++20

SOURCES += \
    classes/common/loghelper.cpp \
    classes/files/category.cpp \
    classes/files/comments.cpp \
    classes/files/exportfile.cpp \
    classes/files/favorites.cpp \
    classes/common/filesaveload.cpp \
    classes/common/generalfunctions.cpp \
    classes/common/images.cpp \
    classes/common/settings.cpp \
    classes/common/theme.cpp \
    classes/files/groupsgames.cpp \
    classes/network/requestdata.cpp \
    classes/network/requestimage.cpp \
    classes/steamApi/sapi.cpp \
    classes/steamApi/structures/sachievements.cpp \
    classes/steamApi/structures/sbadge.cpp \
    classes/steamApi/structures/sbans.cpp \
    classes/steamApi/structures/sfriends.cpp \
    classes/steamApi/structures/sgames.cpp \
    classes/steamApi/structures/sprofile.cpp \
    classes/steamApi/structures/sprofilecustomization.cpp \
    classes/threads/thread/threadstatistics.cpp \
    classes/threads/threadloading.cpp \
    form.cpp \
    forms/main/formprofilesbrowser.cpp \
    forms/main/settings/colorpicker.cpp \
    forms/main/settings/formcommonsettings.cpp \
    forms/main/settings/formimportexport.cpp \
    forms/widgets/formfrienditemgraph.cpp \
    forms/formcomments.cpp \
    forms/formcontainerachievements.cpp \
    forms/formgroups.cpp \
    forms/formmain.cpp \
    forms/achievements/formachievements.cpp \
    forms/achievements/formcategoriesedit.cpp \
    forms/widgets/formfrienditemcompare.cpp \
    forms/main/formfavorites.cpp \
    forms/main/formfriends.cpp \
    forms/main/formgames.cpp \
    forms/main/formprofile.cpp \
    forms/main/formsettings.cpp \
    forms/main/formstatistics.cpp \
    forms/widgets/formimportitem.cpp \
    subWidgets/charts/achievementcompletedpiechart.cpp \
    subWidgets/charts/piechart.cpp \
    subWidgets/collapsablewidget.cpp \
    subWidgets/items/friendlistitem.cpp \
    subWidgets/lineEdit/mylineedit.cpp \
    framelesswindow.cpp \
        main.cpp \
    subWidgets/actions/actioncategory.cpp \
    subWidgets/comboBoxes/multiselectcombobox.cpp \
    subWidgets/delegates/progressbardelegate.cpp \
    subWidgets/items/qlistwidgetachievement.cpp \
    subWidgets/labels/labellight.cpp \
    subWidgets/labels/labelvalue.cpp \
    subWidgets/lists/qlistwidgetachievements.cpp \
    subWidgets/models/achievementsmodel.cpp \
    subWidgets/models/categoriesmodel.cpp \
    subWidgets/models/filters.cpp \
    subWidgets/models/friendsmodel.cpp \
    subWidgets/models/gamesmodel.cpp \
    subWidgets/models/gameswithpercentmodel.cpp \
    subWidgets/progressBars/progressbarbad.cpp \
    subWidgets/progressBars/progressbargood.cpp \
    subWidgets/progressBars/progressbarlight.cpp \
    subWidgets/tables/freezetablewidget.cpp \
    subWidgets/tables/mytable.cpp \
    subWidgets/withData/buttonreachedtype.cpp \
    subWidgets/withData/qbuttonwithdata.cpp \
    subWidgets/withData/qcheckboxwithdata.cpp \
    subWidgets/withData/qcomboboxwithdata.cpp \
    subWidgets/withData/qradiobuttonwithdata.cpp \

HEADERS += \
    classes/common/loghelper.h \
    classes/files/category.h \
    classes/files/comments.h \
    classes/files/exportfile.h \
    classes/files/favorites.h \
    classes/common/filesaveload.h \
    classes/common/generalfunctions.h \
    classes/common/images.h \
    classes/common/settings.h \
    classes/common/theme.h \
    classes/files/groupsgames.h \
    classes/network/requestdata.h \
    classes/network/requestimage.h \
    classes/steamApi/sapi.h \
    classes/steamApi/structures/sachievements.h \
    classes/steamApi/structures/sbadge.h \
    classes/steamApi/structures/sbans.h \
    classes/steamApi/structures/sfriends.h \
    classes/steamApi/structures/sgames.h \
    classes/steamApi/structures/sprofile.h \
    classes/steamApi/structures/sprofilecustomization.h \
    classes/threads/thread/threadstatistics.h \
    classes/threads/threadloading.h \
    form.h \
    forms/main/formprofilesbrowser.h \
    forms/main/settings/colorpicker.h \
    forms/main/settings/formcommonsettings.h \
    forms/main/settings/formimportexport.h \
    forms/widgets/formfrienditemgraph.h \
    forms/formcomments.h \
    forms/formcontainerachievements.h \
    forms/formgroups.h \
    forms/formmain.h \
    forms/achievements/formachievements.h \
    forms/achievements/formcategoriesedit.h \
    forms/widgets/formfrienditemcompare.h \
    forms/main/formfavorites.h \
    forms/main/formfriends.h \
    forms/main/formgames.h \
    forms/main/formprofile.h \
    forms/main/formsettings.h \
    forms/main/formstatistics.h \
    forms/widgets/formimportitem.h \
    subWidgets/charts/achievementcompletedpiechart.h \
    subWidgets/charts/piechart.h \
    subWidgets/collapsablewidget.h \
    subWidgets/items/friendlistitem.h \
    subWidgets/lineEdit/mylineedit.h \
    framelesswindow.h \
    subWidgets/actions/actioncategory.h \
    subWidgets/comboBoxes/multiselectcombobox.h \
    subWidgets/delegates/progressbardelegate.h \
    subWidgets/items/qlistwidgetachievement.h \
    subWidgets/labels/labellight.h \
    subWidgets/labels/labelvalue.h \
    subWidgets/lists/qlistwidgetachievements.h \
    subWidgets/models/achievementsmodel.h \
    subWidgets/models/categoriesmodel.h \
    subWidgets/models/filters.h \
    subWidgets/models/friendsmodel.h \
    subWidgets/models/gamesmodel.h \
    subWidgets/models/gameswithpercentmodel.h \
    subWidgets/progressBars/progressbarbad.h \
    subWidgets/progressBars/progressbargood.h \
    subWidgets/progressBars/progressbarlight.h \
    subWidgets/tables/freezetablewidget.h \
    subWidgets/tables/mytable.h \
    subWidgets/withData/buttonreachedtype.h \
    subWidgets/withData/qbuttonwithdata.h \
    subWidgets/withData/qcheckboxwithdata.h \
    subWidgets/withData/qcomboboxwithdata.h \
    subWidgets/withData/qradiobuttonwithdata.h \
    version.h

FORMS += \
    forms/main/formprofilesbrowser.ui \
    forms/main/settings/colorpicker.ui \
    forms/main/settings/formcommonsettings.ui \
    forms/main/settings/formimportexport.ui \
    forms/widgets/formfrienditemgraph.ui \
    forms/formcomments.ui \
    forms/formcontainerachievements.ui \
    forms/formgroups.ui \
    forms/formmain.ui \
    forms/achievements/formachievements.ui \
    forms/achievements/formcategoriesedit.ui \
    forms/widgets/formfrienditemcompare.ui \
    forms/main/formfavorites.ui \
    forms/main/formfriends.ui \
    forms/main/formgames.ui \
    forms/main/formprofile.ui \
    forms/main/formsettings.ui \
    forms/main/formstatistics.ui \
    forms/widgets/formimportitem.ui \
    framelesswindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources/fonts/fonts.qrc \
    resources/images/img.qrc \
    resources/languages/lang.qrc \
    resources/themes/thm.qrc

RC_FILE = SAS.rc

DISTFILES += \
    resources/images/languages/eng.png \
    resources/images/languages/rus.png

RC_ICONS = SAS.ico
