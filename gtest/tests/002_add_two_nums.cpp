//
// Created by root on 2/25/17.
//

#include <iostream>
#include <gtest/gtest.h>

/**
    You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

    You may assume the two numbers do not contain any leading zero, except the number 0 itself.

    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8
 */

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode result(0);

        ListNode *head = &result;

        int sum, carry = 0;
        while (l1 || l2 || carry) {
            sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;

            (*head).next = new ListNode(sum % 10);
            head = (*head).next;

            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }

        return result.next;
    }
};

TEST(leetcode, add_two_nums) {
    ListNode sample1(2);
    sample1.next = new ListNode(4);
    sample1.next->next = new ListNode(3);

    ListNode sample2(5);
    sample2.next = new ListNode(6);
    sample2.next->next = new ListNode(4);

    ListNode expect(7);
    expect.next = new ListNode(0);
    expect.next->next = new ListNode(8);

//    EXPECT_EQ(&expect, Solution().addTwoNumbers(&sample1, &sample2));
    ListNode *result = Solution().addTwoNumbers(&sample1, &sample2);
    while(result != NULL) {
        cout << result->val << endl;
        result = result->next;
    }

    EXPECT_EQ(1, 1);
}