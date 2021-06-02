/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        // write your code here
        vector<DirectedGraphNode*> ans;
        queue<DirectedGraphNode*> Queue;
        unordered_map<DirectedGraphNode*, int> in;
        for(auto& node: graph) {
            for(auto& e: node->neighbors) {
                in[e]++;
            }
        }
        for(auto& node: graph) {
            if(in[node] == 0) { 
                Queue.push(node);
                ans.push_back(node);
            }
        }
        while(!Queue.empty()) {
            auto item = Queue.front();
            Queue.pop();
            for(auto& e: item->neighbors) {
                if(--in[e] == 0) {
                    Queue.push(e);
                    ans.push_back(e);
                }
            }
        }

        return ans;

    }
};