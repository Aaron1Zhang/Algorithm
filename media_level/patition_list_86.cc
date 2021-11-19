#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}

};
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* samll = new ListNode();
        auto small_temp = samll;
        ListNode* large = new ListNode();
        auto large_temp = large;
        auto cur = head;
        while (cur) {
            if (cur->val < x) {
                small_temp->next = cur;
                small_temp = small_temp->next;
            } else {
                large_temp->next = cur;
                large_temp = large_temp->next;
            }
            cur = cur->next;
        }
        large_temp->next = nullptr;
        small_temp->next = large->next;
        return samll->next;

    }
};
int main(int argc, const char** argv) {
    Solution s;
    ListNode* head = new ListNode(1);
    auto temp = head;
    vector<int> v {4,3,2,5,2};
    for (auto& i: v) {
        temp->next = new ListNode(i);
        temp = temp->next;
    }
    
    s.partition(head, 3);
}