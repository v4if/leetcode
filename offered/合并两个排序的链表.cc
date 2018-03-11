/*
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
*/

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode dummyNode(0);
        ListNode* cur = &dummyNode;
        while(pHead1&&pHead2) {
            if (pHead1->val <= pHead2->val) {
                cur->next = pHead1;
                pHead1=pHead1->next;
            } else {
                cur->next = pHead2;
                pHead2=pHead2->next;
            }
            cur = cur->next;
        }
        
        if (pHead1) cur->next = pHead1;
        if (pHead2) cur->next = pHead2;
        return dummyNode.next;
    }
};
