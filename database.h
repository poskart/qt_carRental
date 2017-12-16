#ifndef DATABASE_H
#define DATABASE_H

#include "car.h"
#include "person.h"
#include "renting.h"

class Database
{
public:
    Database();

    bool addCar(Car & c);
    bool removeCar(Car & c);
    bool addPerson(Person & p);
    bool removePerson(Person & p);
    bool addRenting(Renting & r);
    bool removeRenting(Renting & r);

    Car * findCar(QString carId) const;
    Person * findPerson(QString personId) const;
    Renting * findRenting(QString carId) const;
    std::vector<Car> * getCarList(void);
    std::vector<Person> * getPeopleList(void);
    std::vector<Renting> * getRentList(void);

signals:
    void carsChanged(void){}
    void personChanged(void){}
    void rentingChanged(void){}

private:
    std::vector<Car> _cars;
    std::vector<Person> _people;
    std::vector<Renting> _rentList;
};

#endif // DATABASE_H
