#ifndef FORMCONTAINERACHIEVEMENTS_H
#define FORMCONTAINERACHIEVEMENTS_H

//#include <QWidget>
#include "forms/achievements/formachievements.h"
#include "form.h"

namespace Ui {
class FormContainerAchievements;
}

class FormContainerAchievements : public Form {
    Q_OBJECT

public slots:
    void addFormAchievement(const SProfile &profileId, const SGame &game);
    void show();

public:
    explicit FormContainerAchievements(QWidget *parent = nullptr);
    ~FormContainerAchievements();

    void retranslate() override;
    void updateIcons() override;
    void updateSettings(QFlags<changedSettings> settings) override;;

    void clear();
signals:
    void s_removeAchievements(int index);

private slots:
    void closeEvent(QCloseEvent*) override;
    void on_TabWidgetAchievements_tabCloseRequested(int index);

private:
    Ui::FormContainerAchievements *ui;
    int getTabIndex(const SProfile &profile, const SGame &game);
};

#endif // FORMCONTAINERACHIEVEMENTS_H
