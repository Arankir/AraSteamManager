#ifndef FILTERS_H
#define FILTERS_H

#include <QSortFilterProxyModel>
#include <QObject>

class SortFilterProxyModelMiltiRow : public QSortFilterProxyModel {
    Q_OBJECT
public:
    SortFilterProxyModelMiltiRow(QObject *parent = nullptr): QSortFilterProxyModel(parent) {};
    void addRow(const int &row);
    void removeRow(const int &row);
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;

private:
    QList<int> _rows;
};

class SortFilterProxyModelFreezeRow : public QSortFilterProxyModel {
    Q_OBJECT
public:
    SortFilterProxyModelFreezeRow(QObject *parent = nullptr);
    virtual bool lessThan(const QModelIndex &source_left, const QModelIndex &source_right) const override;

};

class SortFilterProxyModelCategory : public QSortFilterProxyModel {
    Q_OBJECT
public:
    SortFilterProxyModelCategory(const QString &parentName, QObject *parent = nullptr): QSortFilterProxyModel(parent), _parent(parentName) {};
    QString parentName() const {return _parent;}
    void addCategory(const QString &name, const QStringList &apis);
    void removeCategory(const QString &name);

private:
    void updateRegExp();

    QString _parent;
    QList<QPair<QString, QStringList>> _categories;
};

class QSortFilterProxyInvertModel : public QSortFilterProxyModel {
    Q_OBJECT
public:
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override {
        bool original = QSortFilterProxyModel::filterAcceptsRow(source_row, source_parent);
        return filterRegularExpression().pattern() == "()" ? original : !original;
    };

};

class Filter {
public:
    Filter(int rows = 0, int cols = 0);
    bool operator[](int aRow) const;
    void setData(int row, int col, bool aData);
    void setRows(int rows);
    void setCols(int cols);
    void insertRow(int row);
    void removeRow(int row);
    void insertCol(int col);
    void removeCol(int col);
    void disableCol(int col);
    void enableCol(int col);
    void clearCol(int col);
    void clear();
    friend QDebug operator<<(QDebug dbg, const Filter &f) {
        dbg.nospace() << "Filter" << "(";
        for (int r = 0; r < f.rows_; ++r) {
            for (int c = 0; c < f.cols_; ++c) {
                dbg.nospace() << (f.filter_[r][c / 8] >> (c % 8));
            }
            dbg.nospace() << "\n";
        }
        dbg.nospace() << ")\n";
        return dbg.space();
    }

private:
    int rows_ = 0;
    int cols_ = 0;
    QList<char> checkCols_;
    QList<QList<char>> filter_;
};

class FilterModel : public QSortFilterProxyModel {
    Q_OBJECT
public:
    FilterModel(int row = 0, int col = 0, QObject *parent = nullptr): QSortFilterProxyModel(parent), filter_(row, col) {};

protected:
    QMap<QString, int> columns_;
    Filter filter_;
};

#endif // FILTERS_H
