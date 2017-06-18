//
// Created by root on 6/17/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.
 * */

using namespace std;

namespace solve_first {
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;

        for (int i = 0; i < (int)words.size();) {
            int cnt = 0;
            int lower_bound = i;
            while (i < (int)words.size() && cnt + (int) words[i].size() + (i - lower_bound - 1)< maxWidth) {
                cnt += words[i].size();
                ++i;
            }

            int nums_blank = i - lower_bound - 1;
//            向下取整
            int slots = nums_blank > 1 ? (maxWidth - cnt) / (i - lower_bound - 1) : 0;
//            这里空格具体怎么算没读懂题意
            int left = nums_blank > 1 ? (maxWidth - cnt) - slots * ((i - lower_bound - 1 - 1)) : maxWidth - cnt;

//            当前是最后一行
            if (i == (int)words.size()) {
                left = 1;
                slots = 1;
            }

            ans.push_back(words[lower_bound]);
            lower_bound++;
            if (lower_bound < i) ans.back().append(string(left, ' '));

            while (lower_bound < i - 1) {
                ans.back().append(words[lower_bound]);
                ans.back().append(string(slots, ' '));
                lower_bound++;
            }
            if (lower_bound < i) {
                ans.back().append(words[lower_bound]);
            }

            int pad = (int)ans.back().size();
            if (pad < maxWidth) {
                ans.back().append(string(maxWidth - pad, ' '));
            }
        }

        return ans;
    }
}

TEST(leetcode, text_justfication) {
    vector<string> result{   "This    is    an",
                             "example  of text",
                             "justification.  "};
    vector<string> words{"This", "is", "an", "example", "of", "text", "justification."};
    EXPECT_EQ(result, solve_first::fullJustify(words, 16));

    words = {"What","must","be","shall","be."};
    result = {"What must be","shall be.   "};
    EXPECT_EQ(result, solve_first::fullJustify(words, 12));

    words = {""};
    result = {""};
    EXPECT_EQ(result, solve_first::fullJustify(words, 0));

    words = {"a"};
    result = {"a"};
    EXPECT_EQ(result, solve_first::fullJustify(words, 1));

    words = {"Don't","go","around","saying","the","world","owes","you","a","living;","the"};
    result = {"Don't  go  around  saying  the","world  owes  you a living; the"};
    EXPECT_EQ(result, solve_first::fullJustify(words, 30));
}