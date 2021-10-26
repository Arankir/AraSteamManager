#ifndef FORMCONTAINERACHIEVEMENTS_H
#define FORMCONTAINERACHIEVEMENTS_H

#include <QWidget>
#include "forms/achievements/formachievements.h"
#include "form.h"
#include "classes/common/settings.h"

namespace Ui {
class FormContainerAchievements;
}

class FormContainerAchievements : public Form {
    Q_OBJECT

public slots:
    void addFormAchievement(const SProfile &ids, const SGame &game);
    void show();

public:
    explicit FormContainerAchievements(QWidget *parent = nullptr);
    ~FormContainerAchievements();

    void retranslate() override {};
    void updateIcons() override {};
    void updateSettings(QFlags<changedSettings> aSettings) override;;

signals:
    void s_removeAchievements(int index);
//    void s_formClose();

private slots:
    void closeEvent(QCloseEvent*) override;
    void on_TabWidgetAchievements_tabCloseRequested(int index);

private:
    Ui::FormContainerAchievements *ui;
    int getTabIndex(const SProfile &aProfile, const SGame &aGame);
};

#endif // FORMCONTAINERACHIEVEMENTS_H
