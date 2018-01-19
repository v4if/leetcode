#include <iostream>
#include <vector>

using namespace std;

struct node {
    int data;
    struct node* next;
    node(int x):data(x), next(NULL){}
};

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

node* reverseList(node* head) {
    node* dummy = new node(0);
    node* cur = head;
    while (cur) {
        node* next = cur->next;
        cur->next = dummy->next;
        dummy->next = cur;
        
        cur = next;
    }
    return dummy->next;
}

void travelList(node* head) {
    node* cur = head;
    while (cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << "\n";
}

int main() {
    vector<int> nums{1};
    node* head = buildList(nums);
    travelList(head);
    head = reverseList(head);
    travelList(head);
    return 0;
}
