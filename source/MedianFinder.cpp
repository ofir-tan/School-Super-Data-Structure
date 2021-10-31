#include "MedianFinder.h"
#include "Student.h"
#include "Worker.h"

template
class MedianFinder<Student *>;

template
class MedianFinder<Worker *>;

template<class T>
void MedianFinder<T>::insert(T item) {
    maxHeap.push(item);
    minHeap.push(maxHeap.top());
    maxHeap.pop();
    balance();
}

template<class T>
void MedianFinder<T>::erase(T item) {
    if (item < minHeap.top())
        maxHeap.pop();
    else
        minHeap.pop();
    balance();

}

template<class T>
void MedianFinder<T>::balance() {

    if (minHeap.size() - maxHeap.size() == 2) {
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }
}

template<class T>
double MedianFinder<T>::findMedian() {
    if (size() == 0) return 0;
    return minHeap.size() > maxHeap.size() ? +*minHeap.top() : ((double) +*maxHeap.top() + +*minHeap.top()) / 2;
}
template<class T>
unsigned int MedianFinder<T>::size() {
    return minHeap.size() + maxHeap.size();
}
