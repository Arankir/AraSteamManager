#include "generalfunctions.h"
#include <QDir>
#include <QFile>

const int c_toolTipMaxWidth = 30;

QString textToToolTip(const QString &aText, const QString &aSplitter) {
    QStringList linesList = aText.split("\n");
    QString result;
    for (QString &line: linesList) {
        QStringList wordsList = line.split(aSplitter);
        int currentWidth = 0;
        while (!wordsList.isEmpty()) {
            if (wordsList[0].length() + currentWidth > c_toolTipMaxWidth) {
                if (currentWidth > 0) {
                    result += aSplitter + "\n";
                    currentWidth = 0;
                } else {
                    QString longWord = wordsList.takeFirst();
                    while (longWord.length() > c_toolTipMaxWidth) {
                        result += longWord.left(c_toolTipMaxWidth) + "\n";
                        longWord.remove(0, c_toolTipMaxWidth);
                    }
                    result += longWord;
                    currentWidth = longWord.length();
                }
            }
            if (currentWidth != 0) {
                result += aSplitter;
                ++currentWidth;
            }
            currentWidth += wordsList[0].length();
            result += wordsList.takeFirst();
        }
        result += "\n";
    }
    result.remove(result.length() - 1, 1);
    return result;
}

bool createDir(const QString &aPath) {
    bool exist = true;
    QString path = aPath;
    path.replace("\\", "/");
    QStringList dirs = path.split("/");
    if (dirs.last() != "") {
        dirs.removeLast();
    }
    QString pathNow = "";
    for (auto &dir: dirs) {
        pathNow += std::move(dir) + "/";
        exist = (QDir().mkdir(pathNow) && exist);
    }
    return exist;
}

bool saveFile(const QString &aFilePath, const QByteArray &aData) {
    createDir(aFilePath);
    QFile file(aFilePath);
    file.open(QFile::WriteOnly);
    int bytes = file.write(aData);
    file.close();
    return bytes != -1;
}

bool readFile(const QString &aFilePath, QByteArray &bytes) {
    bool isCompleted = false;
    bytes.clear();
    createDir(aFilePath);
    QFile file(aFilePath);
    if (file.exists()) {
        if (file.open(QFile::ReadOnly)) {
            bytes = file.readAll();
            file.close();
            isCompleted = true;
        }
    }
    return isCompleted;
}

QTableView *initingTable(QTableView *table) {
    table->setVerticalScrollMode  (QAbstractItemView::ScrollMode::ScrollPerPixel);
    table->setHorizontalScrollMode(QAbstractItemView::ScrollMode::ScrollPerPixel);

    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setShowGrid(false);
    table->setSortingEnabled(true);
    table->horizontalHeader()->setStretchLastSection(true);
    table->verticalHeader()->setVisible(false);
    table->setContextMenuPolicy(Qt::CustomContextMenu);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    return table;
}

bool centralize(const QWidget *parent, QWidget *child) {
    QRect parentGeometry = parent->geometry();
    QSize childSize = child->sizeHint();
    QRect result(((parentGeometry.width() / 2) - (childSize.width() / 2)),
                ((parentGeometry.height() / 2) - (childSize.height() / 2)),
                childSize.width(),
                childSize.height());
    child->setGeometry(result);
    return true;
}

int daysInMonth(const QDate aDate) {
    switch (aDate.month()) {
    case 1: {
        return 31;
    }
    case 2: {
        if (aDate.isLeapYear(aDate.year())) {
            return 29;
        } else {
            return 28;
        }
    }
    case 3: {
        return 31;
    }
    case 4: {
        return 30;
    }
    case 5: {
        return 31;
    }
    case 6: {
        return 30;
    }
    case 7: {
        return 31;
    }
    case 8: {
        return 31;
    }
    case 9: {
        return 30;
    }
    case 10: {
        return 31;
    }
    case 11: {
        return 30;
    }
    case 12: {
        return 31;
    }
    }
    return 0;
}
