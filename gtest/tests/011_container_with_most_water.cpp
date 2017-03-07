//
// Created by root on 2/27/17.
//

#include <iostream>
#include <gtest/gtest.h>

/**
    Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

    Note: You may not slant the container and n is at least 2.
*/

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int maxArea = 0;
//        头尾双向指针向中间移动
        while (l < r) {
//            l、r之间无线段
            int area = min(height[l], height[r]) * (r - l);
            if (area > maxArea) {
                maxArea = area;
            }

//            短板在l
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }

        return maxArea;
    }
};

TEST(leetcode, container_with_most_water) {
    vector<int> sample;
    sample.push_back(0);
    sample.push_back(2);
    EXPECT_EQ(0, Solution().maxArea(sample));
}