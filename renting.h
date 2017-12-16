#ifndef RENTING_H
#define RENTING_H

#include <QDate>
#include "person.h"
#include "car.h"
#include <memory>

class Renting
{
public:
    Renting();
    Renting(Person * p, Car * c, QDate bDate, QDate eDate);

    QString getCarId(void) const;
    Person & getPerson(void) const;
    Car & getCar(void) const;
    QDate getBeginDate(void) const;
    QDate getEndDate(void) const;

private:
    Person * person;
    Car * car;
    QDate beginDate;
    QDate endDate;
};

#endif // RENTING_H
