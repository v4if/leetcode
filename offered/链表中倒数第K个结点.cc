/*
输入一个链表，输出该链表中倒数第k个结点。
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (pListHead == NULL || k == 0) return NULL;
        
        ListNode *slow = pListHead, *fast = pListHead;
        while(k > 0 && fast!=NULL) {
            fast = fast->next;
            k--;
        }
        //cout << k << endl;
        if (k>0) return NULL;
        while(fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
