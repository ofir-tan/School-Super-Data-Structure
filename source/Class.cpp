#include "Class.h"

int Class::numOfOutstanding() {
    int counter = 0;
    for (auto &pupil: pupils)
        counter += pupil->isOutstanding();
    return counter;
}

void Class::info() {
    cout << "\tClass " << layer << " - " << classNum <<
         " | Average: " << avg() << '.' << endl;
    cout << "Student List:" << endl;
    for (int i = 0; i < pupils.size(); i++) {
        cout << i + 1 << "] ";
        pupils[i]->info();
    }
    cout << endl;

    cout << "Outstanding Student List:" << endl;
    for (auto &pupil: pupils)
        if (pupil->isOutstanding())
            pupil->info();
    cout << endl;

}

double Class::avg() {
    double res = 0;
    for (auto &pupil: pupils)
        res += pupil->avg();
    return res / pupils.size();
}