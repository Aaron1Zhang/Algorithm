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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }
        int len = 1;
        auto temp = head;
        while (temp->next) {
            len++;
            temp = temp->next;
        }
        temp->next = head;
        int move_len = k % len;
        auto cur = head;
        for (int i = 1; i < len - move_len; ++i) {
            cur = cur->next;
        }
        auto new_head = cur->next;
        cur->next = nullptr;
        return new_head;
    }
    
};