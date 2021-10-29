#ifndef MAIN_CPP_TRIENODE_H
#define MAIN_CPP_TRIENODE_H
#define CHAR ' ' // first char in trie vector nodes
#define AB_SIZE 91 // Alphabet size of trie

#include "vector"
#include "string"

using namespace std;

template<class T>
class TrieNode {
    vector<TrieNode *> links;
    bool end = false;
    T item;
public:
    TrieNode() : links({AB_SIZE, nullptr}) {};
    ~TrieNode();

    TrieNode *insert(char c);
    T getItem() { return item; }
    void setEnd(bool isEnd = true) { end = isEnd; }
    void setItem(const T &newItem) { item = newItem; }
    TrieNode *get(char c) { return links[c - CHAR]; }
    [[nodiscard]] bool isEnd() const { return end; }
};

#endif //MAIN_CPP_TRIENODE_H