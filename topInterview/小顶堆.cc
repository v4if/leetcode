#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void shiftdown(vector<int>& nums, int idx) {
    int sz = nums.size();
  
    while (idx < sz) {
        int left = idx * 2;
        int right = left + 1;
        
        int next = idx;
        next = left < sz && nums[left] < nums[next] ? left : next;
        next = right < sz && nums[right] < nums[next] ? right : next;
        
        if (next != idx) {
            swap(nums[next], nums[idx]);
            idx = next;
        } else break;
    }
}

int popheap(vector<int>& nums) {
    if (nums.size() == 1) return -1;
    
    int result = nums[1];
    
    int sz = nums.size();
    swap(nums[1], nums[sz - 1]);
    nums.resize(sz - 1);
    shiftdown(nums,1);
    
    return result;
}

void buildheap(vector<int>& nums) {
    int last = nums.size() - 1;
    int notleaf = last / 2;
    for (int i = notleaf; i > 0; i--) {
        shiftdown(nums, i);
    }
}

void craftheap_test() {
    vector<int> nums{-1,  3,1,5,2,4,7,2}; //-1为哑结点
    buildheap(nums);
    for (int num : nums) cout << num << " ";
    cout << "\n";
    
    int top = -1;
    while ((top = popheap(nums)) && top != -1) cout << top << " ";
    cout << endl;
}


class Cmp {
public:
    bool operator() (int a1, int a2){
        return a1 > a2;
    }
};
void priority_queue_test() {
    vector<int> nums{-1,  3,1,5,2,4,7,2}; //-1为哑结点
    priority_queue<int, vector<int>, Cmp> heap;
    for (int num : nums) heap.push(num);
    while (!heap.empty()) {
        int top = heap.top();
        heap.pop();
        cout << top << " ";
    }
    cout << "\n";
}

int main() {
    cout << "priority queue test: \n";
    priority_queue_test();
    
    cout << "craft test: \n";
    craftheap_test();

    return 0;
}
