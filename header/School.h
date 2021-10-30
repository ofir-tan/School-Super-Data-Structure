#ifndef UNTITLED1_SCHOOL_H
#define UNTITLED1_SCHOOL_H

#include "AuxiliaryFunctions.h"
#include "treeAnalyser.h"
#include "Secretary.h"
#include "Layer.h"
#include "Enums.h"
#include "Tutor.h"
#include <mutex>
#include <fstream>

class School {
private:
    static School *BGU;
    vector<Layer *> layers;
    treeAnalyser<Worker *> workers;
    treeAnalyser<Student *> students;

    // mutex:
    mutex mx_student;
    mutex mx_worker;

    // constructor:
    School(quantity numberOfLayers, quantity numberOfClasses);

public:
    static School *getInstance() { return BGU; };
    static School *getInstance(quantity numberOfLayers, quantity numberOfClasses);
    ~School();

    // import data / remove:
    bool importStudents(const string &path);
    bool importWorkers(const string &path);
    bool importWorkers(const string &path, jobs job);

    void eraseWorker(const string &name) { workers -= name; }
    void eraseStudent(const string &name) { students -= name; }

    // basic methods:
    void info();
    void printWorkers();
    void printStudents();
    Worker *findWorker(const string &name) { return workers[name]; }
    Student *findStudent(const string &name) { return students[name]; }
    // RTTI:
    template<typename T>
    vector<T> getWorkers();

    // statistical methods:
    unsigned int workersSize() { return workers.size(); }
    unsigned int studentsSize() { return students.size(); }

    Worker *topWorker() { return workers.top(); }
    Student *topStudent() { return students.top(); }

    double meanGPA() { return students.avg(); }
    double meanSalary() { return workers.avg(); }

    double medianGPA() { return students.median(); }
    double medianSalary() { return workers.median(); }
};

#endif

// template function:
template<typename T>
vector<T> School::getWorkers() {
    vector<T> vec_workers;
    for (const auto&[name, worker]: workers)
        if (dynamic_cast<T>(worker))
            vec_workers.push_back(dynamic_cast<T>(worker));
    return vec_workers;
}

