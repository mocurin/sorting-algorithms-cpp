//
// Created by mocurin on 30.11.2020.
//

#include <functional>

#include "misc.hpp"

template <class ForwardIt, class Compare = std::less<>>
bool is_sorted(ForwardIt first, ForwardIt last, Compare cmp = Compare{}) {
    if (first != last) {
        auto next = first;
        while (++next != last) {
            if (cmp(*next, *first)) {
                return false;
            }
            first = next;
        }
    }
    return true;
}