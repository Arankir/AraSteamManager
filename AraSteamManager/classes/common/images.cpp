#include "images.h"
#include "./theme.h"

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

QString Images::levels(int aHundreds) {
    return QString("://levels/%1.png").arg(QString::number(aHundreds));
}

#define AchievementsDir {
#define AchievementsCheckBox {
QString Images::allAchievements() {
    return Theme::getCurrentTheme().pathImages + "achievements/checkbox/all.png";
}

QString Images::reached() {
    return Theme::getCurrentTheme().pathImages + "achievements/checkbox/reached.png";
}

QString Images::notReached() {
    return Theme::getCurrentTheme().pathImages + "achievements/checkbox/notreached.png";
}

QString Images::reachedGif() {
    return Theme::getCurrentTheme().pathImages + "achievements/checkbox/3-states.gif";
}
#define AchievementsCheckBoxEnd }

#define AchievementsCategories {
QString Images::checkVisible() {
    return Theme::getCurrentTheme().pathImages + "achievements/categories/check_visible.png";
}

QString Images::uncheckVisible() {
    return Theme::getCurrentTheme().pathImages + "achievements/categories/uncheck_visible.png";
}

QString Images::reverse() {
    return Theme::getCurrentTheme().pathImages + "achievements/categories/reverse.png";
}

QString Images::deleteCategory() {
    return Theme::getCurrentTheme().pathImages + "achievements/categories/delete_category.png";
}

QString Images::deleteAllCategories() {
    return Theme::getCurrentTheme().pathImages + "achievements/categories/delete_all_categories.png";
}

QString Images::expand() {
    return Theme::getCurrentTheme().pathImages + "achievements/categories/expand.png";
}

QString Images::collapse() {
    return Theme::getCurrentTheme().pathImages + "achievements/categories/collapse.png";
}
#define AchievementCategoriesEnd }

QString Images::category() {
    return Theme::getCurrentTheme().pathImages + "achievements/category.png";
}

QString Images::checkAll() {
    return Theme::getCurrentTheme().pathImages + "achievements/check_all.png";
}

QString Images::guides() {
    return Theme::getCurrentTheme().pathImages + "achievements/guides.png";
}

QString Images::guide() {
    return Theme::getCurrentTheme().pathImages + "achievements/guide.png";
}
#define AchievementsDirEnd }

#define Comments {
QString Images::isComment() {
    return Theme::getCurrentTheme().pathImages + "comments/isComment.png";
}

QString Images::isNotComment() {
    return Theme::getCurrentTheme().pathImages + "comments/isNotComment.png";
}
#define CommentsEnd }

#define Direction {
QString Images::first() {
    return Theme::getCurrentTheme().pathImages + "dirrection arrows/first.png";
}

QString Images::back() {
    return Theme::getCurrentTheme().pathImages + "dirrection arrows/left.png";
}

QString Images::next() {
    return Theme::getCurrentTheme().pathImages + "dirrection arrows/right.png";
}

QString Images::last() {
    return Theme::getCurrentTheme().pathImages + "dirrection arrows/last.png";
}

QString Images::top() {
    return Theme::getCurrentTheme().pathImages + "dirrection arrows/top.png";
}

QString Images::up() {
    return Theme::getCurrentTheme().pathImages + "dirrection arrows/up.png";
}

QString Images::down() {
    return Theme::getCurrentTheme().pathImages + "dirrection arrows/down.png";
}

QString Images::bottom() {
    return Theme::getCurrentTheme().pathImages + "dirrection arrows/bottom.png";
}
#define DirectionEnd }

#define Favorites {
QString Images::isFavorites() {
    return Theme::getCurrentTheme().pathImages + "favorites/in_favorites.png";
}

QString Images::isNotFavorites() {
    return Theme::getCurrentTheme().pathImages + "favorites/favorites.png";
}
#define FavoritesEnd }

#define Hide {
QString Images::hide() {
    return Theme::getCurrentTheme().pathImages + "hide/hide.png";
}

QString Images::visible() {
    return Theme::getCurrentTheme().pathImages + "hide/visible.png";
}
#define HideEnd }

#define Main {
QString Images::findProfile() {
    return Theme::getCurrentTheme().pathImages + "main/find_profile.png";
}

QString Images::home() {
    return Theme::getCurrentTheme().pathImages + "main/home.png";
}

QString Images::left() {
    return Theme::getCurrentTheme().pathImages + "main/left.png";
}

QString Images::right() {
    return Theme::getCurrentTheme().pathImages + "main/right.png";
}

QString Images::settings() {
    return Theme::getCurrentTheme().pathImages + "main/settings.png";
}

QString Images::english() {
    return ":/languages/eng.png";
}

QString Images::russian() {
    return ":/languages/rus.png";
}
#define MainEnd }

#define Management {
QString Images::apply() {
    return Theme::getCurrentTheme().pathImages + "management/apply.png";
}

QString Images::cancel() {
    return Theme::getCurrentTheme().pathImages + "management/cancel.png";
}

QString Images::change() {
    return Theme::getCurrentTheme().pathImages + "management/change.png";
}

QString Images::compare() {
    return Theme::getCurrentTheme().pathImages + "management/back.png";
}

QString Images::create() {
    return Theme::getCurrentTheme().pathImages + "management/create.png";
}

QString Images::deleteIcon() {
    return Theme::getCurrentTheme().pathImages + "management/delete.png";
}

QString Images::deleteAll() {
    return Theme::getCurrentTheme().pathImages + "management/delete_all.png";
}

QString Images::moveItem() {
    return Theme::getCurrentTheme().pathImages + "management/move_item.png";
}

QString Images::moveInTree() {
    return Theme::getCurrentTheme().pathImages + "management/move_in_tree.png";
}

QString Images::download() {
    return Theme::getCurrentTheme().pathImages + "management/download.png";
}

QString Images::edit() {
    return Theme::getCurrentTheme().pathImages + "management/edit.png";
}

QString Images::find() {
    return Theme::getCurrentTheme().pathImages + "management/find.png";
}

QString Images::update() {
    return Theme::getCurrentTheme().pathImages + "management/update.png";
}
#define ManagementEnd }

#define ProfileIcon {
QString Images::friends() {
    return Theme::getCurrentTheme().pathImages + "profile icons/friends.png";
}

QString Images::games() {
    return Theme::getCurrentTheme().pathImages + "profile icons/games.png";
}

QString Images::setHome() {
    return Theme::getCurrentTheme().pathImages + "profile icons/set_home.png";
}

QString Images::statistic() {
    return Theme::getCurrentTheme().pathImages + "profile icons/statistic.png";
}

QString Images::special() {
    return Theme::getCurrentTheme().pathImages + "profile icons/special.png";
}

QString Images::normal() {
    return Theme::getCurrentTheme().pathImages + "profile icons/normal.png";
}

QString Images::foil() {
    return Theme::getCurrentTheme().pathImages + "profile icons/foil.png";
}

QString Images::badges1() {
    return Theme::getCurrentTheme().pathImages + "profile icons/badges1.png";
}

QString Images::badges2() {
    return Theme::getCurrentTheme().pathImages + "profile icons/badges2.png";
}

QString Images::badges3() {
    return Theme::getCurrentTheme().pathImages + "profile icons/badges3.png";
}

QString Images::badges4() {
    return Theme::getCurrentTheme().pathImages + "profile icons/badges4.png";
}

QString Images::badges5() {
    return Theme::getCurrentTheme().pathImages + "profile icons/badges5.png";
}

QString Images::badges5plus() {
    return Theme::getCurrentTheme().pathImages + "profile icons/badges5+.png";
}

QString Images::windows() {
    return Theme::getCurrentTheme().pathImages + "profile icons/windows.png";
}

QString Images::linux() {
    return Theme::getCurrentTheme().pathImages + "profile icons/linux.png";
}

QString Images::mac() {
    return Theme::getCurrentTheme().pathImages + "profile icons/mac.png";
}
#define ProfileIconEnd }

#define Widgets {
QString Images::checkBoxChecked() {
    return Theme::getCurrentTheme().pathImages + "widgets/checkbox_checked.png";
}

QString Images::checkBoxCheckedHover() {
    return Theme::getCurrentTheme().pathImages + "widgets/checkbox_checked_hover.png";
}

QString Images::checkBoxCheckedPress() {
    return Theme::getCurrentTheme().pathImages + "widgets/checkbox_checked_press.png";
}

QString Images::checkBoxUnchecked() {
    return Theme::getCurrentTheme().pathImages + "widgets/checkbox_unchecked.png";
}

QString Images::checkBoxUncheckedHover() {
    return Theme::getCurrentTheme().pathImages + "widgets/checkbox_unchecked_hover.png";
}

QString Images::checkBoxUncheckedPress() {
    return Theme::getCurrentTheme().pathImages + "widgets/checkbox_unchecked_press.png";
}

QString Images::radioButtonChecked() {
    return Theme::getCurrentTheme().pathImages + "widgets/radiobutton_checked.png";
}

QString Images::radioButtonCheckedHover() {
    return Theme::getCurrentTheme().pathImages + "widgets/radiobutton_checked_hover.png";
}

QString Images::radioButtonCheckedPress() {
    return Theme::getCurrentTheme().pathImages + "widgets/radiobutton_checked_press.png";
}

QString Images::radioButtonUnchecked() {
    return Theme::getCurrentTheme().pathImages + "widgets/radiobutton_unchecked.png";
}

QString Images::radioButtonUncheckedHover() {
    return Theme::getCurrentTheme().pathImages + "widgets/radiobutton_unchecked_hover.png";
}

QString Images::radioButtonUncheckedPress() {
    return Theme::getCurrentTheme().pathImages + "widgets/radiobutton_unchecked_press.png";
}

QString Images::comboBoxDown() {
    return Theme::getCurrentTheme().pathImages + "widgets/combobox_down.png";
}

QString Images::scrollBarUp() {
    return Theme::getCurrentTheme().pathImages + "widgets/scrollbar_up.png";
}

QString Images::scrollBarDown() {
    return Theme::getCurrentTheme().pathImages + "widgets/scrollbar_down.png";
}

QString Images::scrollBarLeft() {
    return Theme::getCurrentTheme().pathImages + "widgets/scrollbar_left.png";
}

QString Images::scrollBarRight() {
    return Theme::getCurrentTheme().pathImages + "widgets/scrollbar_right.png";
}

QString Images::doubleUp() {
    return Theme::getCurrentTheme().pathImages + "widgets/double_up.png";
}

QString Images::doubleDown() {
    return Theme::getCurrentTheme().pathImages + "widgets/double_down.png";
}

QString Images::doubleLeft() {
    return Theme::getCurrentTheme().pathImages + "widgets/double_left.png";
}

QString Images::doubleRight() {
    return Theme::getCurrentTheme().pathImages + "widgets/double_right.png";
}
#define WidgetsEnd }

#define WindowButtons {
QString Images::closeWindow() {
    return Theme::getCurrentTheme().pathImages + "window buttons/close_window.png";
}

QString Images::maximizeWindow() {
    return Theme::getCurrentTheme().pathImages + "window buttons/maximize_window.png";
}

QString Images::minimizeWindow() {
    return Theme::getCurrentTheme().pathImages + "window buttons/minimize_window.png";
}

QString Images::normalizeWindow() {
    return Theme::getCurrentTheme().pathImages + "window buttons/restore_window.png";
}
#define WindowButtonsEnd }

#define Other {
QString Images::achievement() {
    return Theme::getCurrentTheme().pathImages + "achievement.png";
}

QString Images::backRounded() {
    return Theme::getCurrentTheme().pathImages + "back.png";
}

QString Images::exit() {
    return Theme::getCurrentTheme().pathImages + "exit.png";
}

QString Images::filter() {
    return Theme::getCurrentTheme().pathImages + "filter.png";
}

QString Images::goTo() {
    return Theme::getCurrentTheme().pathImages + "go_to.png";
}

QString Images::group1() {
    return Theme::getCurrentTheme().pathImages + "group1.png";
}

QString Images::group2() {
    return Theme::getCurrentTheme().pathImages + "group2.png";
}

QString Images::link() {
    return Theme::getCurrentTheme().pathImages + "link.png";
}

QString Images::profile() {
    return Theme::getCurrentTheme().pathImages + "profile.png";
}
#define OtherEnd }

QString Images::missingImage() {
    return "://MissingImage.png";
}
