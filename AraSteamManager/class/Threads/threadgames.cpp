#include "threadgames.h"

ThreadGames::ThreadGames(QObject *parent) : QObject(parent){

}

void ThreadGames::Set(QTableWidget *AtableWidgetGames, QVector<SGame> Agames){
    _games=Agames;
    _TableWidgetGames=AtableWidgetGames;
}

int ThreadGames::Fill(){
    for(int i=0;i<_games.size();i++){
        _TableWidgetGames->setItem(i,1,new QTableWidgetItem(_games[i].GetName()));
        emit s_progress(i,i);
        }
    emit s_finished();
    return 1;
}

