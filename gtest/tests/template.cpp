//
// Created by root on 2/25/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*

 * */

using namespace std;

class Solution {
public:

};

TEST(leetcode, template) {
//    二进制比较
    EXPECT_EQ(1, 1);
//    浮点型检查
    EXPECT_FLOAT_EQ(1.0, 1.0);
//    字符串比较
    ASSERT_STREQ("str", "str");
}