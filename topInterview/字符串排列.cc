#include<bits/stdc++.h>
using namespace std;

    void bt(string str, int idx, vector<bool>& used, vector<char>& result, vector<string>& answer) {
        int sz = str.size();
        if (idx == sz) {
            string re(result.begin(), result.end());
            answer.push_back(re);
        }
        
        for (int i = 0;i < sz;i++) {
            if (i!=0 && str[i-1] == str[i] && !used[i-1]) continue;
            if (!used[i]) {
                used[i] = true;
                result.push_back(str[i]);
                bt(str, idx + 1, used, result, answer);
                result.pop_back();
                used[i] = false;
            }
        }
    }
    vector<string> Permutation(string str) {
        if (str.empty()) return vector<string>{};
        
        sort(str.begin(), str.end());
        
        vector<string> answer;
        vector<bool> used(str.size(), false);
        vector<char> result;
        bt(str, 0, used, result, answer);
        return answer;
    }
int main(){
    vector<string> strPerm = Permutation("bbbbc");
    for (auto str : strPerm) cout << str << endl;
}

//==========================================================
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
