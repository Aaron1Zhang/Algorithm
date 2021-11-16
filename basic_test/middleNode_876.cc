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
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        int len = getLen(head);
        int index = len / 2;
        auto temp = head;
        while (index--) {
            temp = temp->next;
        }
        return temp;
    }
    int getLen(ListNode* head) {
        int len = 0;
        auto temp = head;
        while (temp) {
            len++;
            temp = temp->next;
        }
        return len;
    }
};