//
// Created by root on 5/1/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
    Merge two sorted linked lists and return it as a new list.
    The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, *curr;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                if (head == nullptr) {
                    head = l1;
                    l1 = l1->next;

                    head->next = nullptr;
                    curr = head;
                } else {
                    curr->next = l1;
                    l1 = l1->next;

                    curr->next->next = nullptr;

                    curr = curr->next;
                }
            } else {
                if (head == nullptr) {
                    head = l2;
                    l2 = l2->next;

                    head->next = nullptr;
                    curr = head;
                } else {
                    curr->next = l2;
                    l2 = l2->next;

                    curr->next->next = nullptr;

                    curr = curr->next;
                }
            }
        }

        while (l1) {
            if (head == nullptr) {
                head = l1;
                l1 = l1->next;

                head->next = nullptr;
                curr = head;
            } else {
                curr->next = l1;
                l1 = l1->next;

                curr->next->next = nullptr;

                curr = curr->next;
            }
        }

        while (l2) {
            if (head == nullptr) {
                head = l2;
                l2 = l2->next;

                head->next = nullptr;
                curr = head;
            } else {
                curr->next = l2;
                l2 = l2->next;

                curr->next->next = nullptr;

                curr = curr->next;
            }
        }

        return head;
    }
};

class SolutionPerfect {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(INT8_MIN);
        ListNode *tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};

TEST(leetcode, merge_two_sorted_lists) {
    int l1baits[] = {1, 3};
    int l2baits[] = {2, 4, 7};
    ListNode* l1, *l2, *curr;

    l1 = nullptr;
    int len = sizeof(l1baits) / sizeof(l1baits[0]);
    for (int i = len - 1; i >= 0; --i) {
        curr = static_cast<ListNode*>(malloc(sizeof(ListNode)));
        curr->val = l1baits[i];

        curr->next = l1;
        l1 = curr;
    }

    l2 = nullptr;
    len = sizeof(l2baits) / sizeof(l2baits[0]);
    for (int i = len - 1; i >= 0; --i) {
        curr = static_cast<ListNode*>(malloc(sizeof(ListNode)));
        curr->val = l2baits[i];

        curr->next = l2;
        l2 = curr;
    }

    curr = Solution().mergeTwoLists(l1, l2);

    while (curr) {
        cout << curr->val << "  ";
        curr = curr->next;
    }
    cout << endl;
}