class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int pre, last, l, r;
    // 下界
        for (l = 0, r = data.size() ;l < r; ) {
            int mid = (l + r) / 2;
            if (data[mid] >= k)
                r = mid;
            else
                l = mid + 1;
        }
        pre = r;

    // 上界
        for (l = -1, r = (int)data.size() - 1; l < r; ) {
            int mid = (l + r + 1) / 2;
            if (data[mid] <= k)
                l = mid;
            else
                r = mid - 1;
        }
        last = l;
        return last - pre + 1;
    }
};
