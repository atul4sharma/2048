#include "matrix.h"
#include <QVector>

Matrix::Matrix(int x,int y,QObject *parent) 
            : QObject(parent) , rows(x) , columns(y)
{
    A = new int*[rows];
    basicInitialisation();                
}

Matrix::~Matrix()
{
    delete [] A;
}

void Matrix::basicInitialisation()
{
    for(int i=0;i<this->rows;i++)
        A = new int[columns];
    
    for(int i=0;i<this->rows;i++)
        for(int j=0;j<this->columns;j++)
            A[i][j]=0;
        
}

int Matrix::getA(int, int)
{
    return A[i][j];
}

int Matrix::randomTwoFour()
{
    srand(time(0));
    int val = rand()%2+1; //will generate random number either 1 or 2
    return 2*val;
}

void Matrix::randomSlot()
{
    struct slot{int a;int b;};
    
    QVector<slot> emptyList;
    
    for(int i=0;i<this->rows;i++)
    {
        for(int j=0;j<this->columns;j++)
        {
            if(A[i][j]==0)
            {
                slot index={i,j};
                emptyList.append(index);
            }
        }
    }
    
    if(emptyList.size()){
        srand(time(0));
        int randomIndex=rand()%emptyList.size();
        A[emptyList[randomIndex].x][emptyList[randomIndex].y]=randomTwoFour();
        //should emit signal here        
    } 
    else{
        //check whether move is possible or not 
        // if not then 'game over'
    }
}

