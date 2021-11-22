#ifndef MAIN_C___WORKER_H
#define MAIN_C___WORKER_H

#include "Person.h"
#include <fstream>

class Worker : public Person {
protected:
    double yearsOfTeach{};
    double yearsOfManage{};
    static int base;
    static int tutorBonus;
public:
    // constructors
    explicit Worker(ifstream &file);
    Worker(string &firstName, string &lastName, double yearsOfTeach, double yearsOfManage)
            : Person(firstName, lastName), yearsOfTeach(yearsOfTeach),
              yearsOfManage(yearsOfManage) {}
    // methods:
    void info() override;
    virtual void importData(ifstream &file) = 0;
    [[nodiscard]] virtual double getSalary() const = 0;
    static void setBasis(int newBasis) { base = newBasis; }
    static void setTutorBonus(int newBonus) { tutorBonus = newBonus; }
    // operator overloading:
    double operator-() const { return -getSalary(); }
    double operator+() const { return getSalary(); }
    bool operator<(const Worker &other) const { return getSalary() < other.getSalary(); }

    friend class School;
};

#endif