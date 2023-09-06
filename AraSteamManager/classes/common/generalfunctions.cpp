#include "generalfunctions.h"

#include <QDir>
#include <QHeaderView>
#include <QDebug>
#include <QCoreApplication>
#include <QApplication>

const int c_toolTipMaxWidth = 30;

QString textToToolTip(const QString &aText, const QString &aSplitter, const QString &aSymvolNextLine) {
    QStringList linesList = aText.split(aSymvolNextLine);
    QStringList result;
    for (QString &line: linesList) {
        QString resultLine;
        QStringList wordsList = line.split(aSplitter);
        while (!wordsList.isEmpty()) {
            if (wordsList.at(0).length() + resultLine.length() > c_toolTipMaxWidth) {
                if (resultLine.length() > 0) {
                    result << resultLine;
                    resultLine = "";
                } else {
                    QString longWord = wordsList.takeFirst();
                    while (longWord.length() > c_toolTipMaxWidth) {
                        result << longWord.left(c_toolTipMaxWidth);
                        longWord.remove(0, c_toolTipMaxWidth);
                    }
                    resultLine = "";
                }
            }
            if (resultLine.length() != 0) {
                resultLine += aSplitter;
            }
            resultLine += wordsList.takeFirst();
        }
        result << resultLine;
    }
    return result.join(aSymvolNextLine);
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
//    for (QString &dir: dirs) {
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
    aTable->setIconSize(QSize(32, 32));
    return aTable;
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
//    QMovie *movie = new QMovie(this);
//    movie->setFileName("C:\\Users\\Pavel\\Desktop\\GenerousColossalCurlew-size_restricted.gif");
//    connect(movie, &QMovie::frameChanged, [=]{
//        ui->pushButton->setIcon(movie->currentPixmap());
//    });
//    movie->start();
//    ui->pushButton->setIconSize(QSize(movie->currentPixmap().size()));
//    ui->pushButton->setFixedSize(QSize(movie->currentPixmap().size()).operator+=(QSize(10, 10)));
