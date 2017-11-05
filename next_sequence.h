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

template <typename Iter, typename CmpType>
int _firstBadIdx(const Iter begin, const Iter end, CmpType cmp, int initIdx)
{
  if (0 < initIdx && initIdx < std::distance(begin, end)-1)
  {
    if (!cmp(*std::next(begin, initIdx-1), *std::next(begin, initIdx+1)))
    {
      return initIdx - 1;
    }
  }

  for (unsigned i=initIdx+1; i < std::distance(begin, end) -1 ; i++)
  {
    if (!cmp(*std::next(begin, i), *std::next(begin, i+1)))
    {
      return i;
    }
  }
  return -1;
}

template <typename Iter, typename CmpType=std::less<typename std::iterator_traits<Iter>::value_type >>
bool almostIncreasingSequence(const Iter begin, const Iter end, CmpType Comp={})
{
  if (std::distance(begin, end) <= 2)
  {
    return true;
  }
  int firstBadIdx = _firstBadIdx(begin, end, Comp, -1);
  if (firstBadIdx == -1)
  {
    return true;
  }
  if (-1 == _firstBadIdx(begin, end, Comp, firstBadIdx))
  {
    return true;
  }
  if (-1 == _firstBadIdx(begin, end, Comp, firstBadIdx+1))
  {
    return true;
  }
  return false;
}

#endif
