/*
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 
针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： 
{[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
*/

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> result;
        int sz = num.size();
        if (sz < size) return result;
        
        int front = 0;
        deque<int> dq;
        for(int i = 0;i < sz;i++) {
            while(!dq.empty() && num[dq.back()] < num[i]) dq.pop_back();
            dq.push_back(i);
            
            if (i >= size) front++;
            while(!dq.empty() && dq.front() < front) dq.pop_front();
            
            if (i >= size - 1) result.push_back(num[dq.front()]);
        }
        return result;
    }
};
