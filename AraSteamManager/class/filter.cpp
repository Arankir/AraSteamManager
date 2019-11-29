#include "filter.h"

Filter::Filter(int row, int col, QObject *parent) : QObject(parent){
    Resize(row,col);
}
Filter::~Filter(){
    for(int i=0;i<row;i++)
        delete [] filter[i];
    delete [] filter;
}

void Filter::SetRow(int row){
    Resize(row, col);
}
void Filter::SetCol(int col){
    Resize(row, col);
}
void Filter::SetData(int row, int col, bool data){
    if(row<this->row&&col<this->col)
        filter[row][col]=data;
}
void Filter::DeleteCol(int col){
    if(col<this->col){
        for(int i=col;i<col-1;i++){
            for(int j=0;j<row;j++){
                filter[j][i]=filter[j][i+1];
            }
        }
        Resize(row,col);
    }
}
bool Filter::GetData(int row, int col){
    if(row<this->row&&col<this->col){
        return filter[row][col];
    }
    return false;
}
bool Filter::GetData(int row){
    if(row<this->row){
        bool answer = true;
        for(int i=0;i<col;i++){
            if(!filter[row][i]){
                answer=false;
                break;
            }
        }
        return answer;
    }
    return false;
}
void Filter::Resize(int row, int col){
    if((col==this->col&&row==this->row)){
        return;
    } else {
        if(!(col==0||row==0)){
            bool **NewA = new bool*[row];
            for(int i=0;i<row;i++) {
                NewA[i]=new bool[col];
                for(int j=0;j<col;j++) {
                    if(i<this->row&&j<this->col)
                        NewA[i][j]=filter[i][j];
                    else
                        NewA[i][j]=true;
                    }
                }
            if(this->row>0&&this->col>0){
                for(int i=0;i<this->row;i++){
                    delete [] filter[i];
                }
                delete [] filter;
            }
            this->col=col;
            this->row=row;
            filter = NewA;
        } else {
            this->col=col;
            this->row=row;
        }
    }
}
