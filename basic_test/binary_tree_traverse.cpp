#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
};

//层次遍历
auto level_traverse(TreeNode* root) {
    queue<TreeNode*> lists;
    vector<vector<int>> res;
    if(root == nullptr) {
        return res;
    } 
    lists.push(root);
    while(!lists.empty()) {
        auto level_size = lists.size();
        vector<int> cur_level;

        for(auto i = 0; i < level_size; ++i) {
            auto t = lists.front();
            lists.pop(); 
            cur_level.push_back(t->value);
            if(t->left != nullptr) {
                lists.push(t->left);
            }
            if(t->right != nullptr) {
                lists.push(t->right);
            }
        }
        res.push_back(cur_level);
        
    }
    return res;
}

vector<int> pre_traverse(TreeNode* root) {
    vector<int> res;
    if(root == nullptr) {
        return res;
    }
    stack<TreeNode*> lists;
    lists.push(root);
    while(!lists.empty()) {
        auto item = lists.top();
        res.push_back(item->value);
        lists.pop(); 
        if(item->right) {
            lists.push(item->right);
        }
        if(item->left) {
            lists.push(item->left);
        }
       
    }
    return res;
}

//中序非递归遍历
vector<int> mid_Traversal(TreeNode* root) {
    vector<int> res;
    if(root == nullptr) {
        return res;
    }
    stack<TreeNode*> lists;
    lists.push(root);

    while(root != nullptr || !lists.empty()) {
        while(root != nullptr) {
            lists.push(root);
            root = root->left;
        }
        root = lists.top();
        lists.pop();
        res.push_back(root->value);
        root = root->right;
    }
    return res;

}

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            res.push_back(root->value);
            root = root->right;
        }
        return res;
    }
};


