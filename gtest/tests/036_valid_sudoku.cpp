//
// Created by root on 5/20/17.
//

#include <iostream>
#include <gtest/gtest.h>
#include <unordered_map>

/*
    Determine if a Sudoku is valid.
    The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
    Note:
    A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
 * */
/*
 * 循环需要考虑的是每次需要执行多少次 和 一共需要多少轮
 * */
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            unordered_map<char, int> row;
            unordered_map<char, int> column;
            unordered_map<char, int> sub;

            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    if (row.find(board[i][j]) != row.end()) return false;
                    else row[board[i][j]] = 1;
                }

                if (board[j][i] != '.') {
                    if (column.find(board[j][i]) != column.end()) return false;
                    else column[board[j][i]] = 1;
                }

                int sub_i = 3 * (i / 3) + j / 3, sub_j = 3 * (i % 3) + j % 3;
                if (board[sub_i][sub_j] != '.') {
                    if (sub.find(board[sub_i][sub_j]) != sub.end()) return false;
                    else sub[board[sub_i][sub_j]] = 1;
                }
            }
        }

        return true;
    }
};
