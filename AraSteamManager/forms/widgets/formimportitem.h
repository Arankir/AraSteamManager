#ifndef FORMIMPORTITEM_H
#define FORMIMPORTITEM_H

#include <QWidget>
#include "classes/files/exportfile.h"
#include "classes/common/settings.h"
#include "classes/common/images.h"

namespace Ui {
class FormImportItem;
}

class FormImportItem : public QWidget {
    Q_OBJECT

public:
    explicit FormImportItem(QWidget *parent = nullptr);
    explicit FormImportItem(ImportExportData *importData, QWidget *parent = nullptr);
    ~FormImportItem();

    void findProfile();
    bool isChecked();
    bool isNeedProfile();
    bool isProfileSelected();
    ImportExportData *importData();
protected:
    void init();
    void initProfile();
private:
    Ui::FormImportItem *ui;
    ImportExportData *importData_ = nullptr;
    ProfileID profileId_;
};

#endif // FORMIMPORTITEM_H
