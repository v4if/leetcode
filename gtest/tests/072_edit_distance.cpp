//
// Created by root on 2017/7/1.
//

#include <iostream>
#include <gtest/gtest.h>

/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
 * */

using namespace std;

namespace solve_first {
    int minDistance(string word1, string word2) {
        if (word1.length() == 0) return word2.length();
        if (word2.length() == 0) return word1.length();

        int n1 = word1.length();
        int n2 = word2.length();
//        留一个空白
        int dp[n1 + 1][n2 + 1];

        dp[0][0] = 0;
        for (int i = 1; i < n2 + 1; ++i) {
            dp[0][i] = dp[0][i - 1] + 1;
        }
        for (int i = 1; i < n1 + 1; ++i) {
            dp[i][0] = dp[i - 1][0] + 1;
        }

        for (int i = 1; i < n1 + 1; ++i) {
            for (int j = 1; j < n2 + 1; ++j) {
                dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                int v = word1[i - 1] == word2[j - 1] ? 0 : 1;
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + v);
            }
        }

        return dp[n1][n2];
    }
}

namespace solve_dp_optimize_store{
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<int> pre(n + 1, 0), cur(n + 1, 0);
        for (int i = 0; i <= n; i++) cur[i] = i;
        for (int i = 1; i <= m; i++) {
            pre = cur;
            cur[0] = i;
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) cur[j] = pre[j - 1];
                else
                    cur[j] = min(cur[j - 1], min(pre[j],pre[j - 1])) + 1;
            }
        }
        return cur[n];
    }
}

TEST(leetcode, leetcode_edit_distance_test) {
    cout << solve_first::minDistance("a", "b") << endl;
}