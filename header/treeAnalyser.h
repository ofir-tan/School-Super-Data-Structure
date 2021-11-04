#ifndef MAIN_C___TREEANALYSER_H
#define MAIN_C___TREEANALYSER_H

#include "PriorityQueue.h"
#include "MedianFinder.h"
#include "Comparators.h"
#include <functional>
#include "Manager.h"
#include "Trie.h"
#include "map"

template<class T>

class treeAnalyser {
private:
    double averageVal;
    // data structures:
    Trie<T> dict;
    map<string, T> treeMap;
    PriorityQueue<T, Comp> pq;
    MedianFinder<T, Comp> medianFinder;
public:
    treeAnalyser() : averageVal(0) {};
    ~treeAnalyser();

    // iterators:
    auto end() { return treeMap.end(); }
    auto begin() { return treeMap.begin(); }

    // method's:
    void print();
    void insert(T &ptr);
    void erase(string key);
    T find(const string &name);

    // statistical methods:
    T top() { return pq.top(); }
    double avg() { return averageVal; }
    unsigned int size() { return treeMap.size(); }
    double median() { return medianFinder.findMedian(); }
    vector<T> certainCondition(const function<bool(T item)> &func);

    // operator overloading:
    void operator+=(T ptr) { insert(ptr); }
    void operator-=(string key) { erase(key); }
    T operator[](string name) { return find(name); }
};

#endif //MAIN_C___TREEANALYSER_H
