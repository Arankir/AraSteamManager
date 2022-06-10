#ifndef GENERALFUNCTIONS_H
#define GENERALFUNCTIONS_H

#include <QTableView>
#include <QHBoxLayout>

#include "framelesswindow.h"
#include "form.h"

QTableView *initingTable(QTableView *table);
int getWidthTableColumns(QTableView *table, bool includeScrollBar = true);
int getHeightTableColumns(QTableView *table, bool includeScrollBar = true);
QString textToToolTip(const QString &text, const QString &aSplitter = " ");
//bool createDir(const QString &path);
bool saveFile(const QString &filePath, const QByteArray &data);
bool readFile(const QString &filePath, QByteArray &data);
bool centralize(const QWidget *parent, QWidget *child);
int daysInMonth(const QDate);

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
