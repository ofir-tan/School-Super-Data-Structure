#include <iostream>


int main() {
    singleton_t &s = singleton_t::instance(5, 7);
    std::cout << s.a << " " << s.b << std::endl;
    singleton_t &f = singleton_t::instance(4, 10);
    std::cout << s.a << " " << s.b << std::endl;
    return 0;
}