/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> Queue;
        vector<vector<int>> res;
        if(!root) {
            return res;
        }
        res.push_back(vector<int>{root->val});
        Queue.push(root);
        while(!Queue.empty()) {
            auto size = Queue.size();
            vector<int> cur;
            while(size) {
                auto node = Queue.front();
                Queue.pop();
                if(node->left) {
                    cur.push_back(node->left->val);  
                    Queue.push(node->left);
                }
                if(node->right) {
                    cur.push_back(node->right->val);
                    Queue.push(node->right);
                }
                --size;       
            }
            if(cur.size() > 0) {
                res.push_back(cur);
            }
                        
        }
        return res;

    }
};