//
// Created by root on 6/4/17.
//

#include <iostream>
#include <gtest/gtest.h>
#include <unordered_map>
#include <algorithm>

/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
 * */

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> tuple;
        vector<vector<int>> ret;
        unordered_map<int, bool> visited;

        sort(nums.begin(), nums.end());
        recursive2(nums, visited, 0, tuple, ret);

        return ret;
    }

    void recursive2(vector<int>& nums, unordered_map<int, bool> visited, int n, vector<int>& tuple, vector<vector<int>>& ret) {
        int len = nums.size();
        if (n == len) {
            ret.push_back(tuple);
            return;
        }

        for (int i = 0; i < len; ++i) {
            if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == false) continue;

            if (!visited[i]) {
                visited[i] = true;

                tuple.push_back(nums[i]);
                recursive2(nums, visited, n + 1, tuple, ret);
                tuple.pop_back();

                visited[i] = false;
            }
        }
    }
};

TEST(leetcode, permutations2) {
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> ret = Solution().permuteUnique(nums);
    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j < ret[i].size(); ++j) {
            cout << ret[i][j] << "  ";
        }
        cout << endl;
    }

    nums = {3,3,0,0,2,3,2};
    ret = Solution().permuteUnique(nums);
    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j < ret[i].size(); ++j) {
            cout << ret[i][j] << "  ";
        }
        cout << endl;
    }

    nums = {1, 2};
    ret = Solution().permuteUnique(nums);
    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j < ret[i].size(); ++j) {
            cout << ret[i][j] << "  ";
        }
        cout << endl;
    }
}