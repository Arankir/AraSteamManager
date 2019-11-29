#ifndef FILTER_H
#define FILTER_H

#include <QObject>
#include <QDebug>

class Filter : public QObject
{
    Q_OBJECT
public:
    explicit Filter(int row, int col, QObject *parent = nullptr);
    Filter() { row=0; col=0;}
    ~Filter();
    void SetRow(int row);
    void SetCol(int col);
    void SetData(int row, int col, bool data);
    void DeleteCol(int col);
    bool GetData(int row, int col);
    bool GetData(int row);
    int GetRow() {return row;}
    int GetCol() {return col;}

private slots:
    void Resize(int row, int col);

signals:

public slots:

private:
    bool **filter;
    int row;
    int col;
};

#endif // FILTER_H
