#ifndef MAIN_CPP_COMPARATORS_H
#define MAIN_CPP_COMPARATORS_H

struct Comp {
    template<typename T>
    bool operator()(const T &x, const T &y) const {
        return *x < *y;
    }
};

#endif //MAIN_CPP_COMPARATORS_H