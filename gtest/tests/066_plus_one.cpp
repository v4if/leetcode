//
// Created by root on 6/17/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.

大数加一
* */

using namespace std;

namespace solve_first {
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            int sum = digits[i] + carry;
            carry = sum / 10;
            digits[i] = sum % 10;
        }

        if (carry) digits.insert(digits.begin(), carry);
        return digits;
    }
}

TEST(leetcode, plus_one) {
    vector<int> digits{9, 9, 9};
    vector<int> result{1, 0, 0, 0};
    EXPECT_EQ(result, solve_first::plusOne(digits));
}