/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param head: a ListNode
     * @param v1: An integer
     * @param v2: An integer
     * @return: a new head of singly-linked list
     */
    ListNode * swapNodes(ListNode * head, int v1, int v2) {
        // write your code here
        ListNode* dummy = new ListNode();
        dummy->next = head;
        auto prev = dummy;
        ListNode* prev_v1 = nullptr;
        ListNode* cur_v1 = nullptr;

        ListNode* prev_v2 = nullptr;
        ListNode* cur_v2 = nullptr;
        auto cur = head;
        while (cur) {
            auto cur_val = cur->val;
            if (cur_val == v1) {
                prev_v1 = prev;
                cur_v1 = cur;
            }
            if (cur_val == v2) {
                prev_v2 = prev;
                cur_v2 = cur;
            }
            if (prev_v1 && prev_v2) {
                if (prev_v2 == cur_v1) {
                    cur_v1->next = cur_v2->next;
                    prev_v1->next = cur_v2;
                    cur_v2->next = cur_v1;
                    break;
                }
                prev_v1->next = cur_v2;
                auto temp = cur_v2->next;
                cur_v2->next = cur_v1->next;

                prev_v2->next = cur_v1;
                cur_v1->next = temp;
                break;
            }
            prev = cur;
            cur = cur->next;
        }
        return dummy->next;
    }
};