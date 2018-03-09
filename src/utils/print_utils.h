#ifndef PRINT_H
#define PRINT_H

#include "../header.h"

/* Generic Print Functor, Helpful to print containers */
struct Print { 
    std::ostream& os;
    Print(std::ostream& os) : os(os) {}
    template<typename T>
    void operator()(const T& obj) { os << obj << ' '; }
};

#endif