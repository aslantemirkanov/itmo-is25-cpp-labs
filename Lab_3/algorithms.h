#include <iostream>

#ifndef CIRCULAR_BUFFER_ALGORITHMS_H
#define CIRCULAR_BUFFER_ALGORITHMS_H


template<typename TInputIterator, typename TPredicate>
bool my_all_of(TInputIterator begin, TInputIterator end, TPredicate f) {
    while (begin != end) {
        if (!f(*begin)) {
            return false;
        }
        ++begin;
    }
    return true;
}

template<typename TIterator, typename TPredicate>
bool my_any_of(TIterator begin, TIterator end, TPredicate f) {
    while (begin != end) {
        if (f(*begin)) {
            return true;
        }
        ++begin;
    }
    return false;
}

template<typename TInputIterator, typename TPredicate>
bool my_none_of(TInputIterator begin, TInputIterator end, TPredicate f) {
    while (begin != end) {
        if (f(*begin)) {
            return false;
        }
        ++begin;
    }
    return true;
}

template<typename TInputIterator, typename TPredicate>
bool my_one_of(TInputIterator begin, TInputIterator end, TPredicate f) {
    size_t count = 0;
    while (begin != end) {
        if (f(*begin)) {
            ++count;
            if (count > 1) {
                count = 2;
                break;
            }
        }
        ++begin;
    }
    return (count == 1);
}

template<typename TInputIterator, typename TPredicate>
bool my_is_sorted(TInputIterator begin, TInputIterator end, TPredicate f) {
    TInputIterator prev_it = begin;
    if (begin != end) {
        ++begin;
    }
    while (begin != end) {
        if (!f(prev_it, begin)) {
            return false;
        }
        ++prev_it;
        ++begin;
    }
    return true;
}

template<typename TInputIterator, typename TPredicate>
bool my_is_partitioned(TInputIterator begin, TInputIterator end, TPredicate f) {
    bool exist = true;
    bool was = false;
    bool prev = f(*begin);
    ++begin;
    for (; begin != end; ++begin) {
        bool cur = f(*begin);
        if (cur != prev) {
            if (was) return false;
            else was = true;
            prev = cur;
        }
    }
    return true;
}

template<typename TInputIterator, typename T>
TInputIterator my_find_not(TInputIterator begin, TInputIterator end, T value) {
    for (; begin != end; ++begin) {
        if ((*begin) != value)
            return begin;
        ++begin;
    }
    return end;
}

template<typename TInputIterator, typename T>
TInputIterator my_find_backward(TInputIterator begin, TInputIterator end, T value) {
    TInputIterator ans = begin;
    for (; begin != end; ++begin) {
        if ((*begin) == value)
            ans = begin;
        ++begin;
    }
    return ans;
}

template<typename TInputIterator, typename TPredicate>
bool my_is_palindrome(TInputIterator begin, TInputIterator end, TPredicate f) {
    if (begin - end > 1) {
        --end;
        while (begin != end) {
            if (!f(*begin, *end)) return false;
            ++begin;
            --end;
        }
        return true;
    }else{
        return true;
    }
}


#endif
