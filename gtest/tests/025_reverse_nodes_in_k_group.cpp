//
// Created by root on 5/5/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
    Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

    k is a positive integer and is less than or equal to the length of the linked list.
    If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

    You may not alter the values in the nodes, only nodes itself may be changed.
    Only constant memory is allowed.

    For example,
        Given this linked list: 1->2->3->4->5

        For k = 2, you should return: 2->1->4->3->5

        For k = 3, you should return: 3->2->1->4->5
 * */

using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(INT8_MIN);
        ListNode *pre, *cur, *next, *temp;

        dummy.next = head;
        cur = &dummy;
        pre = &dummy;
        int num = 0;
        while (cur = cur->next) {
            num++;
        }

        while (num >= k) {
            cur = pre->next;
            next = cur->next;
            for (int i = 1; i < k; ++i) {
                temp = next->next;
                next->next = pre->next;
                pre->next = next;
                cur->next = temp;

                next = temp;
            }

            pre = cur;
            num = num - k;
        }

        return dummy.next;
    }
};

TEST(leetcode, reverse_nodes_in_k_group) {
    int l1baits[] = {1, 2, 3, 4, 5};
    ListNode* l1, *curr;

    l1 = nullptr;
    int len = sizeof(l1baits) / sizeof(l1baits[0]);
    for (int i = len - 1; i >= 0; --i) {
        curr = static_cast<ListNode*>(malloc(sizeof(ListNode)));
        curr->val = l1baits[i];

        curr->next = l1;
        l1 = curr;
    }

    curr = Solution().reverseKGroup(l1, 3);
    while (curr) {
        cout << curr->val << "  ";
        curr = curr->next;
    }
    cout << endl;
}