#include "threading.h"

Threading::Threading(QObject *parent) : QObject(parent)
{

}

int Threading::AddThreadGames(QTableWidget *TableWidgetGames, QVector<SGame> games, QString key, QIcon Favorite, QString AchievementsLocalisation){
    ThreadGames* Games = new ThreadGames;
    QThread * thread = new QThread;
    Games->moveToThread(thread);
    Games->Set(TableWidgetGames,games,key,Favorite,AchievementsLocalisation);
    connect(thread,SIGNAL(started()),Games,SLOT(Fill()));
    //connect(tr,SIGNAL(Err(double)),this,SLOT(Finish(double)));
    connect(Games,SIGNAL(finished()),thread,SLOT(quit()));
    connect(Games,SIGNAL(finished()),Games,SLOT(deleteLater()));
    connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));
    connect(Games,SIGNAL(progress(int,int)),this->parent(),SLOT(ProgressLoading(int,int)),Qt::DirectConnection);
    connect(Games,SIGNAL(setimage(QPixmap,int)),this->parent(),SLOT(ImageSet(QPixmap,int)),Qt::DirectConnection);
    thread->start();
}

int Threading::AddThreadAchievements(){

}

int Threading::AddThreadCompare(){

}

int Threading::AddThreadFriends(){

}
