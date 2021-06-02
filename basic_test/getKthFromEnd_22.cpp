/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        int n = 0;
        auto temp = head;
        while(temp) {
            n++;
            temp = temp->next;
        }
        auto pos = n - k;
        while(pos) {
            pos--;
            head = head->next;
        }
        return head;
    }
};