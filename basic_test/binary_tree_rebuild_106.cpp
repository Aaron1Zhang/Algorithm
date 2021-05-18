#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
从中序与后序遍历序列构造二叉树
中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }

    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int left, int right, int post_start, int post_end) {
        if(left > right) {
            return nullptr;
        }
        auto root = new TreeNode(postorder[post_end]);
        if(left == right) {
            return root;
        }
        auto iter = std::find(inorder.begin(), inorder.end(), postorder[post_end]);
        auto root_index = iter - inorder.begin();
        auto post_end_index = post_start + (root_index-1-left);
        
        root->left = helper(inorder, postorder, left, root_index-1, post_start, post_end_index);
        auto post_len = right - (root_index+1);
        root->right = helper(inorder, postorder, root_index+1, right, post_end_index + 1, post_end_index + 1 + post_len);
        return root;
    }
};