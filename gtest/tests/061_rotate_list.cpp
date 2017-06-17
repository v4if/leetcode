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
        if(!head) return head;

        int len=1; // number of nodes
        ListNode *newH, *tail;
        newH=tail=head;

        while(tail->next)  // get the number of nodes in the list
        {
            tail = tail->next;
            len++;
        }
        tail->next = head; // circle the link

        if(k %= len)
        {
            for(auto i=0; i<len-k; i++) tail = tail->next; // the tail node is the (len-k)-th node (1st node is head)
        }
        newH = tail->next;
        tail->next = NULL;
        return newH;
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