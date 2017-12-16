#ifndef PERSON_H
#define PERSON_H

#include <QString>

class Person
{
public:
    Person();
    Person(QString _name, QString _secName, QString _idNumber, int _age);

    void setName(QString _name);
    void setSecName(QString _name);
    void setIdNumber(QString _id);
    void setAge(int _age);

    QString getName(void) const;
    QString getSecName(void) const;
    QString getIdNumber(void) const;
    int getAge(void) const;

private:

    QString name;
    QString secName;
    QString idNumber;
    int age;
};

#endif // PERSON_H
