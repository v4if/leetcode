//
// Created by root on 5/21/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
    Given an unsorted integer array, find the first missing positive integer.

    For example,
    Given [1,2,0] return 3,
    and [3,4,-1,1] return 2.

    Your algorithm should run in O(n) time and uses constant space.
 * */

using namespace std;

class Solution {
public:
//    空间复杂度随着被处理的数据规模而改变
    int firstMissingPositive_On(vector<int>& nums) {
        int *bitmap = new int[128];
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) bitmap[i] = 1;
        }

        for (int j = 1; j < 128; ++j) {
            if (bitmap[j] != 1) return j;
        }

        delete[] bitmap;
    }

//    利用当前数组，省去开辟bitmap的空间，空间复杂度转换为O(1)
//    把数组中的元素放入到合适的位置 nums[i] = i + 1 如 nums[0] = 1
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 1;

        for (int i = 0; i < len; ++i) {
            while (nums[i] != i + 1) {
                if (nums[i] >= len || nums[i] <= 0 || nums[i] == nums[nums[i] - 1]) break;

                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int j = 0; j < len; ++j) {
            if (nums[j] != j + 1) return j + 1;
        }

        return len + 1;
    }
};

TEST(leetcode, first_missing_positive) {
    vector<int> nums = {3, 4, -1, 1};
    EXPECT_EQ(2, Solution().firstMissingPositive(nums));
}