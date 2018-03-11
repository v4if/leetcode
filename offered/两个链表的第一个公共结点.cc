/*
输入两个链表，找出它们的第一个公共结点。
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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int l1 = 0, l2 = 0;
        ListNode* cur = pHead1;
        while(cur) {
            cur = cur->next;
            l1++;
        }
        
        cur = pHead2;
        while(cur) {
            cur = cur->next;
            l2++;
        }
        
        int diff = l1 >= l2 ? l1 - l2 : l2 - l1;
        ListNode* cur1 = pHead1;
        ListNode* cur2 = pHead2;
        if (l1 >= l2) {
            while(diff){
                cur1 = cur1->next;
                diff--;
            }
        } else {
            while(diff){
                cur2 = cur2->next;
                diff--;
            }
        }
        
        while(cur1&& cur2) {
            if (cur1->val == cur2->val) return cur1;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return NULL;
    }
};
