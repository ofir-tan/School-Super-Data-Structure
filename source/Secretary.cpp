#include "Secretary.h"
#include <fstream>

void Secretary::info() {
    AdministrativeMan::info();
    cout << "Number of children at school: " << numOfChildren << endl;
    cout << "Salary: " << getSalary() << " $" << endl;
}

void Secretary::importData(ifstream &file) {
    file >> this->office;
    file >> this->numOfChildren;
}
