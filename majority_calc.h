#ifndef MAJORITY_CALC_H
#define MAJORITY_CALC_H
#include "header.h"

template < typename Iter, typename CmpType=std::equal_to<typename std::iterator_traits<Iter>::value_type> >
Iter majorityElement(Iter begin, Iter end, CmpType eq={}, float threshold=0.51)
{
  assert(threshold > 0.5);
  Iter majorityElement = end;
  size_t counter = 0, matches=0, total=0;

  for (Iter it=begin; it != end; it++)
  {
    if (counter == 0)
    {
      majorityElement = it;
      counter++;
    }
    else
    {
      if (eq(*majorityElement, *it))
      {
        counter++;
      }
      else
      {
        counter--;
      }
    }
  }
  for (Iter it=begin; it != end; it++)
  {
    if (eq(*majorityElement, *it))
      matches++;
    total++;
  }
  return float(matches)/float(total) >= threshold ? majorityElement : end;
}

#endif
