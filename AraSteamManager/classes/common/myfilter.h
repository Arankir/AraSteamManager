#ifndef FILTER_H
#define FILTER_H

#include <QDebug>
#include <iostream>
#include <iomanip>

class MyFilter {
public:
    explicit MyFilter(const int &row, const int &col);
    MyFilter() {}
    ~MyFilter() {}

    MyFilter &setRow(const int &row);
    MyFilter &setCol(const int &col);
    MyFilter &addCol(const int &col);
    MyFilter &removeCol(const int &col);
    MyFilter &clearCol(const int &col);
    MyFilter &setData(const int &row, const int &col, const bool &data);

    bool getData(const int &row, const int &col) const;
    bool getData(const int &row) const;
    int rows() const {return _row;}
    int cols() const {return _col;}

    friend QDebug operator<<(QDebug dbg, const MyFilter &f) {
        int row = -1;
        dbg.nospace() << "\nFilter\n";
        for(auto &filterRow: f._filter) {
            dbg.nospace() << QString::number(++row).leftJustified(5, ' ') << " (";
            for(auto &filterColumn: filterRow) {
                dbg.nospace() << (filterColumn ? 1 : 0);
            }
            dbg.nospace() << ")\n";
        }
        return dbg.space();
    }

private:
    int _row {0};
    int _col {0};
    QVector<QVector<bool>> _filter;
};

#endif // FILTER_H
