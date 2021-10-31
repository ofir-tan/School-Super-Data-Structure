#include <iostream>
#include <chrono>
#include <thread>
#include "School.h"

using namespace std;

#define PATH (string)"C:/Users/AppTa/Documents/Programming/C++/Project/School-Super-Data-Structure/data/"

int main(int argc, char *argv[]) {
    School *bgu = School::getInstance(Six, Three);

    auto start = chrono::high_resolution_clock::now();

    // demonstration of several methods:
    thread t1([bgu](const string &str) { bgu->importStudents(str); }, PATH + "Students.txt");
    thread t2([bgu](const string &str) { bgu->importWorkers(str); }, PATH);
    t1.join();
    t2.join();

    bgu->info();

    if (bgu->findStudent("Jacki Mickey"))
        bgu->findStudent("Jacki Mickey")->info();

    auto secretary = bgu->getWorkers<Secretary *>();
    for (auto &s: secretary)
        s->info();

    // to comparing times with/without threads:
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "\nExecution Time: " << duration.count() << endl;
    return 0;
}