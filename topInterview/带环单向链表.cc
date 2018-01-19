#include <iostream>
#include <vector>

// https://www.cnblogs.com/snake-hand/p/3148328.html
using namespace std;

struct node {
    int data;
    struct node* next;
    node(int x):data(x), next(NULL){}
};

node* buildCircleList(vector<int>& nums) {
    node* dummy = new node(0);
    node* cur = dummy;
    for (int num : nums) {
        node* nn = new node(num);
        cur->next = nn;
        cur = cur->next;
    }
    
    // circle
    cur->next = dummy->next->next;
    return dummy->next;
}

node* buildList(vector<int>& nums) {
    node* dummy = new node(0);
    node* cur = dummy;
    for (int num : nums) {
        node* nn = new node(num);
        cur->next = nn;
        cur = cur->next;
    }
    
    return dummy->next;
}

bool checkCircle(node* head) {
    node* slow = head;
    node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (fast == slow) return true;
    }
    
    return false;
}

node* intersectNode(node* head) { 
    node* slow = head;
    node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (fast == slow) break;
    }
    
    node* cur = head;
    while (cur) {
        cur = cur->next;
        slow = slow->next;
        
        if (cur == slow) return cur;
    }
    
    return NULL;
}

void travelList(node* head) {
    node* cur = head;
    int idx = 0;
    while (cur) {
        cout << cur->data << " ";
        cur = cur->next;
        
        if (idx > 15) break;
        idx++;
    }
    cout << "\n";
}

int main() {
    vector<int> nums{1,2,3,4,5,6,7};
    node* circleHead = buildCircleList(nums);
    travelList(circleHead);
    
    node* nonCircleHead = buildList(nums);
    
    cout << checkCircle(circleHead) << endl;
    cout << checkCircle(nonCircleHead) << endl;
    
    node* intersect = intersectNode(circleHead);
    cout << intersect->data << endl;
    return 0;
}
