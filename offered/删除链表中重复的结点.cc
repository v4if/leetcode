/*
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
*/

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
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
};
