//
// Created by root on 2017/7/4.
//

#include <iostream>
#include <gtest/gtest.h>

/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
 * */

using namespace std;

namespace solve_first {
    struct ListNode{
        int val;
        ListNode* next;
        ListNode(int x): val(x), next(NULL){}
    };
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode dummy(0);
        ListNode* prev = &dummy;
        ListNode* curr = head;
        while (curr) {
            prev->next = curr;
            prev = curr;
            while (curr->next && curr->next->val == curr->val) {
                curr = curr->next;
            }
            curr = curr->next;
            prev->next = NULL;
        }

        return dummy.next;
    }
}

TEST(leetcode, remove_duplicates_from_sorted_array_test) {
    vector<int> nums{1,1,1,2,2,3,4,4,5,5};
    using namespace solve_first;
    ListNode dummy(0);
    for (int i = nums.size() - 1; i >= 0; --i) {
        ListNode* l = new ListNode(nums[i]);
        l->next = dummy.next;
        dummy.next = l;
    }

    ListNode* n = deleteDuplicates(dummy.next);
    while (n) {
        cout << n->val << " ";
        n = n->next;
    }
    cout << endl;

}