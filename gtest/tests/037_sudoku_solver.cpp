//
// Created by root on 5/20/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
    Write a program to solve a Sudoku puzzle by filling the empty cells.

    Empty cells are indicated by the character '.'.

    You may assume that there will be only one unique solution.
 * */

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if (board.empty() || board.size() != 9 || board[0].size() != 9) return;
        solver(board, 0, 0);
    }

//    需要递归填充的位置
    bool solver(vector<vector<char>>& board, int i, int j) {
        if (i == 9) return true;
        if (j >= 9) return solver(board, i + 1, 0);

        if (board[i][j] == '.') {
            for (int k = 1; k < 10; ++k) {
                board[i][j] = static_cast<char>(k + '0');
                if (isValid(board, i, j)) {
                    if (solver(board, i, j + 1)) return true;
                }

                board[i][j] = '.';
            }
        } else {
            return solver(board, i, j + 1);
        }

        return false;
    }

//    判断新添加的位置数字是否合法
    bool isValid(vector<vector<char>>& board, int i, int j) {
//        行
        for (int k = 0; k < 9; ++k) {
            if (k != j && board[i][k] == board[i][j]) return false;
        }

//        列
        for (int k = 0; k < 9; ++k) {
            if (k != i && board[k][j] == board[i][j]) return false;
        }

//        子数独
        for (int row = i / 3 * 3; row < i / 3 * 3 + 3; ++row) {
            for (int col = j / 3 * 3; col < j / 3 * 3 + 3; ++col) {
                if ((row != i || col != j) && board[i][j] == board[row][col]) return false;
            }
        }

        return true;
    }
};
