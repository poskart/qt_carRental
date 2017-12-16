#include "carsModel.h"

CarsModel::CarsModel(QObject* parent) :
QAbstractTableModel(parent)
{
    carsList = new std::vector<Car>();
}

void CarsModel::setData(std::vector<Car> * cars)
{
    delete carsList;
    carsList = cars;
}

int CarsModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 5;
}

int CarsModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return carsList->size();
}

QVariant CarsModel::data (const QModelIndex & index, int role) const
{
    if (!index.isValid()) return QVariant();

    if ((size_t)index.row() >= carsList->size() || index.row() < 0) return QVariant();

    if (role == Qt::DisplayRole) {
        const Car& car = carsList->at(index.row());
        switch (index.column()) {
        case 0:
            return car.getName();
        case 1:
            return car.getIdNumber();
        case 2:
            return car.getType();
        case 3:
            return car.getPrice();
        case 4:
            return car.getPower();
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

QVariant CarsModel::headerData(int section,
                                      Qt::Orientation orientation,int role) const {
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return tr("Name");
        case 1:
            return tr("ID number");
        case 2:
            return tr("Type");
        case 3:
            return tr("Price");
        case 4:
            return tr("Power");
        default:
            return QVariant();
        }
    }

    return section + 1;
}
