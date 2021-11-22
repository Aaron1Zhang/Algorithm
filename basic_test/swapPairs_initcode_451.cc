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
     * @return: a ListNode
     */
    ListNode * swapPairs(ListNode * head) {
        // write your code here
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode* prev = head;
        auto cur = head->next;
        
        auto temp = cur->next;
        cur->next = prev;
        prev->next = swapPairs(temp);
        return cur;
    }
};