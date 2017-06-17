//
// Created by root on 6/17/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time.
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 * */

using namespace std;

namespace solve_first {
    void backtrace(int m, int n, int curr_m, int curr_n, int& ans) {
        if (curr_m == m && curr_n == n) {
            ans++;
            return;
        }

        if (curr_m < m) {
            backtrace(m, n, curr_m + 1, curr_n, ans);
        }

        if (curr_n < n) {
            backtrace(m, n, curr_m, curr_n + 1, ans);
        }
    }

    int uniquePaths(int m, int n) {
        int ans = 0;
        backtrace(m - 1, n - 1, 0, 0, ans);

        return ans;
    }
}

namespace solve_optimise_dp {
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n -1];
    }
}


TEST(leetcode, unique_paths) {
    EXPECT_EQ(792, solve_optimise_dp::uniquePaths(8, 6));
}