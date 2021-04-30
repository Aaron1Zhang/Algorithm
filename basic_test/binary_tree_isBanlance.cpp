#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Result {
    bool isBal;
    int depth;
    //Result(): isBal{false}, depth{0} {}
};
bool isBalanced(TreeNode* root) {
        auto res = helper(root);
        return res.isBal;
}
Result helper(TreeNode* root) {
    //Result res;
    if(root == NULL) {
        
        return Result{true, 0};
    }
    auto leftRes = helper(root->left);
    auto rightRes = helper(root->right);
    if(!leftRes.isBal) {
        return leftRes;
    } 
    if(!rightRes.isBal) {
        return rightRes;
    }
    if(abs(leftRes.depth - rightRes.depth) > 1) {
        return Result{false, -1};
    }
    return Result{true, 1 + max(leftRes.depth, rightRes.depth)};

}
//另一种简单方法
class Solution {

public:
    bool isBal{true};

    bool isBalanced(TreeNode* root) {
        depth(root);
        return isBal;
    }
    int depth(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        auto leftDepth = depth(root->left);
        auto rightDepth = depth(root->right);
        if(abs(leftDepth - rightDepth) > 1) {
            isBal = false;
        }
        return 1 + max(leftDepth, rightDepth);
    }
      
};