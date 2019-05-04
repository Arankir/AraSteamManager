#ifndef FORMFRIENDS_H
#define FORMFRIENDS_H

#include <QWidget>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

namespace Ui {
class FormFriends;
}

class FormFriends : public QWidget
{
    Q_OBJECT

public:
    explicit FormFriends(QString ids, QString keys, int languages, QJsonDocument QJsonDocFriends, QWidget *parent = nullptr);
    ~FormFriends();

private:
    Ui::FormFriends *ui;
    QString id;
    QString key;
    int language=0;
    QJsonDocument QJsonDocFriends;
};

#endif // FORMFRIENDS_H
