#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& nums, int low, int high) {
    int cand = nums[high];
    int pivot = low;
    for (int i = low; i < high; i++) {
        if (nums[i] < cand) {
            swap(nums[i], nums[pivot]);
            pivot++;
        }
    }
    swap(nums[pivot], nums[high]);
    return pivot;
}

void quicksort(vector<int>& nums, int low, int high) {
    if (low < high) {
        int pivot = partition(nums, low, high);
        quicksort(nums, low, pivot - 1);
        quicksort(nums, pivot + 1, high);
    }
}

int main() {
    vector<int> nums{3,2,4,1,7};
    quicksort(nums, 0, 4);
    for (int num : nums) cout << num << " ";
    cout << "\n";
    return 0;
}
