#include "peoplemodel.h"

PeopleModel::PeopleModel(QObject* parent) :
QAbstractTableModel(parent)
{
    personList = new std::vector<Person>();
}

void PeopleModel::setData(std::vector<Person> * people)
{
    delete personList;
    personList = people;
}

int PeopleModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 4;
}

int PeopleModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return personList->size();
}

QVariant PeopleModel::data (const QModelIndex & index, int role) const
{
    if (!index.isValid()) return QVariant();

    if ((size_t)index.row() >= personList->size() || index.row() < 0) return QVariant();

    if (role == Qt::DisplayRole) {
        const Person& person = personList->at(index.row());
        switch (index.column()) {
        case 0:
            return person.getName();
        case 1:
            return person.getSecName();
        case 2:
            return person.getIdNumber();
        case 3:
            return person.getAge();
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

QVariant PeopleModel::headerData(int section,
                                      Qt::Orientation orientation,int role) const {
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return tr("Name");
        case 1:
            return tr("Surname");
        case 2:
            return tr("IdCard number");
        case 3:
            return tr("Age");
        default:
            return QVariant();
        }
    }

    return section + 1;
}
