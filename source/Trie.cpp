#include "treeAnalyser.h"
#include "Student.h"

template
class Trie<Student *>;

template
class Trie<Worker *>;

template<class T>
TrieNode<T> *Trie<T>::search(const string &word) {
    TrieNode<T> *node = head;
    for (auto c: word) {
        node = node->get(c);
        if (!node) break;
    }
    return node != nullptr && node->isEnd() ? node : nullptr;
}

template<class T>
void Trie<T>::insert(const T &item) {
    string word = item->fullName();
    TrieNode<T> *node = head;
    for (auto c: word)
        node = node->insert(c);
    node->setEnd();
    node->setItem(item);
}

template<class T>
void Trie<T>::erase(const string &name) {
    TrieNode<T> *node = search(name);
    node->setEnd(false);
}