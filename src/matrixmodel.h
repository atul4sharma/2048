#ifndef MATRIXMODEL_H
#define MATRIXMODEL_H

#include <QAbstractTableModel>
#include <QModelIndex>
#include <QVariant>
#include <QHash>
#include "matrix.h"

class MatrixModel : public QAbstractTableModel
{
    Q_OBJECT
    
    Q_PROPERTY(int score READ currentScore NOTIFY scoreChanged)
    Q_PROPERTY(bool gameOver READ gameOver NOTIFY stateIsChanged)
public:
    explicit MatrixModel(int rows =4 , int columns=4 , QObject *parent =0);
    int rowCount(const QModelIndex &parent )const;
    int columnCount(const QModelIndex &parent )const;
    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    
    QHash<int, QByteArray> roleNames() const ;
    void showData(); //just for debugging , console o/p
    int currentScore() const;
    bool gameOver();
    void basicInitialisaton();
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
private:
    int totalRows,totalColumns;
    Matrix *gameMatrix;
    enum MatrixRoles{ firstCol = Qt::UserRole, secondCol , thirdCol , fourthCol };
    enum gameState{over=0,notOver};
    gameState state;
};

#endif
