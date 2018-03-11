/*
输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
输出描述:
对应每个测试案例，输出两个数，小的先输出。
*/

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        if (array.size() < 2) return vector<int>{};
        
        int min = INT32_MAX;
        map<int, bool> mp;
        vector<int> result(2,0);
        bool flag = false;
        for (int i = 0;i < array.size();i++) {
            int target = sum - array[i];
            if (mp.count(target) > 0 && target * array[i] < min) {
                min = target*array[i];
                result[0] = target < array[i] ? target : array[i];
                result[1] = target < array[i] ? array[i] : target;
                flag = true;
            }
            mp[array[i]] = true;
        }
        return flag ? result : vector<int>{};
    }
};
