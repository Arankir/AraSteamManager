#ifndef FORMFAVORITES_H
#define FORMFAVORITES_H

#include <QWidget>

namespace Ui {
class FormFavorites;
}

class FormFavorites : public QWidget
{
    Q_OBJECT

public:
    explicit FormFavorites(QWidget *parent = nullptr);
    ~FormFavorites();

signals:
    void return_to_profile();

private slots:
    void on_pushButton_clicked();

private:
    Ui::FormFavorites *ui;
};

#endif // FORMFAVORITES_H
