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
    //ui->TableWidgetGames->resizeRowsToContents();
    //this->setMinimumSize(33+ui->TableWidgetGames->columnWidth(1)+ui->TableWidgetGames->columnWidth(2)+ui->TableWidgetGames->columnWidth(3)+11+ui->TableWidgetGames->verticalHeader()->width(),577);
    //http://media.steampowered.com/steamcommunity/public/images/apps/{appid}/{hash}.jpg
    emit finished();
    return 1;
}

