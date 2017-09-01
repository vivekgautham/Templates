#ifndef DPUTILS_H
#define DPUTILS_H
#include "header.h"

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

}

#endif
