//
// Created by root on 4/23/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*

    Given a digit string, return all possible letter combinations that the number could represent.

    A mapping of digit to letters (just like on the telephone buttons).

    Input:Digit string "23"
    Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].Input:Digit string "23"
    Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

 * */

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            return result;
        }

        string phoneMap[] = {" ", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        result.push_back("");

//        遍历拿到的数字，然后将result和phoneMap组合，更新result
        for (int i = 0; i < digits.size(); ++i) {
            int c = digits[i] - 0x30;
            vector<string> buff;
            for (int j = 0; j < result.size(); ++j) {
                for (int k = 0; k < phoneMap[c].size(); ++k) {
                    buff.push_back(result[j] + phoneMap[c][k]);
                }
            }

//            result.swap(buff);
            result.erase(result.begin(), result.end());
            for (int l = 0; l < buff.size(); ++l) {
                result.push_back(buff[l]);
            }
        }

        return result;
    }
};

TEST(leetcode, letter_combinations) {
    string mystring[] = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    vector<string> myvector(mystring, mystring + 9);
    EXPECT_EQ(myvector, Solution().letterCombinations("23"));
}