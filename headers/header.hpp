//
// Created by mocurin on 30.11.2020.
//

#ifndef ADS_HEADER_HPP
#define ADS_HEADER_HPP

#include <algorithm>
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


template <class RandomIt, class SeqGenerator = size_t(*)(size_t), class Compare = std::less<>>
void shell_sort(RandomIt first, RandomIt last,
                Compare cmp = Compare{},
                SeqGenerator gen = [](size_t prev) -> size_t { return prev / 2; }) {
    for (auto step = gen(std::distance(first, last)); step > 0; step = gen(step)) {
        for (size_t offset = 0; offset < step; ++offset) {
            for (auto outer_it = first + offset + step; outer_it < last; outer_it += step) {
                for (auto inner_it = outer_it;
                     inner_it > first + offset &&
                     cmp(*inner_it, *(inner_it - step));
                     inner_it -= step) {
                    std::iter_swap(inner_it, inner_it - step);
                }
            }
        }
    }
}

template <typename RandomIt, typename Compare = std::less<>>
void merge_sort(RandomIt first, RandomIt last, Compare cmp = Compare{}) {
    if (first == last || std::next(first) == last) return;
    auto it = first + std::distance(first, last) / 2;
    merge_sort(first, it, cmp);
    merge_sort(it, last, cmp);
    std::inplace_merge(first, it, last, cmp);
}

#endif //ADS_HEADER_HPP
