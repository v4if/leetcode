//
// Created by root on 6/17/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
 * */

using namespace std;

namespace solve_first {
    string addBinary(string a, string b) {
        vector<int> ans;
        string ret;

        int carry = 0;
        int i, j;
        for (i = a.length() - 1, j = b.length() - 1; i >= 0 && j >= 0; --i, --j) {
            int sum = (int)(a[i] - '0') + (int)(b[j] - '0') + carry;
            carry = sum / 2;
            ans.push_back(sum % 2);
        }

        while (i >= 0) {
            int sum = int(a[i] - '0') + carry;
            carry = sum / 2;
            ans.push_back(sum % 2);

            --i;
        }

        while (j >= 0) {
            int sum = int(b[j] - '0') + carry;
            carry = sum / 2;
            ans.push_back(sum % 2);

            --j;
        }

        if (carry) ans.push_back(carry);

        for (int i = ans.size() - 1; i >= 0; --i) {
            ret.push_back(char(ans[i] + '0'));
        }

        return ret;
    }
}

TEST(leetcode, add_binary) {
    string a{"11"};
    string b{"1"};
    EXPECT_EQ("100", solve_first::addBinary(a, b));
}