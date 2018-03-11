/*
在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置
*/

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        map<char, int> mp;
        int sz = str.size();
        for (int i = 0;i < sz;i++) {
            if (mp.count(str[i]) == 0) mp[str[i]] = 1;
            else mp[str[i]] += 1;
        }
        
        for (int i = 0;i < sz;i++) {
            if (mp[str[i]] == 1) return i;
        }
        return -1;
    }
};
