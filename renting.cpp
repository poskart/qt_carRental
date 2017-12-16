#include "renting.h"

Renting::Renting()
{
}

Renting::Renting(Person * p, Car * c, QDate bDate, QDate eDate):
    person(p), car(c), beginDate(bDate), endDate(eDate) {}

QString Renting::getCarId(void) const
{
    return car->getIdNumber();
}

Person & Renting::getPerson(void) const
{
    return *person;
}

Car & Renting::getCar(void) const
{
    return *car;
}

QDate Renting::getBeginDate(void) const
{
    return beginDate;
}

QDate Renting::getEndDate(void) const
{
    return endDate;
}
