//
// Created by root on 5/14/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
 * */

/*
 * 旋转有序数组 二分法的本质是每次二分之后如何确定选择哪一半边
 * */

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo, hi;
        lo = 0;
        hi = nums.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] == target) return mid;

//            左侧有序
            if (nums[lo] <= nums[mid]) {
                if (nums[lo] <= target && target <= nums[mid]) hi = mid - 1;
                else lo = mid + 1;
            } else {
//                右侧有序
                if (nums[mid] <= target && target <= nums[hi]) lo = mid + 1;
                else hi = mid - 1;
            }
        }

        if (lo == hi) return nums[lo] == target ? lo : -1;
        else return -1;
    }
};

TEST(leetcode, search_in_rotated_sorted_array) {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2, 3};
    EXPECT_EQ(5, Solution().search(nums, 1));

    nums = {1};
    EXPECT_EQ(0, Solution().search(nums, 1));

    nums = {1, 3};
    EXPECT_EQ(-1, Solution().search(nums, 2));

    nums = {3, 1};
    EXPECT_EQ(1, Solution().search(nums, 1));

    nums = {5, 1, 3};
    EXPECT_EQ(2, Solution().search(nums, 3));

    nums = {4,5,6,7,8,1,2,3};
    EXPECT_EQ(4 , Solution().search(nums, 8));
}