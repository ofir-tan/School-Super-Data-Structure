#include "Student.h"

void Student::info() {
    Person::info();
    cout << "Grades: ";
    for (auto grade: grades)
        cout << grade << ", ";
    cout << endl;
    cout << "Average: " << avg() << ", Class: " << layer << "-" << classNumber << endl;
}