/*
给你六种面额1、5、10、20、50、100元的纸币，假设每种币值的数量都足够多，编写程序求组成N员（N为0-10000的非负整数）的不同组合的个数。
输入描述:
输入为一个数字N，即需要拼凑的面额
输出描述:
输出也是一个数字，为组成N的组合个数。
示例1
输入

5
输出

2
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("in.txt", "r", stdin);

    int n;
    vector<int> coins{1, 5, 10, 20, 50, 100};
    while(cin >> n) {
        vector<long> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 0;i < coins.size();i++) {
            for (int j = coins[i]; j <= n;j++) {
                dp[j] += dp[j - coins[i]];
            }
        }

        cout << dp[n] << endl;
    }
}
