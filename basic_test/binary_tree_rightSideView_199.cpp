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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> Queue;
        vector<int> res;
        if(!root) {
            return res;
        }
        //res.push_back(root->val);
        Queue.push(root);

        while(!Queue.empty()) {
            auto size = Queue.size();
            auto node = Queue.front();
            res.push_back(node->val);
            while(size) {
                --size;
                auto node = Queue.front();
                Queue.pop();   
                if(node->right) {
                    Queue.push(node->right);   
                }   
                if(node->left) {
                    Queue.push(node->left); 
                    
                }

            }

        }
        return res;

    }
};