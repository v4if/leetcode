//
// Created by root on 5/12/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
 * */

using namespace std;

/*
1：从后向前比较相邻的两个元素，直到前一个元素小于后一个元素，停止
2：如果已经没有了前一个元素，则说明这个排列是递减的，所以这个排列是没有下一个排列的。

124653这个排列终止情况是上面介绍的第一种，从后向前比较相邻的2个元素，遇到4<6的情况停止。
并且我们可以知道：
1：124653和它的下一个排列的公共前缀为12(因为4653存在下一个排列，所以前面的数字12保持不变)
2：4后面的元素是递减的(上面介绍的终止条件是前一个元素小于后一个元素，这里是4<6)
 * */

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k = -1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                k = i;
                break;
            }
        }
        if (k == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int l = -1;
        for (int i = nums.size() - 1; i > k; i--) {
            if (nums[i] > nums[k]) {
                l = i;
                break;
            }
        }
        swap(nums[k], nums[l]);
        reverse(nums.begin() + k + 1, nums.end());
    }
};

TEST(leetcode, next_permutation) {
    vector<int> nums = {3, 6, 4, 2};
    vector<int> result = {4, 2, 3, 6};

    Solution().nextPermutation(nums);
    EXPECT_EQ(result, nums);
}