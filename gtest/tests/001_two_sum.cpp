//
// Created by root on 2/25/17.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <gtest/gtest.h>

/**
    Given an array of integers, return indices of the two numbers such that they add up to a specific target.

    You may assume that each input would have exactly one solution, and you may not use the same element twice.

    Example:
    Given nums = [2, 7, 11, 15], target = 9,

    Because nums[0] + nums[1] = 2 + 7 = 9,
    return [0, 1].
 */

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> hash;
        vector<int> result;

        for (int i = 0; i < nums.size(); ++i) {
            int left = target - nums[i];

            if (hash.find(left) != hash.end()) {
                result.push_back(hash[left]);
                result.push_back(i);

                return result;
            }

            hash[nums[i]] = i;
        }
    }
};

TEST(leetcode, two_sum) {
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);

    vector<int> result;
    result.push_back(0);
    result.push_back(1);

    int target = 9;

    EXPECT_EQ(result, Solution().twoSum(nums, target));
}
