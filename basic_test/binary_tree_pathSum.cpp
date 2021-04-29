#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> helper(TreeNode* root, int targetSum) {
    vector<int> sums;
    if(root == nullptr) {
        return sums;
    }
    if(root->left == nullptr && root->right == nullptr) {
        sums.push_back(root->val);
        return sums;
    }
    auto leftSum = helper(root->left, targetSum);
    auto rightSum = helper(root->right, targetSum);
    for(auto& i: leftSum) {
        i += root->val;
    }
    for(auto& j: rightSum) {
        j += root->val;
    }
    sums.insert(sums.end(), leftSum.begin(), leftSum.end());
    sums.insert(sums.end(), rightSum.begin(), rightSum.end());
    return sums;
}

bool hasPathSum(TreeNode* root, int targetSum) {
    auto res = helper(root, targetSum);
    for(auto i: res) {
        if(targetSum == i) {
            return true;
        }
    }
    return false;
}

bool hasPathSum(TreeNode* root, int targetSum) {
    if(root == nullptr) {
        return false;
    }
    if(root->left == nullptr && root->right == nullptr) {
        return targetSum == root->val;
    }
    if(hasPathSum(root->left, targetSum - root->val)) {
        return true;
    }
    if(hasPathSum(root->right, targetSum - root->val)) {
        return true;
    }
    return false;
}