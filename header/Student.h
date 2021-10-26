#ifndef UNTITLED1_PUPIL_H
#define UNTITLED1_PUPIL_H

#include "Person.h"

class Student : public Person {
private:
    vector<double> grades;
    char layer;
    short classNumber;
public:
    // Constructor:
    Student(string &firstName, string &lastName,
            vector<double> &grades, char layer, short classNumber) : Person(firstName, lastName),
                                                                     grades(grades), layer(layer),
                                                                     classNumber(classNumber) {};
    // getters:
    [[nodiscard]] char getLayer() const { return layer; }
    [[nodiscard]] vector<double> getGrades() const { return grades; }
    [[nodiscard]] int getClassNumber() const { return classNumber; }
    // setters:
    void setLayer(char newLayer) { layer = newLayer; };
    void setGrades(vector<double> &newGrades) { grades = newGrades; }
    void setClaseNumber(const short newClassNumber) { classNumber = newClassNumber; }
    // methods:
    void info() override;
    [[nodiscard]] double avg() const {
        return accumulate(grades.begin(), grades.end(), 0.0) / grades.size();
    }
    bool isOutstanding() override {
        return (avg() > 85 && *min_element(grades.begin(), grades.end()) > 65);
    }
    // operator overloading:
    double operator+() const { return avg(); }
    double operator-() const { return -avg(); }
    bool operator<(const Student &other) const { return this->avg() < other.avg(); }
};

#endif