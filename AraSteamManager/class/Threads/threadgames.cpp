#include "threadgames.h"

ThreadGames::ThreadGames(QObject *parent) : QObject(parent){

}

void ThreadGames::Set(QTableWidget *a_tableWidgetGames, SGames a_games){
    _games=a_games;
    _TableWidgetGames=a_tableWidgetGames;
}

int ThreadGames::Fill(){
    for(int i=0;i<_games.GetCount();i++){
        _TableWidgetGames->setItem(i,0,new QTableWidgetItem(QString::number(_games[i].GetAppid())));
        _TableWidgetGames->setItem(i,1,new QTableWidgetItem(QString::number(i)));
        _TableWidgetGames->setItem(i,3,new QTableWidgetItem(_games[i].GetName()));
        emit s_progress(i,i);
        }
    emit s_finished();
    return 1;
}

