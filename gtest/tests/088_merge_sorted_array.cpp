//
// Created by root on 9/12/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
The number of elements initialized in nums1 and nums2 are m and n respectively.
 * */

using namespace std;

namespace solve_first {
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, tar = m + n - 1;
        while (j >= 0) {
            nums1[tar--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
    }
}

TEST(leetcode, leetcode_merge_sorted_array_Test) {
    vector<int> nums1{1, 3, 6};
    vector<int> nums2{3, 4, 7};
    solve_first::merge(nums1, 3, nums2, 3);

    for (int i = 0; i < nums1.size(); ++i) {
        std::cout << to_string(nums1[i]) + "  ";
    }
    std::cout << std::endl;
}