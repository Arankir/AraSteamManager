#ifndef FORMGROUPSGAMESINTERACTIONS_H
#define FORMGROUPSGAMESINTERACTIONS_H

#include <QWidget>
#include <QVBoxLayout>
#include <QCheckBox>
#include "classes/games/groupsgames.h"
#include "form.h"

namespace Ui {
class FormGroups;
}

class FormGroups : public Form
{
    Q_OBJECT

public:
    explicit FormGroups(SProfile &profile, const SGame &game, QWidget *parent = nullptr);
    ~FormGroups();

signals:
    void s_updateGroups();

private slots:
    void setProfileGame();
    void initUi();
    void clear();
    void updateUi();
    void add(const QString &aTitle);
    void changeTitle(const int &aIndex, const QString &aTitle);
    void cancel();
    void apply();

    void add_clicked();
    void changeTitle_clicked();

    void cancel_clicked();
    void apply_clicked();

    void retranslate() override;
    void updateIcons() override;
    void updateSettings() override;

private:
    Ui::FormGroups *ui;
    GroupsGames _groups;
    SGame _game;
};

#endif // FORMGROUPSGAMESINTERACTIONS_H
