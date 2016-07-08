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
public:
    explicit MatrixModel(int rows =4 , int columns=4 , QObject *parent =0);
    int rowCount(const QModelIndex &parent )const;
    int columnCount(const QModelIndex &parent )const;
    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    
private:
    int totalRows,totalColumns;
    Matrix *gameMatrix;
    
};

#endif
