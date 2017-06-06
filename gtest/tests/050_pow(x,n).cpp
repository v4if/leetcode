//
// Created by root on 6/6/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
Implement pow(x, n).
 * */

using namespace std;

namespace solve_normal {
    class Solution {
    public:
        double myPow(double x, int n) {
            if (0 == n) return 1;
            if (n < 0) {
                x = 1 / x;
                if (n == INT32_MIN) return x * myPow(x, INT32_MAX);

                n = -n;
            }

            return (n % 2 == 0) ? myPow(x * x, n / 2) : x * myPow(x * x, n / 2);
        }
    };
}

namespace solve_perfect {
    double myPow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n<0)
        {
            if(n==INT32_MIN)
                return 1.0 / (x * myPow(x,INT32_MAX));
            else
                return 1.0 / myPow(x,-n);
        }

        if(n==0) return 1.0;
        double ans = 1.0 ;
        for(;n>0; x *= x, n>>=1)
        {
//            奇数
            if(n&1)
                ans *= x;
        }
        return ans;
    }
}

TEST(leetcode, pow_x_n) {
    using namespace solve_perfect;
    EXPECT_EQ(64.0, myPow(4, 3));
    EXPECT_EQ(16, myPow(2, 4));
}