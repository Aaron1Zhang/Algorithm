#include <iostream>
#include <vector>
//#include <math.h>
using namespace std;
//二叉树的深度定义为从根节点到最远叶子节点所经过的节点数
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int depth(TreeNode* root) {
    if(root == nullptr) {
        return 0;
    }
    return 1 + max(depth(root->left), depth(root->right));
}

int main(int argc, const char** argv) {
    return 0;
}