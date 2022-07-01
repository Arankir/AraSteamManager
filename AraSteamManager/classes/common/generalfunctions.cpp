#include "generalfunctions.h"

#include <QDir>
#include <QHeaderView>
#include <QDebug>
#include <QCoreApplication>
#include <QApplication>

const int c_toolTipMaxWidth = 30;

QString textToToolTip(const QString &aText, const QString &aSplitter) {
    QStringList linesList = aText.split("\n");
    QString result;
    for (QString &line: linesList) {
        QStringList wordsList = line.split(aSplitter);
        int currentWidth = 0;
        while (!wordsList.isEmpty()) {
            if (wordsList.at(0).length() + currentWidth > c_toolTipMaxWidth) {
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

//bool createDir(const QString &aPath) {
//    bool exist = true;
//    QString path = aPath;
//    path.replace("\\", "/");
//    QStringList dirs = path.split("/");
//    if (dirs.last() != "") {
//        dirs.removeLast();
//    }
//    QString pathNow = "";
//    for (auto &dir: dirs) {
//        pathNow += std::move(dir) + "/";
//        exist = (QDir().mkdir(pathNow) && exist);
//    }
//    return exist;
//}

QString getDirFromFile(const QString &aFilePath) {
    QString path = aFilePath;
    path.replace("\\", "/");
    QStringList list = path.split("/");
    list.removeLast();
    return list.join("/");
}

bool saveFile(const QString &aFilePath, const QByteArray &aData) {
    QDir().mkpath(getDirFromFile(aFilePath));
//    createDir(aFilePath);
    QFile file(aFilePath);
    if (file.open(QFile::WriteOnly)) {
        int bytes = file.write(aData);
        file.close();
        return bytes != -1;
    } else {
        qWarning() << "saveFile" << aFilePath << file.errorString();
        return false;
    }
}

bool readFile(const QString &aFilePath, QByteArray &aBytes) {
    bool isCompleted = false;
    aBytes.clear();
    QDir().mkpath(getDirFromFile(aFilePath));
//    createDir(aFilePath);
    QFile file(aFilePath);
    if (file.exists()) {
        if (file.open(QFile::ReadOnly)) {
            aBytes = file.readAll();
            file.close();
            isCompleted = true;
        } else {
            qWarning() << "readFile" << aFilePath << file.errorString();
        }
    }
    return isCompleted;
}

QTableView *initingTable(QTableView *aTable) {
    aTable->setVerticalScrollMode  (QAbstractItemView::ScrollMode::ScrollPerPixel);
    aTable->setHorizontalScrollMode(QAbstractItemView::ScrollMode::ScrollPerPixel);

    aTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    aTable->setShowGrid(false);
    aTable->setSortingEnabled(true);
    aTable->horizontalHeader()->setStretchLastSection(true);
    aTable->verticalHeader()->setVisible(false);
    aTable->setContextMenuPolicy(Qt::CustomContextMenu);
    aTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    return aTable;
}

bool centralize(const QWidget *aParent, QWidget *aChild) {
    QRect parentGeometry = aParent->geometry();
    QSize childSize = aChild->sizeHint();
    QRect result(((parentGeometry.width() / 2) - (childSize.width() / 2)),
                ((parentGeometry.height() / 2) - (childSize.height() / 2)),
                childSize.width(),
                childSize.height());
    aChild->setGeometry(result);
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

int getWidthTableColumns(QTableView *aTable, bool aIncludeScrollBar) {
    int width = 0;
    for (int i = 0; i < aTable->model()->columnCount(); ++i) {
        width += aTable->columnWidth(i) + 1;
    }
    if (aIncludeScrollBar) {
        width += qApp->style()->pixelMetric(QStyle::PM_ScrollBarExtent);
    }
    return width;
}

int getHeightTableColumns(QTableView *aTable, bool aIncludeScrollBar) {
    int height = 0;
    for (int i = 0; i < aTable->model()->rowCount(); ++i) {
        height += aTable->rowHeight(i) + 1;
    }
    if (aIncludeScrollBar) {
        height += qApp->style()->pixelMetric(QStyle::PM_ScrollBarExtent);
    }
    return height;
}

//Анимация на кнопке
//    auto movie = new QMovie(this);
//    movie->setFileName("C:\\Users\\Pavel\\Desktop\\GenerousColossalCurlew-size_restricted.gif");
//    connect(movie, &QMovie::frameChanged, [=]{
//        ui->pushButton->setIcon(movie->currentPixmap());
//    });
//    movie->start();
//    ui->pushButton->setIconSize(QSize(movie->currentPixmap().size()));
//    ui->pushButton->setFixedSize(QSize(movie->currentPixmap().size()).operator+=(QSize(10, 10)));
