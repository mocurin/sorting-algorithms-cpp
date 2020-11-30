//
// Created by mocurin on 30.11.2020.
//

#include <algorithm>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

#include "gtest/gtest.h"

#include "header.hpp"

TEST(BubbleSortTest, Test1) {
    std::vector<int> victim(1000);
    std::iota(victim.begin(), victim.end(), 0);
    std::vector<int> target(victim);
    std::mt19937 rgen(42);
    std::shuffle(victim.begin(), victim.end(), rgen);

    bubble_sort(victim.begin(), victim.end(), std::less<>());
    for (size_t i = 0; i < target.size(); ++i) {
        EXPECT_EQ(victim[i], target[i]);
    }
}