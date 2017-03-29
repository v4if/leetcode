//
// Created by root on 3/28/17.
//

#include <iostream>
#include <gtest/gtest.h>

/**
    Bubble Sort 冒泡排序
 */

using namespace std;

class Solution {
public:
    void bubbleSort(int num[], int n) {
        int temp;
        for (int i = 0; i < n ; ++i) {
            for (int j = 0; j < n - i; ++j) {
                if (num[j] > num[j + 1]) {
                    temp = num[j];
                    num[j] = num[j + 1];
                    num[j + 1] = temp;
                }
            }
        }
    }
};

TEST(leetcode, bubble_sort) {
    int samples[] = {7, 3, 1, 2, 5, 2};
    int expect[] = {1, 2, 2, 3, 5, 7};

    int i = 0,
            n = sizeof(samples) / sizeof(int);
//    sample传参过去就是指针，只能获取指针的长度
    Solution().bubbleSort(samples, n);
    while (i < n) {
        EXPECT_EQ(expect[i], samples[i]);
        i++;
    }
}