#include "filter.h"

Filter::Filter(int a_row, int a_col, QObject *parent) : QObject(parent){
    _row=a_row>0?a_row:0;
    _col=a_col>0?a_col:0;
    if(_row>0&&_col>0){
        for(int i=0;i<_row;i++){
            QVector<bool> subFilter(_col);
            for(int j=0;j<_col;j++){
                subFilter[j]=true;
            }
            _filter.append(subFilter);
        }
    }
}
Filter::~Filter(){}

void Filter::SetRow(int a_row){
    if(a_row>_row){
        for(int i=_row;i<a_row;i++){
            QVector<bool> subFilter;
            for(int j=0;j<_col;j++){
                subFilter.append(true);
            }
            _filter.append(subFilter);
        }
        _row=a_row;
    } else if(a_row<_row){
        for(int i=_row;i<a_row;i++){
            while(_filter.size()>a_row)
                _filter.takeAt(a_row);
        }
        _row=a_row;
    }
}
void Filter::SetCol(int a_col){
    if(a_col>_col){
        for(int i=_col;i<a_col;i++){
            for(int j=0;j<_row;j++){
                _filter[j].append(true);
            }
        }
        _col=a_col;
    } else if(a_col<_col){
        for(int i=_col;i<a_col;i++){
            for(int j=0;j<_row;j++){
                _filter[j].takeAt(_col);
            }
        }
        _col=a_col;
    }
}
void Filter::SetData(int a_row, int a_col, bool a_data){
    if(a_row<_row&&a_col<_col)
        _filter[a_row][a_col]=a_data;
}

bool Filter::GetData(int a_row, int a_col){
    if(a_row<_row&&a_col<_col){
        return _filter[a_row][a_col];
    }
    return false;
}
bool Filter::GetData(int a_row){
    if(a_row<_row){
        return _filter[a_row].indexOf(false)==-1;
    }
    return false;
}

void Filter::AddCol(int a_colNum){
    if(a_colNum<_col+1){
        for(int i=0;i<_row;i++){
            _filter[a_colNum].append(true);
        }
        _col++;
    }
}
void Filter::RemoveCol(int a_colNum){
    if(a_colNum<_col+1){
        for(int i=0;i<_row;i++){
            _filter[i].remove(a_colNum);
        }
        _col--;
    }
}

