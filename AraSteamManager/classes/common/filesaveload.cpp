#include "filesaveload.h"

#include <QFile>
#include <fstream>

FileSaveLoad::FileSaveLoad(const QString &aFilePath): filePath_(aFilePath) {

}

bool FileSaveLoad::save() const {
    return saveFile(filePath_, QJsonDocument(toJson()).toJson());

//    std::ofstream fout;
//    fout.open(filePath_.toStdString());
//    if(fout.is_open()) {
//        fout.write((char*)this, sizeof(*this));
//        fout.close();
//        return true;
//    }
//    return false;
}

bool FileSaveLoad::load(const QString &savePath) {
    QByteArray bytes;
    if(readFile(savePath, bytes)) {
        fromJson(QJsonDocument::fromJson(bytes).object());
        filePath_ = savePath;
        return true;
    }
    return false;

//    std::ifstream fin;
//    fin.open(savePath.toStdString());
//    if (fin.is_open()) {
//        fin.read((char*)this, sizeof(*this));
//        fin.close();
//        return true;
//    }
//    return false;
}
