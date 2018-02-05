#include <bits/stdc++.h>

using namespace std;

void dfs(int n, int cur, vector<int>& result) {
    for (int i = cur; i <= n; i++) {
        result.push_back(i);
        
        for (int num : result) cout << num << " ";
        cout << "\n";
        dfs(n, i + 1, result);
        
        result.pop_back();
    }
}

void solveit(int n) {
    stack<int> st;
    vector<int> visit;
    vector<int> result;
    st.push(1);
    visit.push_back(1);
    result.push_back(1);
    while (!st.empty()) {
        int cur = st.top();
        bool hasNext = false;
        while(cur < n) {
            cur++;
            if (find(visit.begin(),visit.end(),cur)==visit.end()) {
                st.push(cur);
                visit.push_back(cur);
                result.push_back(cur);
                hasNext = true;
                break;
            }
        }
        if (!hasNext) {
            cur = st.top();
            for (;cur < n; cur++) {
                visit.pop_back();
            }
            st.pop();
            
            for (auto data : result) cout << data << " ";
            cout << "\n";
            result.pop_back();
        }
    }
}

int main() {
    vector<int> result;
    dfs(4, 1, result);

    return 0;
}
