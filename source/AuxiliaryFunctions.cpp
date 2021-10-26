#include "AuxiliaryFunctions.h"

bool isNumber(const string &s) {
    return all_of(s.begin(), s.end(),
                  [](char c) { return isdigit(c) != 0; });
}

vector<string> stringToWords(string const &str, const char delim) {
    vector<string> res;
    // construct a stream from the string
    stringstream ss(str);
    string s;
    while (getline(ss, s, delim)) {
        res.push_back(s);
    }
    return res;
}