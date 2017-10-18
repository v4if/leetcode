//
// Created by root on 10/15/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]
 * */

using namespace std;

namespace palindrome_partition {
    bool isPalindrome(string str) {
        if (str.length() < 2) return true;

        size_t len = str.length();
        for (int i = 0; i < len / 2; ++i) {
            if (str[i] != str[len - i - 1]) return false;
        }

        return true;
    }

    void helper(string str, vector<string>& v, vector<vector<string>>& ret) {
        if (str.empty()) {
            ret.push_back(v);
            return;
        }

        for (size_t i = 0; i < str.length(); ++i) {
            if (isPalindrome(str.substr(0, i + 1))) {
                v.push_back(str.substr(0, i + 1));
                helper(str.substr(i + 1, str.length() - i - 1), v, ret);
                v.pop_back();
            }

        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> v;
        vector<vector<string>> ret;
        helper(s, v, ret);
        return ret;
    }
}

TEST(leetcode, leetcode_palindrome_partition_myTest) {
    using namespace palindrome_partition;
    vector<vector<string>> ret = palindrome_partition::partition("aab");
    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j < ret[i].size(); ++j) {
            std::cout << ret[i][j] << " ";
        }
        std::cout << "\n";
    }
}