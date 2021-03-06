#include "person.h"

Person::Person()
{

}

Person::Person(QString _name, QString _secName, QString _idNumber, int _age):
    name(_name), secName(_secName), idNumber(_idNumber), age(_age) {}


void Person::setName(QString _name)
{
    name = _name;
}

void Person::setSecName(QString _name)
{
    secName = _name;
}

void Person::setIdNumber(QString _id)
{
    idNumber = _id;
}

void Person::setAge(int _age)
{
    age = _age;
}

QString Person::getName(void) const
{
    return name;
}

QString Person::getSecName(void) const
{
    return secName;
}

QString Person::getIdNumber(void) const
{
    return idNumber;
}

int Person::getAge(void) const
{
    return age;
}
