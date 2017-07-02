//
// Created by root on 2017/7/2.
//

#include <iostream>
#include <gtest/gtest.h>

/*
Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
 * */

using namespace std;

namespace solve_first {
    void backtrace(vector<vector<int>>& ans, vector<int>& result, vector<int>& nums, int start) {
        ans.push_back(result);

        for (int i = start; i < nums.size(); ++i) {
            result.push_back(nums[i]);
            backtrace(ans, result, nums, i + 1);
            result.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> result;
        backtrace(ans, result, nums, 0);

        return ans;
    }
}

TEST(leetcode, subsets_test) {
    vector<vector<int>> ans;
    vector<int> nums{1,2};
    ans = solve_first::subsets(nums);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}