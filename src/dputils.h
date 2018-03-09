#ifndef DPUTILS_H
#define DPUTILS_H

#include "header.h"
#include "matrix.h"

namespace DP {

  template < typename Iter, typename CmpType=std::less<typename std::iterator_traits<Iter>::value_type > >
  size_t longestSubsequence( const Iter begin, const Iter end, CmpType Comp={} )
  {
    size_t len = std::distance(begin, end);
    size_t longestSubSeqLen = len;
    if (len == 0)
    {
      return longestSubSeqLen;
    }
    longestSubSeqLen = 1;
    size_t res = 1;
    for (size_t i=1; i<len; i++)
    {
      res = longestSubsequence(begin, std::next(begin, i));
      if (Comp(*std::next(begin, i-1), *std::prev(end)) && res + 1 > longestSubSeqLen)
      {
        longestSubSeqLen = res + 1;
      }
    }
    return longestSubSeqLen;
  }

  template < typename Iter >
  size_t levenshteinDistance(const Iter begin1, const Iter end1, const Iter begin2, const Iter end2)
  {
    size_t dist1 = size_t(std::distance(begin1, end1));
    size_t dist2 = size_t(std::distance(begin2, end2));

    if (dist1 == 0)
    {
      return dist2;
    }
    if (dist2 == 0) {
      return dist1;
    }

    Matrix<size_t> m(dist1+1, dist2+1);

    for (size_t i=1; i<=m.nRows(); i++)
      m.setValue(i, 1, i-1);

    for (size_t i=1; i<=m.nCols(); i++)
      m.setValue(1, i, i-1);

    size_t x=2;
    size_t y=2;

    for (Iter it1 = begin1; it1 != end1; it1++, x++)
    {
      for (Iter it2 = begin2; it2 != end2; it2++, y++) {
        if (*it1 == *it2)
        {
          m.setValue(x, y, m.getValue(x-1, y-1));
        }
        else
        {
          m.setValue(x, y, 1 + std::min(m.getValue(x-1, y), std::min(m.getValue(x-1, y-1), m.getValue(x, y-1))));
        }
      }
      y = 2;
    }

    return m.getValue(dist1+1, dist2+1);

  }

}

#endif
