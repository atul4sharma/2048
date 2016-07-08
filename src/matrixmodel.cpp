#include "matrixmodel.h"

MatrixModel::MatrixModel(int rows,int columns,QObject *parent):
    QAbstractTableModel(parent),totalColumns(columns),totalRows(rows)
{
    gameMatrix = new Matrix(totalRows,totalColumns);

    for(int i=0;i<totalRows;i++)
    {
        for(int j=0;j<totalColumns;j++)
        {
            QModelIndex currentIndex=this->index(i,j);
            this->setData(currentIndex,gameMatrix->getA(i,j),Qt::EditRole);
            //value from A[i][j] is copied to the currentIndex
        }
    }

}

int MatrixModel::rowCount(const QModelIndex &parent = QModelIndex()) const
{
    if(parent.isValid()){
        return 0;
    }
    return this->totalRows;
}

int MatrixModel::columnCount(const QModelIndex &parent = QModelIndex()) const
{
    if(parent.isValid()){
        return 0;
    }
    return this->totalColumns;
}

QVariant MatrixModel::data(const QModelIndex& index, int role) const
{
    if(!index.isValid())
        return QVariant();
    
    if(index.row()<0 || index.row()>this->totalRows -1)
        return QVariant();
    
    if(index.column()<0 || index.column()>this->totalColumns -1 )
        return QVariant();
    
    if(role==Qt::DisplayRole || role==Qt::EditRole)
        return QVariant(gameMatrix->getA(index.row(),index.column()));
    
    if(role==firstCol)
        return QVariant(gameMatrix->getA(index.row(),0));
    
    if(role==secondCol)
        return QVariant(gameMatrix->getA(index.row(),1));
    
    if(role==thirdCol)
        return QVariant(gameMatrix->getA(index.row(),2));

    if(role==fourthCol)
        return QVariant(gameMatrix->getA(index.row(),3));
}

Qt::ItemFlags MatrixModel::flags(const QModelIndex& index) const
{
    if(!index.isValid())
        return Qt::ItemIsEnabled;
    
    return Qt::ItemIsEnabled;
}

QVariant MatrixModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role!=Qt::DisplayRole)
        return QVariant();
    
    return section+1;
}

bool MatrixModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if(!index.isValid())
        return false;
    
    if(role==Qt::EditRole)
    {
        emit dataChanged(index,index);
        return true;
    }
}

QHash<int, QByteArray> MatrixModel::roleNames() const
{
    QHash<int,QByteArray> roles ;
    roles[firstCol]="firstColumn";
    roles[secondCol]="secondColumn";
    roles[thirdCol]="thirdColumn";
    roles[fourthCol]="fourthColumn";
    
    return roles;
}

void MatrixModel::showData()
{
    for(int i=0;i<totalRows;i++)
    {  QDebug debug=qDebug();
        for(int j=0;j<totalColumns;j++)
            debug<< this->data(this->index(i,j),Qt::EditRole).toInt();
    }
}

int MatrixModel::currentScore() const
{
    return gameMatrix->getScore();
}
