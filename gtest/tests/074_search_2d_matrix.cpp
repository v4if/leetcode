//
// Created by root on 2017/7/1.
//

#include <iostream>
#include <gtest/gtest.h>

/*
Write an efficient algorithm that searches for a value in an m x n matrix.
This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
 * */

using namespace std;

namespace solve_first {
    bool binary_search_matrix(vector<vector<int>>& matrix, int p, int q, int target) {
        int i, j;
        while(p < q) {
            int mid = p + (q - p) / 2;

            i = mid / matrix[0].size();
            j = mid % matrix[0].size();
            if (matrix[i][j] == target) return true;

            if (matrix[i][j] > target) q = mid - 1;
            else p = mid + 1;
        }

        i = p / matrix[0].size();
        j = p % matrix[0].size();
        return matrix[i][j] == target;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;

        return binary_search_matrix(matrix, 0, matrix.size() * matrix[0].size() - 1, target);
    }
}

TEST(leetcode, template) {

}