#include "threading.h"

Threading::Threading(QObject* parent) : QObject(parent)
{

}

int Threading::AddThreadGames(QTableWidget* TableWidgetGames, QVector<SGame> games, QString key, QIcon Favorite, QString AchievementsLocalisation){
    ThreadGames* Games = new ThreadGames;
    QThread* thread = new QThread;
    Games->moveToThread(thread);
    Games->Set(TableWidgetGames,games,key,Favorite,AchievementsLocalisation);
    connect(thread,SIGNAL(started()),Games,SLOT(Fill()));
    connect(Games,SIGNAL(finished()),thread,SLOT(quit()));
    connect(Games,SIGNAL(finished()),Games,SLOT(deleteLater()));
    connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));
    connect(Games,SIGNAL(progress(int,int)),this->parent()->parent(),SLOT(ProgressLoading(int,int)));
    connect(Games,SIGNAL(progress(int,int)),this->parent(),SLOT(ProgressLoading(int,int)));
    connect(Games,SIGNAL(setimage(QPixmap,int)),this->parent(),SLOT(ImageSet(QPixmap,int)));
    connect(Games,SIGNAL(finished()),this->parent()->parent(),SLOT(ShowGames()));
    thread->start();
    return 1;
}

int Threading::AddThreadFriends(QTableWidget* TableWidgetFriends,QVector<SProfile> Profiles,SFriends Friendss,QStringList Words){
    ThreadFriends* Friends = new ThreadFriends;
    QThread* thread = new QThread;
    Friends->moveToThread(thread);
    Friends->Set(TableWidgetFriends,Profiles,Friendss,Words);
    connect(thread,SIGNAL(started()),Friends,SLOT(Fill()));
    connect(Friends,SIGNAL(finished()),thread,SLOT(quit()));
    connect(Friends,SIGNAL(finished()),Friends,SLOT(deleteLater()));
    connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));
    connect(Friends,SIGNAL(progress(int,int)),this->parent()->parent(),SLOT(ProgressLoading(int,int)));
    connect(Friends,SIGNAL(progress(int,int)),this->parent(),SLOT(ProgressLoading(int,int)));
    connect(Friends,SIGNAL(setimage(QPixmap,int)),this->parent(),SLOT(ImageSet(QPixmap,int)));
    connect(Friends,SIGNAL(finished()),this->parent()->parent(),SLOT(ShowFriends()));
    thread->start();
    return 1;
}

int Threading::AddThreadCompare(){
    return 1;
}

int Threading::AddThreadAchievements(){
    return 1;
}
