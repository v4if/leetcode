//
// Created by root on 6/4/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
    '?' Matches any single character.
    '*' Matches any sequence of characters (including the empty sequence).

    The matching should cover the entire input string (not partial).

    The function prototype should be:
    bool isMatch(const char *s, const char *p)

    Some examples:
    isMatch("aa","a") → false
    isMatch("aa","aa") → true
    isMatch("aaa","aa") → false
    isMatch("aa", "*") → true
    isMatch("aa", "a*") → true
    isMatch("ab", "?*") → true
    isMatch("aab", "c*a*b") → false
 * */

using namespace std;
namespace wildcard {
    class Solution {
    public:
        bool isMatch(string s, string p) {
            return recursive(s, 0, p, 0);
        }

        bool match_first(const char s, const char p) {
            return ((s == p) || (p == '?' && s != '\0'));
        }

//        递归大数据会出现超时
        bool recursive(string s, size_t p1, string p, size_t p2) {
            size_t n1 = s.length();
            size_t n2 = p.length();
            if (p2 == n2) return p1 == n1;

//        匹配任意字符
            if (p[p2] == '?') return recursive(s, p1 + 1, p, p2 + 1);
            else if (p[p2] == '*') {
                while (p2 + 1 < n2 && p[p2 + 1] == '*') p2++;

                for (size_t i = p1; i <= n1; ++i) {
                    if (match_first(s[i], p[p2 + 1])) {
                        if (recursive(s, i, p, p2 + 1)) return true;
                    }
                }

                return false;
            } else {
                if (!match_first(s[p1], p[p2])) return false;

                return recursive(s, p1 + 1, p, p2 + 1);
            }
        }

        bool isMatchBest(const char *s, const char *p) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function

            const char* star=NULL;
            const char* ss=s;
            while (*s){
                if ((*p=='?')||(*p==*s)){s++;p++;continue;}
                if (*p=='*'){star=p++; ss=s;continue;}
                if (star){ p = star+1; s=++ss;continue;}
                return false;
            }
            while (*p=='*'){p++;}
            return !*p;
        }
    };
}

TEST(leetcode, wildcard_matching) {
    using namespace wildcard;
    EXPECT_TRUE(Solution().isMatch("ab", "?*"));
    EXPECT_FALSE(Solution().isMatch("aab", "c*a*b*"));
    EXPECT_TRUE(Solution().isMatch("aa", "*"));
    EXPECT_FALSE(Solution().isMatch("zacabz", "*a?b*"));
    EXPECT_TRUE(Solution().isMatch("c", "*?*"));
}