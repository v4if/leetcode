//
// Created by root on 5/13/17.
//

#include <iostream>
#include <gtest/gtest.h>
#include <stack>

/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 * */

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int start = -1;
        stack<int> left;
        int max_len = 0;

        const int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                left.push(i);
            } else {
                if (left.empty()) {
//                    左侧匹配失效
                    start = i;
                } else {
                    left.pop();
                    if (left.empty()) {
//                        完整匹配 valid group
                        max_len = max(max_len, i - start);
                    } else {
//                        当前栈顶所在index
//                        栈内还有'('，一个最外的group还没有匹配完成
                        max_len = max(max_len, i - left.top());
                    }
                }
            }
        }

        return max_len;
    }
};

TEST(leetcode, longest_valid_parentheses) {
    EXPECT_EQ(4, Solution().longestValidParentheses(")()())"));
    EXPECT_EQ(2, Solution().longestValidParentheses("()(()"));
}