/**
题目描述
有 n 个学生站成一排，每个学生有一个能力值，牛牛想从这 n 个学生中按照顺序选取 k 名学生，要求相邻两个学生的位置编号的差不超过 d，使得这 k 个学生的能力值的乘积最大，你能返回最大的乘积吗？
输入描述:
每个输入包含 1 个测试用例。每个测试数据的第一行包含一个整数 n (1 <= n <= 50)，表示学生的个数，接下来的一行，包含 n 个整数，按顺序表示每个学生的能力值 ai（-50 <= ai <= 50）。接下来的一行包含两个整数，k 和 d (1 <= k <= 10, 1 <= d <= 50)。
输出描述:
输出一行表示最大的乘积。
示例1
输入

3
7 4 7
2 50
输出

49
*/

/**
DP问题求解的时候从底向上，递归问题从上到下
但是在思考递归问题，列状态转移方程的时候要从上往下思考，因为得求dp[i]与dp[i-1]的关系，能通过当前状态得到下一状态就成了。。。
好多都是从最后一个arr的元素作为最后一个选取开始思考
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    while(cin >> n) {
        vector<int> arr(n);
        for (int i = 0;i< n;i++) {
            cin >> arr[i];
        }
        
        int k,d;
        cin >> k >> d;
        vector<vector<long>> dp_max(n,vector<long>(k+1,0));
        vector<vector<long>> dp_min(n,vector<long>(k+1,0));
        for (int i = 0;i< n;i++) {
            dp_max[i][1]=arr[i];
            dp_min[i][1]=arr[i];
        }
        
        for (int i=2;i<= k;i++){
            for (int j=0;j<n;j++){
                for (int m=1;m<=d&&j-m>=0;m++){
                    dp_max[j][i]=::max(::max(dp_max[j-m][i-1]*arr[j],dp_min[j-m][i-1]*arr[j]), dp_max[j][i]);
                    dp_min[j][i]=::min(::min(dp_max[j-m][i-1]*arr[j],dp_min[j-m][i-1]*arr[j]), dp_min[j][i]);
                }
            }
        }
        
        long max_value=dp_max[k-1][k];
        for (int i=k;i< n;i++){
            if (dp_max[i][k]> max_value)max_value=dp_max[i][k];
        }
        cout << max_value << endl;
    }
    return 0;
}
