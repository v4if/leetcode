#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int>& arr) {
    for (int a : arr) cout << a << " ";
    cout << endl;
}

int getDis(vector<int> arr, int n) {
    if (n == 0) return 0;
    vector<int> leftMin(n, 0);
    for (int i = 0;i < n;i++) leftMin[i] = arr[i];

    deque<int> dq;
    dq.push_front(arr[0]);
    for (int i = 1; i< n;i++) {
        if (dq.front() < arr[i]) {
            leftMin[i] = dq.front();
        } else {
            while(!dq.empty() && dq.front() >= arr[i]) {
                dq.pop_front();
            }
            dq.push_front(arr[i]);
        }
    }

//    printVector(leftMin);
    int maxValue = arr[0] - leftMin[0];
    for (int i = 1;i < n;i++) {
        maxValue = ::max(maxValue, arr[i] - leftMin[i]);
    }
    return maxValue;
}

int main() {
    freopen("in.txt", "r", stdin);

    vector<int> arr{2676,4662,8383,357,6595};
    cout << getDis(arr, arr.size()) << endl;
}
