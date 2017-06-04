//
// Created by root on 6/4/17.
//

#include <iostream>
#include <gtest/gtest.h>
#include <algorithm>
/*
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
 * */

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> tuple;
        vector<vector<int>> ret;
        recursive(nums, 0, tuple, ret);

        return ret;
    }

    void recursive(vector<int>& nums, int n, vector<int>& tuple, vector<vector<int>>& ret) {
        int len = nums.size();
        if (n == len) {
            ret.push_back(tuple);
            return;
        }

        for (int i = 0; i < len; ++i) {
            if (find(tuple.begin(), tuple.end(), nums[i]) == tuple.end()) {
                tuple.push_back(nums[i]);
                recursive(nums, n + 1, tuple, ret);
                tuple.erase(--tuple.end());
            }
        }
    }
};

TEST(leetcode, permutations) {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ret = Solution().permute(nums);
    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j < ret[i].size(); ++j) {
            cout << ret[i][j] << "  ";
        }
        cout << endl;
    }
}