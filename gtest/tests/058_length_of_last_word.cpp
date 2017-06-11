//
// Created by root on 6/11/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5.
 * */

using namespace std;

namespace solve_first {
    int lengthOfLastWord(string s) {
        int ret = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[i] == ' ') s.pop_back();
            else break;
        }
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[i] != ' ') ret++;
            else break;
        }

        return ret;
    }
}

namespace better_solve {
    class Solution {
    public:
//        利用指针避免string的弹出操作，对原string没有破坏
        int lengthOfLastWord(string s) {
            int p = s.length() - 1;
            int len = s.length();
            while (p >= 0 && s[p--] == ' '){
                len--;
            }
            if (len == 0) return 0;
            while(p >=0){
                if (s[p] == ' ') break;
                p--;
            }
            return len - p -1;
        }
    };
}

TEST(leetcode, length_of_last_word) {
    EXPECT_EQ(5, solve_first::lengthOfLastWord("Hello World"));
    EXPECT_EQ(1, solve_first::lengthOfLastWord("a   "));
}