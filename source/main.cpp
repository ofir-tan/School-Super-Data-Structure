#include <iostream>
#include "School.h"
using namespace std;

#define PATH (string)"C:/Users/AppTa/Desktop/DataForProject/"

int main(int argc, char *argv[]) {
    School *bgu = School::getInstance(Six, Three);

    bgu->importStudents(PATH + "Students.txt");
    bgu->importWorkers(PATH);

    bgu->printStudents();
    bgu->printWorkers();

    bgu->topStudent()->info();
    bgu->topWorker()->info();

    cout << '\n' << bgu->meanGPA() << endl;
    cout << bgu->meanSalary() << endl;

    cout << '\n' << bgu->medianGPA() << endl;
    cout << bgu->medianSalary() << endl;

    return 0;
}