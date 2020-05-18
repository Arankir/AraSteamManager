#ifndef FILTER_H
#define FILTER_H

#include <QObject>
#include <QDebug>

class Filter : public QObject
{
    Q_OBJECT
public:
    explicit Filter(int row, int col, QObject *parent = nullptr);
    Filter(QObject *parent = nullptr): QObject(parent) {}
    ~Filter() {};
    void SetRow(int row);
    void SetCol(int col);
    void SetData(int row, int col, bool data);
    bool GetData(int row, int col);
    bool GetData(int row);
    int GetRow() {return _row;}
    int GetCol() {return _col;}
    void AddCol(int colNum);
    void RemoveCol(int colNum);
    friend QDebug operator<<(QDebug dbg, const Filter &f){
        for(auto &filterRow: f._filter){
            dbg.nospace() << "(";
            for(auto &filterColumn: filterRow){
                dbg.nospace() << filterColumn<<" ";
            }
            dbg.nospace() << ")\n";
        }
        return dbg.space();
    }

private slots:

signals:

public slots:

private:
    QVector<QVector<bool>> _filter;
    int _row=0;
    int _col=0;
};

#endif // FILTER_H
