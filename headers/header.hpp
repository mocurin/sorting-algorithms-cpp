//
// Created by mocurin on 30.11.2020.
//

#ifndef ADS_HEADER_HPP
#define ADS_HEADER_HPP

#include <iterator>


template <class BidirectionalIt, class Compare = std::less<>>
void bubble_sort(BidirectionalIt first, BidirectionalIt last, Compare cmp = Compare{}) {
    // пустой рендж
    if (first == last) return;
    auto init_it = std::next(first);
    // рендж длины 1
    while (init_it != last) {
        // оптимизация для отсортированных данных
        auto changed = false;
        for (auto it = init_it; it != last; ++it) {
            // итератор может быть односторонним, если смотреть следующий элемент, а не предыдущий
            // TODO(mocurin): использовать односторонние итераторы
            auto prev_it = std::prev(it);
            if (cmp(*it, *prev_it)) {
                std::iter_swap(it, prev_it);
                changed = true;
            }
        }
        if (!changed) return;
        --last;
    }
}

template <class BidirectionalIt, class Compare = std::less<>>
void insertion_sort(BidirectionalIt first, BidirectionalIt last, Compare cmp = Compare{}) {
    // пустой рендж
    if (first == last) return;
    // рендж длины 1
    for (auto outer_it = std::next(first); outer_it != last; ++outer_it) {
        for (auto inner_it = outer_it;
             outer_it != first && cmp(*inner_it, *std::prev(inner_it));
             --inner_it) {
            std::iter_swap(inner_it, std::prev(inner_it));
        }
    }
}

#endif //ADS_HEADER_HPP
