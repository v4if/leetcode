/**
题目描述
读入一个字符串str，输出字符串str中的连续最长的数字串
输入描述:
个测试输入包含1个测试用例，一个字符串str，长度不超过255。
输出描述:
在一行内输出str中里连续最长的数字串。
示例1
输入

abcd12345ed125ss123456789
输出

123456789
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin >> str;
    {
        int l = -1,r = 0;
        int max = 0;
        int max_l = -1, max_r = 0;
        for (int i = 0;i < str.size();i++){
            if (str[i] >= '0' && str[i] <= '9') r = i + 1;
            else l = i;
            
            if (r - l - 1 > max) {
                max = r - l - 1;
                max_l = l;
                max_r = r;
            }
        }
        
        for (int i = max_l + 1;i < max_r;i++) cout << str[i];
        cout << endl;
    }
}
