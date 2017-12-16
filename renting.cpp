#include "renting.h"

Renting::Renting()
{

}

Renting::Renting(Person * p, Car * c, QDate bDate, QDate eDate):
    person(p), car(c), beginDate(bDate), endDate(eDate) {}
