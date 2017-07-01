//
// Created by root on 2017/7/1.
//

#include <iostream>
#include <gtest/gtest.h>

/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent,
with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 * */

using namespace std;

namespace solve_first {
    void sortColors(vector<int>& nums) {
        int p, q, i;
        i = p = 0;
        q = nums.size() - 1;
//        p,q作为红色和蓝色要填充的下个位置，i作为遍历变量直到碰到蓝色边界
        while (i <= q) {
            if (nums[i] == 0) {
                swap(nums[i], nums[p]);
                p++;
                i++;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[q]);
                q--;
            } else {
                i++;
            }
        }
    }
}

TEST(leetcode, leetcode_sort_colors_test) {
    vector<int> nums{1,0};
    solve_first::sortColors(nums);
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
}