//
// Created by root on 2/25/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.
 * */

using namespace std;

namespace solve_first {
    void backtrace(int n, int h, int& ans) {
        if (h == n) {
            ans++;
            return;
        } else if (h > n) {
            return;
        }

        for (int i = 0; i < 2; ++i) {
            backtrace(n, h + i + 1, ans);
        }
    }

    int climbStairs(int n) {
        int ans = 0;
        backtrace(n, 0, ans);
        return ans;
    }
}

namespace solve_dp {
    int climbStairs(int n) {
        if (n < 3) return n == 1 ? 1 : 2;

        int dp[n];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1; dp[1] = 2;

        for (int i = 2; i < n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n - 1];
    }
}

namespace solve_dp_o1 {
    int climbStairs(int n) {
        int ans;
        int pre1 = 1, pre2 = 2;

        if (n < 3) {
            return n == 1 ? pre1 : pre2;
        }

        for (int i = 2; i < n; ++i) {
            ans = pre1 + pre2;
            pre1 = pre2;
            pre2 = ans;
        }

        return ans;
    }
}

TEST(leetcode, leetcode_climbing_stairs_Test) {
    EXPECT_EQ(1, solve_dp_o1::climbStairs(1));
}