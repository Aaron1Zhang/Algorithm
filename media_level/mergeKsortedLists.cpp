#include <vector>
#include <iostream>
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
    // ListNode* mergeKLists(vector<ListNode*>& lists) {
    //     priority_queue<int, vector<int>, std::greater<int> > min_heap;
    //     for(auto&list:  lists) {
    //         while(list) {
    //             min_heap.push(list->val);
    //             list = list->next;
    //         }
    //     }
    //     ListNode* head = nullptr;
    //     //auto cur = nullptr;
    //     auto prev = head;
    //     while(!min_heap.empty()) {
    //         auto item = min_heap.top();
    //         min_heap.pop();
    //         auto cur = new ListNode(item);
    //         if(head == nullptr) {
    //             head = cur;
    //             prev = cur;
    //             continue;
    //         }
    //         prev->next = cur;
    //         prev = cur;
            
    //     }
    //     return head;
    // }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto size = lists.size();
        if(size < 1) return nullptr;
        return helper(lists, 0, size-1);
    }
    ListNode* helper(vector<ListNode*>& lists, int left, int right) {
        if(left >= right) {
            return lists[left];
        }
        int mid = left + (right-left)/2;
        ListNode* left_res = helper(lists, left, mid);
        ListNode* right_res = helper(lists, mid+1, right);
        
        left_res = merge(left_res, right_res);
        return left_res;
    }
    ListNode*  merge(ListNode* left, ListNode* right) {

        auto head = new ListNode();
        auto res = head;
        while(left && right) {
            if(left->val <= right->val) {
                res->next = left;
                left = left->next;   
            } else {
                res->next = right;
                right = right->next;
            }
            res = res->next;
           
        }
        if(left) {
            res->next = left;
        }
        if(right) {
            res->next = right;
        }
        left = head->next;
        return left;
    }
};

int main(int argc, const char** argv) {
    Solution s{};
    vector<ListNode*> lists;
    lists.push_back(nullptr);
    lists.push_back(new ListNode(1));
    auto res = s.mergeKLists(lists);

    return 0;
}