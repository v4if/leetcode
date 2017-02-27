//
// Created by root on 2/26/17.
//

#include <iostream>
#include <gtest/gtest.h>

/**
    Determine whether an integer is a palindrome. Do this without extra space.
 */

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        string str;
        int y = x;
        while (y) {
            str.push_back(y % 10);
            y = y / 10;
        }

        for (int i = 0; i < str.length() / 2; ++i) {
            if (str[i] != str[str.length() - i - 1])
                return false;
        }
        return true;
    }
};

TEST(leetcode, palindrome_number) {
    EXPECT_EQ(true, Solution().isPalindrome(121));
    EXPECT_EQ(false, Solution().isPalindrome(23));
    EXPECT_EQ(true, Solution().isPalindrome(1));
}