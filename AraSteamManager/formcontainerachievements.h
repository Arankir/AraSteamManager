#ifndef FORMCONTAINERACHIEVEMENTS_H
#define FORMCONTAINERACHIEVEMENTS_H

#include <QWidget>
#include <AchievementsSubForms/formachievements.h>
#include <class/settings.h>

namespace Ui {
class FormContainerAchievements;
}

class FormContainerAchievements : public QWidget {
    Q_OBJECT

public:
    explicit FormContainerAchievements(QWidget *parent = nullptr);
    ~FormContainerAchievements();

public slots:
    void AddFormAchievement(SAchievementsPlayer pl, SProfile ids, SGame game, int num);

signals:
    void s_removeAchievements(int index);
    void s_formClose();

private slots:
    void closeEvent(QCloseEvent*);
    void OnLoadImage(RequestImage*);
    void on_TabWidgetAchievements_tabCloseRequested(int index);

private:
    Ui::FormContainerAchievements *ui;
    Settings _setting;
};

#endif // FORMCONTAINERACHIEVEMENTS_H
