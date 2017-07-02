//
// Created by root on 2017/7/2.
//

#include <iostream>
#include <gtest/gtest.h>
#include <vector>
#include <unordered_map>

/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring.
The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

 * */

using namespace std;

namespace solve_first {
    bool expend_trace(vector<vector<char>>& board, string word, int find_curr, int i, int j, vector<vector<int>>& visited) {
        if (find_curr == word.length()) return true;

        int index_i[4]{i - 1, i, i + 1, i};
        int index_j[4]{j, j + 1, j, j - 1};
        for (int k = 0; k < 4; ++k) {
            if (index_i[k] >= 0 && index_i[k] < board.size() && index_j[k] >= 0 && index_j[k] < board[0].size()) {
                if ((board[index_i[k]][index_j[k]] == word[find_curr]) && (visited[index_i[k]][index_j[k]] == 0)) {
                    visited[index_i[k]][index_j[k]] = 1;
                    if (expend_trace(board, word, find_curr + 1, index_i[k], index_j[k], visited))
                        return true;
                    visited[index_i[k]][index_j[k]] = 0;
                }

            }
        }

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0]) {
                    visited[i][j] = 1;
                    if (expend_trace(board, word, 1, i, j, visited)) return true;
                    visited[i][j] = 0;
                }
            }
        }

        return false;
    }

    void test(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
}

TEST(leetcode, word_search_test) {
    vector<vector<char>> board{{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
    string word{"ABCCED"};
//    solve_first::test(board);
    bool ans = solve_first::exist(board, word);
    cout << ans << endl;
}