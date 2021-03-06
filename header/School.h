#ifndef UNTITLED1_SCHOOL_H
#define UNTITLED1_SCHOOL_H

#include "AuxiliaryFunctions.h"
#include "treeAnalyser.h"
#include "WorkersFactory.h"
#include "Layer.h"
#include "Tutor.h"
#include "queue"
#include "Worker.h"


class School {
private:
    vector<Layer *> layers;
    treeAnalyser<Worker *> workers;
    treeAnalyser<Student *> students;

    // constructor:
    School(quantity numberOfLayers, quantity numberOfClasses);
    ~School();
public:
    static School &getInstance(quantity numberOfLayers = One, quantity numberOfClasses = One);

    // import data / remove:
    void importStudents(const string &path);
    void importWorkers(const string &path);
    void importWorkers(const string &path, enum jobs job);

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

    vector<Student *> sortStudents(const function<int(Student *)> &func = [](Student *s) { return s->avg() - 56; },
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