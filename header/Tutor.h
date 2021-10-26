#ifndef MAIN_C___TUTOR_H
#define MAIN_C___TUTOR_H

#include "Teacher.h"
#include "Class.h"

class Tutor : virtual public Teacher {
private:
    Class *class_;
public:
    // constructor::
    Tutor(string &firstName, string &lastName, double yearsOfTeach,
          double yearsOfManage, vector<string> &courses, Class *class_) :
            Worker(firstName, lastName, yearsOfTeach, yearsOfManage),
            Teacher(firstName, lastName, yearsOfTeach, yearsOfManage, courses), class_(class_) {};
    // get & set:
    Class *getClass() { return class_; }
    void setClass(Class *newClass) { class_ = newClass; }
    // methods:
    [[nodiscard]] double getSalary() const override { return tutorBonus + Teacher::getSalary(); };
    bool isOutstanding() override {
        return class_->getSize() && 0.5 >= (double) class_->numOfOutstanding() / class_->getSize();
    }
    void info() override;

};

#endif //MAIN_C___TUTOR_H
