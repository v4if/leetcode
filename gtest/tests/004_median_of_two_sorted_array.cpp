//
// Created by root on 2/25/17.
//

#include <iostream>
#include <vector>
#include <gtest/gtest.h>

/**
    There are two sorted arrays nums1 and nums2 of size m and n respectively.

    Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

    Example 1:
    nums1 = [1, 3]
    nums2 = [2]

    The median is 2.0
    Example 2:
    nums1 = [1, 2]
    nums2 = [3, 4]

    The median is (2 + 3)/2 = 2.5
 */

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() && nums2.empty())
            return 0.0;

        int cnt = nums1.size() + nums2.size();
        int half = cnt / 2;

        if (nums1.empty()) {
            if (cnt % 2 == 0)
                return (nums2[half - 1] + nums2[half]) / 2.0;
            else
                return nums2[half] / 1.0;
        }

        if (nums2.empty()) {
            if (cnt % 2 == 0)
                return (nums1[half - 1] + nums1[half]) / 2.0;
            else
                return nums1[half] / 1.0;
        }

        int prev = 0, next = 0;
//        对有序数列取相对较小遍历
        int index_l = 0, index_r = 0;
        int iter_num1 = nums1[index_l], iter_num2 = nums2[index_r];
        for (int i = 0; i <= half; ++i) {
            if (iter_num1 < iter_num2) {
                prev = next;
                next = iter_num1;

                index_l = index_l < nums1.size() ? index_l + 1 : index_l;
                if (index_l == nums1.size()) {
                    iter_num1 = nums2[nums2.size() - 1];
                } else {
                    iter_num1 = nums1[index_l];
                }
            } else {
                prev = next;
                next = iter_num2;

                index_r = index_r < nums2.size() ? index_r + 1 : index_r;
                if (index_r == nums2.size()) {
                    iter_num2 = nums1[nums1.size() - 1];
                } else {
                    iter_num2 = nums2[index_r];
                }
            }
        }

        if (cnt % 2 == 0) {
            return (prev + next) / 2.0;
        } else {
            return next;
        }
    }
};

TEST(leetcode, mddian_of_two_sorted_array) {
    vector<int> sample1;
    sample1.push_back(1);
    sample1.push_back(3);
    vector<int> sample2;
    sample2.push_back(2);
    EXPECT_FLOAT_EQ(2.0, Solution().findMedianSortedArrays(sample1, sample2));


    vector<int> sample3;
    vector<int> sample4;
    sample4.push_back(1);
    EXPECT_FLOAT_EQ(1.0, Solution().findMedianSortedArrays(sample3, sample4));

    vector<int> sample5;
    sample5.push_back(1);
    sample5.push_back(2);
    vector<int> sample6;
    sample6.push_back(3);
    sample6.push_back(4);
    EXPECT_FLOAT_EQ(2.5, Solution().findMedianSortedArrays(sample5, sample6));

    vector<int> sample7;
    sample7.push_back(1);
    vector<int> sample8;
    sample8.push_back(1);
    EXPECT_FLOAT_EQ(1.0, Solution().findMedianSortedArrays(sample7, sample8));
}