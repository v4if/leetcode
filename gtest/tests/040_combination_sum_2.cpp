//
// Created by root on 5/21/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
    Given a collection of candidate numbers (C) and a target number (T),
    find all unique combinations in C where the candidate numbers sums to T.

    Each number in C may only be used once in the combination.

    Note:
    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.
    For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
    A solution set is:
    [
      [1, 7],
      [1, 2, 5],
      [2, 6],
      [1, 1, 6]
    ]
 * */

/*
 * 多文件函数重名需要namespace，否则引用混乱
 * */
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        if (candidates.empty()) return result;

        vector<int> vrec;
        sort(candidates.begin(), candidates.end());
        combination2(candidates, 0, target, vrec, result);

        return result;
    }

    void combination2(vector<int>& candidates, int from, int target, vector<int>& vrec, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(vrec);
            return;
        }

        int len = candidates.size();
        for (int i = from; i < len && candidates[i] <= target;) {
            vrec.push_back(candidates[i]);
            combination2(candidates, i + 1, target - candidates[i], vrec, result);
            vrec.erase(find(vrec.begin(), vrec.end(), candidates[i]));

//            去除相同元素的多个解 { { 1, 1, 6 }, { 1, 2, 5 }, { 1, 7 }, { 1, 2, 5 }, { 1, 7 }, { 2, 6 } }
            int next = i;
            while (i < len && candidates[i] == candidates[next]) ++i;
        }
    }
};

TEST(leetcode, combination_sum_2) {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> result = {{ 1, 1, 6 }, { 1, 2, 5 }, { 1, 7 }, { 2, 6 }};
    EXPECT_EQ(result, Solution().combinationSum2(candidates, 8));
}