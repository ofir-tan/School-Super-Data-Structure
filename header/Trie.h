#ifndef MAIN_CPP_TRIE_H
#define MAIN_CPP_TRIE_H

#include "TrieNode.h"

template<class T>
class Trie {
private:
    TrieNode<T> *head;
public:
    // constructor:
    Trie() : head(new TrieNode<T>()) {};

    // method's:
    void erase(const string &name);
    void insert(const T &item);
    TrieNode<T> *search(const string &word);
};

#endif //MAIN_CPP_TRIE_H