#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    ListNode* next;
    int val;
    ListNode(int v):val(v), next(NULL){}
};

ListNode* buildList(vector<int>& arr) {
    ListNode dummyNode(0);
    for (int i = arr.size() - 1;i >= 0;i--) {
        ListNode* node = new ListNode(arr[i]);
        node->next = dummyNode.next;
        dummyNode.next = node;
    }
    return dummyNode.next;
}

void printList(ListNode* head) {
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode* deleteDup(ListNode* head) {
    while(head && head->next && head->val == head->next->val) head = head->next;
    return head->next;
}
ListNode* deleteDuplication(ListNode* pHead)
{
    ListNode dummyNode(0);
    ListNode* prev = &dummyNode;
    prev->next = pHead;
    ListNode* cur = pHead;
    while(cur) {
        if (cur && cur->next && cur->val == cur->next->val) {
            prev->next = deleteDup(cur);
            cur = prev->next;
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
    return dummyNode.next;
}

int main(){
    vector<int> arr{1,2,2,3,3,5};
    ListNode* head = buildList(arr);
    printList(head);
    deleteDuplication(head);
    printList(head);
}
