#ifndef MAIN_CPP_MEDIANFINDER_H
#define MAIN_CPP_MEDIANFINDER_H

#include "PriorityQueue.h"

template<class T, class C>

class MedianFinder {
private:
    PriorityQueue<T, C> maxHeap;
    PriorityQueue<T, C> minHeap;
    void balance();
public:
    // constructor:
    MedianFinder() : minHeap(true) {};

    // method's:
    void insert(T item);
    void erase(T item);
    double findMedian();
    size_t size();
};

#endif //MAIN_CPP_MEDIANFINDER_H