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
        A[i] = new int[this->columns];
    
    for(int i=0;i<this->rows;i++)
        for(int j=0;j<this->columns;j++)
            A[i][j]=0;
        
}

int Matrix::getA(int i, int j)
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
        A[emptyList[randomIndex].a][emptyList[randomIndex].b]=randomTwoFour();
        //should emit signal here        
    } 
    else{
        //check whether move is possible or not 
        // if not then 'game over'
    }
}


void Matrix::moveUp()
{
    int j=0;
    while(j<this->columns)
    {
        int topIndex=0;
        int bottomIndex=this->rows - 1;

        while(topIndex<bottomIndex)
        {
            if(A[topIndex][j]==0)
                this->mergeUp(j,topIndex,bottomIndex);
            else if(A[topIndex][j]==A[topIndex+1][j])   //same values found
            {
                A[topIndex][j]+=A[topIndex+1][j];
                //should emit signal here for data change at A[topIndex][j]
                //update score
                this->mergeUp(j,topIndex+1,bottomIndex);
                topIndex+=1;
            }
            else if(A[topIndex+1][j]==0)
                this->mergeUp(j,topIndex+1,bottomIndex);
            else
                topIndex+=1;
        }
        j+=1;
    }
}

void Matrix::mergeUp(int col,int start,int &end)
{
    for(int k=start;k<end;k++)
    {
        A[k][col]=A[k+1][col];
        //should emit signal here for data change at A[k][col]
    }
    A[end][col]=0;
    //should emit signal here for data change at A[end][col]
    end-=1;
}


void Matrix::moveDown()
{
    int j=0;
    while(j<this->columns)
    {
        int topIndex=0;
        int bottomIndex=this->rows - 1;
        while(bottomIndex>topIndex)
        {
            if(A[bottomIndex][j]==0)
                this->mergeDown(j,bottomIndex,topIndex);
            else if(A[bottomIndex][j]==A[bottomIndex-1][j])
            {
                A[bottomIndex][j]+=A[bottomIndex-1][j];
                //should emit signal here for data change at A[bottomIndex][j]
                //update score
                this->mergeDown(j,bottomIndex-1,topIndex);
                bottomIndex-=1;
            }
            else if(A[bottomIndex-1][j]==0)
                 this->mergeDown(j,bottomIndex-1,topIndex);
            else
                bottomIndex-=1;
        }

        j+=1;
    }
}

void Matrix::mergeDown(int col,int start,int &end)
{
    for(int k=start;k>end;k--)
    {
        A[k][col]=A[k-1][col];
        //should emit signal here for data change at A[k][col]
    }
    A[end][col]=0;
    //should emit signal here for data change at A[end][col]
    end+=1;
}


void Matrix::moveRight()
{
    int i=0;
    while(i < this->rows)
    {
        int leftIndex=0;
        int rightIndex=this->columns - 1;

        while(rightIndex>leftIndex)
        {
            if(A[i][rightIndex]==0)
                this->mergeRight(i,leftIndex,rightIndex);
            else if(A[i][rightIndex]==A[i][rightIndex-1])
            {
                A[i][rightIndex]+=A[i][rightIndex-1];
                //should emit signal here for data change at A[i][rightIndex]
                //update score
                this->mergeRight(i,leftIndex,rightIndex-1);
                rightIndex-=1;
            }
            else if(A[i][rightIndex-1]==0)
                this->mergeRight(i,leftIndex,rightIndex-1);
            else
                rightIndex-=1;
        }
        i+=1;
    }
}

void Matrix::mergeRight(int row,int &start,int end)
{
    for(int k=end;k>start;k--)
    {
        A[row][k]=A[row][k-1];
        //should emit signal here for data change at A[row][k]
    }
    A[row][start]=0;
    //should emit signal here for data change at A[row][start]
    start+=1;
}


void Matrix::moveLeft()
{
    int i=0;
    while(i < this->rows)
    {
        int leftIndex=0;
        int rightIndex=this->columns - 1;
        while(leftIndex<rightIndex)
        {
            if(A[i][leftIndex]==0)
            {
              mergeLeft(i,leftIndex,rightIndex);
            }
            else if(A[i][leftIndex]==A[i][leftIndex+1])
            {
                A[i][leftIndex]+=A[i][leftIndex+1];
                //should emit signal here for data change at A[i][leftIndex]
                //update score
                mergeLeft(i,leftIndex+1,rightIndex);
                leftIndex+=1;
            }
            else if(A[i][leftIndex+1]==0)
            {
                mergeLeft(i,leftIndex+1,rightIndex);
            }
            else
                leftIndex+=1;
        }
        i+=1;
    }
}

void Matrix::mergeLeft(int row,int start,int &end)
{
    for(int k=start;k<end;k++)
    {
        A[row][k]=A[row][k+1];
        //should emit signal here for data change at A[row][k]
    }
    A[row][end]=0;
    //should emit signal here for data change at A[row][end]
    end-=1;
}
