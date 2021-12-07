#ifndef GENERALFUNCTIONS_H
#define GENERALFUNCTIONS_H

#include <QList>
#include <QObject>
#include <QUrl>
#include <QTableView>
#include <QHeaderView>
#include "classes/network/requestdata.h"
#include "framelesswindow.h"
#include "form.h"

QTableView *initingTable(QTableView *table);
QString textToToolTip(const QString &text, const QString &aSplitter = " ");
bool createDir(const QString &path);
bool saveFile(const QString &filePath, const QByteArray &data);
bool readFile(const QString &filePath, QByteArray &data);
bool centralize(const QWidget *parent, QWidget *child);
int daysInMonth(const QDate);

template <typename T>
QList<T> &mySort(QList<T> &aList, bool(*compare)(T &t1, T &t2) = [](T &t1, T &t2){return t1<t2;}) {
//TODO заменить на нормальную сортировку
    std::list<T> list(aList.begin(), aList.end());
    list.sort(compare);
    aList = QList<T>(list.begin(), list.end());
    return aList;
}

template <typename T>
QList<T> &mySort2(QList<T> &aList, const std::function<bool(T &t1, T &t2)> compare = [](T &t1, T &t2){return t1<t2;}) {
//TODO заменить на нормальную сортировку
    std::list<T> list(aList.begin(), aList.end());
    list.sort(compare);
    aList = QList<T>(list.begin(), list.end());
    return aList;
}

template <typename T>
QList<T> reverseList(const QList<T> &aList) {
    QList<T> result;
    result.reserve(aList.size());
    std::reverse_copy(aList.begin(), aList.end(), std::back_inserter(result));
    return result;
}

template <class T>
T *createFramelessForm() {
//TODO Придумать проверку на то, что T - наследуется от определенного класса
    FramelessWindow *f = new FramelessWindow;
    T *t = new T(f);
    f->setWidget(t);
    if (Form *form = dynamic_cast<Form*>(t)) {
        form->setFramelessWindow(f);
        QObject::connect(form, &Form::s_closed, f, &FramelessWindow::close);
    }

    return t;
}

#include <QHBoxLayout>
template <class T>
QFrame *createSubForm(T *aSubForm, QWidget *aParent) {
    QFrame *frame = new QFrame(aParent);
    frame->setObjectName("SubWindow");
    QHBoxLayout *lay = new QHBoxLayout(frame);
    lay->addWidget(aSubForm);
    centralize(aParent, frame);
    frame->show();
    return frame;
}

#endif // GENERALFUNCTIONS_H
