#ifndef PAIRING_H
#define PAIRING_H

template <typename ForwardIterator, typename Functor>
Functor for_each_adjpair(ForwardIterator begin, ForwardIterator end, Functor f)
{
    if (begin != end)
    {
        ForwardIterator t = begin++;
        for (; begin != end; begin++, t++)
        {
            f(*t, *begin);
        }
    }
    return f;
}

template <typename ForwardIterator, typename Functor>
Functor for_all_pairs(ForwardIterator begin, ForwardIterator end, Functor f)
{
    if (begin != end)
    {
        ForwardIterator t = begin++;
        for (; begin != end; begin++, t++)
        {
            for (ForwardIterator temp = begin; temp != end; temp++)
            {
                f(*t, *temp);
            }
        }
    }
    return f;
}

#endif