#ifndef UNTITLED1_LAYER_H
#define UNTITLED1_LAYER_H

#include "Class.h"

class Layer {
private:
    char layer;
    vector<Class *> classes;
public:
    // Constructors Signature:
    explicit Layer(char layer) : layer(layer) {};
    ~Layer();
    // get & set:
    Class *getClass(int i) { return classes[i]; }
    void addClass(Class *newClass) { classes.push_back(newClass); }
    // operator's:
    void operator+=(Class *newClass) { addClass(newClass); }
    Class *operator[](int i) { return getClass(i); }
};

#endif //UNTITLED1_LAYER_H