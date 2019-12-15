#include "filter.h"

Filter::Filter(int ARow, int ACol, QObject *parent) : QObject(parent){
    _row=ARow>0?ARow:0;
    _col=ACol>0?ACol:0;
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
Filter::~Filter(){

}

void Filter::SetRow(int ARow){
    if(ARow>_row){
        for(int i=_row;i<ARow;i++){
            QVector<bool> subFilter;
            for(int j=0;j<_col;j++){
                subFilter.append(true);
            }
            _filter.append(subFilter);
        }
        _row=ARow;
    } else if(ARow<_row){
        for(int i=_row;i<ARow;i++){
            while(_filter.size()>ARow)
                _filter.takeAt(ARow);
        }
        _row=ARow;
    }
}
void Filter::SetCol(int ACol){
    if(ACol>_col){
        for(int i=_col;i<ACol;i++){
            for(int j=0;j<_row;j++){
                _filter[j].append(true);
            }
        }
        _col=ACol;
    } else if(ACol<_col){
        for(int i=_col;i<ACol;i++){
            for(int j=0;j<_row;j++){
                _filter[j].takeAt(_col);
            }
        }
        _col=ACol;
    }
}
void Filter::SetData(int ARow, int ACol, bool AData){
    if(ARow<_row&&ACol<_col)
        _filter[ARow][ACol]=AData;
}

bool Filter::GetData(int ARow, int ACol){
    if(ARow<_row&&ACol<_col){
        return _filter[ARow][ACol];
    }
    return false;
}
bool Filter::GetData(int ARow){
    if(ARow<_row){
        return _filter[ARow].indexOf(false)==-1;
    }
    return false;
}

void Filter::AddCol(int AColNum){
    if(AColNum<_col+1){
        for(int i=0;i<_row;i++){
            _filter[AColNum].append(true);
        }
        _col++;
    }
}
void Filter::RemoveCol(int AColNum){
    if(AColNum<_col+1){
        for(int i=0;i<_row;i++){
            _filter.takeAt(AColNum);
        }
        _col--;
    }
}

