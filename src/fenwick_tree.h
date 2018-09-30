#include "header.h"
#include "./utils/print_utils.h"
#include <type_traits>

template<typename T, typename IT=int>
class Fenwick {
    // static_assert(std::is_base_of<int, T>::value, "T must be of type");

    private:
        IT n;
        std::vector<T> v;

    public:
        explicit Fenwick(IT n);
        Fenwick(const Fenwick&) = delete;
        Fenwick& operator=(Fenwick const&) = delete;

        void update(IT i, T val);
        T rangeSum(IT i);
};

template<typename T, typename IT>
Fenwick<T, IT>::Fenwick(IT n):n(n), v(n, 0){
}

template<typename T, typename IT>
void Fenwick<T, IT>::update(IT i, T val){
    for (; i <= n; i += i&-i){
        v[i-1] += val;
    }
}

template<typename T, typename IT>
T Fenwick<T, IT>::rangeSum(IT i){
    T sum = 0;
    for(; i > 0; i -= i&-i)
        sum += v[i-1];
    return sum;
}
