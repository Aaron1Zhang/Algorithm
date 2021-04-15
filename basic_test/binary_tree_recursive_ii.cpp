#include <iostream>
#include <vector>
using namespace std;

//使用分治法遍历二叉树
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
};

vector<int> preorder_traverse(TreeNode* root) {
    vector<int> res;
    if(root == nullptr) {
        return res;
    }
    auto leftRes = preorder_traverse(root->left);
    auto rightRes = preorder_traverse(root->right);
    res.push_back(root->value);
    res.insert(res.end(), leftRes.begin(), leftRes.end());
    res.insert(res.end(), rightRes.begin(), rightRes.end());
    return res;
}
int main(int argc, const char** argv) {
    return 0;
}