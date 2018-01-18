#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    
    int sz = nums.size();
    for (int i = 0; i < sz; i++) {
        int target = -nums[i];
        int front = i + 1;
        int back = sz - 1;
        while (front < back) {
            int sum = nums[front] + nums[back];
            if (sum < target) {
                front++;
            } else if (sum > target) {
                back--;
            } else {
                vector<int> triplet{nums[i], nums[front], nums[back]};
                ans.push_back(triplet);
                
                while (front < back && nums[front] == triplet[1]) front++; 
                while (front < back && nums[back] == triplet[2]) back--; 
            }
        }
        while (i + 1 < sz && nums[i + 1] == nums[i]) {i++;}
    }
    
    return ans;
}

int main() {
    vector<int> arr{-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = threeSum(arr);
    for (auto vt : ans) {
        for (int v : vt) {
            cout << v << " ";
        }
        cout << "\n";
    }
}
