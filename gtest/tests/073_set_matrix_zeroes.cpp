//
// Created by root on 2017/7/1.
//

#include <iostream>
#include <gtest/gtest.h>

/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 * */

using namespace std;

namespace solve_first {
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return;

        int row = matrix.size();
        int col = matrix[0].size();

        int visited1[row], visited2[col];
        memset(visited1, 0, sizeof(visited1));
        memset(visited2, 0, sizeof(visited2));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == 0) {
                    if (!visited1[i]) {
                        visited1[i] = 1;
                    }
                    if (!visited2[j]) {
                        visited2[j] = 1;
                    }
                }
            }
        }

        for (int i = 0; i < row; ++i) {
            if (visited1[i]) {
                for (int j = 0; j < col; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < col; ++i) {
            if (visited2[i]) {
                for (int j = 0; j < row; ++j) {
                    matrix[j][i] = 0;
                }
            }
        }
    }
}

TEST(leetcode, leetcode_set_matrix_zeroes_test) {
    vector<vector<int>> nums{{0,1}};
    solve_first::setZeroes(nums);
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < nums[0].size(); ++j) {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
}