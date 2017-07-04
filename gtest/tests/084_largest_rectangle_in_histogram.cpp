//
// Created by root on 2017/7/4.
//

#include <iostream>
#include <gtest/gtest.h>

/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1,
find the area of largest rectangle in the histogram.
 * */

using namespace std;

namespace solve_first {
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) return 0;

        int n = heights.size();

        int largest = 0;
        int dp[n][n];
//        dp 考虑所有组合情况 O(n^3)
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - i; ++j) {
                int min_h = heights[j];
                for (int k = j; k <= j + i; ++k) {
                    min_h = std::min(min_h, heights[k]);
                }
                dp[j][j + i] = min_h * (i + 1);
                largest = std::max(dp[j][j + i], largest);
            }
        }

        return largest;
    }
}

TEST(leetcode, largest_rectangle_in_histogram_test) {
    vector<int> height{2,1,5,6,2,3};
    cout << solve_first::largestRectangleArea(height) << endl;
}