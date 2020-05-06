#ifndef FORMTABLESHEADERS_H
#define FORMTABLESHEADERS_H

#include <QWidget>
#include <QtDebug>
#include <QScrollBar>
#include <QTableWidgetItem>
#include <QLabel>
#include <class/steamapi/Sprofile.h>
#include <class/steamapi/Sgames.h>
#include <class/steamapi/Sachievements.h>
#include <class/filter.h>
#include <class/Network/requestimage.h>

namespace Ui {
class FormTablesHeaders;
}

enum class TableType{
    standart,
    compare
};

class FormTablesHeaders : public QWidget
{
    Q_OBJECT

public:
    explicit FormTablesHeaders(int rowHeaders, int rowContent, SGame game, QString id, SAchievements achievements, TableType type, QWidget *parent = nullptr);
    ~FormTablesHeaders();
    void resizeEvent(QResizeEvent *event);

    void Resize();
    void SetColumnCount(int col);
    void SetRowCount(int row);
    void SetRowCountHeaders(int rows);
    void SetColumnWidth(int column, int width);
    void SetRowHeight(int row, int height);
    void SetRowHeightHeaders(int row, int height);
    int GetColumnCount();
    int GetRowCount();
    int GetRowCountHeaders();
    int GetColumnWidth(int column);
    int GetRowHeight(int row);
    int GetRowHeightHeaders(int row);

    void SetWidgetHorizontalHeader(int row, int column, QWidget *widget);
    void SetWidgetContent(int row, int column, QWidget *widget);

    void SetItemHorizontalHeader(int row, int column, QTableWidgetItem *item);
    void SetItemContent(int row, int column, QTableWidgetItem *item);

    QTableWidgetItem* ItemHorizontalHeader(int row, int column);
    QTableWidgetItem* ItemContent(int row, int column);

    void SetVisibleRowContent(int row, bool visible);
    void SetVisibleColumn(int column, bool visible);
    void SetVisibleRowHeaders(int row, bool visible);

    void ChangeHorizontalTitle(int column, QString text);
    void SetVerticalTitle(int row, QTableWidgetItem *item);
    void SetVerticalHeaderTitle(int row, QTableWidgetItem *item);

    void ResizeRowsToContentsContents();
    //void ResizeColumnsToContents();
    void ResizeRowsToContentsHeaders();

    void ResizeRowToContentsContents(int row);
    //void ResizeColumnToContents(int column);
    void ResizeRowToContentsHeaders(int row);

    void ResizeRowContent(int row, int height);
    void ResizeColumn(int column, int width);
    void ResizeRowHeaders(int row, int height);

    void SetType(TableType newType);
    TableType GetType() {return _currentType;}

    QVector<int> GetFriendsColumns() {return _friendsColumns;}
    int GetNoValueColumn() {return _noValueColumn;}
    QVector<int> GetCategoryColumns() {return _categoriesColumns;}

    QTableWidget *GetTableHH();
    QTableWidget *GetTableContent();
signals:
    void s_contentCellClicked(int row, int col);
public slots:
    void InsertRow(int a_row);
    void RemoveRow(int a_row);
    bool AddFriendColumn(SProfile friendProfile);
    void AddNoValueColumn();
    void AddCategoryColumn();
    void RemoveFriendColumn(int a_column);
    void RemoveCategoryColumn(int a_column);
private:
    void SetHorizontalTitle(int column, QString text);
    void InsertColumn(int a_columns);
    void RemoveColumn(int a_columns);
    Ui::FormTablesHeaders *ui;
    bool _visibleHorizontal=true;
    int _horizontalHeaderHeight=0;
    SGame _game;
    TableType _currentType;
    int _baseColumns;
    int _noValueColumn;
    QVector<int> _friendsColumns;
    QVector<int> _categoriesColumns;

    QString _id;
    SAchievements _achievements;
    //для фильтрации
    Filter _fAchievements;
    Filter _fCompare;

};

#endif // FORMTABLESHEADERS_H
