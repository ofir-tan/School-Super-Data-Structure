#include "AdministrativeMan.h"

void AdministrativeMan::info() {
    Worker::info();
    cout << "Office Number: " << office << '.' << endl;
}