//
// Created by root on 6/17/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
 * */

using namespace std;

namespace solve_first {
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < n; ++j) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = std::min(dp[i][j -1], dp[i - 1][j]) + grid[i][j];
            }
        }

        return dp[m - 1][n - 1];
    }
}

TEST(leetcode, minimum_path_sum) {
    vector<vector<int>> grid{{1, 2}, {1, 1}};
    EXPECT_EQ(3, solve_first::minPathSum(grid));
}
