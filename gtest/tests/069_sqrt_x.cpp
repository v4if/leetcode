//
// Created by root on 6/17/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
Implement int sqrt(int x).

Compute and return the square root of x.
 * */

using namespace std;

namespace solve_first {
    int mySqrt(int x) {
        if (x == 0)
            return 0;
        int left = 1, right = INT32_MAX;
        while (true) {
            int mid = left + (right - left)/2;
            if (mid > x/mid) {
                right = mid - 1;
            } else {
                if (mid + 1 > x/(mid + 1))
                    return mid;
                left = mid + 1;
            }
        }
    }
}

TEST(leetcode, sqrt_x) {
    cout << solve_first::mySqrt(7) << endl;
}