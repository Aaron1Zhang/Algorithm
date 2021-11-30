 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        auto cur = dummy;
        int t = 0;
        while (l1 || l2) {
            
            if (l1) {
                t += l1->val;
                l1 = l1->next;

            }
            if (l2) {
                t += l2->val;
                l2 = l2->next;
            }
            cur->next = new ListNode(t % 10);
            cur = cur->next;
            t = t / 10;
        }
        if (t) {
            cur->next = new ListNode(t);
        }
        return dummy->next;

    }