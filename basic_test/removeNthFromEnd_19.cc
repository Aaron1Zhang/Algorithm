/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int list_len = 0;
        auto cur = head;
        while (cur) {
            list_len++;
            cur = cur->next;
        }
        int delete_index = list_len - n;
        ListNode* dummy_node = new ListNode();
        dummy_node->next = head;
        cur = head;
        ListNode* prev = dummy_node;
        int i = 0;
        while (i < delete_index) {
            prev = cur;
            cur = cur->next;
            ++i;
        }
        prev->next = cur->next;
        return dummy_node->next;
    }
    
};