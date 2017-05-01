//
// Created by root on 5/1/17.
//

#include <iostream>
#include <gtest/gtest.h>
#include <unordered_map>
#include <stack>

/*
    Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

    The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 * */

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack_P;
        int pos = 0;

        while (pos < s.length()) {
            if (s[pos] == '(' || s[pos] == '[' || s[pos] == '{') {
                stack_P.push(s[pos]);
            } else if (s[pos] == ')' || s[pos] == ']' || s[pos] == '}') {
                if (stack_P.empty()) {
                    return false;
                }
                switch (s[pos]) {
                    case ')' :
                        if (stack_P.top() == '(') {
                            stack_P.pop();
                            break;
                        } else {
                            return false;
                        }
                    case ']' :
                        if (stack_P.top() == '[') {
                            stack_P.pop();
                            break;
                        } else {
                            return false;
                        }
                    case '}' :
                        if (stack_P.top() == '{') {
                            stack_P.pop();
                            break;
                        } else {
                            return false;
                        }
                }
            }

            ++pos;
        }

        if (stack_P.empty()) {
            return true;
        } else {
            return false;
        }
    }
};

class SolutionPerfect {
public:
    bool isValid(string s) {
        stack<char> paren;
        for (char& c : s) {
            switch (c) {
                case '(':
                case '{':
                case '[': paren.push(c); break;
                case ')': if (paren.empty() || paren.top()!='(') return false; else paren.pop(); break;
                case '}': if (paren.empty() || paren.top()!='{') return false; else paren.pop(); break;
                case ']': if (paren.empty() || paren.top()!='[') return false; else paren.pop(); break;
                default: ; // pass
            }
        }
        return paren.empty() ;
    }
};

TEST(leetcode, valid_parentheses) {
//    二进制比较
    EXPECT_EQ(false, Solution().isValid("]"));
}