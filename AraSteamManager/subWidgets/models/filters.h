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
        return filterRegExp().pattern() == "()" ? original : !original;
    };

};

#endif // FILTERS_H
