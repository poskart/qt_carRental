#include "renting.h"

Renting::Renting()
{
    std::unique_ptr<Car> ptr = std::make_unique<Car>();
}

Renting::Renting(Person * p, Car * c, QDate bDate, QDate eDate):
    person(p), car(c), beginDate(bDate), endDate(eDate) {}
