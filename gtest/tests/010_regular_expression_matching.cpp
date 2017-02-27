//
// Created by root on 2/26/17.
//

#include <iostream>
#include <gtest/gtest.h>

/**
    Implement regular expression matching with support for '.' and '*'.

    '.' Matches any single character.
    '*' Matches zero or more of the preceding element.

    The matching should cover the entire input string (not partial).

    The function prototype should be:
    bool isMatch(const char *s, const char *p)

    Some examples:
    isMatch("aa","a") → false
    isMatch("aa","aa") → true
    isMatch("aaa","aa") → false
    isMatch("aa", "a*") → true
    isMatch("aa", ".*") → true
    isMatch("ab", ".*") → true
    isMatch("aab", "c*a*b") → true
 */

using namespace std;

class Solution_Wrong_Answer {
public:
    bool isMatch(string s, string p) {
        int pattern_pos = 0;
        for (int i = 0; i < s.length();) {
            if (pattern_pos + 1 < p.length() && p[pattern_pos + 1] == '*') {

//                遍历测试字符串，直到遇到下一个字符
                if (pattern_pos + 2 == p.length()) {
                    i = eat_until(s, i, p[pattern_pos], (char)-1);
                } else {
                    i = eat_until(s, i, p[pattern_pos], p[pattern_pos + 2]);
                }
                pattern_pos += 2;
            } else {
                i = eat(s, i, p[pattern_pos]);
                pattern_pos++;
            }

//            不匹配
            if (i == -1)
                return false;
//            aa    aaa
            if (i == s.length() && pattern_pos != p.length())
                return false;
//            aaa   aa
            if (i != s.length() && pattern_pos == p.length())
                return false;
        }

        return true;
    }

//    单个字符
    int eat(string str, int pos, char c) {
        if (pos >= str.length()) {
            return -1;
        }

        if (c == '.' || str[pos] == c) {
            return pos + 1;
        }

        return -1;
    }

    /*
     * 没有考虑到 aaa ab*a*c*a 或者 aaaa ab*a*c*a 等情况
     * */
    int eat_until(string str, int pos, char find, char end) {
        if (pos >= str.length()) {
            return -1;
        }

        if (end == (char)-1) {
            if (find == '.') {
                return str.length();
            } else {
                while (pos < str.length() && str[pos++] != find) {
                    return -1;
                }

                return str.length();
            }
        } else {
//            如果第一个字母都匹配不到，则不用处理 *可以匹配0或者任意多个
//            只负责处理匹配成功的情况
            if (find == '.' || str[pos] == find) {
//                贪心匹配
                while (++pos < str.length() && (find == '.' || str[pos] == find));

//                如果*左右两个字符一样，则回退一个匹配
                if (find == end) {
                    pos--;
                }
            }

            return pos;
        }
    }
};

class Solution_Right_Answer {
public:
    bool matchFirst(const char *s, const char *p){
        return (*p == *s || (*p == '.' && *s != '\0'));
    }

    bool isMatch(const char *s, const char *p) {
        if (*p == '\0') return *s == '\0';	//empty

        if (*(p + 1) != '*') {//without *
            if(!matchFirst(s,p)) return false;
            return isMatch(s + 1, p + 1);
        } else { //next: with a *
            if(isMatch(s, p + 2)) return true;    //try the length of 0

            while ( matchFirst(s, p) )       //try all possible lengths
                if (isMatch(++s, p + 2)) return true;

            return false;
        }
    }
};

/*
 * '*' Matches zero or more of the preceding element.
 * 回溯尝试所有可能匹配
 * */
class Solution {
public:
    bool matchFirst(string s, string p) {
        if (s.empty()) return false;

        return (p.at(0) == '.' || s.at(0) == p.at(0));
    }

//    递归回溯  当前子问题的解将由上一次子问题的解推出
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();

        if (p.length() < 2 || p.at(1) != '*') {
            if (!matchFirst(s, p)) return false;
            return isMatch(s.substr(1, s.length() - 1), p.substr(1, p.length() - 1));
        } else {
            if (isMatch(s, p.length() > 2 ? p.substr(2, p.length() - 2) : "")) return true;

            while (matchFirst(s, p)) {
                if (isMatch(s.substr(1, s.length() - 1), p.length() > 2 ? p.substr(2, p.length() - 2) : "")) return true;
                s = s.length() > 1 ? s.substr(1, s.length() - 1) : "";
            }
            return false;
        }
    }
};

TEST(leetcode, regular_expression_matching) {
    EXPECT_EQ(false, Solution().isMatch("aa", "a"));
    EXPECT_EQ(false, Solution().isMatch("aa", "aaa"));
    EXPECT_EQ(true, Solution().isMatch("ab", ".*"));
    EXPECT_EQ(true, Solution().isMatch("aa", "a*"));
    EXPECT_EQ(false, Solution().isMatch("aa", "d*"));
    EXPECT_EQ(true, Solution().isMatch("aab", "c*a*b*"));
    EXPECT_EQ(true, Solution().isMatch("aa", "a*"));
//    贪心，匹配尽可能多的pattern
    EXPECT_EQ(true, Solution().isMatch("aaa", "a*a"));
    EXPECT_EQ(true, Solution().isMatch("aaca", "ab*a*c*a"));
    EXPECT_EQ(false, Solution().isMatch("cc", "a*"));
    EXPECT_EQ(true, Solution().isMatch("aaa", "ab*a*c*a"));
}