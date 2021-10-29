#include "TrieNode.h"

#include "treeAnalyser.h"
#include "Student.h"

template
class TrieNode<Student *>;

template
class TrieNode<Worker *>;

template<class T>
TrieNode<T> *TrieNode<T>::insert(char c) {
    if (!links[c - CHAR])
        links[c - CHAR] = new TrieNode();
    return links[c - CHAR];
}

template<class T>
TrieNode<T>::~TrieNode() {
    for (auto &link: links)
        delete link;
}
