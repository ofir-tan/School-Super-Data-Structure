#ifndef MAIN_C___MANAGER_H
#define MAIN_C___MANAGER_H

#include "Teacher.h"
#include "AdministrativeMan.h"

class Manager : public Teacher, public AdministrativeMan {
private:
    Manager(string &firstName, string &lastName, double yearsOfTeach, double yearsOfManage,
            vector<string> &courses, string &office);
    static Manager *head;

public:
    // static method's:
    static Manager *getInstance(string &firstName, string &lastName,
                                double yearsOfTeach, double yearsOfManage,
                                vector<string> &courses, string &office);
    static Manager *getInstance() { return head; }
    ~Manager() override { delete head; }
    // method's:
    void info() override;
    [[nodiscard]] double getSalary() const override;
    bool isOutstanding() override { return yearsOfManage > 3; }

};

#endif //MAIN_C___MANAGER_H