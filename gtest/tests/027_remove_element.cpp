//
// Created by root on 5/6/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
    Given an array and a value, remove all instances of that value in place and return the new length.
    Do not allocate extra space for another array, you must do this in place with constant memory.
    The order of elements can be changed. It doesn't matter what you leave beyond the new length.

    Example:
    Given input array nums = [3,2,2,3], val = 3
    Your function should return length = 2, with the first two elements of nums being 2.
 * */

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) return 0;

        int ret = nums.size();

        for (auto ite = nums.begin();ite != nums.end();) {
            if (*ite == val) {
                --ret;
                nums.erase(ite);
            } else {
                ++ite;
            }
        }

        return ret;
    }
};

class SolutionPerfect {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0;
        for(int i = 0 ; i < nums.size() ; ++i) {
            if(nums[i] == val)
                cnt++;
            else
                nums[i-cnt] = nums[i];
        }
        return nums.size()-cnt;
    }
};

TEST(leetcode, remove_element) {
    vector<int> nums = {3, 2, 2, 3};
    EXPECT_EQ(2, Solution().removeElement(nums, 3));
}