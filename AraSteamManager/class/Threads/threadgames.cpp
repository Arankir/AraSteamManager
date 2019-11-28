#include "threadgames.h"

ThreadGames::ThreadGames(QObject* parent) : QObject(parent){

}

void ThreadGames::Set(QTableWidget* TableWidgetGames, QVector<SGame> games){
    this->games=games;
    this->TableWidgetGames=TableWidgetGames;
}

int ThreadGames::Fill(){
    for(int i=0;i<games.size();i++){
        TableWidgetGames->setItem(i,1,new QTableWidgetItem(games[i].GetName()));
        emit progress(i,i);
        }
    emit finished();
    return 1;
}

