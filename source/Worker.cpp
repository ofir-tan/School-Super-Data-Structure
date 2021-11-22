#include "Worker.h"

int Worker::base = 25;
int Worker::tutorBonus = 30;

Worker::Worker(ifstream &file) : Person(file) {
    file >> yearsOfManage;
    file >> yearsOfTeach;
}

void Worker::info() {
    Person::info();
    cout << "Teaching experience: " << yearsOfTeach << ", ";
    cout << "Managerial experience: " << yearsOfManage << '.' << endl;
}