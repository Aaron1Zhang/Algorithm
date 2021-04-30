#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct resultType
{
    bool isBST;
    int Max;
    int Min;
    resultType(bool b, int left, int right): 
        isBST{b}, Max{left}, Min{right} {}
};

class Soution {
public:
    
    bool isValidBST(TreeNode* root) {
        auto res = helper(root);
        return res.isBST;
       
    }
    resultType helper(TreeNode* root) {
        if(root == nullptr) {
            return resultType{true, INT_MIN, INT_MAX};
        }
       
        auto leftRes = helper(root->left);
        auto rightRes = helper(root->right);
        if(!leftRes.isBST || !rightRes.isBST) {
            return resultType{false, 0, 0};
        }
        if(root->left && leftRes.Max >= root->val || 
            root->right && rightRes.Min <= root->val) {
                return resultType{false, 0, 0};
            }
        return resultType{true, max(root->val, rightRes.Max), min(leftRes.Min, root->val)};

    }
};
