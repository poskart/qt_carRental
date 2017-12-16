#ifndef CAR_H
#define CAR_H

#include <QString>
#include <QMetaEnum>

//template<typename QEnum>
//std::string QtEnumToString (const QEnum value)
//{
//  return std::string(QMetaEnum::fromType<QEnum>().valueToKey(value));
//}

class Car
{
//    Q_OBJECT

public:
    Car();
    Car(QString _name, QString _type, QString _idNumber, double _price, int _power);

    void setName(QString _name);
    void setType(QString _type);
    void setIdNumber(QString _id);
    void setPrice(double _price);
    void setPower(int _power);

    QString getName(void);
    QString getType(void);
    QString getIdNumber(void);
    double getPrice(void);
    int getPower(void);
//    enum CarType{
//        Carr,
//        Truck,
//    };

//    Q_ENUM(CarType);

private:
    QString name;
    QString idNumber;
    QString carType;
    double price;
    int power;
};

#endif // CAR_H
