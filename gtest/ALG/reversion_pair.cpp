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
    int reversionPair(int nums[], int n) {
        int *temp = new int[n];

        int ans;
        R_divideAndConquer(nums, 0, n - 1, temp, ans);

        delete[] temp;
        return ans;
    }

    void R_divideAndConquer(int nums[], int begin, int end, int temp[], int& ans) {
        if (begin < end) {
            int mid = (begin + end) / 2;
//            left half
            R_divideAndConquer(nums, begin, mid, temp, ans);
//            right half
            R_divideAndConquer(nums, mid + 1, end, temp, ans);
//            merge and storage the change
            ans += R_mergeArray(nums, begin, mid, end, temp);
        }
    }

    int R_mergeArray(int nums[], int begin, int mid, int end, int temp[]) {
        int ans = 0,
            i = begin,
            j = mid + 1,
            k = 0,
            m = 0;

        while (i <= mid && j <= end) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
//                前有序交换个数
                ans += mid + 1 - i;
                temp[k++] = nums[j++];
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

        return ans;
    }
};

TEST(ALG, reversion_pair) {
    int samples[] = {7, 3, 1, 2, 5, 2};

    int n = sizeof(samples) / sizeof(int);
//    sample传参过去就是指针，只能获取指针的长度
    EXPECT_EQ(9, Solution().reversionPair(samples, n));
}