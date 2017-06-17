//
// Created by root on 6/17/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
 * */

using namespace std;

namespace solve_first {
    struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
    };
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* tail = head;
        ListNode* pre = head;
        ListNode* dummy_head = head;

        while (k-- && tail) {
            tail = tail->next;
        }

        if (k >= 0) return head;

        while (tail && tail->next) {
            pre = pre->next;
            tail = tail->next;
        }

        tail->next = head;
        dummy_head = pre->next;
        pre->next = NULL;

        return dummy_head;
    }
}

TEST(leetcode, rotate_list_) {
    using namespace solve_first;
    int mybaits[] = {1, 2, 3, 4, 5};
    ListNode* head, *curr;

    head = new ListNode(0);
    int len = sizeof(mybaits) / sizeof(mybaits[0]);
    for (int i = len - 1; i >= 0; --i) {
        curr = new ListNode(mybaits[i]);
        curr->val = mybaits[i];

        curr->next = head->next;
        head->next = curr;
    }

    curr = rotateRight(head->next, 2);
    while (curr) {
        cout << curr->val << "  ";
        curr = curr->next;
    }
    cout << endl;
}