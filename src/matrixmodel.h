#ifndef MATRIXMODEL_H
#define MATRIXMODEL_H

#include <QAbstractTableModel>
#include <QModelIndex>
#include <QVariant>
#include <QHash>
#include "matrix.h"

// Inheritence (is a relationship) is used here 
// MatrixModel class inherits QAbstractTableModel publicly 
// ie. All the public members of QAbstractTableModel are accessible by the objects of MatrixModel class also
//
// Encapsulation of data required for MatrixModel class
//
class MatrixModel : public QAbstractTableModel
{
    // Data Abstraction is used here
    /*----------------------------private section----------------------------*/
    // only accessible by private and public member functions of the class
    // Macro defined in order to enable the meta object compiler to work
    Q_OBJECT
    
    Q_PROPERTY(int score READ currentScore NOTIFY scoreChanged)
    Q_PROPERTY(bool gameOver READ gameOver NOTIFY stateIsChanged)    
    /*------------------------------------------------------------------------*/
    
    /*-----------------------------public section ---------------------------*/
    // accessible by the object of class
public:
    // Constructor declared 
    // Polymorphism is achieved here using default arguments, as the Constructor can proceed differently depending upon the arguments passed 
    explicit MatrixModel(int rows =4 , int columns=4 , QObject *parent =0);
    
    // const member function -ie the function's definition cannot modify the members of the class
    int rowCount(const QModelIndex &parent )const;
    int columnCount(const QModelIndex &parent )const;
    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    
    // Template class QHash is used here
    QHash<int, QByteArray> roleNames() const ;
    void showData(); //just for debugging , console o/p
    int currentScore() const;
    bool gameOver();
    void basicInitialisaton();
    /*-----------------------------------------------------------------------------*/
signals:
    void scoreChanged();
    void stateIsChanged();

public slots:
    Q_INVOKABLE void moveUp();
    Q_INVOKABLE void moveDown();
    Q_INVOKABLE void moveRight();
    Q_INVOKABLE void moveLeft();
    Q_INVOKABLE void basicDeletion();
    
    void setModelData(int row,int col,int val);
    void endTheGame();
    
    /*-----------------------private section --------------------------------------*/
private:
    int totalRows,totalColumns;
    
    // Inheritence (has a relationship) is used here
    Matrix *gameMatrix;
    enum MatrixRoles{ firstCol = Qt::UserRole, secondCol , thirdCol , fourthCol };
    enum gameState{over=0,notOver};
    gameState state;
    
    /*-----------------------------------------------------------------------------*/
};

#endif
