#ifndef UNTITLED1_SCHOOL_H
#define UNTITLED1_SCHOOL_H

#include "AuxiliaryFunctions.h"
#include "treeAnalyser.h"
#include "Layer.h"
#include "Enums.h"
#include "Secretary.h"
#include "Tutor.h"
#include <fstream>


class School {
private:
    static School *BGU;
    vector<Layer *> layers;
    treeAnalyser<Worker *> workers;
    treeAnalyser<Student *> students;
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
    void printWorkers();
    void printStudents();
    Worker *findWorker(const string &name) { return workers[name]; }
    Student *findStudent(const string &name) { return students[name]; }
    bool isExist(string name); // soon

    // statistical methods:
    Student *topStudent() { return students.top(); }
    Worker *topWorker() { return workers.top(); }
    double meanSalary() { return workers.avg(); }
    double meanGPA() { return students.avg(); }
    double medianGPA() { return students.median(); }
    double medianSalary() { return workers.median(); }
};

#endif
