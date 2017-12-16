#ifndef PEOPLEMODEL_H
#define PEOPLEMODEL_H


#include <QAbstractTableModel>
#include <QVariant>
#include <QDebug>
#include "person.h"

class PeopleModel : public QAbstractTableModel
{
public:
    PeopleModel(QObject *parent = 0);
    void setData(std::vector<Person> * people);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data (const QModelIndex & index,
                   int role = Qt::DisplayRole) const;
    QVariant headerData(int section,Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
private:
    std::vector<Person> * personList;
};
#endif // PEOPLEMODEL_H
