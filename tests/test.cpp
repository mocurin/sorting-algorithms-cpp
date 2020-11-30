//
// Created by mocurin on 30.11.2020.
//

#include <algorithm>
#include <numeric>
#include <random>
#include <vector>

#include "gtest/gtest.h"

#include "header.hpp"

TEST(BubbleSortTest, Test1) {
    std::vector<int> victim(1000);
    std::iota(victim.begin(), victim.end(), 0);
    std::mt19937 rgen(42);
    std::shuffle(victim.begin(), victim.end(), rgen);

    bubble_sort(victim.begin(), victim.end());
    EXPECT_TRUE(is_sorted(victim.begin(), victim.end()));
}

TEST(InsertionSort, Test1) {
    std::vector<int> victim(1000);
    std::iota(victim.begin(), victim.end(), 0);
    std::mt19937 rgen(42);
    std::shuffle(victim.begin(), victim.end(), rgen);

    insertion_sort(victim.begin(), victim.end());
    EXPECT_TRUE(is_sorted(victim.begin(), victim.end()));
}

TEST(ShellSort, Test1) {
    std::vector<int> victim(1000);
    std::iota(victim.begin(), victim.end(), 0);
    std::mt19937 rgen(42);
    std::shuffle(victim.begin(), victim.end(), rgen);

    shell_sort(victim.begin(), victim.end());
    EXPECT_TRUE(is_sorted(victim.begin(), victim.end()));
}

TEST(MergeSort, Test1) {
    std::vector<int> victim(1000);
    std::iota(victim.begin(), victim.end(), 0);
    std::mt19937 rgen(42);
    std::shuffle(victim.begin(), victim.end(), rgen);

    merge_sort(victim.begin(), victim.end());
    EXPECT_TRUE(is_sorted(victim.begin(), victim.end()));
}