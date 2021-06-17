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
    // ListNode* deleteDuplicates(ListNode* head) {
    //     set<int> sets;
    //     while(head) {
    //         sets.insert(head->val);
    //         head = head->next;
    //     }
    //     ListNode* dummy = new ListNode();
    //     auto temp = dummy;
    //     for(const auto& item: sets) {
    //         temp->next = new ListNode(item);
    //         temp = temp->next;
    //     }
    //     return dummy->next;
    // }
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* first = head;
        while(first) {
            ListNode* second = first->next;
            while(first && second && (first->val == second->val)) {
                second = second->next;
            }
           
            first->next = second;
            first = second;
              
        }
        return head;
    }

};