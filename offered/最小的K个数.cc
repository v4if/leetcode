/*
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
*/

class Solution {
public:
    int partition(vector<int>& input, int front, int back) {
        int idx = front;
        for (int i = front;i < back;i++) {
            if (input[i] < input[back]) {
                swap(input[i], input[idx]);
                idx++;
            }
        }
        swap(input[idx], input[back]);
        return idx;
    }
    vector<int> GetLeastNumbers_Solution(vector<int>& input, int k) {
        if (0 == k || input.empty() || k > input.size()) return vector<int>{};
        if (k == input.size()) return input;
        
        int front = 0;
        int back = input.size() - 1;
        int idx = partition(input, front, back);
        while(idx != k - 1) {
            if (idx > k - 1) {
                back = idx - 1;
                idx = partition(input, front, back);
            } else {
                front = idx + 1;
                idx = partition(input, front, back);
            }
        }
        
        return vector<int>(input.begin(), input.begin()+k);
    }
};
