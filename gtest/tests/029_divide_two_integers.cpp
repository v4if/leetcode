//
// Created by root on 5/7/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
    Divide two integers without using multiplication, division and mod operator.

    If it is overflow, return MAX_INT.
 * */

using namespace std;

class Solution {
public:
    int dividePrime(int dividend, int divisor) {
        if (divisor == 0) return INT32_MAX;
        if (dividend == INT32_MIN && divisor == -1) return INT32_MAX;

        int ret = 0;
        int sum = 0;
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);

        while (sum < dvd) {
            ++ret;
            sum += dvs;
        }

        if (sum != dvd) --ret;

        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) return -ret;
        else return ret;
    }

    int divide(int dividend, int divisor) {
        if ((divisor == 0) || (dividend == INT32_MIN && divisor == -1)) return INT32_MAX;

        int ret = 0;
        int sum = 0;
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);

        while (dvd >= dvs) {
            long long temp = dvs;
            int multiple = 1;
//            指数增长，1,2,4,8,16
            while (dvd >= (temp << 1)) {
                temp = temp << 1;
                multiple = multiple << 1;
            }

            dvd -= temp;
            ret += multiple;
        }


        return ((dividend < 0) ^ (divisor < 0)) ? -ret : ret;
    }
};

TEST(leetcode, divide_two_integers) {
    EXPECT_EQ(-1, Solution().divide(1, -1));
    EXPECT_EQ(2, Solution().divide(5, 2));
    EXPECT_EQ(2147483647, Solution().divide(2147483647, 1));
}