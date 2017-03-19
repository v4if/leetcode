//
// Created by root on 3/19/17.
//

#include <iostream>
#include <gtest/gtest.h>

/**
    Divide And Conquer 归并逆序对数
 */

using namespace std;

class Solution {
public:
    int mergeSort(int nums[], int n) {
        int *temp = new int[n];

        int ans = divideAndConquer(nums, 0, n - 1, temp);

        delete[] temp;
        return ans;
    }

    int divideAndConquer(int nums[], int begin, int end, int temp[]) {
        int ans = 0;

        if (begin < end) {
            int mid = (begin + end) / 2;
//            left half
            divideAndConquer(nums, begin, mid, temp);
//            right half
            divideAndConquer(nums, mid + 1, end, temp);
//            merge and storage the change
            mergeArray(nums, begin, mid, end, temp, ans);
        }

        return ans;
    }

    void mergeArray(int nums[], int begin, int mid, int end, int temp[], int &ans) {
        int i = begin,
                j = mid + 1,
                k = 0,
                m = 0;

        while (i <= mid && j <= end) {
            if (nums[i] < nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
                ans += j - i;
            }
        }

//        左半边或者右半边已经遍历完
        while (i <= mid) {
            temp[k++] = nums[i++];
        }

        while (j <= end) {
            temp[k++] = nums[j++];
        }

//        将临时数组拷贝到结果
        while (m < k) {
            nums[begin + m] = temp[m++];
        }
    }
};

TEST(ALG, merge_sort) {
    int samples[] = {7, 3, 1, 2, 5, 2};

    int n = sizeof(samples) / sizeof(int);
//    sample传参过去就是指针，只能获取指针的长度
    EXPECT_EQ(9, Solution().mergeSort(samples, n));
}