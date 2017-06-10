//
// Created by root on 6/10/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
 * */

using namespace std;

namespace solve_first {
    bool valid(const vector<int>&solve, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (solve[i] == col || row - i == abs(col - solve[i])) return false;
        }

        return true;
    }

    void backtrace(int& cnt, vector<int>& solve, int row, int n) {
        if (row == n) {
            cnt++;
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (!valid(solve, row, i)) continue;

            solve[row] = i;
            backtrace(cnt, solve, row + 1, n);
        }
    }
    int totalNQueens(int n) {
        vector<int> solve(n);
        int ret = 0;
        backtrace(ret, solve, 0, n);
        return ret;
    }
}

TEST(leetcode, n_queens2) {
    EXPECT_EQ(2, solve_first::totalNQueens(4));
}