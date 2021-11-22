#ifndef MAIN_C___MANAGER_H
#define MAIN_C___MANAGER_H

#include "Teacher.h"
#include "AdministrativeMan.h"


class Manager : public Teacher, public AdministrativeMan {
private:
    explicit Manager(ifstream &file) : Teacher(file), AdministrativeMan(file), Worker(file) {};
    Manager(string &firstName, string &lastName, double yearsOfTeach, double yearsOfManage);
    static Manager *head;

public:
    // static method's:
    static Manager *getInstance(ifstream &file);
    static Manager *getInstance() { return head; }
    static void releaseInstance();

    // method's:
    void info() override;
    void importData(ifstream &file) override;
    [[nodiscard]] double getSalary() const override;
    bool isOutstanding() override { return yearsOfManage > 3; }

};

#endif //MAIN_C___MANAGER_H