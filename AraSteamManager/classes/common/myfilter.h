#ifndef FILTER_H
#define FILTER_H

#include <QObject>
#include <QDebug>

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
        dbg.nospace() << "Filter(";
        for(auto &filterRow: f._filter) {
            dbg.nospace() << "      (";
            for(auto &filterColumn: filterRow) {
                dbg.nospace() << filterColumn << " ";
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
