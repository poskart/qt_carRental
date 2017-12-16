#ifndef MYCARSMODEL_H
#define MYCARSMODEL_H

#include <QAbstractTableModel>
#include <QVariant>
#include <QDebug>
#include "car.h"

class CarsModel : public QAbstractTableModel
{
public:
    CarsModel(QObject *parent = 0);
    void setData(std::vector<Car> * cars);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data (const QModelIndex & index,
                   int role = Qt::DisplayRole) const;
    QVariant headerData(int section,Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
private:
    std::vector<Car> * carsList;
};

#endif // MYCARSMODEL_H
