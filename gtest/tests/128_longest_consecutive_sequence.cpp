//
// Created by root on 9/22/17.
//

#include <iostream>
#include <unordered_map>
#include <gtest/gtest.h>

/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
 * */

using namespace std;

namespace longest_consecutive_sequence {
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> map;
        int maxLength = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (map.find(nums[i]) == map.end()) {
                auto left = map.find(nums[i] - 1);
                auto right = map.find(nums[i] + 1);

                int leftSequence = (left != map.end()) ? (left->second) : 0;
                int rightSequence = (right != map.end()) ? (right->second) : 0;
                int fill = leftSequence + rightSequence + 1;
                map[nums[i]] = 1;

                maxLength = max(maxLength, fill);

                map[nums[i] - leftSequence] = fill;
                map[nums[i] + rightSequence] = fill;
            }
        }

        return maxLength;
    }
}

TEST(leetcode, leetcode_longest_consecutive_sequence__Test) {
    using namespace longest_consecutive_sequence;
    vector<int> nums{100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(nums) << endl;
}