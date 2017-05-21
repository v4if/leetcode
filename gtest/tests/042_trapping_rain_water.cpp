//
// Created by root on 5/21/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
    Given n non-negative integers representing an elevation map where the width of each bar is 1,
    compute how much water it is able to trap after raining.

    For example,
    Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 * */

/*
 * 是否能蓄水取决于相邻左右两边最大值leftMostHeight、rightMostHeight是否大于当前值
 * 对每个元素进行遍历，然后求左右 O(n2)
 * 利用动态规划，预先求出左右最大值 O(n)
 * */
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        if (n < 2) return 0;

//        左侧最大值，包括自身
        int *lmh = new int[n];
        int *rmh = new int[n];

        lmh[0] = height[0];
        for (int i = 1; i < n; ++i) {
            lmh[i] = max(lmh[i - 1], height[i]);
        }

        rmh[n - 1] = height[n - 1];
        for (int i = n -2; i >= 0; --i) {
            rmh[i] = max(rmh[i + 1], height[i]);
        }

        int water = 0;
        for (int j = 0; j < n; ++j) {
            water += min(lmh[j], rmh[j]) - height[j];
        }

        delete[] lmh;
        delete[] rmh;

        return water;
    }

//    增量式计算，而不是width*height
    int trap(int A[], int n) {
        int left=0; int right=n-1;
        int res=0;
        int maxleft=0, maxright=0;
        while(left<=right){
            if(A[left]<=A[right]){
                if(A[left]>=maxleft) maxleft=A[left];
                else res+=maxleft-A[left];
                left++;
            }
            else{
                if(A[right]>=maxright) maxright= A[right];
                else res+=maxright-A[right];
                right--;
            }
        }
        return res;
    }
};

TEST(leetcode, trapping_rain_water) {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    EXPECT_EQ(6, Solution().trap(height));
}