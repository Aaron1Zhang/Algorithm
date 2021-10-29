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
     * @param nodes: a array of Undirected graph node
     * @return: a connected set of a Undirected graph
     */
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*> nodes) {
        unordered_set<UndirectedGraphNode*> sets;
        vector<vector<int>> res;
        for (auto& node: nodes) {
            if (sets.find(node) != sets.end()) {
                continue;
            }
            queue<UndirectedGraphNode*> Queue;
            vector<int> vec_nodes;
            Queue.push(node);
            sets.insert(node);
            while (!Queue.empty()) {
                auto item = Queue.front();
                vec_nodes.push_back(item->label);
                Queue.pop();
                for (auto& nei: item->neighbors) {
                    if (sets.find(nei) == sets.end()) {
                        sets.insert(nei);
                        Queue.push(nei);
                    }
                }
            }
            std::sort(vec_nodes.begin(), vec_nodes.end());
            res.push_back(vec_nodes);
        }
        return res;
    }

    void BFS() {

    }
};