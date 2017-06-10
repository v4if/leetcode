//
// Created by root on 6/10/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement,
 where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
 * */

using namespace std;

namespace solve_first {
    bool check_attach(const vector<int>& sol, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if ((sol[i] == col) || (row - i == abs(col - sol[i]))) return false;
        }

        return true;
    }
    void backtrace(vector<vector<string>>& ret, vector<int>& sol, int row, int n) {
        if (row == n) {
            vector<string> str(n, string(n, '.'));
            for (int i = 0; i < sol.size(); ++i) {
                str[i][sol[i]] = 'Q';
            }
            ret.push_back(str);
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (!check_attach(sol, row, i)) continue;
            
            sol[row] = i;
            backtrace(ret, sol, row + 1, n);
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        vector<int> sol(n, -1);

        backtrace(ret, sol, 0, n);
        return ret;
    }
}

TEST(leetcode, n_queens) {
    vector<vector<string>> ret;
    ret = solve_first::solveNQueens(4);

    for (auto v : ret) {
        for (auto str : v) {
            cout << str << " ";
        }
        cout << endl;
    }
}