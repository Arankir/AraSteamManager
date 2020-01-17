#ifndef FORMCONTAINERACHIEVEMENTS_H
#define FORMCONTAINERACHIEVEMENTS_H

#include <QWidget>
#include <subform/formachievements.h>

namespace Ui {
class FormContainerAchievements;
}

class FormContainerAchievements : public QWidget
{
    Q_OBJECT

public:
    explicit FormContainerAchievements(QWidget *parent = nullptr);
    ~FormContainerAchievements();

public slots:
    void AddFormAchievement(SAchievementsPlayer pl, QString ids, SGame game, int num, QWidget *parent = nullptr);

signals:
    void s_removeAchievements(int index);
    void s_formClose();

private slots:
    void on_TabWidgetAchievements_tabCloseRequested(int index);
    void OnResultImage(ImageRequest*);

private:
    Ui::FormContainerAchievements *ui;
};

#endif // FORMCONTAINERACHIEVEMENTS_H
