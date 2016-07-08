#ifndef MATRIX_H
#define MATRIX_H

#include <QObject>
#include <ctime>
#include <cstdlib>
#include <QDebug>

class Matrix : public QObject
{
    Q_OBJECT
public :
    explicit Matrix(int x=4,int y=4,QObject *parent = 0);
    ~Matrix();
    void basicInitialisation(); //to initialise all the values of matrix to zero
    int getA(int , int);        //to get the value at A[i][j]
    int randomTwoFour();    //to return randomly either 2 or 4
    void randomSlot();      //to assign random value to a random indexes
    
    /*-----to evaluate all the values after one move----*/
    void moveUp();  
    void moveDown();
    void moveRight();
    void moveLeft();
    
    void mergeUp(int col,int start,int &end);
    void mergeDown(int col,int start,int &end);
    void mergeRight(int row,int &start,int end);
    void mergeLeft(int row,int start ,int &end);
    /*---------------------------------------*/
    
    

signals:
    
private:
    int **A;
    int rows,columns;    
};

#endif
