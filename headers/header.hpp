//
// Created by mocurin on 30.11.2020.
//

#ifndef ADS_HEADER_HPP
#define ADS_HEADER_HPP

#include <iterator>

template <class BidirectionalIt, class Compare>
void bubble_sort(BidirectionalIt first, BidirectionalIt last, Compare comp) {
    // check if `last - first == 0 -> seq is empty`
    if (first == last) return;
    // can also be ++first, but i'd wish to change name
    auto init_it = std::next(first);
    // check if `last - first != 1 -> seq is one element long`
    // then check if
    while (init_it != last) {
        auto changed = false;
        for (auto it = init_it; it < last; ++it) {
            auto prev_it = std::prev(it);
            if (comp(*it, *prev_it)) {
                std::iter_swap(it, prev_it);
                changed = true;
            }
        }
        if (!changed) return;
        --last;
    }
}

#endif //ADS_HEADER_HPP
