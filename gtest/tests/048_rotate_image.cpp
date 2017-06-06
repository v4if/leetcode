//
// Created by root on 6/6/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
 * */

using namespace std;

class Solution {
public:
//    对角线交换，然后左右交换
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
    }
};

TEST(leetcode, rotate_image) {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution().rotate(matrix);
    for (auto v : matrix) {
        for (auto e : v) {
            cout << e << " ";
        }
        cout << endl;
    }
}