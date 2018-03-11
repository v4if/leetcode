/*
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。
并将P对1000000007取模的结果输出。 即输出P%1000000007

输入描述:
题目保证输入的数组中没有的相同的数字
数据范围：
	对于%50的数据,size<=10^4
	对于%75的数据,size<=10^5
	对于%100的数据,size<=2*10^5
示例1
输入

1,2,3,4,5,6,7,0
输出

7
*/

class Solution {
public:
    void divideAndConquer(vector<int>& data, int front, int back, long long& cnt) {
        if (front >= back) return ;
        int mid = front + (back - front) / 2;
        divideAndConquer(data, front, mid, cnt);
        divideAndConquer(data, mid+1, back, cnt);
        
        vector<int> arr(back - front + 1, 0);
        int i = front, j = mid + 1;
        int k = 0;
        while(i <= mid && j <= back) {
            if (data[i] <= data[j]) {
                arr[k++] = data[i++];
            } else {
                cnt += mid - i + 1;
                arr[k++] = data[j++];
            }
        }
        while (i <= mid) {
            arr[k++] = data[i++];
        }
        while (j <= back) {
            arr[k++] = data[j++];
        }
        for (int i = front;i <= back;i++) {
            data[i] = arr[i-front];
        }
    }
    int InversePairs(vector<int>& data) {
        if (data.empty()) return 0;
        long long cnt = 0;
        divideAndConquer(data, 0, data.size()-1, cnt);
        
        return cnt % 1000000007;
    }
};
