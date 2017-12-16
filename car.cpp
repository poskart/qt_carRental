#include "car.h"

Car::Car()
{

}

Car::Car(QString _name, QString _type, QString _idNumber, double _price, int _power) :
    name(_name), idNumber(_idNumber), carType(_type), price(_price), power(_power){}

void Car::setName(QString _name)
{
    name = _name;
}

void Car::setType(QString _type)
{
    carType = _type;
}

void Car::setIdNumber(QString _id)
{
    idNumber = _id;
}

void Car::setPrice(double _price)
{
    price = _price;
}

void Car::setPower(int _power)
{
    power = _power;
}

QString Car::getName(void)
{
    return name;
}

QString Car::getType(void)
{
    return carType;
}

QString Car::getIdNumber(void)
{
    return idNumber;
}

double Car::getPrice(void)
{
    return price;
}

int Car::getPower(void)
{
    return power;
}
