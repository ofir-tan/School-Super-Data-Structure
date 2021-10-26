#include "Worker.h"

int Worker::basis = 25;
int Worker::tutorBonus = 30;

void Worker::info() {
    Person::info();
    cout << "Teaching experience: " << yearsOfTeach << ", ";
    cout << "Managerial experience: " << yearsOfManage << '.' << endl;
}