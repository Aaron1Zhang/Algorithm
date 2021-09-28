#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = nullptr;
    }
};
class Solution {
public:
    /*
     * @param root: The root of the binary tree.
     * @param A: A TreeNode
     * @param B: A TreeNode
     * @return: Return the LCA of the two nodes.
     */
    struct Res {
        TreeNode* lca;
        bool a_exist;
        bool b_exist;
    };
    TreeNode * lowestCommonAncestor3(TreeNode * root, TreeNode * A, TreeNode * B) {
        return helper(root, A, B).lca;
    }
    Res helper(TreeNode * root, TreeNode * A, TreeNode * B) {
        if (root == nullptr) {
            return Res {nullptr, false, false};
        }
    
        auto leftRes = helper(root->left, A, B);
        auto rightRes = helper(root->right, A, B);
        
        bool a_exist = leftRes.a_exist || rightRes.a_exist || root == A;
        bool b_exist = leftRes.b_exist || rightRes.b_exist || root == B;

        if (root == A || root == B) {
            return Res{root, a_exist, b_exist};
        }

        if (leftRes.lca && rightRes.lca) {
            return Res{root, a_exist, b_exist};
        }
        if (leftRes.lca) {
            return Res{leftRes.lca, a_exist, b_exist};
        }
        if (rightRes.lca) {
            return Res{rightRes.lca, a_exist, b_exist};
        }
        return Res{nullptr, a_exist, b_exist};
    }
};