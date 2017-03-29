//
// Created by root on 3/28/17.
//

#include <iostream>
#include <gtest/gtest.h>

/**
    Insert Sort 插入排序
 */

using namespace std;

class Solution {
public:
    void insertSort(int num[], int n) {
        int curr, temp;
        for (int i = 1; i < n; ++i) {
            curr = i;
            temp = num[curr];
            while (curr > 0 && temp < num[curr - 1]) {
                num[curr] = num[curr - 1];
                curr--;
            }

            num[curr] = temp;
        }
    }
};

TEST(leetcode, insert_sort) {
    int samples[] = {7, 3, 1, 2, 5, 2};
    int expect[] = {1, 2, 2, 3, 5, 7};

    int i = 0,
            n = sizeof(samples) / sizeof(int);
//    sample传参过去就是指针，只能获取指针的长度
    Solution().insertSort(samples, n);
    while (i < n) {
        EXPECT_EQ(expect[i], samples[i]);
        i++;
    }
}