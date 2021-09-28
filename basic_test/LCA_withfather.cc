#include <iostream>
#include <unordered_set>
using namespace std;
class ParentTreeNode {
public:
    int val;
     ParentTreeNode *parent, *left, *right;
};



class Solution {
public:
    /*
     * @param root: The root of the tree
     * @param A: node in the tree
     * @param B: node in the tree
     * @return: The lowest common ancestor of A and B
     */
    ParentTreeNode * lowestCommonAncestorII(ParentTreeNode * root, ParentTreeNode * A, ParentTreeNode * B) {
        ParentTreeNode* cur = A;
        unordered_set<ParentTreeNode*> sets;
        
        while (cur) {
            sets.insert(cur);
            cur = cur->parent;
        }

        cur = B;
        while (cur) {
            auto iter = sets.find(cur);
            if (iter != sets.end()) {
                return *iter;
            }
            cur = cur->parent;
            
        }

    }
};







