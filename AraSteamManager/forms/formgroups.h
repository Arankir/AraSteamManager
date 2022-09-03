#ifndef FORMGROUPSGAMESINTERACTIONS_H
#define FORMGROUPSGAMESINTERACTIONS_H

#include <QListWidgetItem>

#include "classes/files/groupsgames.h"
#include "form.h"

namespace Ui {
class FormGroups;
}

class FormGroups : public Form {
    Q_OBJECT

public:
    explicit FormGroups(QWidget *parent = nullptr);
    ~FormGroups();
    void setProfileGames(const ProfileID &profileId, const SGames &game);

signals:
    void s_updateGroups();

protected slots:
    void init();
    QMenu *createMenu(QListWidgetItem *aItem);
    void removeGroup(QListWidgetItem *aItem);

    void initUi();
    void clear();
    void updateUi();

    void cancel();
    void apply();

    void cancelClicked();
    void applyClicked();

    void retranslate() override;
    void updateIcons() override;
//    void updateSettings(QFlags<changedSettings> aSettings) override;

private:
    Ui::FormGroups *ui;
    GroupsGames groups_;
    SGames games_;
};

#endif // FORMGROUPSGAMESINTERACTIONS_H
