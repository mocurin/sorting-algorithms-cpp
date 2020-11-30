//
// Created by mocurin on 30.11.2020.
//

#ifndef ADS_HEADER_HPP
#define ADS_HEADER_HPP

#include <algorithm>
#include <iterator>

template <class BidirectionalIt, class Compare = std::less<>>
void bubble_sort(BidirectionalIt first, BidirectionalIt last, Compare cmp = Compare{}) {
    if (first == last) return;
    auto init_it = std::next(first);
    while (init_it != last) {
        auto changed = false;
        for (auto it = init_it; it != last; ++it) {
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
    if (first == last) return;
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
void merge_sort_recursive(RandomIt first, RandomIt last, Compare cmp = Compare{}) {
    if (first == last || std::next(first) == last) return;
    auto it = first + std::distance(first, last) / 2;
    merge_sort_recursive(first, it, cmp);
    merge_sort_recursive(it, last, cmp);
    std::inplace_merge(first, it, last, cmp);
}

template <typename RandomIt, typename Compare = std::less<>>
void merge_sort_iterative(RandomIt first, RandomIt last, Compare cmp = Compare{}) {
    if (first == last) return;
    auto len = std::distance(first, last);
    for (auto step = 1; step < len; step *= 2) {
        for (auto it = first; it < last - step; it += 2 * step) {
            std::inplace_merge(it, it + step, std::min(it + 2 * step, last), cmp);
        }
    }
}

template <typename ForwardIt, typename Compare = std::less<>>
void selection_sort(ForwardIt first, ForwardIt last, Compare cmp = Compare{}) {
    for (auto outer_it = first; outer_it < last; ++outer_it) {
        auto reduce_res = outer_it;
        for (auto inner_it = std::next(outer_it); inner_it < last; ++inner_it) {
            if (cmp(*inner_it, *reduce_res)) {
                reduce_res = inner_it;
            }
        }
        std::iter_swap(outer_it, reduce_res);
    }
}

template <typename RandomIt, typename Compare = std::less<>>
void heap_sort(RandomIt first, RandomIt last, Compare cmp = Compare{}) {
    std::make_heap(first, last, cmp);
    while (first != last) {
        std::pop_heap(first, last--, cmp);
    }
}

#endif //ADS_HEADER_HPP
