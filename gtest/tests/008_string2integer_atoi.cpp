//
// Created by root on 2/26/17.
//

#include <iostream>
#include <gtest/gtest.h>

/**
    Implement atoi to convert a string to an integer.

    Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
 */

using namespace std;

class Solution {
public:
//    1a aa -123 溢出 2.54 +1
    int myAtoi(string str) {
//        ans定义为long，比返回值的存储范围要大
        long ans = 0, num;
//      若非空第一个字母非数字，只允许是+ -
        int i, sign = 1;
        for (i = 0; i < str.length(); ++i) {
            if (str[i] != ' ') {
                if (str[i] == '+') {
                    i++;
                } else if (str[i] == '-') {
                    i++;
                    sign = -1;
                }
                break;
            }
        }

        for (; i < str.length(); ++i) {
            if (str[i] >= 0x30 && str[i] <= 0x39) {
                num = str[i] - '0';
                ans = ans * 10 + num * sign;
//                溢出处理
                if (ans >= INT32_MAX) return INT32_MAX;
                if (ans <= INT32_MIN) return INT32_MIN;
//                ans = temp;
            } else {
                break;
            }
        }

        return ans;
    }
};

class Solution1 {
public:
    int myAtoi(string str) {
        long result = 0;
        int indicator = 1;
        for(int i = 0; i<str.size();)
        {
            i = str.find_first_not_of(' ');
            if(str[i] == '-' || str[i] == '+')
                indicator = (str[i++] == '-')? -1 : 1;
            while('0'<= str[i] && str[i] <= '9')
            {
                result = result*10 + (str[i++]-'0');
                if(result*indicator >= INT32_MAX) return INT32_MAX;
                if(result*indicator <= INT32_MIN) return INT32_MIN;
            }
            return result*indicator;
        }
    }
};

TEST(leetcode, string2integer_atoi) {
    EXPECT_EQ(1, Solution().myAtoi("1"));
    EXPECT_EQ(1, Solution().myAtoi("1a"));
    EXPECT_EQ(NULL, Solution().myAtoi("aa"));
    EXPECT_EQ(2147483647, Solution().myAtoi("2147483648"));
    EXPECT_EQ(-2147483648, Solution().myAtoi("-2147483649"));
    EXPECT_EQ(2147483647, Solution().myAtoi("10522545459"));
    EXPECT_EQ(-123, Solution().myAtoi("-123"));
    EXPECT_EQ(1, Solution().myAtoi("+1"));
    EXPECT_EQ(10, Solution().myAtoi("010"));
}