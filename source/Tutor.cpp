#include "Tutor.h"

void Tutor::info() {
    Worker::info();
    printCourses();
    cout << "Salary: " << getSalary() << " $" << endl;
    cout << "Tutor Of Class: " << layer << '-' << classNum << '.' << endl;
}

void Tutor::importData(ifstream &file) {
    Teacher::importData(file);
    file >> layer;
    file >> classNum;
}
