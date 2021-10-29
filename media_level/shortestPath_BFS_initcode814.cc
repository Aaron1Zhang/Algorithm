/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution {
public:
    /**
     * @param graph: a list of Undirected graph node
     * @param A: nodeA
     * @param B: nodeB
     * @return:  the length of the shortest path
     */
    int shortestPath(vector<UndirectedGraphNode*> graph, UndirectedGraphNode* A, UndirectedGraphNode* B) {
        unordered_set<UndirectedGraphNode*> sets;
        queue<UndirectedGraphNode*> Queue;
        int path = 0;
        sets.insert(A);
        Queue.push(A);
        while (!Queue.empty()) {
            auto size = Queue.size();
            while (size--) {
                auto item = Queue.front();  
                Queue.pop();
                if (item->label == B->label) {
                    return path;
                }
                for (auto& nei: item->neighbors) {
                    if (sets.count(nei) == 0) {
                        sets.insert(nei);
                        Queue.push(nei);
                    }
                }
            } 
            path++; 
        }
        
        return path;

    }
};