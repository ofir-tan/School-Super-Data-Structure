#ifndef MAIN_C___TEACHER_H
#define MAIN_C___TEACHER_H

#include "Worker.h"

class Teacher : virtual public Worker {
protected:
    vector<string> courses;
public:
    Teacher(string &firstName, string &lastName,
            double yearsOfTeach, double yearsOfManage,
            vector<string> &courses) :
            Worker(firstName, lastName, yearsOfTeach, yearsOfManage), courses(courses) {}

    // methods:
    [[nodiscard]] unsigned int getNumOfCurses() const { return courses.size(); }
    [[nodiscard]] double getSalary() const override {
        return basis * (1 + (double) courses.size() / 10) + 300 * yearsOfTeach;
    }
    bool isOutstanding() override { return 4 < courses.size(); }
    void printCourses();
    void info() override;
};

#endif //MAIN_C___TEACHER_H