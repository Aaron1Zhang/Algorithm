 //Definition for a binary tree node.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return helper(preorder,inorder,0,inorder.size()-1, index);     
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int left, int right, int& root_index) {
        if(left > right || root_index == preorder.size()) {
            --root_index;
            return nullptr;
        }       
        TreeNode* root = new TreeNode(preorder[root_index]);
        if(left == right) {
            return root;
        }
        auto iter=std::find(inorder.begin(), inorder.end(), preorder[root_index]);    
        auto index = iter - inorder.begin();
        root->left = helper(preorder, inorder, left, index-1, ++root_index);
        root->right = helper(preorder, inorder, index+1, right, ++root_index);
        return root;
    }
};
int main(int argc, const char** argv) {
    vector<int> pre{3,9,4,5,20,15,7};
    vector<int> order{4,9,5,3,15,20,7};
    auto res = buildTree(pre, order);
    return 0;
}

