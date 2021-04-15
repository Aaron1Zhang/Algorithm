#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};
//先序遍历，先根再左子树后右子树
void pre_order(Node* root) {
    if(root == nullptr) 
        return;
    cout << root->value;
    pre_order(root->left);
    pre_order(root->right);

}
//中序遍历，先左子树后根再右子树
void mid_order(Node* root) {
    if(root == nullptr) 
        return;
    mid_order(root->left);
    cout << root->value;
    mid_order(root->right);

}
//后序遍历，先左子树后右子树再根
void post_order(Node* root) {
    if(root == nullptr) {
        return;
    }
    post_order(root->left);
    post_order(root->right);
    cout << root->value;
}

int main(int argc, const char** argv) {
    return 0;
}