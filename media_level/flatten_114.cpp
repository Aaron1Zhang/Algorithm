/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void flatten(TreeNode * root) {
        root = helper(root);   
    }
    TreeNode* helper(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        auto leftRes = helper(root->left);
        auto rightRes = helper(root->right);
        if (leftRes && rightRes) {
            auto temp = leftRes;
            while (temp->right) {
                temp = temp->right;
            }
            temp->right = rightRes;
            root->right = leftRes;
            root->left = nullptr;
            return root;
        }
        if (leftRes) {
            root->right = leftRes;
            root->left = nullptr;
            return root;
        }

        if (rightRes) {
            return root;
        }
        return root;
    }
};

