//
// Created by root on 2017/7/4.
//

#include <iostream>
#include <gtest/gtest.h>

/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
 * */

using namespace std;

namespace solve_first {
    struct ListNode{
        int val;
        ListNode* next;
        ListNode(int x): val(x), next(NULL){}
    };

    ListNode* deleteDuplicates(ListNode* head) {
//        空或者只有一个节点
        if (head == NULL || head->next == NULL) return head;

        ListNode dummy(0);
        ListNode* link = &dummy;
        ListNode* curr = head;
        int last_cnt = INT32_MAX;
        ListNode* pre;
        while (curr) {
//            一次只添加一个节点，添加的节点为上次统计只有一个的节点
            if (last_cnt == 1) {
                pre->next = NULL;
                link->next = pre;
                link = pre;
            }
            last_cnt = 1;
            pre = curr;
            while (curr->next && curr->next->val == curr->val) {
                curr = curr->next;
                last_cnt++;
            }
            curr = curr->next;
        }

        if (last_cnt == 1) {
            pre->next = NULL;
            link->next = pre;
        }

        return dummy.next;
    }
}

TEST(leetcode, remove_duplicates_from_sorted_array2_test) {
    vector<int> nums{1,1,1,2,2,3,4,4,5};
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