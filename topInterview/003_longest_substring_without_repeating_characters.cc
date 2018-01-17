#include <iostream>
#include <vector>
#include <map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int max = 0;
    int left = 0;
    map<char, int> m;
    vector<map<char, int>::iterator> out;
    
    int sz = s.size();
    for (int i = 0; i < sz; i++) {
        auto iter = m.find(s[i]);
        if (iter != m.end()) {
            
            int len = i - left;
            if (len > max) {
                max = len;
            }
            
            left = iter->second + 1;
            for (auto it = m.begin(); it != m.end(); it++) {
                if (it->second < left) {
                    out.push_back(it);
                }
            }
            for (auto it : out) {
                m.erase(it);
            }
            out.clear();
        }
        m[s[i]] = i; 
    }
    
    int len = sz - left;
    return max > len ? max : len ;
}

int main() {
    cout << lengthOfLongestSubstring("c") << endl;
}
