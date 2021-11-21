#ifndef MAIN_C___TUTOR_H
#define MAIN_C___TUTOR_H

#include "Teacher.h"
#include "Class.h"
#include <fstream>

class Tutor : virtual public Teacher {
private:
    char layer{};
    int classNum{};
    Class *class_;
public:
    // constructor::
    Tutor(string &firstName, string &lastName, double yearsOfTeach,
          double yearsOfManage, Class *class_ = nullptr) :
            Worker(firstName, lastName, yearsOfTeach, yearsOfManage),
            Teacher(firstName, lastName, yearsOfTeach, yearsOfManage), class_(class_) {};

    // get & set:
    Class *getClass() { return class_; }
    void setClass(Class *newClass) { class_ = newClass; }
    // methods:
    [[nodiscard]] double getSalary() const override { return tutorBonus + Teacher::getSalary(); };
    bool isOutstanding() override {
        return class_->getSize() && 0.5 >= (double) class_->numOfOutstanding() / class_->getSize();
    }
    void importData(ifstream &file) override;
    void info() override;
};

#endif //MAIN_C___TUTOR_H
