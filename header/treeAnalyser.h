#ifndef MAIN_C___TREEANALYSER_H
#define MAIN_C___TREEANALYSER_H

#include <queue>
#include "map"
#include "Manager.h"
#include "PriorityQueue.h"
#include "MedianFinder.h"

template<class T>

class treeAnalyser {
private:
    map<string, T> treeMap;
    PriorityQueue<T, Comp> pq;
    MedianFinder<T> medianFinder;
    double averageVal;
public:
    treeAnalyser() : averageVal(0) {};
    ~treeAnalyser();
    // method's:
    void print();
    void insert(T &ptr);
    void erase(string key);
    T &find(string name) { return treeMap[name]; }

    // statistical methods:
    T top() { return pq.top(); }
    double avg() { return averageVal; }
    double median() { return medianFinder.findMedian(); }

    // operator overloading:
    void operator+=(T ptr) { insert(ptr); }
    void operator-=(string key) { erase(key); }
    T &operator[](string name) { return find(name); }
};

#endif //MAIN_C___TREEANALYSER_H