//
// Created by root on 3/6/17.
//

#include <iostream>
#include <unordered_map>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        char hardKey[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        int hardNum[] = {1, 5, 10, 50, 100, 500, 1000};

        unordered_map<char, int> hardRoman;
        for (int i = 0; i < sizeof(hardKey); ++i) {
            hardRoman[hardKey[i]] = hardNum[i];
        }

        int ans = 0;
        for (int j = 0; j < s.length(); ++j) {
//            左减的数字
            if (j != s.length() - 1 && startWithLeftSubValue(hardRoman, s.substr(j, s.length() - j))) {
                ans += hardRoman[s[j + 1]] - hardRoman[s[j]];
                j++;
            } else {
                ans += hardRoman[s[j]];
            }
        }

        return ans;
    }

    bool startWithLeftSubValue (unordered_map<char, int> hardRoman, string str) {
        char leftSubValue[] = {'I', 'X', 'C'};
        bool isPrefix = false;
        for (int i = 0; i < sizeof(leftSubValue); ++i) {
            if (leftSubValue[i] == str[0]) {
                isPrefix = true;
                break;
            }
        }

        if (!isPrefix) return false;

        if (hardRoman[str[1]] > hardRoman[str[0]]) return true;
        else return false;
    }
};

TEST(leetcode, roman_to_integer) {
    EXPECT_EQ(1993, Solution().romanToInt("MCMXCIII"));
}