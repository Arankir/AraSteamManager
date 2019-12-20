#include "filter.h"

Filter::Filter(int Arow, int Acol, QObject *parent) : QObject(parent){
    _row=Arow>0?Arow:0;
    _col=Acol>0?Acol:0;
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

void Filter::SetRow(int Arow){
    if(Arow>_row){
        for(int i=_row;i<Arow;i++){
            QVector<bool> subFilter;
            for(int j=0;j<_col;j++){
                subFilter.append(true);
            }
            _filter.append(subFilter);
        }
        _row=Arow;
    } else if(Arow<_row){
        for(int i=_row;i<Arow;i++){
            while(_filter.size()>Arow)
                _filter.takeAt(Arow);
        }
        _row=Arow;
    }
}
void Filter::SetCol(int Acol){
    if(Acol>_col){
        for(int i=_col;i<Acol;i++){
            for(int j=0;j<_row;j++){
                _filter[j].append(true);
            }
        }
        _col=Acol;
    } else if(Acol<_col){
        for(int i=_col;i<Acol;i++){
            for(int j=0;j<_row;j++){
                _filter[j].takeAt(_col);
            }
        }
        _col=Acol;
    }
}
void Filter::SetData(int Arow, int Acol, bool Adata){
    if(Arow<_row&&Acol<_col)
        _filter[Arow][Acol]=Adata;
}

bool Filter::GetData(int Arow, int Acol){
    if(Arow<_row&&Acol<_col){
        return _filter[Arow][Acol];
    }
    return false;
}
bool Filter::GetData(int Arow){
    if(Arow<_row){
        return _filter[Arow].indexOf(false)==-1;
    }
    return false;
}

void Filter::AddCol(int AcolNum){
    if(AcolNum<_col+1){
        for(int i=0;i<_row;i++){
            _filter[AcolNum].append(true);
        }
        _col++;
    }
}
void Filter::RemoveCol(int AcolNum){
    if(AcolNum<_col+1){
        for(int i=0;i<_row;i++){
            _filter.takeAt(AcolNum);
        }
        _col--;
    }
}

