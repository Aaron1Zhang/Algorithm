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

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> paths;
    if(root == nullptr) {
        return paths;
    }
    if(root->left == nullptr && root->right == nullptr) {
        paths.push_back(to_string(root->val));
        return paths;
    }
    auto leftPaths = binaryTreePaths(root->left);
    auto rightPaths = binaryTreePaths(root->right);
    for(auto& path: leftPaths) {
        path.insert(0, to_string(root->val) + "->");
    }
    for(auto& path: rightPaths) {
        path.insert(0, to_string(root->val) + "->");
    }
    paths.insert(paths.end(), leftPaths.begin(), leftPaths.end());
    paths.insert(paths.end(), rightPaths.begin(), rightPaths.end());
    return paths;
}




int main(int argc, const char** argv) {
    return 0;
}