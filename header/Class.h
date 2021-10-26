#ifndef MAIN_C___CLASS_H
#define MAIN_C___CLASS_H

#include "Student.h"

class Tutor;

class Class {
private:
    char layer;
    int classNum;
    Tutor *tutor;
    vector<Student *> pupils;
public:
    // constructor:
    Class(char layer, int classNum) : layer(layer), classNum(classNum), tutor(nullptr) {};

    // get & set:
    Tutor *getTutor() { return tutor; }
    [[nodiscard]] char getLayer() const { return layer; }
    [[nodiscard]] int getClassNum() const { return classNum; }
    void setTutor(Tutor *newTutor) { tutor = newTutor; }
    [[nodiscard]] unsigned int getSize() const { return pupils.size(); }

    // method's:
    void operator+=(Student &new_pupil) { pupils.push_back(&new_pupil); };
    Student &operator[](int i) { return *pupils.at(i); }
    int numOfOutstanding();
    double avg();
    void info();
};

#endif //MAIN_C___CLASS_H