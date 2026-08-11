#ifndef GENERALFUNCTIONS_H
#define GENERALFUNCTIONS_H

#include <QTableView>

QTableView *initingTable(QTableView *table);
int getWidthTableColumns(QTableView *table, bool includeScrollBar = true);
int getHeightTableColumns(QTableView *table, bool includeScrollBar = true);
QString textToToolTip(const QString &text, const QString &splitter = " ", const QString &symvolNextLine = "\n");
bool saveFile(const QString &filePath, const QByteArray &data);
bool readFile(const QString &filePath, QByteArray &data);

template <typename T>
QList<T> reverseList(const QList<T> &aList) {
    QList<T> result;
    result.reserve(aList.size());
    std::reverse_copy(aList.begin(), aList.end(), std::back_inserter(result));
    return result;
}

template <typename T>
QList<T> reverseList(QList<T> &&aList) {
    std::reverse(aList.begin(), aList.end());
    return aList;
}

#endif // GENERALFUNCTIONS_H
