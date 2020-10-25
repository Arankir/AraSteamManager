#ifndef FREEZETABLEWIDGET_H
#define FREEZETABLEWIDGET_H

#include <QTableView>

class FreezeRowsTable : public QTableView {
     Q_OBJECT

public:
    FreezeRowsTable(QWidget *&widget) : QTableView(widget) {};
    FreezeRowsTable(QAbstractItemModel * model);
    ~FreezeRowsTable();

protected:
    void resizeEvent(QResizeEvent *event) override;
    QModelIndex moveCursor(CursorAction cursorAction, Qt::KeyboardModifiers modifiers) override;
    void scrollTo (const QModelIndex & index, ScrollHint hint = EnsureVisible) override;

private:
    QTableView *frozenTableView;
    void init();
    void updateFrozenTableGeometry();

private slots:
    void updateSectionWidth(int logicalIndex, int oldSize, int newSize);
    void updateSectionHeight(int logicalIndex, int oldSize, int newSize);

};
#endif // FREEZETABLEWIDGET_H
