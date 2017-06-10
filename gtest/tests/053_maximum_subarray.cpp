//
// Created by root on 6/10/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 * */

using namespace std;

namespace solve_first {
// dp[i]代表以第i个元素结尾的最大子序列和
//    动态方程：dp[i] = dp[i - 1] > 0 ? dp[i - 1] + nums[i] : nums[i]
//    max代表第i个元素之前（包括）全局最大子序列和
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int* dp = new int[n];

        int max = nums[0];
        dp[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = dp[i - 1] > 0 ? dp[i - 1] + nums[i] : nums[i];
            max = std::max(max, dp[i]);
        }

        return max;
    }
}

TEST(leetcode, maximum_subarray) {
    vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    EXPECT_EQ(6, solve_first::maxSubArray(nums));
}