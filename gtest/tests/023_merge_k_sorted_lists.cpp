//
// Created by root on 5/1/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
    Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
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
//    二分的思想
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        while (lists.size() > 1) {
            lists[0] = merge2lists(lists[0], lists[1]);
            lists.erase(find(lists.begin(), lists.end(), lists[1]));
        }

        return lists.size() > 0 ? lists[0] : nullptr;
    }

    ListNode* merge2lists(ListNode* l1, ListNode* l2) {
        ListNode dummy(INT8_MIN);
        ListNode* head = &dummy;
        ListNode* tail = head;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
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

TEST(leetcode, merge_k_sorted_lists) {
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

    vector<ListNode*> v = {l1, l2};
    curr = Solution().mergeKLists(v);
    while (curr) {
        cout << curr->val << "  ";
        curr = curr->next;
    }
    cout << endl;

//    v.erase(find(v.begin(), v.end(), l1));
//    for (ListNode* item : v) {
//        curr = item;
//        while (curr) {
//            cout << curr->val << "  ";
//            curr = curr->next;
//        }
//        cout << endl;
//    }
}