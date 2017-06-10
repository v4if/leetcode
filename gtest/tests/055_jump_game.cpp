//
// Created by root on 6/10/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
 * */

using namespace std;

namespace solve_first {
    bool canJump(vector<int>& nums) {
        int scope = nums[0];
        int n = nums.size();
        int i = 1;
        while (scope < n - 1) {
            if (i > scope) return false;

            scope = max(scope, nums[i] + i);
            i++;
        }

        return true;
    }
}

TEST(leetcode, jump_game) {
    vector<int> nums{2,3,1,1,4};
    EXPECT_TRUE(solve_first::canJump(nums));
    nums = {3,2,1,0,4};
    EXPECT_FALSE(solve_first::canJump(nums));
    nums = {0};
    EXPECT_TRUE(solve_first::canJump(nums));
}