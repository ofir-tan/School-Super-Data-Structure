#include "Teacher.h"

void Teacher::printCourses() {
    if (courses.empty())
        cout << "No courses to display.";
    else {
        cout << "Courses List:";
        for (unsigned int i = 0; i < courses.size(); i++)
            cout << " | [" << i + 1 << "] " << courses[i];
    }
    cout << endl;
}

void Teacher::info() {
    Worker::info();
    printCourses();
    cout << "Salary: " << getSalary() << " $" << endl;
}
