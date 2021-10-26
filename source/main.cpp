#include <string>
#include <iostream>
#include "Student.h"
#include "AuxiliaryFunctions.h"
#include "School.h"
using namespace std;

#define PATH (string)"C:/Users/AppTa/Desktop/DataForProject/"

int main(int argc, char *argv[]) {
    
    School *bgu = School::getInstance(Six, Three);
    cout << bgu->importStudents(PATH + "Students.txt") << endl;
    cout << bgu->importWorkers(PATH) << endl;

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
