#ifndef MAIN_CPP_WORKERSFACTORY_H
#define MAIN_CPP_WORKERSFACTORY_H

#include <fstream>
#include <utility>
#include "Enums.h"

using namespace std;

class WorkersFactory {
private:
    ifstream file;
    const string path;
public:
    explicit WorkersFactory(const string& path) : path(path) {
        file.open(path);
        if (file.is_open())
            file.get();
        else
            cout << "Error opening file";
    };
    ~WorkersFactory() { file.close(); }
    ifstream &getFile() { return file; }
    bool done() { return file.eof(); }
    Worker *createWorker(enum jobs job) {
        // common variables:
        string firstName, lastName;
        int yearsOfTeach, yearsOfManage;

        // read from file:
        file >> firstName;
        file >> lastName;
        file >> yearsOfTeach;
        file >> yearsOfManage;

        // creation:
        switch (job) {
            case Tutors:
                return new Tutor(firstName, lastName, yearsOfTeach, yearsOfManage);
            case Teachers:
                return new Teacher(firstName, lastName, yearsOfTeach, yearsOfManage);
            case Secretariat:
                return new Secretary(firstName, lastName, yearsOfTeach, yearsOfManage);
            case Managers:
                return Manager::getInstance(firstName, lastName, yearsOfTeach, yearsOfManage);
            default :
                return nullptr;
        }
    }
};

#endif //MAIN_CPP_WORKERSFACTORY_H