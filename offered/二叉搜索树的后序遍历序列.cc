/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
*/

class Solution {
public:
    bool bt(vector<int>& arr, int front, int back) {
        if (front >= back) return true;
        
        int idx = front;
        for (;idx < back;idx++) {
            if (arr[idx] > arr[back]) break;
        }
        bool afterFlag = true;
        for (int i = idx;i < back;i++) {
            if (arr[i] < arr[back]) {
                afterFlag = false;
                break;
            }
        }
        return afterFlag && bt(arr, front, idx - 1) && bt(arr, idx, back - 1);
    }
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.size() == 0) return false;
        if (sequence.size() < 3) return true;
        return bt(sequence, 0, sequence.size()-1);
    }
};
