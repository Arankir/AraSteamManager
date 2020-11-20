#ifndef FORMCATEGORYVALUE_2_H
#define FORMCATEGORYVALUE_2_H

#include <QWidget>
#include <QStandardItemModel>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include "class/settings.h"
#include "class/steamapi/Sachievements.h"

namespace Ui {
class FormCategoryValue_2;
}

class FormCategoryValue_2 : public QWidget
{
    Q_OBJECT

public:
    explicit FormCategoryValue_2(QWidget *parent = nullptr);
    ~FormCategoryValue_2();

    void setTitle(const QString &title);
    void setAchievements(QList<SAchievement> &achievements, const int &gameId);

    QString getTitle() const;
    QList<QString> getAchievements() const;

signals:
    void s_goFirst();
    void s_goBack();
    void s_goNext();
    void s_goLast();
    void s_deleteValue();
    void s_deleteAchievement();

private slots:
    void on_ButtonDelete_clicked();

    void on_ButtonFirst_clicked();

    void on_ButtonBack_clicked();

    void on_ButtonNext_clicked();

    void on_ButtonLast_clicked();

    void on_ButtonAddVisible_clicked();

    void on_ButtonRemoveVisible_clicked();

    void on_ButtonReverse_clicked();

    void setIcons();
    QMenu *createMenu(QModelIndex aIndex);
private:
    Ui::FormCategoryValue_2 *ui;
    QString _currentAchievement = "";
};

#endif // FORMCATEGORYVALUE_2_H
