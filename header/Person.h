#ifndef UNTITLED1_PERSON_H
#define UNTITLED1_PERSON_H

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

class Person {
private:
    string firstName;
    string lastName;
public:
    // constructor:
    Person() : firstName("Ofir"), lastName("Tanami") {};
    Person(string &firstName, string &lastName) : firstName(firstName), lastName(lastName) {};
    virtual ~Person() = default;
    // methods:
    virtual bool isOutstanding() = 0;
    string fullName() { return firstName + ' ' + lastName; }
    virtual void info() { cout << "First Name: " << firstName << " | Last Name: " << lastName << '.' << endl; }
};

#endif