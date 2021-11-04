#ifndef MAIN_CPP_PRIORITYQUEUE_H
#define MAIN_CPP_PRIORITYQUEUE_H

#include <iostream>
#include "set"

using namespace std;

template<class T, class C>

class PriorityQueue {
private:
    multiset<T, C> priorityQueue;
    const bool minHeap;
public:
    // constructor:
    explicit PriorityQueue(bool type = false) : minHeap(type) {};
    // method's:
    void erase(T item) { priorityQueue.erase(item); }
    void push(T item) { priorityQueue.insert(item); }
    unsigned int size() { return priorityQueue.size(); }
    T top();
    T pop();
};

#endif //MAIN_CPP_PRIORITYQUEUE_H