#ifndef MAIN_CPP_WORKERSFACTORY_H
#define MAIN_CPP_WORKERSFACTORY_H

#include <fstream>
#include <utility>
#include "Enums.h"

using namespace std;

class WorkersFactory {
private:
    ifstream file;
public:
    explicit WorkersFactory(const string& path){
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
        // creation:
        switch (job) {
            case Tutors:
                return new Tutor(file);
            case Teachers:
                return new Teacher(file);
            case Secretariat:
                return new Secretary(file);
            case Managers:
                return Manager::getInstance(file);
            default :
                return nullptr;
        }
    }
};

#endif //MAIN_CPP_WORKERSFACTORY_H