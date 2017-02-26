//
// Created by root on 2/25/17.
//

#include <iostream>
#include <gtest/gtest.h>

/**
    The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

    P   A   H   N
    A P L S I I G
            Y   I   R
    And then read line by line: "PAHNAPLSIIGYIR"
    Write the code that will take a string and make this conversion given a number of rows:

    string convert(string text, int nRows);
    convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 */

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) {
            return s;
        }

//        string和vector是不是同一个东西，new出来是一个指针！？
//        纵向为numRows，横向为可以push_back的string
        string *str = new string[numRows];
        int row = 0, step = 1;
        for (int i = 0; i < s.length(); ++i) {
            str[row].push_back(s[i]);

            if (row == 0) {
                step = 1;
            }

            if (row == numRows - 1) {
                step = -1;
            }

            row += step;
        }

        s.clear();
        for (int j = 0; j < numRows; ++j) {
            s.append(str[j]);
        }
        delete[] str;

        return s;
    }
};

TEST(leetcode, zigzag_conversion) {
    string str;
    str.push_back('c');
    str.append("hello world");
    cout << str << endl;

    EXPECT_EQ("PAHNAPLSIIGYIR", Solution().convert("PAYPALISHIRING", 3));
}