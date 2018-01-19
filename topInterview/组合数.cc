#include <iostream>
#include <vector>

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

int main() {
    vector<int> result;
    dfs(4, 1, result);

    return 0;
}
