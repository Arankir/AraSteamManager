#ifndef FORMACHIEVEMENTS_H
#define FORMACHIEVEMENTS_H

#include <QWidget>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QDir>
#include <QComboBox>
#include <QMessageBox>
#include <QFormLayout>
#include <QButtonGroup>
#include <QPropertyAnimation>
#include <QDesktopServices>
#include <QMenu>
#include <QAction>
#include <QTreeWidgetItem>
#include "framelesswindow.h"
#include "classes/network/requestimage.h"
#include "classes/common/settings.h"
#include "classes/steamApi/structures/sgames.h"
#include "classes/steamApi/structures/sachievements.h"
#include "classes/common/myfilter.h"
#include "classes/common/favorites.h"
#include "classes/common/comments.h"
#include "classes/achievements/categoriesgame.h"
#include "classes/threads/threading.h"
#include "subWidgets/withData/qbuttonwithdata.h"
#include "subWidgets/withData/qradiobuttonwithdata.h"
#include "subWidgets/withData/qcomboboxwithdata.h"
#include "subWidgets/withData/qcheckboxwithdata.h"
#include "subWidgets/progressBars/progressbargood.h"
#include "forms/formcomments.h"
#include "forms/subForms/achievements/formcategoriesedit.h"
#include "forms/subForms/achievements/widgets/formreachedfilter.h"

enum tableAchievementsColumns {
    ColumnAchievementsAppid         = 0,
    ColumnAchievementsIndex         = 1,
    ColumnAchievementsIcon          = 2,
    ColumnAchievementsTitle         = 3,
    ColumnAchievementsDescription   = 4,
    ColumnAchievementsComment       = 5,
    ColumnAchievementsWorld         = 6,
    ColumnAchievementsReachedMy     = 7,
    ColumnAchievementsCount         = 8
};

enum filterAchievementsColumns {
    FilterAchievementsName             = 0,
    FilterAchievementsReached          = 1,
    FilterAchievementsFavorite         = 2,
    FilterAchievementsColumnCount      = 3,
    FilterAchievementsEndConstValues   = 3
};

enum tabsAchievements {
    TabAchievementsStandart     = 0,
    TabAchievementsCategories   = 1,
    TabAchievementsCompare      = 2
};

namespace Ui {
    class FormAchievements;
}

class FormAchievements: public QWidget {
    Q_OBJECT

enum FriendType {
    haventGame,
    haveGame
};

public slots:
    void progressLoading(int value, int max);
    void onModelPulled(QStandardItemModel *aModel, int reached, int notReached);
    QString getProfileId() const {return _profile.steamID();}
    int getGameAppId() const {return _game.appId();}
    void buttonUpdate_Clicked();
    
    void updateSettings();
    void buttonManual_Clicked();
public:
    explicit FormAchievements(QList<SAchievementPlayer> &pl, SProfile &profile, SGame &game, QWidget *parent = nullptr);
    ~FormAchievements();

signals:
    void s_updateSettings();
    void s_updatedHiddenRows();

private slots:
    void changeEvent(QEvent *event);
    void closeEvent(QCloseEvent*);
    void initComponents();
    void retranslate();
    void setIcons();

    void showCategories();

    void comboBoxCategory_IndexChange(int index);
    void checkBoxCategory_StateChanged(int ind);

    void checkBoxFavorites_StateChanged(int arg1);

    void buttonFavorite_Clicked();

    void loadEditCategory();
    void loadCompare();
    void tabWidget_CurrentChanged(int index);

    void createThread();
    void initTableStandart();
    void initCategoriesTree();
    void initComments();
    void updateCurrentAchievement();
    void updateHiddenRows();
    void buttonComment_Clicked();
    QMenu *createMenu(const SAchievement &aAchievement);
    void updateFilterWithMyProfile(ReachedType aType);
    void updateFilterTextAchievement(const QString &aNewText);
    void updateHiddenColumnsStandart();
    void updateFilterCategory(int categoryIndex, bool clear, QList<QString> achievementNames = QList<QString>());
    void updateFilterFavorite(const QList<FavoriteAchievement> &aFavoritesAchievements);
    int rowFromId(QString aId);
    int recursAddCategoryToTree(Category &category, int count, QTreeWidgetItem *root = nullptr);
    void updateCurrentCategory();
    QMenu *createMenuCategory(const Category &aCategory);
    void categoryChange();
    void categoryAdd();
    void categoryDelete();
    void loading(bool aIsLoading);
private:
    Ui::FormAchievements *ui;
    QList<SAchievementSchema> _global;
    QList<SAchievementPercentage> _percent;
    QList<SAchievementPlayer> _player;
    QList<SAchievement> _achievements;

    //ключевые данные
    SProfile _profile;
    SGame _game;
    Categories _categoriesGame;
    Favorites _favorites;
    Comments _comments;

    //загружены ли другие формы
    bool _isEditCategoryLoaded = false;
    bool _isCompareLoaded      = false;

    //для фильтрации
    MyFilter _fCategories;
    MyFilter _fAchievements;

    //выбранное достижение
    SAchievement *_currentAchievement = nullptr;
    int _currentAchievementIndex;

    //выбранная категория
    Category *_currentCategory = nullptr;
    int _currentCategoryIndex;

};

#endif // FORMACHIEVEMENTS_H
