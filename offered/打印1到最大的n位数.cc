#include <bits/stdc++.h>
using namespace std;

void printNum(vector<int>& strNum) {
    int idx = 0;
    int sz = strNum.size();
    while (idx < sz && strNum[idx] == 0) idx++;

    for (;idx < sz;idx++) cout << strNum[idx];
    cout << endl;
}

void print1ToMax(vector<int>& strNum, int idx) {
    int sz = strNum.size();
    if (idx == sz) {
        printNum(strNum);
        return;
    }

    for (int i = 0; i < 10; i++) {
        int old = strNum[idx];
        strNum[idx] = i;
        print1ToMax(strNum, idx+1);
        strNum[idx] = old;
    }
}

int main() {
    int n = 3;
    vector<int> strNum(n, 0);
    print1ToMax(strNum, 0);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
