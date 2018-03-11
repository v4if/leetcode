/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/

class Solution {
public:
    int jumpFloor(int number) {
        if (number == 0) return 0;
        
        vector<int> dp(number, 1);
        dp[1] = 2;
        for (int i = 2;i < number; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[number-1];
    }
};
