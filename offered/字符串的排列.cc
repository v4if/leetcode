/*
输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
输入描述:
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
*/

class Solution {
public:
    void bt(string str, int idx, vector<string>& result) {
        int sz = str.size();
        if (idx == sz) {
            result.push_back(str);
        }

        for (int i = idx;i < sz;i++) {
            if (i != idx && str[i] == str[idx]) continue;
            
            swap(str[idx], str[i]);
            bt(str, idx + 1, result);
            swap(str[idx], str[i]);
        }
    }
    vector<string> Permutation(string str) {
        if (str.empty()) return vector<string>{};
        
        vector<string> result;
        bt(str, 0, result);
        sort(result.begin(), result.end());
        return result;
    }
};
