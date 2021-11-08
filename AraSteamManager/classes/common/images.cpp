#include "images.h"
QString Images::loading() {
    return "://loading.png";
}

QString Images::logo() {
    return "://logo.png";
}

#define States {
QString Images::stateBlue() {
    return "://state_blue.png";
}

QString Images::stateGreen() {
    return "://state_green.png";
}

QString Images::stateRed() {
    return "://state_red.png";
}

QString Images::stateYellow() {
    return "://state_yellow.png";
}
#define StatesEnd }

QString Images::levels(const int &aHundreds) {
    return QString("://levels/%1.png").arg(QString::number(aHundreds));
}

#define AchievementsDir {
#define AchievementsCheckBox {
QString Images::allAchievements() {
    return "://" + Settings::iconsColor() + "/achievements/checkbox/all.png";
}

QString Images::reached() {
    return "://" + Settings::iconsColor() + "/achievements/checkbox/reached.png";
}

QString Images::notReached() {
    return "://" + Settings::iconsColor() + "/achievements/checkbox/notreached.png";
}
#define AchievementsCheckBoxEnd }

#define AchievementsCategories {
QString Images::checkVisible() {
    return "://" + Settings::iconsColor() + "/achievements/categories/check_visible.png";
}

QString Images::uncheckVisible() {
    return "://" + Settings::iconsColor() + "/achievements/categories/uncheck_visible.png";
}

QString Images::reverse() {
    return "://" + Settings::iconsColor() + "/achievements/categories/reverse.png";
}

QString Images::deleteCategory() {
    return "://" + Settings::iconsColor() + "/achievements/categories/delete_category.png";
}

QString Images::deleteAllCategories() {
    return "://" + Settings::iconsColor() + "/achievements/categories/delete_all_categories.png";
}
#define AchievementCategoriesEnd }

QString Images::category() {
    return "://" + Settings::iconsColor() + "/achievements/category.png";
}

QString Images::checkAll() {
    return "://" + Settings::iconsColor() + "/achievements/check_all.png";
}

QString Images::guides() {
    return "://" + Settings::iconsColor() + "/achievements/guides.png";
}

QString Images::guide() {
    return "://" + Settings::iconsColor() + "/achievements/guide.png";
}
#define AchievementsDirEnd }

#define Comments {
QString Images::isComment() {
    return "://" + Settings::iconsColor() + "/comments/isComment.png";
}

QString Images::isNotComment() {
    return "://" + Settings::iconsColor() + "/comments/isNotComment.png";
}
#define CommentsEnd }

#define Direction {
QString Images::first() {
    return "://" + Settings::iconsColor() + "/dirrection arrows/first.png";
}

QString Images::back() {
    return "://" + Settings::iconsColor() + "/dirrection arrows/left.png";
}

QString Images::next() {
    return "://" + Settings::iconsColor() + "/dirrection arrows/right.png";
}

QString Images::last() {
    return "://" + Settings::iconsColor() + "/dirrection arrows/last.png";
}

QString Images::top() {
    return "://" + Settings::iconsColor() + "/dirrection arrows/top.png";
}

QString Images::up() {
    return "://" + Settings::iconsColor() + "/dirrection arrows/up.png";
}

QString Images::down() {
    return "://" + Settings::iconsColor() + "/dirrection arrows/down.png";
}

QString Images::bottom() {
    return "://" + Settings::iconsColor() + "/dirrection arrows/bottom.png";
}
#define DirectionEnd }

#define Favorites {
QString Images::isFavorites() {
    return "://" + Settings::iconsColor() + "/favorites/in_favorites.png";
}

QString Images::isNotFavorites() {
    return "://" + Settings::iconsColor() + "/favorites/favorites.png";
}
#define FavoritesEnd }

#define Hide {
QString Images::hide() {
    return "://" + Settings::iconsColor() + "/hide/hide.png";
}

QString Images::visible() {
    return "://" + Settings::iconsColor() + "/hide/visible.png";
}
#define HideEnd }

#define Main {
QString Images::findProfile() {
    return "://" + Settings::iconsColor() + "/main/find_profile.png";
}

QString Images::home() {
    return "://" + Settings::iconsColor() + "/main/home.png";
}

QString Images::left() {
    return "://" + Settings::iconsColor() + "/main/left.png";
}

QString Images::right() {
    return "://" + Settings::iconsColor() + "/main/right.png";
}

QString Images::settings() {
    return "://" + Settings::iconsColor() + "/main/settings.png";
}
#define MainEnd }

#define Management {
QString Images::apply() {
    return "://" + Settings::iconsColor() + "/management/apply.png";
}

QString Images::cancel() {
    return "://" + Settings::iconsColor() + "/management/cancel.png";
}

QString Images::change() {
    return "://" + Settings::iconsColor() + "/management/change.png";
}

QString Images::compare() {
    return "://" + Settings::iconsColor() + "/management/back.png";
}

QString Images::create() {
    return "://" + Settings::iconsColor() + "/management/create.png";
}

QString Images::deleteIcon() {
    return "://" + Settings::iconsColor() + "/management/delete.png";
}

QString Images::deleteAll() {
    return "://" + Settings::iconsColor() + "/management/delete_all.png";
}

QString Images::moveItem() {
    return "://" + Settings::iconsColor() + "/management/move_item.png";
}

QString Images::moveInTree() {
    return "://" + Settings::iconsColor() + "/management/move_in_tree.png";
}

QString Images::download() {
    return "://" + Settings::iconsColor() + "/management/download.png";
}

QString Images::edit() {
    return "://" + Settings::iconsColor() + "/management/edit.png";
}

QString Images::find() {
    return "://" + Settings::iconsColor() + "/management/find.png";
}

QString Images::update() {
    return "://" + Settings::iconsColor() + "/management/update.png";
}
#define ManagementEnd }

#define ProfileIcon {
QString Images::friends() {
    return "://" + Settings::iconsColor() + "/profile icons/friends.png";
}

QString Images::games() {
    return "://" + Settings::iconsColor() + "/profile icons/games.png";
}

QString Images::setHome() {
    return "://" + Settings::iconsColor() + "/profile icons/set_home.png";
}

QString Images::statistic() {
    return "://" + Settings::iconsColor() + "/profile icons/statistic.png";
}
#define ProfileIconEnd }

#define Widgets {
QString Images::checkBoxChecked() {
    return "://" + Settings::iconsColor() + "/widgets/checkbox_checked.png";
}

QString Images::checkBoxCheckedHover() {
    return "://" + Settings::iconsColor() + "/widgets/checkbox_checked_hover.png";
}

QString Images::checkBoxCheckedPress() {
    return "://" + Settings::iconsColor() + "/widgets/checkbox_checked_press.png";
}

QString Images::checkBoxUnchecked() {
    return "://" + Settings::iconsColor() + "/widgets/checkbox_unchecked.png";
}

QString Images::checkBoxUncheckedHover() {
    return "://" + Settings::iconsColor() + "/widgets/checkbox_unchecked_hover.png";
}

QString Images::checkBoxUncheckedPress() {
    return "://" + Settings::iconsColor() + "/widgets/checkbox_unchecked_press.png";
}

QString Images::radioButtonChecked() {
    return "://" + Settings::iconsColor() + "/widgets/radiobutton_checked.png";
}

QString Images::radioButtonCheckedHover() {
    return "://" + Settings::iconsColor() + "/widgets/radiobutton_checked_hover.png";
}

QString Images::radioButtonCheckedPress() {
    return "://" + Settings::iconsColor() + "/widgets/radiobutton_checked_press.png";
}

QString Images::radioButtonUnchecked() {
    return "://" + Settings::iconsColor() + "/widgets/radiobutton_unchecked.png";
}

QString Images::radioButtonUncheckedHover() {
    return "://" + Settings::iconsColor() + "/widgets/radiobutton_unchecked_hover.png";
}

QString Images::radioButtonUncheckedPress() {
    return "://" + Settings::iconsColor() + "/widgets/radiobutton_unchecked_press.png";
}

QString Images::comboBoxDown() {
    return "://" + Settings::iconsColor() + "/widgets/combobox_down.png";
}

QString Images::scrollBarUp() {
    return "://" + Settings::iconsColor() + "/widgets/scrollbar_up.png";
}

QString Images::scrollBarDown() {
    return "://" + Settings::iconsColor() + "/widgets/scrollbar_down.png";
}

QString Images::scrollBarLeft() {
    return "://" + Settings::iconsColor() + "/widgets/scrollbar_left.png";
}

QString Images::scrollBarRight() {
    return "://" + Settings::iconsColor() + "/widgets/scrollbar_right.png";
}
#define WidgetsEnd }

#define WindowButtons {
QString Images::closeWindow() {
    return "://" + Settings::iconsColor() + "/window buttons/close_window.png";
}

QString Images::maximizeWindow() {
    return "://" + Settings::iconsColor() + "/window buttons/maximize_window.png";
}

QString Images::minimizeWindow() {
    return "://" + Settings::iconsColor() + "/window buttons/minimize_window.png";
}

QString Images::normalizeWindow() {
    return "://" + Settings::iconsColor() + "/window buttons/restore_window.png";
}
#define WindowButtonsEnd }

#define Other {
QString Images::achievement() {
    return "://" + Settings::iconsColor() + "/achievement.png";
}

QString Images::backRounded() {
    return "://" + Settings::iconsColor() + "/back.png";
}

QString Images::exit() {
    return "://" + Settings::iconsColor() + "/exit.png";
}

QString Images::filter() {
    return "://" + Settings::iconsColor() + "/filter.png";
}

QString Images::goTo() {
    return "://" + Settings::iconsColor() + "/go_to.png";
}

QString Images::group1() {
    return "://" + Settings::iconsColor() + "/group1.png";
}

QString Images::group2() {
    return "://" + Settings::iconsColor() + "/group2.png";
}

QString Images::link() {
    return "://" + Settings::iconsColor() + "/link.png";
}

QString Images::profile() {
    return "://" + Settings::iconsColor() + "/profile.png";
}
#define OtherEnd }

QString Images::missingImage() {
    return "://MissingImage.png";
}
