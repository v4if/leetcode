//
// Created by root on 5/20/17.
//

#include <iostream>
#include <gtest/gtest.h>
#include <numeric>

/*
    Given a set of candidate numbers (C) (without duplicates) and a target number (T),
    find all unique combinations in C where the candidate numbers sums to T.

    The same repeated number may be chosen from C unlimited number of times.

    Note:
    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.
    For example, given candidate set [2, 3, 6, 7] and target 7,
    A solution set is:
    [
      [7],
      [2, 2, 3]
    ]
 * */

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;

        if (candidates.empty()) return result;

        vector<int> v;
        sort(candidates.begin(), candidates.end());
        combination(candidates, 0, target, v, result);
        return result;
    }

//    递归：首先判断结束条件，注意递归之间变量的清除
    void combination(vector<int>& candidates, int from, int remains, vector<int> &v, vector<vector<int>>& result) {
        if (remains == 0) {
            result.push_back(v);
            return;
        }

//        递归求解所有组合
//        from限制多重解 {2, 2, 3} {2, 3, 2} {3, 2, 2}
        for (int i = from; i < candidates.size() && candidates[i] <= remains;++i) {
            v.push_back(candidates[i]);
            combination(candidates, i, remains - candidates[i], v, result);
            v.erase(find(v.begin(), v.end(), candidates[i]));
        }
    }
};

TEST(leetcode, combination_sum) {
    vector<int> candidates = {2, 3, 6, 7};
    vector<vector<int>> result = {{2, 2, 3}, {7}};
    EXPECT_EQ(result, Solution().combinationSum(candidates, 7));

    candidates = {1, 2};
    result = {{1}};
    EXPECT_EQ(result, Solution().combinationSum(candidates, 1));

    candidates = {3, 5, 7};
    result = {{3, 3, 3}};
    EXPECT_EQ(result, Solution().combinationSum(candidates, 9));

    candidates = {8, 7, 4, 3};
    result = {{3, 4, 4}, {3, 8}, {4, 7}};
    EXPECT_EQ(result, Solution().combinationSum(candidates, 11));
}