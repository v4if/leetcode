//
// Created by root on 4/23/17.
//

#include <iostream>
#include <algorithm>
#include <set>
#include <gtest/gtest.h>

/*
    Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
    Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * */

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = target;
        int absDelta = INT32_MAX;
        set<int> visited;
        sort(nums.begin(), nums.end());

//        遍历，然后双向指针取target值，重复值去掉
        for (int i = 0; i < nums.size(); ++i) {
            if (find(visited.begin(), visited.end(), nums[i]) != visited.end()) {
                continue;
            }

            visited.insert(nums[i]);

            int expect = target - nums[i];
            int front = i + 1;
            int end = nums.size() - 1;

            while (front < end) {
                int sums = nums[front] + nums[end];
                int delta = sums + nums[i] - target;

                if (abs(delta) < absDelta) {
                    ans = sums + nums[i];
                    absDelta = abs(delta);
                }

                if (sums < expect) {
                    front++;
                } else if (sums > expect) {
                    end--;
                } else {
                    return target;
                }
            }
        }

        return ans;
    }
};

TEST(leetcode, _3sum_closest) {
    int myints[] = {-1, 2, 1, -4};
    vector<int> myvector(myints, myints + 4);

    EXPECT_EQ(2, Solution().threeSumClosest(myvector, 1));
}