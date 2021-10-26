#include "Manager.h"

Manager *Manager::head = nullptr;

double Manager::getSalary() const {
    double extra = basis * 2 + yearsOfManage * 500;
    return extra + Teacher::getSalary();
}

Manager *Manager::getInstance(string &firstName, string &lastName,
                              double yearsOfTeach, double yearsOfManage,
                              vector<string> &courses, string &office) {
    if (!head)
        head = new Manager(firstName, lastName,
                           yearsOfTeach, yearsOfManage,
                           courses, office);
    else
        cout << "It is not possible to add more than one administrator." << endl;
    return head;
}

Manager::Manager(string &firstName, string &lastName,
                 double yearsOfTeach, double yearsOfManage,
                 vector<string> &courses, string &office) :
        Worker(firstName, lastName, yearsOfTeach, yearsOfManage),
        Teacher(firstName, lastName, yearsOfTeach, yearsOfManage, courses),
        AdministrativeMan(firstName, lastName, yearsOfTeach, yearsOfManage, office) {
}

void Manager::info() {
    AdministrativeMan::info();
    printCourses();
    cout << "Salary: " << getSalary() << " $" << endl;
}

