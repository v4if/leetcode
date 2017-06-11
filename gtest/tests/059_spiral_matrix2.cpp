//
// Created by root on 6/11/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
 * */

using namespace std;

namespace solve_first {
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n, 0));

        int up = 0;
        int down = n - 1;
        int left = 0;
        int right = n - 1;

        int factor = n * n;
        for (int k = 1; k <= factor;) {
            for (int i = left; i <= right; ++i) {
                ret[up][i] = k++;
            }
            up++;

            for (int i = up; i <= down; ++i) {
                ret[i][right] = k++;
            }
            right--;

            for (int i = right; i >= left; --i) {
                ret[down][i] = k++;
            }
            down--;

            for (int i = down; i >= up; --i) {
                ret[i][left] = k++;
            }
            left++;
        }

        return ret;
    }
}

TEST(leetcode, spiral_matrix2) {
    vector<vector<int>> ret;
    ret = solve_first::generateMatrix(3);
    for (auto v : ret) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
}