//
// Created by root on 5/1/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
    Given a linked list, swap every two adjacent nodes and return its head.

    For example,
    Given 1->2->3->4, you should return the list as 2->1->4->3.

    Your algorithm should use only constant space.
    You may not modify the values in the list, only nodes itself can be changed.
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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(INT8_MIN);
        ListNode *curr = &dummy;
        ListNode *temp;
        while (head && head->next) {
            curr->next = head->next;

            temp = head;
            head = head->next->next;
            curr->next->next = temp;
            curr->next->next->next = nullptr;

            curr = curr->next->next;
        }

        if (head != nullptr) {
            curr->next = head;
        }

        return dummy.next;
    }
};

TEST(leetcode, swap_in_pairs) {
    int l1baits[] = {1, 2, 3};
    ListNode* l1, *curr;

    l1 = nullptr;
    int len = sizeof(l1baits) / sizeof(l1baits[0]);
    for (int i = len - 1; i >= 0; --i) {
        curr = static_cast<ListNode*>(malloc(sizeof(ListNode)));
        curr->val = l1baits[i];

        curr->next = l1;
        l1 = curr;
    }

    curr = Solution().swapPairs(l1);
    while (curr) {
        cout << curr->val << "  ";
        curr = curr->next;
    }
    cout << endl;
}