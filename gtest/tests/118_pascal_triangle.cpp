//
// Created by root on 9/16/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
 * */

using namespace std;

namespace pascal_triangle {
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        for (int i = 0; i < numRows; ++i) {
            vector<int> level(i + 1);
            level[0] = level[i] = 1;
            for (int j = 1; j < i; ++j) {
                level[j] = ret[i - 1][j - 1] + ret[i - 1][j];
            }
            ret.push_back(level);
        }

        return ret;
    }
}

namespace pascal_triangle_perfect {
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> r(numRows);

        for (int i = 0; i < numRows; i++) {
            r[i].resize(i + 1);
            r[i][0] = r[i][i] = 1;

            for (int j = 1; j < i; j++)
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
        }

        return r;
    }
}

TEST(leetcode, pascal_triangle_test) {
    using namespace pascal_triangle;
    vector<vector<int>> ret = generate(5);
    string out;
    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j < ret[i].size(); ++j) {
            out += to_string(ret[i][j]) + ", ";
        }
        out = out.substr(0, out.size() - 2) + "\n";
    }
    cout << out;
}