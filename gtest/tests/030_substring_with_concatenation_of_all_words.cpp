//
// Created by root on 5/7/17.
//

#include <iostream>
#include <unordered_map>
#include <gtest/gtest.h>

/*
    You are given a string, s, and a list of words, words, that are all of the same length.
    Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once
    and without any intervening characters.

    For example, given:
    s: "barfoothefoobarman"
    words: ["foo", "bar"]

    You should return the indices: [0,9].
    (order does not matter).
 * */

using namespace std;

class Solution {
public:
//    滑块窗口，每次滑动距离为words[0]的长度
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        if (s.empty() || words.empty()) return ret;

        int len = words[0].length();
        unordered_map<string, int> pattern;
        for (string word : words) {
            if (pattern.find(word) != pattern.end()) {
                pattern[word]++;
            } else {
                pattern[word] = 1;
            }
        }
//        移动滑块的初始起点，所以循环次数就是单词的长度
        for (int i = 0; i < len; ++i) {
//            当前窗口
            unordered_map<string, int> sliding;
            int start = i;
//            当前窗口包含的words
            int count = 0;
//            包括自身节点 =
            for (int j = i; j + len <= s.length(); j = j + len) {
                string sub = s.substr(j, len);
                if (pattern.find(sub) != pattern.end()) {
                    if (sliding.find(sub) != sliding.end()) {
                        sliding[sub]++;
                    } else {
                        sliding[sub] = 1;
                    }
//                    当前窗口中包含的单词数
                    count++;

//                    窗口向右紧缩
                    while (sliding[sub] > pattern[sub]) {
                        string shift = s.substr(start, len);
                        sliding[shift]--;

                        count--;
                        start = start + len;
                    }

                    if (count == words.size()) {
                        ret.push_back(static_cast<int>(start));

//                        窗口右滑，重置匹配到的第一个词
                        string left = s.substr(start, len);
                        sliding[left]--;
                        count--;
                        start = start + len;
                    }
                } else {
//                    非给出的words，直接右移滑动窗口，重置判断条件
                    start = j + len;
                    count = 0;
                    sliding.clear();
                }
            }
        }

        return ret;
    }
};

TEST(leetcode, substring_with_concatenation_of_all_words) {
    vector<int> result = {};
    vector<string> words = {"mississippis"};
    EXPECT_EQ(result, Solution().findSubstring("mississippi", words));

    result = {0, 9};
    words = {"foo", "bar"};
    EXPECT_EQ(result, Solution().findSubstring("barfoothefoobarman", words));

    result = {8};
    words = {"word","good","best","good"};
    EXPECT_EQ(result, Solution().findSubstring("wordgoodgoodgoodbestword", words));
}