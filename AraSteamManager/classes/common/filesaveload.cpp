#include "filesaveload.h"

#include <QFile>

FileSaveLoad::FileSaveLoad(const QString &aFilePath): filePath_(aFilePath) {

}

bool FileSaveLoad::save() const {
    return saveFile(filePath_, QJsonDocument(toJson()).toJson());
}

bool FileSaveLoad::load(const QString &savePath) {
    QByteArray bytes;
    if(readFile(savePath, bytes)) {
        fromJson(QJsonDocument::fromJson(bytes).object());
        filePath_ = savePath;
        return true;
    }
    return false;
}
