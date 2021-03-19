#include "generalfunctions.h"
#include <QDir>

const int c_toolTipMaxWidth = 30;

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

QString textToToolTip(QString aText) {
    QStringList wordsList = aText.split(" ");
    QString result;
    int currentWidth = 0;
    while (!wordsList.isEmpty()) {
        if (wordsList[0].length() + currentWidth > c_toolTipMaxWidth) {
            if (currentWidth > 0) {
                result += "\n";
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
            result += " ";
            ++currentWidth;
        }
        currentWidth += wordsList[0].length();
        result += wordsList.takeFirst();
    }
    return result;
}
