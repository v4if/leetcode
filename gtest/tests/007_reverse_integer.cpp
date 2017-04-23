//
// Created by root on 2/26/17.
//

#include <iostream>
#include <vector>
#include <gtest/gtest.h>

/**
    Reverse digits of an integer.

    Example1: x = 123, return 321
    Example2: x = -123, return -321

    click to show spoilers.

    Have you thought about this?
    Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

    If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

    Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

    For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

    Note:
            The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.
 */

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ans = 0, temp;
        while (x) {
            temp = ans * 10 + x % 10;
//            乘10相加溢出
            if (temp / 10 != ans)
                return 0;

            ans = temp;
            x = x / 10;
        }

        return ans;
    }
};

TEST(leetcode, reverse_integer) {
    // cout << -123 % 10 << endl;
    EXPECT_EQ(321, Solution().reverse(123));
    EXPECT_EQ(-123, Solution().reverse(-321));
}
