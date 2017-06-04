//
// Created by root on 6/4/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
    Given an array of non-negative integers, you are initially positioned at the first index of the array.

    Each element in the array represents your maximum jump length at that position.

    Your goal is to reach the last index in the minimum number of jumps.

    For example:
    Given array A = [2,3,1,1,4]

    The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
 * */

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.empty()) return 0;
        return recursive(nums, 0, 0);
    }

    int recursive(const vector<int>& nums, int n, int iter) {
        int len = nums.size();
        if (n == len - 1) return iter;
        if (n >= len) return INT32_MAX;

        int step = nums[n];
        if (step == 0) return INT32_MAX;

        vector<int> v;
        for (int i = 1; i <= step; ++i) {
            int result = recursive(nums, n + i, iter + 1);
            v.push_back(result);
        }
        return *min_element(v.begin(), v.end());
    }
};

namespace jump_game2_dp {
    class Solution {
    public:
        int jump(vector<int>& nums) {
            int n = nums.size();

            if (n <= 1) return 0;

            vector<int> dp(n, 0);
            for (int i = 1; i < n; ++i) {
                int min = INT32_MAX;
                for (int j = 0; j < i; ++j) {
                    if ((j + nums[j] >= i) && (dp[j] + 1 < min)) {
                        min = dp[j] + 1;
                    }
                }
                dp[i] = min;
            }

            return dp[n - 1];
        }
    };
}

namespace jump_game2_greedy {
    class Solution {
    public:
        int jump(vector<int>& nums) {
            int n = nums.size();

            if (n <= 1) return 0;

            int last, curr, ret;
            last = curr = ret = 0;
            for (int i = 0; i < n; ++i) {
                if (i > last) {
                    last = curr;
                    ret++;
                }

                curr = max(curr, nums[i] + i);
            }

            return ret;
        }
    };
}

TEST(leetcode, jump_game2) {
    vector<int> nums = {2,3,1,1,4};
    EXPECT_EQ(2, jump_game2_greedy::Solution().jump(nums));

    nums = {3, 2, 0, 1};
    EXPECT_EQ(1, jump_game2_greedy::Solution().jump(nums));

    nums = {2, 3, 1};
    EXPECT_EQ(1, jump_game2_greedy::Solution().jump(nums));
}