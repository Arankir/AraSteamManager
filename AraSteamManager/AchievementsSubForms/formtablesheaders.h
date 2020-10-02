#ifndef FORMTABLESHEADERS_H
#define FORMTABLESHEADERS_H

#include <QWidget>
#include <QtDebug>
#include <QScrollBar>
#include <QTableWidgetItem>
#include <QLabel>
#include "subwidget/qradiobuttonwithdata.h"
#include "class/steamapi/Sprofile.h"
#include "class/steamapi/Sgames.h"
#include "class/steamapi/Sachievements.h"
#include "class/filter.h"
#include "class/settings.h"
#include "class/Network/requestimage.h"
#include "class/Threads/threading.h"

namespace Ui {
class FormTablesHeaders;
}

enum class TableType {
    standart,
    compare
};

class FormTablesHeaders : public QWidget {
    Q_OBJECT

public slots:
    void insertRow(int row);
    void removeRow(int row);
    bool addFriendColumn(SProfile &friendProfile);
    void addNoValueColumn();
    void addCategoryColumn();
    void removeFriendColumn(const QString &friendName);
    void removeFriendColumn(int column);
    void removeCategoryColumn(int column);
    bool pullTable();
    void hideCheckedAchievement(QTableWidgetItem *aItem);
    void updateFilterWithMyProfile(ReachedType type, bool solo, bool compare);
    void updateFilterWithFriend(const QString &friendName, ReachedType type);
    void updateFilterCategoriesColumns(int categories);
    void updateFilterTextAchievement(const QString &newText, bool solo, bool compare);
    void updateFilterCategory(int categoryIndex, bool clear, QList<QString> achievementNames = QList<QString>());
    void updateFilterFavorite(QJsonArray favoritesAchievement);
    void setValuesMode(bool value);
    void setUniqueMode(bool unique);
    void setVisibleContentSelect(int pos, bool select);
    void categoryToTable(const QString &title, QList<QString> aNoValues, QJsonArray aValues, bool aIsNoValue);
    bool swapCategoryColumns(int aPosOld, int aPosNew);
    void update();
    QString getHeaderText(int aIndex);
    SAchievement getAchievement(int aIndex);
    void cancelCategory();
    void createThread();

    void reverseCategoryColumn(int index);
public:
    explicit FormTablesHeaders(SGame &game, const QString &id, SAchievementsPlayer &achievements, QWidget *parent = nullptr);
    ~FormTablesHeaders();
    void resizeEvent(QResizeEvent *event);
    void changeEvent(QEvent *event);

    void resize();
    void setColumnCount(int col);
    void setRowCount(int row);
    void setRowCountHeaders(int rows);
    void setColumnWidth(int column, int width);
    void setRowHeight(int row, int height);
    void setRowHeightHeaders(int row, int height);
    int getColumnCount();
    int getRowCount();
    int getRowCountHeaders();
    int getColumnWidth(int column);
    int getRowHeight(int row);
    int getRowHeightHeaders(int row);

    void setWidgetHorizontalHeader(int row, int column, QWidget *widget);
    void setWidgetContent(int row, int column, QWidget *widget);

    void setItemHorizontalHeader(int row, int column, QTableWidgetItem *item);
    void setItemContent(int row, int column, QTableWidgetItem *item);

    QTableWidgetItem* itemHorizontalHeader(int row, int column);
    QTableWidgetItem* itemContent(int row, int column);

    void setVisibleRowContent(int row, bool visible);
    void setVisibleColumn(int column, bool visible);
    void setVisibleRowHeaders(int row, bool visible);

    void changeHorizontalTitle(int column, const QString &text);
    void setVerticalTitle(int row, QTableWidgetItem *item);
    void setVerticalHeaderTitle(int row, QTableWidgetItem *item);

    void resizeRowsToContentsContents();
    //void ResizeColumnsToContents();
    void resizeRowsToContentsHeaders();

    void resizeRowToContentsContents(int row);
    //void ResizeColumnToContents(int column);
    void resizeRowToContentsHeaders(int row);

    void resizeRowContent(int row, int height);
    void resizeColumn(int column, int width);
    void resizeRowHeaders(int row, int height);

    void setType(TableType newType);
    TableType getType();

    QVector<int> getFriendsColumns();
    int getNoValueColumn();
    QVector<int> getCategoryColumns();

signals:
    void s_contentCellClicked(int row, int col);
    void s_achievementsLoaded(int progress, int row);
    void s_tablePulled(int, int);

private slots:
    void setHorizontalTitle(int column, const QString &text);
    void insertColumn(int columns);
    void removeColumn(int columns);
    void retranslate();
    void onTablePulled(int reached, int notReached);
    QTableWidgetItem *createFlag(bool flagState);
    void updateHiddenRows();

    QTableWidget *getTableHH();
    QTableWidget *getTableContent();

    int insertCheckableColumn();
private:
    Ui::FormTablesHeaders *ui;
    bool _visibleHorizontal = true;
    int _horizontalHeaderHeight = 0;
    SGame _game;
    TableType _currentType;
    int _baseColumns;
    int _noValueColumn;
    QVector<int> _friendsColumns;
    QVector<int> _categoriesColumns;
    Settings _setting;

    bool _isUnique;
    bool _isNoValue;

    QString _id;
    SAchievements _achievements;
    //для фильтрации
    Filter _fAchievements;
    Filter _fCompare;

};

#endif // FORMTABLESHEADERS_H
