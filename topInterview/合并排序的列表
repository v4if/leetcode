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
