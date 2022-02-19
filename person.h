#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>

using namespace std;

class Person
{
public:
    string name;
    string email;
    string phone;
    string birthday;

    Person(string _name, string _email, string _phone, string _birthday)
    {
        this->name = _name;
        this->email = _email;
        this->phone = _phone;
        this->birthday = _birthday;
    }

    bool operator<(Person B)
    {
        return this->name < B.name;
    }
};

#endif
