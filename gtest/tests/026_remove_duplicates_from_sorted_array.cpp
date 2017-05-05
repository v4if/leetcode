//
// Created by root on 5/6/17.
//

#include <iostream>
#include <unordered_map>
#include <gtest/gtest.h>

/*
    Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
    Do not allocate extra space for another array, you must do this in place with constant memory.

    For example,
        Given input array nums = [1,1,2],
        Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
        It doesn't matter what you leave beyond the new length.

// 有序，只需要比较相邻两个是否相等
    int count = 0;
    for(int i = 1; i < n; i++){
        if(A[i] == A[i-1]) count++;
        else A[i-count] = A[i];
    }
    return n-count;
 * */

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int ret = nums.size();
        unordered_map<int, int> unique;
        for (auto ite = nums.begin(); ite != nums.end();) {
            if (unique.find(*ite) != unique.end()) {
//                删除之后自动指向下一个
                nums.erase(ite);
                --ret;
            } else {
                unique[*ite] = *ite;
                ++ite;
            }
        }

        return ret;
    }
};

TEST(leetcode, remove_duplicates_from_sorted_array) {
    vector<int> nums = {1, 1};
    EXPECT_EQ(1, Solution().removeDuplicates(nums));
}