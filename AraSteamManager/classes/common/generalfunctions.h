#ifndef GENERALFUNCTIONS_H
#define GENERALFUNCTIONS_H

#include <QList>
#include <QObject>
#include <QUrl>
#include "classes/network/requestdata.h"

template <typename T>
QList<T> &sort(QList<T> &aList, bool(*compare)(T &t1, T &t2) = [](T &t1, T &t2){return t1<t2;}) {
    std::list<T> list(aList.begin(), aList.end());
    list.sort(compare);
    aList = QList<T>(list.begin(), list.end());
    return aList;
}

#endif // GENERALFUNCTIONS_H
