#ifndef MAIN_CPP_TIMER_H
#define MAIN_CPP_TIMER_H

#include <iostream>
#include <chrono>
#include <utility>
#include "string"

using namespace std;

struct Timer {
    std::chrono::time_point<chrono::system_clock> start, end;
    std::chrono::duration<double> duration{};
    const string title;
    explicit Timer(string title = "NULL"): title(std::move(title)) {
        start = chrono::high_resolution_clock::now();
    }

    ~Timer() {
        end = chrono::high_resolution_clock::now();
        duration = end - start;
        cout << "\n\tfunction: " << title;
        cout << " | elapsed time: " << duration.count() << " [seconds]\n";
    }
};

#endif //MAIN_CPP_TIMER_H