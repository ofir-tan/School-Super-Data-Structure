
#ifndef MAIN_C___AdministrativeMan_H
#define MAIN_C___AdministrativeMan_H

#include "Worker.h"

class AdministrativeMan : virtual public Worker {
protected:
    string office;
public:
    // constructor:
    AdministrativeMan(string &firstName, string &lastName,
                      double yearsOfTeach, double yearsOfManage, string &office) :
            Worker(firstName, lastName, yearsOfTeach, yearsOfManage), office(office) {};
    AdministrativeMan(string &firstName, string &lastName,
                      double yearsOfTeach, double yearsOfManage) :
            Worker(firstName, lastName, yearsOfTeach, yearsOfManage) {};

    // methods:
    string getOffice() { return office; }
    void setOffice(string &newOffice) { office = newOffice; }
    void info() override;
};

#endif