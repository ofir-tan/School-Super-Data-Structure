#ifndef MAIN_CPP_MEDIANFINDER_H
#define MAIN_CPP_MEDIANFINDER_H

#include "PriorityQueue.h"
#include "Comparators.h"

template<class T>

class MedianFinder {
private:
    PriorityQueue<T, Comp> maxHeap;
    PriorityQueue<T, Comp> minHeap;
    void balance();
public:
    // constructor:
    MedianFinder() : minHeap(true) {};
    
    // method's:
    void insert(T item);
    void erase(T item);

    double findMedian() {
        return minHeap.size() > maxHeap.size() ? +*minHeap.top() : ((double) +*maxHeap.top() + +*minHeap.top()) * 0.5;
    }
};

#endif //MAIN_CPP_MEDIANFINDER_H
