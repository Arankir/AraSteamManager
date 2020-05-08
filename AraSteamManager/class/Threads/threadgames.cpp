#include "threadgames.h"

int ThreadGames::Fill(){
    for(int i=0;i<_games.GetCount();i++){
        _TableWidgetGames->setItem(i,c_tableColumnAppid,new QTableWidgetItem(QString::number(_games[i].GetAppid())));
        _TableWidgetGames->setItem(i,c_tableColumnIndex,new QTableWidgetItem(QString::number(i)));
        _TableWidgetGames->setItem(i,c_tableColumnName,new QTableWidgetItem(_games[i].GetName()));
        emit s_progress(i,i);
        }
    emit s_finished();
    return 1;
}

