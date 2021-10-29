#include <iostream>
#include "School.h"

using namespace std;

#define PATH (string)"C:/Users/AppTa/Documents/Programming/C++/Project/School-Super-Data-Structure/data/"

int main(int argc, char *argv[]) {
    School *bgu = School::getInstance(Six, Three);

    bgu->importStudents(PATH + "Students.txt");
    bgu->importWorkers(PATH);

    bgu->info();

    if (bgu->findStudent("Jacki Mickey"))
        bgu->findStudent("Jacki Mickey")->info();

    return 0;
}