#ifndef FILESAVELOAD_H
#define FILESAVELOAD_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "classes/common/generalfunctions.h"

class FileSaveLoad {
public:
    FileSaveLoad(const QString &aFilePath);
    bool save() const;
    bool load(const QString &savePath);
    virtual void fromJson(const QJsonObject&) = 0;
    virtual QJsonObject toJson() const = 0;

protected:
    QString filePath_;
};

#endif // FILESAVELOAD_H
