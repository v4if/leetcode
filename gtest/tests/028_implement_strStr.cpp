//
// Created by root on 5/6/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
    Implement strStr().

    Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 * */

using namespace std;

class SolutionBrute {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;

        int i, j;
        for (i = 0; i < haystack.length(); ++i) {
            for (j = 0; j < needle.length(); ++j) {
                if (haystack[i + j] != needle[j]) break;
            }

            if (j == needle.length()) return i;
        }

        return -1;
    }
};

class Solution {
public:
    int* genNext(string patt) {
        int k = -1;
        int *next = new int[patt.length() + 1];

        next[0] = -1;
        for (int i = 0; i < patt.length();) {
            if (k == -1 || patt[i] == patt[k]) next[++i] = ++k;
            else k = next[k];
        }

        return next;
    }

    int* genNextOptimize(string patt) {
        int k = -1;
        int *next = new int[patt.length() + 1];

        next[0] = -1;
        for (int i = 0; i < patt.length();) {
            if (k == -1 || patt[i] == patt[k]) {
                if (patt[++i] != patt[++k]) next[i] = k;
//                继续回退
                else next[i] = next[k];
            }
            else k = next[k];
        }

        return next;
    }

    int strStr(string haystack, string needle) {
        int *next = genNextOptimize(needle);

        int i = 0, k = 0;
        while (i < haystack.length() && k < (int)needle.length()) {
            if (k == -1 || needle[k] == haystack[i]) {
                ++i;
                ++k;
            } else {
//                回退
                k = next[k];
            }
        }


        free(next);
        if (k >= needle.length()) {
            return i - static_cast<int>(needle.length());
        } else {
            return -1;
        }
    }
};

TEST(leetcode, implement_strStr) {

    EXPECT_EQ(-1, Solution().strStr("mississippi", "issipi"));
}