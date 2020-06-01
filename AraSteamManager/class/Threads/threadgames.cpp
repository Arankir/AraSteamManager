#include "threadgames.h"

ThreadGames::ThreadGames(const int aTableColumnAppid, const int aTableColumnIndex, const int aTableColumnName, QTableWidget *aTableWidgetGames, SGames aGames, QObject *aParent):
QObject(aParent), c_tableColumnAppid(aTableColumnAppid), c_tableColumnIndex(aTableColumnIndex), c_tableColumnName(aTableColumnName), _games(aGames), _TableWidgetGames(aTableWidgetGames) {

}

int ThreadGames::fill() {
    int id = std::move(QFontDatabase::addApplicationFont(_setting.c_defaultFont));
    QString family = std::move(QFontDatabase::applicationFontFamilies(id).at(0));
    QFont font(family, 10);
    for(int i = 0; i < _games.getCount(); i++){
        QTableWidgetItem *itemTitle = new QTableWidgetItem(_games[i]._name);
        itemTitle->setFont(font);
        _TableWidgetGames->setItem(i, c_tableColumnAppid, new QTableWidgetItem(QString::number(_games[i]._appID)));
        _TableWidgetGames->setItem(i, c_tableColumnIndex, new QTableWidgetItem(QString::number(i)));
        _TableWidgetGames->setItem(i, c_tableColumnName, itemTitle);
        emit s_progress(i, i);
        }
    emit s_finished();
    return 1;
}

