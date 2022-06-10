#ifndef IMAGES_H
#define IMAGES_H

#include <QString>

class Images {
public:
    static QString loading();
    static QString logo();

    //States
    static QString stateBlue();
    static QString stateGreen();
    static QString stateRed();
    static QString stateYellow();

    static QString levels(const int &hundreds);

    //Achievements Checkbox
    static QString allAchievements();
    static QString reached();
    static QString notReached();

    //Achievements Categories
    static QString checkVisible();
    static QString uncheckVisible();
    static QString reverse();
    static QString deleteCategory();
    static QString deleteAllCategories();

    //Achievements
    static QString category();
    static QString checkAll();
    static QString guides();
    static QString guide();

    //Comments
    static QString isComment();
    static QString isNotComment();

    //Dirrection arrows
    static QString first();
    static QString back();
    static QString next();
    static QString last();
    static QString top();
    static QString bottom();
    static QString up();
    static QString down();

    //Favorites
    static QString isFavorites();
    static QString isNotFavorites();

    //Hide
    static QString hide();
    static QString visible();

    //Main
    static QString findProfile();
    static QString home();
    static QString left();
    static QString right();
    static QString settings();

    //Management
    static QString apply();
    static QString cancel();
    static QString change();
    static QString compare();
    static QString create();
    static QString deleteIcon();
    static QString deleteAll();
    static QString moveItem();
    static QString moveInTree();
    static QString download();
    static QString edit();
    static QString find();
    static QString update();

    //Profile icon
    static QString friends();
    static QString games();
    static QString setHome();
    static QString statistic();

    //Window buttons
    static QString closeWindow();
    static QString maximizeWindow();
    static QString minimizeWindow();
    static QString normalizeWindow();

    //Other
    static QString achievement();
    static QString backRounded();
    static QString exit();
    static QString filter();
    static QString goTo();
    static QString group1();
    static QString group2();
    static QString link();
    static QString profile();

    //Widgets
    static QString checkBoxChecked();
    static QString checkBoxCheckedHover();
    static QString checkBoxCheckedPress();

    static QString checkBoxUnchecked();
    static QString checkBoxUncheckedHover();
    static QString checkBoxUncheckedPress();

    static QString radioButtonChecked();
    static QString radioButtonCheckedHover();
    static QString radioButtonCheckedPress();

    static QString radioButtonUnchecked();
    static QString radioButtonUncheckedHover();
    static QString radioButtonUncheckedPress();

    static QString comboBoxDown();

    static QString scrollBarUp();
    static QString scrollBarDown();
    static QString scrollBarLeft();
    static QString scrollBarRight();

    static QString missingImage();
};

#endif // IMAGES_H
