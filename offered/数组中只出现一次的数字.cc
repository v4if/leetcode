/*
一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
*/

class Solution {
public:
    bool isBit(int num, int idx) {
        return (num >> idx) & 0x1;
    }
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if (data.size() < 2) return;
        
        int xorValue = data[0];
        for (int i = 1;i < data.size();i++) {
            xorValue ^= data[i];
        }
        
        int idx = 0;
        while(xorValue) {
            if (xorValue & 0x1) break;
            xorValue = xorValue >> 1;
            idx++;
        }
        
        for (int i = 0;i < data.size();i++) {
            if (isBit(data[i], idx)) {
                *num1 ^= data[i];
            } else {
                *num2 ^= data[i];
            }
        }
    }
};
