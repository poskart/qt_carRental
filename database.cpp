#include "database.h"

Database::Database()
{

}

bool Database::addCar(Car & c)
{
    if(std::none_of(_cars.begin(), _cars.end(),
                    [&](Car tmpCar){return c.getIdNumber() == tmpCar.getIdNumber(); }))
    {
        _cars.push_back(c);
        emit carsChanged();
        return true;
    }
    return false;
}

bool Database::removeCar(Car & c)
{
    auto it = std::find_if(_cars.begin(), _cars.end(),
                        [&](Car tmpCar){ return tmpCar.getIdNumber() == c.getIdNumber(); });
    if(it != _cars.end())
    {
        _cars.erase(it);
        emit carsChanged();
        return true;
    }
    return false;
}

bool Database::addPerson(Person & p)
{
    if(std::none_of(_people.begin(), _people.end(),
                    [&](Person tmpPerson){return p.getIdNumber() == tmpPerson.getIdNumber(); }))
    {
        _people.push_back(p);
        emit personChanged();
        return true;
    }
    return false;
}

bool Database::removePerson(Person & p)
{
    auto it = std::find_if(_people.begin(), _people.end(),
                        [&](Person tmpPerson){ return tmpPerson.getIdNumber() == p.getIdNumber(); });
    if(it != _people.end())
    {
        _people.erase(it);
        emit personChanged();
        return true;
    }
    return false;
}

bool Database::addRenting(Renting & r)
{
    if(std::none_of(_rentList.begin(), _rentList.end(),
                    [&](Renting tmpRent){return r.getCarId() == tmpRent.getCarId(); }))
    {
        _rentList.push_back(r);
        emit rentingChanged();
        return true;
    }
    return false;
}

bool Database::removeRenting(Renting & r)
{
    auto it = std::find_if(_rentList.begin(), _rentList.end(),
                        [&](Renting tmpRent){ return tmpRent.getCarId() == r.getCarId(); });
    if(it != _rentList.end())
    {
        _rentList.erase(it);
        emit rentingChanged();
        return true;
    }
    return false;
}

std::vector<Car> * Database::getCarList(void)
{
    return &_cars;
}
std::vector<Person> * Database::getPeopleList(void)
{
    return &_people;
}
std::vector<Renting> * Database::getRentList(void)
{
    return &_rentList;
}
