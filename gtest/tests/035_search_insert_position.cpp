//
// Created by root on 5/19/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
Given a sorted array and a target value, return the index if the target is found.
If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
 * */

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty()) return 0;

        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi) >> 1;
            if (target > nums[mid]) lo = mid + 1;
            else hi = mid;
        }

        if (lo == hi && nums[lo] == target) return lo;
        else return (target < nums[lo]) ? lo : (lo + 1);
    }
};

TEST(leetcode, search_insert_position) {
    vector<int> nums = {1,3,5,6};
    EXPECT_EQ(2, Solution().searchInsert(nums, 5));
    EXPECT_EQ(1, Solution().searchInsert(nums, 2));
    EXPECT_EQ(4, Solution().searchInsert(nums, 7));
    EXPECT_EQ(0, Solution().searchInsert(nums, 0));

    nums = {1};
    EXPECT_EQ(0, Solution().searchInsert(nums, 0));
}