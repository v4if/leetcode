//
// Created by root on 2/25/17.
//

#include <iostream>
#include <unordered_map>
#include <gtest/gtest.h>

/**
    Given a string, find the length of the longest substring without repeating characters.

    Examples:

            Given "abcabcbb", the answer is "abc", which the length is 3.

    Given "bbbbb", the answer is "b", with the length of 1.

    Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;

        unordered_map<char, int> hash;
        int max_length = 1, cur_length = 1;
        hash[s[0]] = 0;
        for (int i = 1; i < s.length();) {
            if (hash.find(s[i]) != hash.end()) {
                if (cur_length > max_length) {
                    max_length = cur_length;
                }
                i = hash[s[i]] + 1;
                cur_length = 0;
                hash.clear();
            } else {
                hash[s[i]] = i;
                cur_length ++;
                i++;
            }
        }

//        au等无重复字符串没有对max_length赋值
        return max_length < cur_length ? cur_length : max_length;
    }
};

TEST(leetcode, longest_substr) {
    EXPECT_EQ(3, Solution().lengthOfLongestSubstring("abcabcbb"));
    EXPECT_EQ(1, Solution().lengthOfLongestSubstring("bbbbb"));
    EXPECT_EQ(3, Solution().lengthOfLongestSubstring("pwwkew"));
    EXPECT_EQ(2, Solution().lengthOfLongestSubstring("au"));
}