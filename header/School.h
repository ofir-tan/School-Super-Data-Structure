#ifndef UNTITLED1_SCHOOL_H
#define UNTITLED1_SCHOOL_H

#include "AuxiliaryFunctions.h"
#include "treeAnalyser.h"
#include "Secretary.h"
#include "Layer.h"
#include "Enums.h"
#include "Tutor.h"
#include <fstream>

class School {
private:
    static School *BGU;
    vector<Layer *> layers;
    treeAnalyser<Worker *> workers;
    treeAnalyser<Student *> students;

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

    vector<Student *> studentCondition(const function<bool(Student *)> &func =
    [](Student *s) { return s->isOutstanding(); }) {
        return students.certainCondition(func);
    }

    vector<Worker *> workerCondition(const function<bool(Worker *)> &func =
    [](Worker *s) { return s->isOutstanding(); }) {
        return workers.certainCondition(func);
    }

    vector<Student *> sortStudent(const function<int(Student *)> &func = [](Student *s) { return s->avg() - 56; },
                                  int size = 45);

    // static method's:
    static void setBaseSalary(int base = 25) { Worker::base = base; }
    static void setBonusTutorSalary(int bonus = 30) { Worker::tutorBonus = bonus; }
};

#endif

// template functions:
template<typename T>
vector<T> School::getWorkers() {
    vector<T> vec_workers;
    for (const auto&[name, worker]: workers)
        if (dynamic_cast<T>(worker))
            vec_workers.push_back(dynamic_cast<T>(worker));
    return vec_workers;
}