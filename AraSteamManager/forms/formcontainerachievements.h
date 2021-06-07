#ifndef FORMCONTAINERACHIEVEMENTS_H
#define FORMCONTAINERACHIEVEMENTS_H

#include <QWidget>
#include "forms/subForms/achievements/formachievements.h"
#include "form.h"
#include "classes/common/settings.h"

namespace Ui {
class FormContainerAchievements;
}

class FormContainerAchievements : public Form {
    Q_OBJECT

public slots:
    void addFormAchievement(SProfile ids, SGame &game);
    void show();

public:
    explicit FormContainerAchievements(QWidget *parent = nullptr);
    ~FormContainerAchievements();

    void retranslate() override {};
    void updateIcons() override {};
    void updateSettings() override {};

signals:
    void s_removeAchievements(int index);
//    void s_formClose();

private slots:
    void closeEvent(QCloseEvent*) override;
    void on_TabWidgetAchievements_tabCloseRequested(int index);

private:
    Ui::FormContainerAchievements *ui;
};

#endif // FORMCONTAINERACHIEVEMENTS_H
