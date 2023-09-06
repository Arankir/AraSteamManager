#ifndef FORMIMPORTEXPORT_H
#define FORMIMPORTEXPORT_H

#include <QTreeWidgetItem>
#include "form.h"
#include "classes/files/exportfile.h"

namespace Ui {
class FormImportExport;
}

class FormImportExport : public Form {
    Q_OBJECT

public:
    explicit FormImportExport(QWidget *parent = nullptr);
    void update();
    ~FormImportExport();

    void updateExportData();
    void resizeEvent(QResizeEvent *aEvent) override;

protected:
    void buttonExport_Clicked();
    QList<ImportExportData *> getFileFromPath(const QString &aPath);
    void showImportTable(QList<ImportExportData *> aFileData);

private slots:
    void retranslate() override;
    void updateSettings(QFlags<changedSettings>) override;
    void updateIcons() override;

private:
    Ui::FormImportExport *ui;

    void init();
};

#endif // FORMIMPORTEXPORT_H
