#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int>& arr) {
    for (int a : arr) cout << a << " ";
    cout << endl;
}

vector<int> getPath(vector<int>& father, int idx) {
    vector<int> path;
    while(idx != -1) {
        path.push_back(idx);
        idx = father[idx];
    }
//    printVector(path);
    return path;
}

bool dfs(vector<string>& arr, vector<int>& result, vector<int>& used, int curIdx, int idx) {
    if (curIdx == idx) {
        return true;
    } else if (curIdx < arr.size()) {
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[curIdx].at(i) == '1' && !used[i]) {
                result.push_back(i);
                used[i] = 1;
                if (dfs(arr, result, used, i, idx)) return true;
                result.pop_back();
                used[i] = 0;
            }
        }
    }
    return false;
}

int getSplitNode(vector<string> arr, int indexA, int indexB) {
    int sz = arr.size();
    if (arr.size() == 0) return 0;
    vector<int> father(sz, -1);
    vector<int> visited(sz, 0);
    deque<int> dq;
    dq.push_back(0);
    visited[0] = 1;
    while (!dq.empty()) {
        int idx = dq.front();
        dq.pop_front();

        for (int i = 0;i < sz;i++) {
            if (arr[idx].at(i) == '1' && !visited[i]) {
                visited[i] = 1;
                father[i] = idx;
                dq.push_back(i);
            }
        }
    }

    vector<int> pa = getPath(father, indexA);
    vector<int> pb = getPath(father, indexB);
    reverse(pa.begin(), pa.end());
    reverse(pb.begin(), pb.end());
    int maxIdx = ::min(pa.size(), pb.size());
    int i = 0;
    while(i < maxIdx && pa[i] == pb[i]) i++;
    return pa[i-1];
}

int main() {
    freopen("in.txt", "r", stdin);

    vector<string> arr{"01011","10100","01000","10000","10000"};
//    cout << getSplitNode(arr, 1, 2) << endl;
    vector<int> result;
    vector<int> used(arr.size(), 0);
    result.push_back(0);
    used[0] = 1;
    dfs(arr, result, used, 0, 2);
    printVector(result);
}
