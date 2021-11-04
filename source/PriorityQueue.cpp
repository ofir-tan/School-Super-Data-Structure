#include "PriorityQueue.h"
#include "Comparators.h"
#include "Student.h"
#include "Worker.h"

template
class PriorityQueue<Student *, Comp>;

template
class PriorityQueue<Worker *, Comp>;

template<class T, class C>
T PriorityQueue<T, C>::pop() {
    if (priorityQueue.empty()) return nullptr;
    auto it = minHeap ? priorityQueue.begin() : --priorityQueue.end();
    T top = *it;
    priorityQueue.erase(it);
    return top;
}

template<class T, class C>
T PriorityQueue<T, C>::top() {
    if (priorityQueue.empty()) return nullptr;
    auto it = minHeap ? priorityQueue.begin() : --priorityQueue.end();
    return *it;
}