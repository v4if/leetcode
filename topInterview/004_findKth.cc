#include <iostream>
#include <vector>

using namespace std;

// pa + pb = k
int findKth(const vector<int>& arr1, int s1, const vector<int>& arr2, int s2, int k) {
    
    if (arr1.size() - s1 > arr2.size() - s2) return findKth(arr2, s2, arr1, s1, k);
    if (arr1.size() - s1 == 0) return arr2[s2 + k - 1];
    if (k == 1) return min(arr1[s1], arr2[s2]);
    
    int pa = k / 2 > (int)arr1.size() ? arr1.size() : k / 2;
    int pb = k - pa;
    if (arr1[s1 + pa - 1] < arr2[s2 + pb - 1]) {
        return findKth(arr1, s1 + pa, arr2, s2, k - pa);
    } else if (arr1[s1 + pa - 1] > arr2[s2 + pb - 1]) {
        return findKth(arr1, s1, arr2, s2 + pb, k - pb);
    } else {
        return arr1[s1 + pa - 1];
    }
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int len = nums1.size() + nums2.size();
    if (len == 0) return 0;
    
    if (len % 2) {
        return findKth(nums1, 0, nums2, 0, len / 2 + 1);
    } else {
        return (findKth(nums1, 0, nums2, 0, len / 2) + findKth(nums1, 0, nums2, 0, len / 2 + 1)) / 2.0;
    }
}

int main() {
    vector<int> arr1{1,2};
    vector<int> arr2{3,4};
    cout << findMedianSortedArrays(arr1, arr2) << endl;
}
