//
// Created by root on 4/23/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
    Given a linked list, remove the nth node from the end of list and return its head.

    Given linked list: 1->2->3->4->5, and n = 2.
    After removing the second node from the end, the linked list becomes 1->2->3->5.
 * */

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode **p_del, *rear;
        p_del = &head;
        rear = head;

        while (--n && rear != nullptr) {
            rear = rear->next;
        }

        if (n > 0) { return nullptr;}

        while (rear && rear->next) {
            rear = rear->next;
            p_del = &((*p_del)->next);
        }

        *p_del = (*p_del)->next;

        return head;
    }
};

TEST(leetcode, remove_nth_node) {
    int mybaits[] = {1, 2};
    ListNode* head, *curr;

    head = static_cast<ListNode*>(malloc(sizeof(ListNode)));
    head->next = NULL;
    int len = sizeof(mybaits) / sizeof(mybaits[0]);
    for (int i = len - 1; i >= 0; --i) {
        curr = static_cast<ListNode*>(malloc(sizeof(ListNode)));
        curr->val = mybaits[i];
        curr->next = NULL;

        curr->next = head->next;
        head->next = curr;
    }

    head = Solution().removeNthFromEnd(head->next, 2);

    curr = head;
    while (curr) {
        cout << curr->val << "  ";
        curr = curr->next;
    }
    cout << endl;
}