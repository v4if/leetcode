//
// Created by root on 5/1/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
    Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

    For example, given n = 3, a solution set is:
    [
      "((()))",
      "(()())",
      "(())()",
      "()(())",
      "()()()"
    ]
 * */

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        addParen(res, "", n, 0);

        return res;
    }

    void addParen(vector<string>& v, string str, int m_L, int n_R) {
        if (m_L == 0 && n_R == 0) {
            v.push_back(str);
        }

        if (m_L > 0) addParen(v, str + '(', m_L - 1, n_R + 1);
        if (n_R > 0) addParen(v, str + ')', m_L, n_R - 1);
    }
};

TEST(leetcode, generate_parentheses) {
    vector<string> v;
    v = Solution().generateParenthesis(3);
    for (string item : v) {
        cout << item << "  ";
    }
    cout << endl;
}