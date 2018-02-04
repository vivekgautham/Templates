#ifndef WAVY_ARRAY_H
#define WAVY_ARRAY_H
#include "header.h"

template < typename Iter, typename CmpType=std::less<typename std::iterator_traits<Iter>::value_type> >
void wavify(Iter begin, Iter end, CmpType lessThanComp={})
{
    if (begin == end || std::distance(begin, end) <= 2)
      return;

    unsigned size = std::distance(begin, end);
    Iter curr = begin;
    for (unsigned i=0; i<size; i+=2)
    {
      if ( i > 0 && lessThanComp(*curr, *std::prev(curr)) )
      {
        std::iter_swap(curr, std::prev(curr));
      }
      if ( i < size-1 && lessThanComp(*curr, *std::next(curr)) )
      {
        std::iter_swap(curr, std::next(curr));
      }
      std::advance(curr, 2);
    }

}

#endif
