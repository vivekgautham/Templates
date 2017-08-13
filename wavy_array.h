#ifndef WAVY_ARRAY_H
#define WAVY_ARRAY_H
#include "header.h"

template < typename Iter, typename CmpType=std::less<typename std::iterator_traits<Iter>::value_type> >
void wavify(Iter begin, Iter end, CmpType lessThanComp={})
{
    if (begin == end || std::distance(begin, end) <= 2)
      return;
    std::sort(begin, end, lessThanComp);
    unsigned size = std::distance(begin, end);
    Iter curr = begin;
    for (unsigned i=1; i<size; i++)
    {
      if ((i%2 == 0 && lessThanComp(*curr, *std::prev(curr))) || (i%2 == 1 && !lessThanComp(*curr, *std::prev(curr))))
      {
        std::iter_swap(curr, std::prev(curr));
      }
      std::advance(curr, 1);
    }

}

#endif
