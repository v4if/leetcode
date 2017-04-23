//
// Created by root on 4/23/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
    Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
    Find all unique quadruplets in the array which gives the sum of target.

    For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
    A solution set is:
    [
      [-1,  0, 0, 1],
      [-2, -1, 1, 2],
      [-2,  0, 0, 2]
    ]
 * */

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
//        pair是将2个数据组合成一个数据
        set<pair<int, int>> visited;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (visited.find(pair<int, int>(nums[i], nums[j])) != visited.end()) {
                    continue;
                }
                visited.insert(pair<int, int>(nums[i], nums[j]));

                int front = j + 1;
                int end = nums.size() - 1;

                while (front < end) {
                    int aim = target - nums[i] - nums[j];
                    int sums = nums[front] + nums[end];

                    if (sums < aim) {
                        front++;
                    } else if (sums > aim) {
                        end--;
                    } else {
                        vector<int> tuple(4, 0);
                        tuple[0] = nums[i];
                        tuple[1] = nums[j];
                        tuple[2] = nums[front];
                        tuple[3] = nums[end];
                        result.push_back(tuple);

//                        重复元素
                        while (front < end && nums[front] == tuple[2]) front++;
                        while (front < end && nums[end] == tuple[3]) end--;
                    }

                }
            }
        }

        return result;
    }
};

TEST(leetcode, _4sum) {
    int mybaits[] = {1, 0, -1, 0, -2, 2};
    vector<int> myvector(mybaits, mybaits + 6);

    vector<vector<int>> expect;
    vector<int> tuple(4, 0);
    tuple[0] = -2;
    tuple[1] = -1;
    tuple[2] = 1;
    tuple[3] = 2;
    expect.push_back(tuple);
    tuple[0] = -2;
    tuple[1] = 0;
    tuple[2] = 0;
    tuple[3] = 2;
    expect.push_back(tuple);
    tuple[0] = -1;
    tuple[1] = 0;
    tuple[2] = 0;
    tuple[3] = 1;
    expect.push_back(tuple);

    vector<vector<int>> result;
    result = Solution().fourSum(myvector, 0);

    for (int i = 0; i < expect.size(); ++i) {
        for (int j = 0; j < expect[i].size(); ++j) {
            EXPECT_EQ(expect[i][j], result[i][j]);
//            cout << result[i][j] << endl;
        }
//        cout << endl;
    }
}