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
     * @param root: The root of the binary search tree.
     * @param A: A TreeNode in a Binary.
     * @param B: A TreeNode in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    //1、如果A，B位于根节点的左右，那么根节点就是LCA
    //2、如果A，B位于根节点的一侧，那么先找到A或者B直接返回，A或者B就是LCA
    //3、如果根节点为null，那么直接返回;
    
    TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * A, TreeNode * B) {
        // write your code here
        if (root == nullptr || root == A || root == B) {
            return root;
        }      

        auto leftRes = lowestCommonAncestor(root->left, A, B);
        auto rightRes = lowestCommonAncestor(root->right, A, B);

        if (leftRes && rightRes) {
            return root;
        }
        if (leftRes) {
            return leftRes;
        }
        if (rightRes) {
            return rightRes;
        }
        return nullptr;

    }
};
