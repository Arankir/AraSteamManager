#ifndef FORMHIDDENGAMES_H
#define FORMHIDDENGAMES_H

#include "form.h"
#include "classes/steamApi/structures/sgames.h"
#include <QMenu>

namespace Ui {
class FormHiddenGames;
}

namespace HiddenGamesData {
    enum Columns {
        id = 1,
        icon = 0,
        text = 0
    };
}

class FormHiddenGames : public Form {
    Q_OBJECT

public:
    explicit FormHiddenGames(QWidget *parent = nullptr);
    ~FormHiddenGames();

    void init();
    void update();

signals:
    void s_showAchievements(const SGame &);

private slots:
    void retranslate() override;
    void updateIcons() override;

    QMenu *createMenu(const QModelIndex &aIndex);
    void achievementsClicked();
    void hideClicked();
private:
    Ui::FormHiddenGames *ui;
};

#endif // FORMHIDDENGAMES_H
