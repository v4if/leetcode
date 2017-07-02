//
// Created by root on 2017/7/1.
//

#include <iostream>
#include <gtest/gtest.h>
#include <unordered_set>
#include <unordered_map>
#include <queue>
/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
 * */

using namespace std;

namespace solve_first {
    string minWindow(string s, string t) {
        if (s.length() < t.length() || s.length() == 0 || t.length() == 0) return "";

        unordered_map<char, int> character;
        for (int i = 0; i < t.length(); ++i) {
            if (character.find(t[i]) != character.end()) {
                character[t[i]]++;
            } else {
                character[t[i]] = 1;
            }
        }
        int count = t.length();

        int left = 0;
        int right = 0;
        int cnt = 0;
        int min_len = s.length() + 1;
        int min_start = 0;
        for (int right = 0; right < s.length(); ++right) {
            if (character.find(s[right]) != character.end()) {
                character[s[right]]--;
                if (character[s[right]] >= 0) cnt++;
//                找到一个包含串
                while (cnt == count) {
                    if (right - left + 1 < min_len) {
                        min_len = right - left + 1;
                        min_start = left;
                    }
//                    窗口左边界右滑
                    if (character.find(s[left]) != character.end()) {
                        character[s[left]]++;
                        if (character[s[left]] > 0) cnt--;
                    }
                    left++;
                }
            }
        }

        if (min_len > s.length()) return "";
        return s.substr(min_start, min_len);
    }
}

namespace solve_best{
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) {
            return "";
        }

        vector<int> dict(128, 0);
        for (const char& c: t) {
            ++dict[c];
        }

        int count = 0, begin = -1, end = -1;
        for (int i = 0, j = 0; i < s.size(); ++i) {
            if (dict[s[i]] > 0) {
                ++count;
            }
            --dict[s[i]];
            while (j <= i && count >= t.size()) {
                if (begin < 0 || i - j < end - begin) {
                    end = i;
                    begin = j;
                }
                if (dict[s[j]] >= 0) {
                    --count;
                }
                ++dict[s[j]];
                ++j;
            }
        }

        return begin >= 0 ? s.substr(begin, end - begin + 1) : "";
    }
}

TEST(leetcode, leetcode_minimum_window_substring_test) {
    string s{"ab"};
    string t{"b"};
    string ans = solve_best::minWindow(s, t);
    cout << ans << endl;
}