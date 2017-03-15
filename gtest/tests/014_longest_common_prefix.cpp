//
// Created by root on 3/15/17.
//

#include <iostream>
#include <vector>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";

        if (strs.empty()) {
            return prefix;
        }

        int minSize = strs[0].size(), s;
        for (int i = 0; i < strs.size(); ++i) {
            s = strs[i].size();
            minSize = s < minSize ? s : minSize;
        }

        char ch;
        bool search = true;
        for (int j = 0; j < minSize; ++j) {
            ch = strs[0].at(j);
            for (int i = 1; i < strs.size(); ++i) {
                if (ch != strs[i].at(j)) {
                    search = false;
                    break;
                }
            }

            if (search) {
                prefix.push_back(ch);
            } else {
                break;
            }
        }

        return prefix;
    }

    string longestCommonPrefixPerfect(vector<string>& strs) {
        string prefix = "";
        for(int idx=0; strs.size()>0; prefix+=strs[0][idx], idx++)
            for(int i=0; i<strs.size(); i++)
                if(idx >= strs[i].size() ||(i > 0 && strs[i][idx] != strs[i-1][idx]))
                    return prefix;
        return prefix;
    }
};

TEST(leetcode, longest_common_prefix) {
    vector<string> sample;
    sample.push_back("prefix_test");
    sample.push_back("prefix_common");
    sample.push_back("prefix_gtest");
    EXPECT_EQ("prefix_", Solution().longestCommonPrefix(sample));
}