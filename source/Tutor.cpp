#include "Tutor.h"

void Tutor::info() {
    Worker::info();
    printCourses();
    cout << "Salary: " << getSalary() << " $" << endl;
    cout << "Tutor Of Class: " << class_->getLayer() << '-' << class_->getClassNum() << '.' << endl;
}