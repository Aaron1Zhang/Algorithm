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
     * @param head: a singly linked list
     * @return: Modified linked list
     */
    ListNode * oddEvenList(ListNode * head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return head;
        }
        
        ListNode* oddList_dummy = new ListNode();
        ListNode* evenList_dummy = new ListNode();

        auto odd_temp = oddList_dummy;
        auto even_temp = evenList_dummy;
        auto cur = head;
        int index = 1;
        while (cur) {
            if (index % 2 == 1) {
                odd_temp->next = cur;
                odd_temp = odd_temp->next;
            } else {
                even_temp->next = cur;
                even_temp = even_temp->next;
            }
            cur = cur->next;
            index++;
        }
        even_temp->next = nullptr;
        odd_temp->next = evenList_dummy->next;
        return oddList_dummy->next;
    }
};