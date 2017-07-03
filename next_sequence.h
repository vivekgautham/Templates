#ifndef NEXT_SEQ_H
#define NEXT_SEQ_H

#include "header.h"

template <typename ForwardIterator>
ForwardIterator sortedUntil(ForwardIterator begin, ForwardIterator end)
{
  if (begin == end)
    return end;

  ForwardIterator until = begin;
  ++until;

  if (until == end)
    return end;

  for (;until != end; ++until, ++begin)
  {
    if (*until < *begin)
    {
      return until;
    }
  }
  return end;
}

template <typename BidirectionalIterator>
bool nextSequence(BidirectionalIterator begin, BidirectionalIterator end)
{
  if (begin == end)
    return false;

  typedef std::reverse_iterator<BidirectionalIterator> ReverseIterator;

  ReverseIterator rbegin(end), rend(begin);
  ReverseIterator crossoverIter = sortedUntil(rbegin, rend);
  if (crossoverIter == rend)
  {
    std::reverse(begin, end);
    return false;
  }
  std::iter_swap(crossoverIter, std::upper_bound(rbegin, crossoverIter, *crossoverIter));
  std::reverse(rbegin, crossoverIter);
  return true;
}

#endif
