//
// Created by root on 6/17/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
 * */

using namespace std;

namespace solve_first {
    bool isNumber(string s) {
        int begin = 0;
        int end = s.length();

        while (begin < end && s[begin] == ' ') begin++;
        while (end > 0 && s[end - 1] == ' ') end--;

        bool seen_dot = false;
        bool seen_e = false;
        bool before_e = false;
        bool after_e = true;
        bool seen_number = false;
        for (int i = begin; i < end; ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                if (!seen_e) before_e = true;

                seen_number = true;
                after_e = true;
            } else if (s[i] == '.') {
                if (seen_dot || seen_e) return false;

                seen_dot = true;
            } else if (s[i] == 'e') {
                if (seen_e) return false;

                seen_e = true;
                after_e = false;
            } else if (s[i] == '-' || s[i] == '+') {
                if (i != begin && s[i - 1] != 'e') return false;
            } else {
                return false;
            }
        }

        return seen_number && before_e && after_e;
    }
}

TEST(leetcode, valid_number) {
    EXPECT_EQ(true, solve_first::isNumber(string("0")));
    EXPECT_EQ(true, solve_first::isNumber(string(" 0.1 ")));
    EXPECT_EQ(false, solve_first::isNumber(string(" 1 a ")));
    EXPECT_EQ(true, solve_first::isNumber(string(" 2e10")));
    EXPECT_EQ(false, solve_first::isNumber(string(" 2e")));
    EXPECT_EQ(false, solve_first::isNumber(string(".")));
    EXPECT_EQ(true, solve_first::isNumber(string("-1.")));
    EXPECT_EQ(false, solve_first::isNumber(string("+-")));
}