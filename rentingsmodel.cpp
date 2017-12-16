#include "rentingsmodel.h"

RentingsModel::RentingsModel(QObject* parent) :
QAbstractTableModel(parent)
{
    rentingList = new std::vector<Renting>();
}

void RentingsModel::setData(std::vector<Renting> * rentings)
{
    delete rentingList;
    rentingList = rentings;
}

int RentingsModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 6;
}

int RentingsModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return rentingList->size();
}

QVariant RentingsModel::data (const QModelIndex & index, int role) const
{
    if (!index.isValid()) return QVariant();

    if ((size_t)index.row() >= rentingList->size() || index.row() < 0) return QVariant();

    if (role == Qt::DisplayRole) {
        const Renting & renting= rentingList->at(index.row());
        switch (index.column()) {
        case 0:
            return renting.getCar().getIdNumber();
        case 1:
            return renting.getPerson().getName();
        case 2:
            return renting.getPerson().getSecName();
        case 3:
            return renting.getPerson().getIdNumber();
        case 4:
            return renting.getBeginDate();
        case 5:
            return renting.getEndDate();
        default:
            return QVariant();
        }
    }
    else if (role == Qt::TextAlignmentRole) {
        if (index.column() == 0)
            return QVariant(Qt::AlignLeft | Qt::AlignVCenter);
        else
            return Qt::AlignCenter;
    }
    return QVariant();
}

QVariant RentingsModel::headerData(int section,
                                      Qt::Orientation orientation,int role) const {
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return tr("Car ID number");
        case 1:
            return tr("Name");
        case 2:
            return tr("Surname");
        case 3:
            return tr("Renter ID");
        case 4:
            return tr("Begin date");
        case 5:
            return tr("End date");
        default:
            return QVariant();
        }
    }

    return section + 1;
}
