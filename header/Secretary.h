#ifndef UNTITLED1_SECRETARY_H
#define UNTITLED1_SECRETARY_H

#include "AdministrativeMan.h"

class Secretary : public AdministrativeMan {
private:
    int numOfChildren{};
public:
    // Constructors:
    explicit Secretary(ifstream &file) : AdministrativeMan(file), Worker(file) {};
    Secretary(string &firstName, string &lastName,
              double yearsOfTeach, double yearsOfManage, string &office, int numOfChildren) :
            Worker(firstName, lastName, yearsOfTeach, yearsOfManage),
            AdministrativeMan(firstName, lastName, yearsOfTeach, yearsOfManage, office),
            numOfChildren(numOfChildren) {}
    Secretary(string &firstName, string &lastName,
              double yearsOfTeach, double yearsOfManage) :
            Worker(firstName, lastName, yearsOfTeach, yearsOfManage),
            AdministrativeMan(firstName, lastName, yearsOfTeach, yearsOfManage) {}

    // methods:
    [[nodiscard]] double getSalary() const override { return 200 * numOfChildren + base; }
    bool isOutstanding() override { return yearsOfManage > 10; }
    void importData(ifstream &file) override;
    void info() override;
};

#endif