//
// Created by root on 6/10/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
 * */

using namespace std;

namespace solve_first {
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;

        int m = matrix.size();
        if (m == 0) return ret;
        int n = matrix[0].size();
        if (n == 0) return ret;

        int min_m, min_n;
        min_n = -1;
        min_m = 0;

        int factor = m * n;
        int row, col, row_step, col_step;
        row = col = row_step = 0;
        col_step = 1;
        for (int i = 0; i < factor; ++i, row += row_step, col += col_step) {
            ret.push_back(matrix[row][col]);

            if (col_step != 0) {
                if (col + col_step == n) {
                    col_step = 0;
                    row_step = 1;
                    n--;
                }
                if (col + col_step == min_n) {
                    col_step = 0;
                    row_step = -1;
                    min_n++;
                }
            }

            if (row_step != 0) {
                if (row + row_step == m) {
                    row_step = 0;
                    col_step = -1;
                    m--;
                }
                if (row + row_step == min_m) {
                    row_step = 0;
                    col_step = 1;
                    min_m++;
                }
            }
        }

        return ret;
    }
}

namespace best_solve{
//    记录上下左右四个边界，四重循环
    class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> res;
            int rows = matrix.size();
            if (0 == rows)
                return res;
            int cols = matrix[0].size();
            int up = 0;
            int down = rows-1;
            int left = 0;
            int right = cols-1;

            while (true) {

                for (int i = left; i <= right; i++) {
                    res.push_back(matrix[up][i]);
                }
                up++;
                if (existConditionMet(up, down, left, right))
                    break;

                for (int i = up; i <= down; i++) {
                    res.push_back(matrix[i][right]);
                }
                right--;
                if (existConditionMet(up, down, left, right))
                    break;

                for (int i = right; i >= left; i--) {
                    res.push_back(matrix[down][i]);
                }
                down--;
                if (existConditionMet(up, down, left, right))
                    break;

                for (int i = down; i >= up; i--) {
                    res.push_back(matrix[i][left]);
                }
                left++;
                if (existConditionMet(up, down, left, right))
                    break;
            }

            return res;
        }

        bool existConditionMet(int up, int down, int left, int right) {
            if (up <= down && left <= right)
                return false;
            return true;
        }
    };
}

TEST(leetcode, spiral_matrix) {
    vector<int> ret;
    vector<vector<int>> matrix{ { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, {13, 14, 15, 16}};
    ret = solve_first::spiralOrder(matrix);
    for (auto i : ret) cout << i << " ";
    cout << endl;
}