//
// Created by root on 3/6/17.
//

#include <iostream>
#include <gtest/gtest.h>

/**
    Given an integer, convert it to a roman numeral.

    Input is guaranteed to be within the range from 1 to 3999.

    罗马数字共有7个，即Ⅰ（1）、Ⅴ（5）、Ⅹ（10）、Ⅼ（50）、Ⅽ（100）、Ⅾ（500）和Ⅿ（1000）
    * 重复数次：一个罗马数字重复几次，就表示这个数的几倍。
    * 右加左减：
        在较大的罗马数字的右边记上较小的罗马数字，表示大数字加小数字。
        在较大的罗马数字的左边记上较小的罗马数字，表示大数字减小数字。
        左减的数字有限制，仅限于I、X、C。比如45不可以写成VL，只能是XLV
        但是，左减时不可跨越一个位值。比如，99不可以用IC（100-1）表示，而是用XCIX（[100-10]+[10-1]）表示。（等同于阿拉伯数字每位数字分别表示。）
        左减数字必须为一位，比如8写成VIII，而非IIX。
        右加数字不可连续超过三位，比如14写成XIV，而非XIIII。（见下方“数码限制”一项。）
    * 加线乘千：
        在罗马数字的上方加上一条横线或者加上下标的Ⅿ，表示将这个数乘以1000，即是原数的1000倍。
        同理，如果上方有两条横线，即是原数的1000000（1000^2）倍。
    * 数码限制：
        同一数码最多只能连续出现三次，如40不可表示为XXXX，而要表示为XL。
        例外：由于IV是古罗马神话主神朱庇特（即IVPITER，古罗马字母里没有J和U）的首字，因此有时用IIII代替IV。
*/

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        int hardKey[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string hardRoman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string ans;
        int i = 0, l, r;
        while (num) {
            l = num / hardKey[i];
            while (l) {
                ans.append(hardRoman[i]);
                l--;
            }

            num = num % hardKey[i];
            i++;
        }

        return ans;
    }
};

TEST(leetcode, integer_to_roman) {
    string expect = "I";
    EXPECT_EQ(expect, Solution().intToRoman(1));
    string expect1 = "MCMXCIII";
    EXPECT_EQ(expect1, Solution().intToRoman(1993));
}