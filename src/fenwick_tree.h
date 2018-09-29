#include "header.h"
#include "./utils/print_utils.h"
#include <type_traits>

template<typename T>
class Fenwick {
    // static_assert(std::is_base_of<int, T>::value, "T must be of type");

    private:
        T n;
        std::vector<T> v;

    public:
        explicit Fenwick(T n);
        Fenwick(const Fenwick&) = delete;
        Fenwick& operator=(Fenwick const&) = delete;

        void update(T i, T val);
        T rangeSum(T i);
};

template<typename T>
Fenwick<T>::Fenwick(T n):n(n), v(n, 0){
}

template<typename T>
void Fenwick<T>::update(T i, T val){
    for (; i <= n; i += i&-i){
        v[i-1] += val;
    }
}

template<typename T>
T Fenwick<T>::rangeSum(T i){
    T sum = 0;
    for(; i > 0; i -= i&-i)
        sum += v[i-1];
    return sum;
}
