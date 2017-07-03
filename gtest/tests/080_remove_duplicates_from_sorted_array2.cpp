//
// Created by root on 2017/7/3.
//

#include <iostream>
#include <gtest/gtest.h>

/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3.
It doesn't matter what you leave beyond the new length.
 * */

using namespace std;

namespace solve_first {
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        int right = 1;
        int cnt = 1;
        int last_num = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == last_num) {
                cnt++;
            } else {
                cnt = 1;
                last_num = nums[i];
            }
            if (cnt <= 2) {
                if (i != right) swap(nums[right], nums[i]);
                right++;
            }
        }

        return right;
    }
}

TEST(leetcode, remove_duplicates_from_sorted_array2) {
    vector<int> nums{1,1,1,2,2,2,3,3};
    cout << solve_first::removeDuplicates(nums) << endl;
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
}