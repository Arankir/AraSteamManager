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
    return Theme::getCurrentTheme().getPathImages() + "achievements/checkbox/all.png";
}

QString Images::reached() {
    return Theme::getCurrentTheme().getPathImages() + "achievements/checkbox/reached.png";
}

QString Images::notReached() {
    return Theme::getCurrentTheme().getPathImages() + "achievements/checkbox/notreached.png";
}
#define AchievementsCheckBoxEnd }

#define AchievementsCategories {
QString Images::checkVisible() {
    return Theme::getCurrentTheme().getPathImages() + "achievements/categories/check_visible.png";
}

QString Images::uncheckVisible() {
    return Theme::getCurrentTheme().getPathImages() + "achievements/categories/uncheck_visible.png";
}

QString Images::reverse() {
    return Theme::getCurrentTheme().getPathImages() + "achievements/categories/reverse.png";
}

QString Images::deleteCategory() {
    return Theme::getCurrentTheme().getPathImages() + "achievements/categories/delete_category.png";
}

QString Images::deleteAllCategories() {
    return Theme::getCurrentTheme().getPathImages() + "achievements/categories/delete_all_categories.png";
}
#define AchievementCategoriesEnd }

QString Images::category() {
    return Theme::getCurrentTheme().getPathImages() + "achievements/category.png";
}

QString Images::checkAll() {
    return Theme::getCurrentTheme().getPathImages() + "achievements/check_all.png";
}

QString Images::guides() {
    return Theme::getCurrentTheme().getPathImages() + "achievements/guides.png";
}

QString Images::guide() {
    return Theme::getCurrentTheme().getPathImages() + "achievements/guide.png";
}
#define AchievementsDirEnd }

#define Comments {
QString Images::isComment() {
    return Theme::getCurrentTheme().getPathImages() + "comments/isComment.png";
}

QString Images::isNotComment() {
    return Theme::getCurrentTheme().getPathImages() + "comments/isNotComment.png";
}
#define CommentsEnd }

#define Direction {
QString Images::first() {
    return Theme::getCurrentTheme().getPathImages() + "dirrection arrows/first.png";
}

QString Images::back() {
    return Theme::getCurrentTheme().getPathImages() + "dirrection arrows/left.png";
}

QString Images::next() {
    return Theme::getCurrentTheme().getPathImages() + "dirrection arrows/right.png";
}

QString Images::last() {
    return Theme::getCurrentTheme().getPathImages() + "dirrection arrows/last.png";
}

QString Images::top() {
    return Theme::getCurrentTheme().getPathImages() + "dirrection arrows/top.png";
}

QString Images::up() {
    return Theme::getCurrentTheme().getPathImages() + "dirrection arrows/up.png";
}

QString Images::down() {
    return Theme::getCurrentTheme().getPathImages() + "dirrection arrows/down.png";
}

QString Images::bottom() {
    return Theme::getCurrentTheme().getPathImages() + "dirrection arrows/bottom.png";
}
#define DirectionEnd }

#define Favorites {
QString Images::isFavorites() {
    return Theme::getCurrentTheme().getPathImages() + "favorites/in_favorites.png";
}

QString Images::isNotFavorites() {
    return Theme::getCurrentTheme().getPathImages() + "favorites/favorites.png";
}
#define FavoritesEnd }

#define Hide {
QString Images::hide() {
    return Theme::getCurrentTheme().getPathImages() + "hide/hide.png";
}

QString Images::visible() {
    return Theme::getCurrentTheme().getPathImages() + "hide/visible.png";
}
#define HideEnd }

#define Main {
QString Images::findProfile() {
    return Theme::getCurrentTheme().getPathImages() + "main/find_profile.png";
}

QString Images::home() {
    return Theme::getCurrentTheme().getPathImages() + "main/home.png";
}

QString Images::left() {
    return Theme::getCurrentTheme().getPathImages() + "main/left.png";
}

QString Images::right() {
    return Theme::getCurrentTheme().getPathImages() + "main/right.png";
}

QString Images::settings() {
    return Theme::getCurrentTheme().getPathImages() + "main/settings.png";
}
#define MainEnd }

#define Management {
QString Images::apply() {
    return Theme::getCurrentTheme().getPathImages() + "management/apply.png";
}

QString Images::cancel() {
    return Theme::getCurrentTheme().getPathImages() + "management/cancel.png";
}

QString Images::change() {
    return Theme::getCurrentTheme().getPathImages() + "management/change.png";
}

QString Images::compare() {
    return Theme::getCurrentTheme().getPathImages() + "management/back.png";
}

QString Images::create() {
    return Theme::getCurrentTheme().getPathImages() + "management/create.png";
}

QString Images::deleteIcon() {
    return Theme::getCurrentTheme().getPathImages() + "management/delete.png";
}

QString Images::deleteAll() {
    return Theme::getCurrentTheme().getPathImages() + "management/delete_all.png";
}

QString Images::moveItem() {
    return Theme::getCurrentTheme().getPathImages() + "management/move_item.png";
}

QString Images::moveInTree() {
    return Theme::getCurrentTheme().getPathImages() + "management/move_in_tree.png";
}

QString Images::download() {
    return Theme::getCurrentTheme().getPathImages() + "management/download.png";
}

QString Images::edit() {
    return Theme::getCurrentTheme().getPathImages() + "management/edit.png";
}

QString Images::find() {
    return Theme::getCurrentTheme().getPathImages() + "management/find.png";
}

QString Images::update() {
    return Theme::getCurrentTheme().getPathImages() + "management/update.png";
}
#define ManagementEnd }

#define ProfileIcon {
QString Images::friends() {
    return Theme::getCurrentTheme().getPathImages() + "profile icons/friends.png";
}

QString Images::games() {
    return Theme::getCurrentTheme().getPathImages() + "profile icons/games.png";
}

QString Images::setHome() {
    return Theme::getCurrentTheme().getPathImages() + "profile icons/set_home.png";
}

QString Images::statistic() {
    return Theme::getCurrentTheme().getPathImages() + "profile icons/statistic.png";
}
#define ProfileIconEnd }

#define Widgets {
QString Images::checkBoxChecked() {
    return Theme::getCurrentTheme().getPathImages() + "widgets/checkbox_checked.png";
}

QString Images::checkBoxCheckedHover() {
    return Theme::getCurrentTheme().getPathImages() + "widgets/checkbox_checked_hover.png";
}

QString Images::checkBoxCheckedPress() {
    return Theme::getCurrentTheme().getPathImages() + "widgets/checkbox_checked_press.png";
}

QString Images::checkBoxUnchecked() {
    return Theme::getCurrentTheme().getPathImages() + "widgets/checkbox_unchecked.png";
}

QString Images::checkBoxUncheckedHover() {
    return Theme::getCurrentTheme().getPathImages() + "widgets/checkbox_unchecked_hover.png";
}

QString Images::checkBoxUncheckedPress() {
    return Theme::getCurrentTheme().getPathImages() + "widgets/checkbox_unchecked_press.png";
}

QString Images::radioButtonChecked() {
    return Theme::getCurrentTheme().getPathImages() + "widgets/radiobutton_checked.png";
}

QString Images::radioButtonCheckedHover() {
    return Theme::getCurrentTheme().getPathImages() + "widgets/radiobutton_checked_hover.png";
}

QString Images::radioButtonCheckedPress() {
    return Theme::getCurrentTheme().getPathImages() + "widgets/radiobutton_checked_press.png";
}

QString Images::radioButtonUnchecked() {
    return Theme::getCurrentTheme().getPathImages() + "widgets/radiobutton_unchecked.png";
}

QString Images::radioButtonUncheckedHover() {
    return Theme::getCurrentTheme().getPathImages() + "widgets/radiobutton_unchecked_hover.png";
}

QString Images::radioButtonUncheckedPress() {
    return Theme::getCurrentTheme().getPathImages() + "widgets/radiobutton_unchecked_press.png";
}

QString Images::comboBoxDown() {
    return Theme::getCurrentTheme().getPathImages() + "widgets/combobox_down.png";
}

QString Images::scrollBarUp() {
    return Theme::getCurrentTheme().getPathImages() + "widgets/scrollbar_up.png";
}

QString Images::scrollBarDown() {
    return Theme::getCurrentTheme().getPathImages() + "widgets/scrollbar_down.png";
}

QString Images::scrollBarLeft() {
    return Theme::getCurrentTheme().getPathImages() + "widgets/scrollbar_left.png";
}

QString Images::scrollBarRight() {
    return Theme::getCurrentTheme().getPathImages() + "widgets/scrollbar_right.png";
}
#define WidgetsEnd }

#define WindowButtons {
QString Images::closeWindow() {
    return Theme::getCurrentTheme().getPathImages() + "window buttons/close_window.png";
}

QString Images::maximizeWindow() {
    return Theme::getCurrentTheme().getPathImages() + "window buttons/maximize_window.png";
}

QString Images::minimizeWindow() {
    return Theme::getCurrentTheme().getPathImages() + "window buttons/minimize_window.png";
}

QString Images::normalizeWindow() {
    return Theme::getCurrentTheme().getPathImages() + "window buttons/restore_window.png";
}
#define WindowButtonsEnd }

#define Other {
QString Images::achievement() {
    return Theme::getCurrentTheme().getPathImages() + "achievement.png";
}

QString Images::backRounded() {
    return Theme::getCurrentTheme().getPathImages() + "back.png";
}

QString Images::exit() {
    return Theme::getCurrentTheme().getPathImages() + "exit.png";
}

QString Images::filter() {
    return Theme::getCurrentTheme().getPathImages() + "filter.png";
}

QString Images::goTo() {
    return Theme::getCurrentTheme().getPathImages() + "go_to.png";
}

QString Images::group1() {
    return Theme::getCurrentTheme().getPathImages() + "group1.png";
}

QString Images::group2() {
    return Theme::getCurrentTheme().getPathImages() + "group2.png";
}

QString Images::link() {
    return Theme::getCurrentTheme().getPathImages() + "link.png";
}

QString Images::profile() {
    return Theme::getCurrentTheme().getPathImages() + "profile.png";
}
#define OtherEnd }

QString Images::missingImage() {
    return "://MissingImage.png";
}
