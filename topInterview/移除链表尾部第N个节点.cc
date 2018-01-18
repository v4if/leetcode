#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(NULL){}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* slow = dummy, *fast=dummy;
    for(int i=0;i!=n+1;i++){
        fast = fast->next;
    }
    while(fast!=NULL){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next = slow->next->next;
    return dummy->next;
}

ListNode* buildList(vector<int>& nums) {
    ListNode dummy(0);
    ListNode* cur = &dummy;
    for (int num : nums) {
        ListNode* node = new ListNode(num);
        cur->next = node;
        cur = cur->next;
    }
    
    return dummy.next;
}

void travelList(ListNode* head) {
    ListNode* cur = head;
    while (cur) {
        cout << cur->val << " ";
        cur = cur->next;
    }
}

int main() {
    vector<int> nums{1,2,3,4,5};
    ListNode* head = buildList(nums);
    head = removeNthFromEnd(head, 2);
    travelList(head);
}
