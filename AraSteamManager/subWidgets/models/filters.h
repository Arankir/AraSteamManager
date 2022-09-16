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
    QList<int> rows_;
};

class SortFilterProxyModelFreezeRow : public QSortFilterProxyModel {
    Q_OBJECT
public:
    SortFilterProxyModelFreezeRow(QObject *parent = nullptr);
    virtual bool lessThan(const QModelIndex &source_left, const QModelIndex &source_right) const override;

private:

};

class SortFilterProxyModelCategory : public QSortFilterProxyModel {
    Q_OBJECT
public:
    SortFilterProxyModelCategory(const QString &parentName, QObject *parent = nullptr);;
    QString parentName() const;
    void addCategory(const QString &name, const QStringList &apis);
    void removeCategory(const QString &name);

private:
    void updateRegExp();

    QString parent_;
    QList<QPair<QString, QStringList>> categories_;
};

class QSortFilterProxyInvertModel : public QSortFilterProxyModel {
    Q_OBJECT
public:
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;

};

class Filter {
public:
    Filter(const int &rows = 0, const int &cols = 0);
    bool operator[](int row) const;
    void setData(int row, int col, bool data);
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
    QList<bool> enabledCols();
    friend QDebug operator<<(QDebug dbg, const Filter &filter) {
        dbg.nospace() << "Filter" << "(";
        for (int r = 0; r < filter.rows_; ++r) {
            for (int c = 0; c < filter.cols_; ++c) {
                dbg.nospace() << (filter.filter_[r][c / 8] >> (c % 8));
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
    FilterModel(const int &row = 0, const int &col = 0, QObject *parent = nullptr);
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    void setSourceModel(QAbstractItemModel *sourceModel);

signals:
    void s_modelFinished();
    void s_rowsUpdated();

protected:
    QMap<QString, int> columns_;
    Filter filter_;
protected slots:
    void forceInvalidate();
};

#endif // FILTERS_H
