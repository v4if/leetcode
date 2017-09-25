//
// Created by root on 9/25/17.
//

#include <iostream>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <gtest/gtest.h>

/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
 * */

using namespace std;

namespace surrounded_regions {
    void bfs(vector<vector<char>>& board, int w, int l) {
        int width = board.size();
        int length = board[0].size();

        queue<pair<int, int>> q;
        q.push(make_pair(w, l));
        board[w][l] = 'B';
        while (!q.empty()) {
            pair<int, int> cur = std::move(q.front());
            q.pop();
            pair<int, int> adjs[4] = {{cur.first - 1, cur.second},
                                      {cur.first, cur.second + 1},
                                      {cur.first + 1, cur.second},
                                      {cur.first, cur.second - 1}};
            for (int i = 0; i < 4; ++i) {
                int adjW = adjs[i].first;
                int adjL = adjs[i].second;
                if (adjW >= 0 && adjW < width && adjL >= 0 && adjL < length && board[adjW][adjL] == 'O') {
                    q.push(make_pair(adjW, adjL));
                    board[adjW][adjL] = 'B';
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int width = board.size();
        if (width == 0) return;
        int length = board[0].size();
        if (length == 0) return;
        for (int i = 0; i < length; ++i) {
            if (board[0][i] == 'O') {
                bfs(board, 0, i);
            }

            if (board[width - 1][i] == 'O') {
                bfs(board, width - 1, i);
            }
        }

        for (int j = 0; j < width; ++j) {
            if (board[j][0] == 'O') {
                bfs(board, j, 0);
            }

            if (board[j][length - 1] == 'O') {
                bfs(board, j, length - 1);
            }
        }

        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < length; ++j) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == 'B') {
                    board[i][j] = 'O';
                }
            }
        }
    }
}

TEST(leetcode, leetcode_surrounded_regions__Test) {
    using namespace surrounded_regions;
    vector<vector<char>> board{{'X','X','X','X'},
                               {'X', 'O','O','X'},
                               {'X','X','O','X'},
                               {'X','O','X','X'}};
    solve(board);
    string out;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            out += to_string(board[i][j]) + ", ";
        }
        out = out.substr(0, out.size() - 2);
        out += '\n';
    }
    cout << out;
}