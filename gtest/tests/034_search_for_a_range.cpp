//
// Created by root on 5/19/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
 * */

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return vector<int>{-1, -1};

        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] == target) break;

            if (nums[mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }

        int equal = (lo == hi) ? lo : (lo + hi) / 2;
        if (nums[equal] != target) return vector<int>{-1, -1};

        int left, right;
        left = right = equal;
        while (left > 0) {
            if (nums[left - 1] == target) left--;
            else break;
        }
        while (right < nums.size() - 1) {
            if (nums[right + 1] == target) right++;
            else break;
        }

        return vector<int>{left, right};
    }
};

TEST(leetcode, search_for_a_range) {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    vector<int> result = {3, 4};

    EXPECT_EQ(result, Solution().searchRange(nums, 8));
}