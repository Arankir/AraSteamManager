#include "filesaveload.h"

FileSaveLoad::FileSaveLoad(const QString &aFilePath): filePath_(aFilePath) {

}

void FileSaveLoad::save() const {
    saveFile(filePath_, QJsonDocument(toJson()).toJson());
}

void FileSaveLoad::load(const QString &savePath) {
    QByteArray bytes;
    if(readFile(savePath, bytes)) {
        fromJson(QJsonDocument::fromJson(bytes).object());
        filePath_ = savePath;
    } else {
        qWarning() << "file" << savePath << "coudn't open";
    }
}
