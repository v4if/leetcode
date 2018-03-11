/*
把只包含因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含因子7。 
习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
*/

//每一个丑数都是由以前的数字乘以2,3,5得到的最小值
//dp[i] = min(dp[j]*{2,3,5}, j:0-i-1, >dp[j-1])
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index < 1) return 0;
        vector<int> dp(index, 1);
        int dir[3] = {2, 3, 5};
        for (int i = 1;i < index;i++) {
            int min = INT32_MAX;
            for (int j = 0;j < i;j++) {
                for (int k = 0;k < 3;k++) {
                    int num = dir[k] * dp[j];
                    if (num > dp[i - 1] && num < min)
                        min = num;
                }
            }
            dp[i] = min;
        }
        return dp[index - 1];
    }
};
