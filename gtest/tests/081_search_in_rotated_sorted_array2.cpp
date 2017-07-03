//
// Created by root on 2017/7/3.
//

#include <iostream>
#include <gtest/gtest.h>

/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Write a function to determine if a given target is in the array.

The array may contain duplicates.
 * */

using namespace std;

namespace solve_first {
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0) return false;

        int p = 0, q = nums.size() - 1;
        while (p < q) {
            int r = p + (q - p) / 2;
            if (nums[r] == target) return true;

            if (nums[p] < nums[r]) {
                if (target >= nums[p] && target <= nums[r]) q = r - 1;
                else p = r + 1;
            } else if (nums[p] > nums[r]){
                if (target >= nums[r] && target <= nums[q]) p = r + 1;
                else q = r - 1;
            } else {
//                如果全部都是一个元素，或者只有一个元素不同于其他元素，恰好在最后一个，时间复杂度就会降为O(n)
                p++;
            }
        }

        return nums[p] == target;
    }
}

TEST(leetcode, search_in_rotated_sorted_array2) {
    vector<int> nums{1,3,1,1,1};
    cout << solve_first::search(nums, 3) << endl;
}