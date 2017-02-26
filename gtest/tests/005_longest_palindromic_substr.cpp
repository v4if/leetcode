//
// Created by root on 2/25/17.
//

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return 0;
        }

//        暴力
        string max_palindrome = "";
        for (int i = 0; i < s.length(); ++i) {
            for (int j = 1; j < s.length() - i + 1; ++j) {
//                substr(start, length)
                if (isPalindrome(s.substr(i, j))) {
                    if (max_palindrome.length() < j) {
                        max_palindrome = s.substr(i, j);
                    }
                }
            }
        }
        return max_palindrome;
    }

    bool isPalindrome(string s) {
        for (int i = 0; i < s.length() / 2; ++i) {
            if (s[i] != s[s.length() - i - 1])
                return false;
        }
        return true;
    }
};

class Solution1 {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) {
            return s;
        }

//        以s[i]为中心左右扩展
        string max_palindrome = s.substr(0, 1);
        int extend;
        for (int i = 1; i < s.length(); ++i) {
            extend = 0;
//            奇数扩展
            for (int j = 1; i - j >= 0 && i + j < s.length(); ++j) {
                if (s[i - j] != s[i + j]) {
                    break;
                }

                extend = j;
            }

            if (max_palindrome.length() < extend * 2 + 1) {
                max_palindrome = s.substr(i - extend, extend * 2 + 1);
            }

            extend = 0;
//            偶数扩展
            for (int k = 1; i - k >= 0 && i + k - 1 < s.length() ; ++k) {
                if (s[i - k] != s[i + k - 1]) {
                    break;
                }

                extend = k;
            }

            if (max_palindrome.length() < extend * 2) {
                max_palindrome = s.substr(i - extend, extend * 2);
            }
        }

        return max_palindrome;
    }
};

TEST(leetcode, longest_palindromic_substr) {
    ASSERT_TRUE(Solution().isPalindrome("aba"));
    ASSERT_TRUE(Solution().isPalindrome("bb"));
    ASSERT_TRUE(!Solution().isPalindrome("bcba"));

    ASSERT_EQ("bab", Solution().longestPalindrome("babad"));
    ASSERT_EQ("bb", Solution().longestPalindrome("cbbd"));
    ASSERT_EQ("bb", Solution().longestPalindrome("bb"));
    ASSERT_EQ("s", Solution().longestPalindrome("s"));

    ASSERT_EQ("bab", Solution1().longestPalindrome("babad"));
    ASSERT_EQ("b", Solution1().longestPalindrome("ba"));
    ASSERT_EQ("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", Solution1().longestPalindrome("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));
}
