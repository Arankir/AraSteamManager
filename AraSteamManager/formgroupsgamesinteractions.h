#ifndef FORMGROUPSGAMESINTERACTIONS_H
#define FORMGROUPSGAMESINTERACTIONS_H

#include <QWidget>
#include <QVBoxLayout>
#include <QCheckBox>
#include "class/groupsgames.h"

namespace Ui {
class FormGroupsGamesInteractions;
}

class FormGroupsGamesInteractions : public QWidget
{
    Q_OBJECT

public:
    explicit FormGroupsGamesInteractions(SProfile &profile, SGame &game, QWidget *parent = nullptr);
    ~FormGroupsGamesInteractions();

signals:
    void s_updateGroups(bool isUpdate);

private slots:
    void init();
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

private:
    Ui::FormGroupsGamesInteractions *ui;
    GroupsGames _groups;
    SGame _game;
};

#endif // FORMGROUPSGAMESINTERACTIONS_H
