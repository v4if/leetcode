#include <bits/stdc++.h>
using namespace std;

/*
1 1 2 2 4 4 8 8
*/
int main(){
    freopen("in.txt", "r", stdin);
    int n = 0;
    while(cin >> n) {
        int k = (int)(log(n) / log(2));
        vector<int> arr((k + 1) * 2, 0);
        for (int i = 0;i <= k;i++) {
            arr[i * 2] = 1 << i;
            arr[i * 2 + 1] = 1 << (i + 1);
        }

        int dp[n + 1] = {0};
        dp[0] = 1;
        for (int i = 0;i <= k; i++) {
            for (int j = n;j >= 0;j--) {
                dp[j] = dp[j] + (j >= arr[i * 2] ? dp[j - arr[i * 2]] : 0) + (j >= arr[i * 2 + 1] ? dp[j - arr[i * 2 + 1]] : 0);
            }
        }

        cout << dp[n] << endl;
    }
}
