//
// Created by root on 2017/7/2.
//

#include <iostream>
#include <gtest/gtest.h>

/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
 * */

using namespace std;

namespace solve_first {
    void backtrace(vector<vector<int>>& ans, vector<int>& result, int n, int k, int right, int start) {
        if (right == k) {
            ans.push_back(result);
            return;
        }

        for (int i = start; i <= n; ++i) {
            if (find(result.begin(), result.end(), i) == result.end()) {
                result.push_back(i);
                backtrace(ans, result, n, k, right + 1, i + 1);
                result.pop_back();
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> result;
        backtrace(ans, result, n, k, 0, 1);

        return ans;
    }
}

TEST(leetcode, leetcode_combinations_test) {
    vector<vector<int>> ans;
    ans = solve_first::combine(3, 2);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[0].size(); ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}