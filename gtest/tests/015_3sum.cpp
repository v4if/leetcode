//
// Created by root on 3/15/17.
//

#include <iostream>
#include <algorithm>
#include <set>
#include <gtest/gtest.h>

/*
    Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

    Note: The solution set must not contain duplicate triplets.

    For example, given array S = [-1, 0, 1, 2, -1, -4],

    A solution set is:
    [
      [-1, 0, 1],
      [-1, -1, 2]
    ]
 * */

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<int> visited;
        sort(nums.begin(), nums.end());

//        遍历，然后双向指针取target值，重复值去掉
        for (int i = 0; i < nums.size(); ++i) {
            if (find(visited.begin(), visited.end(), nums[i]) != visited.end()) {
                continue;
            }

            visited.insert(nums[i]);

            int target = -nums[i];
            int front = i + 1;
            int end = nums.size() - 1;

            while (front < end) {
                int sums = nums[front] + nums[end];

                if (sums < target) {
                    front++;
                } else if (sums > target) {
                    end--;
                } else {
                    //vector<T> v(n,i)形式，v包含n 个值为 i 的元素
                    vector<int> triplet(3, 0);
                    triplet[0] = nums[i];
                    triplet[1] = nums[front];
                    triplet[2] = nums[end];
                    ans.push_back(triplet);

//                    处理相同元素
                    while (front < end && nums[front] == triplet[0]) front++;
                    while (front < end && nums[end] == triplet[2]) end--;
                }
            }
        }

        return ans;
    }
};

TEST(leetcode, _3sum) {
    int myints[] = {-1, 0, 1, 2, -1, -4};
    std::vector<int> myvector (myints, myints + 6);

    vector<vector<int>> result;
    result = Solution().threeSum(myvector);

    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << "  " << endl;
        }
        cout << endl;
    }
}