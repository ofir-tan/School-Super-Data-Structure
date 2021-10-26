#include "Secretary.h"

void Secretary::info() {
    AdministrativeMan::info();
    cout << "Number of children at school: " << numOfChildren << endl;
    cout << "Salary: " << getSalary() << " $" << endl;
}