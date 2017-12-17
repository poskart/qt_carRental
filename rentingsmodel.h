#ifndef RENTINGSMODEL_H
#define RENTINGSMODEL_H

#include <QAbstractTableModel>
#include <QVariant>
#include <QDebug>
#include "database.h"
#include <QObject>

class RentingsModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    RentingsModel(Database * db, QObject *parent = 0);
    bool add(const Renting& r);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data (const QModelIndex & index,
                   int role = Qt::DisplayRole) const;
    QVariant headerData(int section,Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;

public slots:
    void addItemToModel(void);
private:
    std::vector<Renting> * rentingList;
    Database * _data;
};

#endif // RENTINGSMODEL_H
