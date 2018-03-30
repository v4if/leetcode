#include <bits/stdc++.h>
using namespace std;

bool valid(const string& str, int idx, const string& sub){
    for (int i = 0;i < sub.size();i++) {
        if (str[idx + i] != sub[i]) return false;
    }
    return true;
}
int substringindex(const std::string &str, const std::string &sub) {
    if (str.size() < sub.size() || sub.empty()) return -1;

    int back = str.size() - sub.size();
    for (int i = 0;i <= back;i++) {
        if (valid(str, i, sub)) return i;
    }
    return -1;
}

void getNext(string& sub, vector<int>& next) {
    if (sub.empty()) return;

    next[0] = -1;
    int j = 1, k = -1;
    while(j < sub.size()) {
        if (k == -1 || sub[j] == sub[k]) {
            j++;
            k++;
            next[j] = k;
        } else {
            k = next[k];
        }
    }
}

int kmp(string& str, string& sub) {
    if (str.size() < sub.size() || sub.empty()) return -1;

    vector<int> next(sub.size(), 0);
    getNext(sub, next);

    int i = 0, j = 0;
    int sz1 = str.size();
    int sz2 = sub.size();
    while(i < sz1 && j < sz2) {
        if (j == -1 || str[i] == sub[j]) {
            i++;j++;
        } else {
            j = next[j];
        }
    }

    return j == sub.size() ? i - j : -1;
}

int main () {
    string str{"abcadabcabcad"};
    string sub{"abcabcad"};
    cout << kmp(str, sub) << endl;
    return 0;
}
