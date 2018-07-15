#ifndef VECUTILS_H
#define VECUTILS_H

#include "../header.h"

template <typename T>
void trimVector(std::vector<T>& v){
    if (v.size() == v.capacity()){
        return;
    }

    v = std::vector<T>(
        std::make_move_iterator(v.begin()),
        std::make_move_iterator(v.end())
    );
}

#endif