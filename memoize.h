#ifndef MEMOIZE_H
#define MEMOIZE_H

#include "header.h"


template < typename T >
class Memoize
{

  template < typename... Args >
  static auto memoizeFunc(Args&&... args) -> decltype(T::memoizeFunc(std::forward(Args)(args)...))
  {
    {
        /* Create a static map variable with
        key type = type of tuple of argument type passed in
        value type = return type of function that's been memoized
        */
        static std::map< std::tuple<Args...>, decltype(T::memoizeFunc(std::forward<Args>(args)...)) > repository;
        auto key = std::make_tuple(std::forward<Args>(args)...);
        auto it = repository.find(key);
        if (it != repository.end())
        {
            return it->second;
        }
        else
        {
            auto result = T::Func(std::forward<Args>(args)...);
            repository[key] = result;
            return result;
        }
    }
  }
};

#endif
