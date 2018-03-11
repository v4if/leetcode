// 统计一个数字在排序数组中出现的次数。

class Solution {
public:
    int myUpper(vector<int>& data, int k) {
        int low = -1;
        int high = data.size() - 1;
        while(low < high) {
            int mid = (low + high + 1) / 2;
            if (data[mid] > k) {
                high = mid - 1;
            } else {
                low = mid;
            }
        }
        return low + 1;
    }
    int myLower(vector<int>& data, int k) {
        int low = 0;
        int high = data.size();
        while(low < high) {
            int mid = (low + high) / 2;
            if (data[mid] < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
    int GetNumberOfK(vector<int> data ,int k) {
        //return upper_bound(data.begin(), data.end(), k) - lower_bound(data.begin(), data.end(), k);
        return myUpper(data,k) - myLower(data, k);
    }
};
