#ifndef FILTER_H
#define FILTER_H

#include <QObject>
#include <QDebug>
#include <iostream>
#include <iomanip>

class MyFilter : public QObject {
    Q_OBJECT
public:
    explicit MyFilter(int row, int col, QObject *parent = nullptr);
    MyFilter(QObject *parent = nullptr): QObject(parent) {}
    ~MyFilter() {}

    MyFilter &setRow(int row);
    MyFilter &setCol(int col);
    MyFilter &addCol(int colNum);
    MyFilter &removeCol(int colNum);
    MyFilter &setData(int row, int col, bool data);

    bool getData(int row, int col) const;
    bool getData(int row) const;
    int getRow() const {return _row;}
    int getCol() const {return _col;}

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

private slots:

signals:

public slots:

private:
    int _row {0};
    int _col {0};
    QVector<QVector<bool>> _filter;
};

#endif // FILTER_H
