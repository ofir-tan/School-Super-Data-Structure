#include "MedianFinder.h"
#include "Student.h"
#include "Worker.h"
#include "Comparators.h"

template
class MedianFinder<Student *, Comp>;

template
class MedianFinder<Worker *, Comp>;

template<class T, class C>
void MedianFinder<T, C>::insert(T item) {
    maxHeap.push(item);
    minHeap.push(maxHeap.top());
    maxHeap.pop();
    balance();
}

template<class T, class C>
void MedianFinder<T, C>::erase(T item) {
    if (item < minHeap.top())
        maxHeap.pop();
    else
        minHeap.pop();
    balance();
}

template<class T, class C>
void MedianFinder<T, C>::balance() {

    if (minHeap.size() - maxHeap.size() == 2) {
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }
}

template<class T, class C>
double MedianFinder<T, C>::findMedian() {
    if (size() == 0) return 0;
    return minHeap.size() > maxHeap.size() ? +*minHeap.top() : ((double) +*maxHeap.top() + +*minHeap.top()) / 2;
}

template<class T, class C>
size_t MedianFinder<T, C>::size() {
    return minHeap.size() + maxHeap.size();
}
