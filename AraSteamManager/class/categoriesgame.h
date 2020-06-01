#ifndef CATEGORIESGAME_H
#define CATEGORIESGAME_H

#include <QObject>
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <class/settings.h>
#include <class/steamapi/Sgames.h>

class CategoriesGame : public QObject {
    Q_OBJECT
public:
    explicit CategoriesGame(SGame game, QObject *parent = nullptr);
    //CategoriesGame & operator=(const CategoriesGame &);
    CategoriesGame(const CategoriesGame &categories);

signals:

public slots:
    QString getTitle(int a_index);
    int getIsNoValues(int a_index);
    QJsonArray getValues(int a_value);
    QString getGame();
    int getCount();
    int getGameID();
    QList<QString> getTitles();
    QList<QString> getValues(int category, int value);
    QList<QString> getNoValues(int category);
    void deleteCategory(int index);
    void deleteAll();
    void changeCategory(int category, QJsonObject newCategory);
    void update();
    void save();

private slots:
    QFileInfoList getFiles(QString path);
    void convertOldCategories();
    void loadCategories();

private:
    QJsonObject _categories;
    Settings _setting;
    SGame _game;
};

#endif // CATEGORIESGAME_H
