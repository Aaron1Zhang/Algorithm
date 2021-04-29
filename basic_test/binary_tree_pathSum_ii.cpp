#include <iostream>
#include <vector>
using namespace std;
// root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
// 输出：[[5,4,11,2],[5,8,4,5]]

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void helper(TreeNode* root, int targetSum, vector<vector<int>>& res, vector<int>& cur) {
    if(root == nullptr) {
        return;
    }
    if(root->left == nullptr && root->right == nullptr) {
        if(targetSum == root->val) {
            cur.push_back(root->val);
            res.push_back(cur);
            cur.pop_back();
            return;
        }
        return;
    }
    cur.push_back(root->val);
    helper(root->left, targetSum - root->val, res, cur);
    helper(root->right, targetSum - root->val, res, cur);
    cur.pop_back();
}
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> res;
    vector<int> cur;
    helper(root, targetSum, res, cur);
    return res;
}