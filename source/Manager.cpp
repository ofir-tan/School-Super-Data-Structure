#include "Manager.h"

Manager *Manager::head = nullptr;

double Manager::getSalary() const {
    double extra = base * 2 + yearsOfManage * 500;
    return extra + Teacher::getSalary();
}

Manager *Manager::getInstance(string &firstName, string &lastName,
                              double yearsOfTeach, double yearsOfManage) {
    if (!head)
        head = new Manager(firstName, lastName,
                           yearsOfTeach, yearsOfManage);
    else
        cout << "It is not possible to add more than one administrator." << endl;
    return head;
}

Manager::Manager(string &firstName, string &lastName,
                 double yearsOfTeach, double yearsOfManage) :
        Worker(firstName, lastName, yearsOfTeach, yearsOfManage),
        Teacher(firstName, lastName, yearsOfTeach, yearsOfManage),
        AdministrativeMan(firstName, lastName, yearsOfTeach, yearsOfManage) {
}

void Manager::info() {
    AdministrativeMan::info();
    printCourses();
    cout << "Salary: " << getSalary() << " $" << endl;
}

void Manager::releaseInstance() {
    delete head;
    head = nullptr;
}

void Manager::importData(ifstream &file) {
    Teacher::importData(file);
    file >> office;
}
