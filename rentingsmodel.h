#ifndef RENTINGSMODEL_H
#define RENTINGSMODEL_H

#include <QAbstractTableModel>
#include <QVariant>
#include <QDebug>
#include "renting.h"

class RentingsModel : public QAbstractTableModel
{
public:
    RentingsModel(QObject *parent = 0);
    void setData(std::vector<Renting> * rentings);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data (const QModelIndex & index,
                   int role = Qt::DisplayRole) const;
    QVariant headerData(int section,Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
private:
    std::vector<Renting> * rentingList;
};

#endif // RENTINGSMODEL_H
