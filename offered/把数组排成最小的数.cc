/*
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
*/

class Solution {
public:
    static bool cmp(int n1, int n2) {
        //return to_string(n1) + to_string(n2) < to_string(n2) + to_string(n1);
        stringstream ss1;
        ss1 << n1;
        string s1 = ss1.str();
        
        stringstream ss2;
        ss2 << n2;
        string s2 = ss2.str();
        
        return s1+s2 < s2+s1;
    }
    string PrintMinNumber(vector<int> numbers) {
        sort(numbers.begin(), numbers.end(), cmp);
        string str;
        for (int i = 0;i < numbers.size();i++) str += to_string(numbers[i]);
        return str;
    }
};
