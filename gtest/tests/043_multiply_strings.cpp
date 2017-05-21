//
// Created by root on 5/21/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
    Given two non-negative integers num1 and num2 represented as strings,
    return the product of num1 and num2.

    Note:

    The length of both num1 and num2 is < 110.
    Both num1 and num2 contains only digits 0-9.
    Both num1 and num2 does not contain any leading zero.
    You must not use any built-in BigInteger library or convert the inputs to integer directly.
 * */

/*
 * 对于一个m位整数乘以n位整数的结果，最多只有m+n位
 * */
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        vector<int> mul(n1 + n2, 0);

        int k = n1 + n2 - 2;
        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < n2; ++j) {
                mul[k - i - j] += static_cast<int>(num1[i] - '0') * static_cast<int>(num2[j] - '0');
            }
        }

//        处理进位
        int carry = 0;
        for (int i = 0; i < n1 + n2; ++i) {
            mul[i] = mul[i] + carry;
            carry = mul[i] / 10;
            mul[i] = mul[i] % 10;
        }

//        去除前导零
        k = n1 + n2 - 1;
        while (k >= 0 && mul[k] == 0) --k;

//        乘积为零
        if (k < 0) return "0";

        string result;
        while (k >= 0) result.push_back(mul[k--] + '0');
        return result;
    }
};

TEST(leetcode, multiply_strings) {
    EXPECT_EQ("226865", Solution().multiply("289", "785"));
    EXPECT_EQ("0", Solution().multiply("0", "0"));
}