#include "treeAnalyser.h"
#include "Student.h"

template
class treeAnalyser<Student *>;

template
class treeAnalyser<Worker *>;

template<class T>
void treeAnalyser<T>::print() {
    for (const auto&[key, value]: treeMap)
        value->info();
    cout << endl;
}

template<class T>
treeAnalyser<T>::~treeAnalyser() {
    for (const auto&[key, value]: treeMap)
        delete value;
}

template<class T>
void treeAnalyser<T>::erase(string key) {
    averageVal = (averageVal * treeMap.size() + (-*treeMap[key])) / (treeMap.size() + 1);
    treeMap.erase(treeMap.find(key));
    medianFinder.erase(treeMap[key]);
    dict.erase(key);
    pq.erase(treeMap[key]);

}

template<class T>
void treeAnalyser<T>::insert(T &ptr) {
    averageVal = (+*ptr + averageVal * treeMap.size()) / (treeMap.size() + 1);
    treeMap[ptr->fullName()] = ptr;
    medianFinder.insert(ptr);
    dict.insert(ptr);
    pq.push(ptr);
}
template<class T>
T treeAnalyser<T>::find(const string &name) {
    TrieNode<T> *node = dict.search(name);
    return node ? node->getItem() : nullptr;
}