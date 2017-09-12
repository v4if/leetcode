//
// Created by root on 9/12/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
 * */

using namespace std;

namespace solve_first {
    int backtrace(string s) {
        if (s.empty()) return 1;

        int ways = 0;
        ways += s.size() >= 1 && stoi(s.substr(0, 1)) > 0 ? backtrace(s.substr(1, s.size() - 1)) : 0;
        ways += s.size() >= 2 && stoi(s.substr(0, 2)) <= 26 && stoi(s.substr(0, 2)) >= 10 ? backtrace(s.substr(2, s.size() - 2)) : 0;
        return ways;
    }

    int numDecodings(string s) {
        if (s.empty()) return 0;
        return backtrace(s);
    }
}

namespace solve_dp {
    int numDecodings(string s) {
        if (s.length() == 0) return 0;

        vector<int> dp(s.length() + 1, 0);
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;
        for (int i = 2; i <= s.length(); ++i) {
            if (stoi(s.substr(i - 2, 2)) >= 10 && stoi(s.substr(i - 2, 2)) <= 26) {
                dp[i] += dp[i - 2];
            }
            if (stoi(s.substr(i - 1, 1)) != 0) {
                dp[i] += dp[i - 1];
            }
        }

        return dp[s.length()];
    }
}

TEST(leetcode, leetcode_decode_ways_Test) {
    std::cout << solve_dp::numDecodings("126") << std::endl;
}