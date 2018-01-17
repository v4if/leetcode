#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> twosum(vector<int>& nums, int target) {
    map<int, int> m;
    int sz = nums.size();
    for (int i = 0; i < sz; i++) {
        int remain = target - nums[i];
        auto iter = m.find(remain);
        if (iter != m.end()) {
            return vector<int>{iter->second, i};
        } else {
            m[nums[i]] = i;
        }
    }
    
    return vector<int>{};
}

int main() {
    vector<int> nums{1,2,3,4};
    vector<int> result = twosum(nums, 5);
    for (int r : result) {
        cout << r << " ";
    }
    cout << "\n";
}
