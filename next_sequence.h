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

unsigned long factorial(size_t a)
{
  if (a == 0 || a == 1){
    return 1;
  }
  return a * factorial(a-1);
}

bool _diffByOneChar(const std::string& a, const std::string& b)
{
  if (a.size() != b.size()){
    return false;
  }
  if (a == b){
    return false;
  }
  unsigned short count = 0;
  auto iter1 = a.begin();
  auto iter2 = b.begin();
  while (iter1 != a.end()){
    if (*iter1 != *iter2){
      count++;
    }
    iter1++;
    iter2++;
  }
  if (count == 1){
    return true;
  }
  return false;
}

bool stringsRearrangement(const std::vector<std::string>& l)
{
    /* Is it possible to rearrange the list of strings such
       that, consecutive strings differ by one character */
    std::vector<std::string> c;
    c.assign(l.begin(), l.end());
    unsigned long k = factorial(c.size());
    while (k)
    {
      nextSequence(c.begin(), c.end());

      unsigned short i = 0;
      bool flag = true;
      while (i < c.size()-1){
        if (_diffByOneChar(c[i], c[i+1]) == false){
          flag = false;
          break;
        }
        i++;
      }
      k--;
      if (flag == true){
        return true;
      }
    }
    return false;
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
