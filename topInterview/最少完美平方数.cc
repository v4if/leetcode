#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int perfectSquare(int x){
    vector<int> dp(x + 1, 0);
    
    int sz = dp.size();
    dp[0] = dp[1] = 1;
    for (int i = 2; i < sz; i++) {
        int temp = sqrt(i);
        if (temp * temp == i) dp[i] = 1;
        else {
            int half = i / 2;
            int min = dp[1] + dp[i - 1];
            for (int j = 2; j <= half; j++) {
                int sum = dp[j] + dp[i - j];
                if (sum < min) {
                    min = sum;
                }
            }
            dp[i] = min;
        }
    }
    return dp[x];
}

int main() {
    cout << perfectSquare(100) << endl;
}
