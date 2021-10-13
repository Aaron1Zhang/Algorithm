/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) {
            return root;
        }        
        queue<Node*> Queue;
        Queue.push(root);
        while (!Queue.empty()) {
            int queue_size = Queue.size();
            
            while (queue_size) {
                queue_size--;
                auto item = Queue.front();
                Queue.pop();
                if (queue_size > 0) {
                    item->next = Queue.front();
                }
                if (item->left) {
                    Queue.push(item->left);
                    
                }
                if (item->right) {
                    Queue.push(item->right);
                    
                }
            }
        }
        
        return root;
    }
   
};









