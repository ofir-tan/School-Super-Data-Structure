#include <iostream>
#include <chrono>
#include <thread>
#include "School.h"
#include <bitset>
#include "Timer.h"

using namespace std;

#define PATH (string)"C:/Users/AppTa/Documents/Programming/C++/Project/School-Super-Data-Structure/data/"

int main(int argc, char *argv[]) {
    School &bgu = School::getInstance(Six, Three);

    Timer timer("School"); // timer to measure the speed-up with threads
    // demonstration of several methods:
    thread t1([&](const string &str) { bgu.importStudents(str); }, PATH + "Students.txt");
    thread t2([&](const string &str) { bgu.importWorkers(str); }, PATH);
    t1.join();
    t2.join();

    bgu.info();

    if (bgu.findStudent("Jacki Mickey"))
        bgu.findStudent("Jacki Mickey")->info();

    auto secretary = bgu.getWorkers<Secretary *>();
    for (auto &s: secretary)
        s->info();

    auto f = [](Worker *s) { return s->getSalary() > 10 * 5; };
    auto v = bgu.workerCondition(f);

    return 0;
}