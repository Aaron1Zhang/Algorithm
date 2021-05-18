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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
    TreeNode* helper(vector<int>& nums, int left, int right) {
        if(left > right) {
            return nullptr;
        }
        auto max_iter = max_element(nums.begin() + left, nums.begin() + right+1);
        auto max_index = max_iter - nums.begin();
        auto root = new TreeNode(*max_iter);
        if(left == right) {
            return root;
        }
        root->left = helper(nums, left, max_index - 1);
        root->right = helper(nums, max_index + 1, right);
        return root;
    }
};