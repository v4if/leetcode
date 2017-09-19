//
// Created by root on 9/19/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
 * */

using namespace std;

namespace valid_palindrome {
    bool isPalindrome(string s) {
        if (s.empty())
        {
            return true;
        }

        int l = 0;
        int r = s.size() - 1;

        while (l < r)
        {
            while (!isalnum(s[l]) && l < r) l++;
            while (!isalnum(s[r]) && l < r) r--;
            if (l == r) break;

            if ( tolower(s[l]) != tolower(s[r]))
            {
                return false;
            }
            l++;r--;
        }

        return true;
    }
}

TEST(leetcode, leetcode_valid_palindrome__Test) {
    using namespace valid_palindrome;

    cout << isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << isPalindrome("race a car") << endl;
    cout << isPalindrome("`l;`` 1o1 ??;l`") << endl;
    cout << isPalindrome("`l;`` 131 ??;l`") << endl;
}