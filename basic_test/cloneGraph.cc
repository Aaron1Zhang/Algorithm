#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

struct UndirectedGraphNode
{
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x){};
};

class Solution
{
public:
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
    {
        if (node == nullptr) return nullptr;
        auto allNodes = findAllNodes(node);
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> maps = cloneNodes(allNodes);
        cloneEdges(maps, allNodes);
        return maps[node];
    }
    vector<UndirectedGraphNode *> findAllNodes(UndirectedGraphNode *node)
    {
        vector<UndirectedGraphNode *> nodes;
        unordered_set<UndirectedGraphNode *> visited;
        queue<UndirectedGraphNode *> Queue;
        nodes.push_back(node);
        Queue.push(node);
        visited.insert(node);
        while (!Queue.empty())
        {
            auto item = Queue.front();
            Queue.pop();
            for (const auto neib : item->neighbors)
            {
                if (visited.find(neib) == visited.end())
                {
                    Queue.push(neib);
                    visited.insert(neib);
                    nodes.push_back(neib);
                }
            }
        }
        return nodes;
    }
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> cloneNodes(vector<UndirectedGraphNode *> &nodes)
    {
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> maps;
        for (const auto node : nodes)
        {
            maps[node] = new UndirectedGraphNode(node->label);
        }
        return maps;
    }
    void cloneEdges(unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> &maps, vector<UndirectedGraphNode *> &nodes)
    {
        for (auto node : nodes) {
            auto copy_node = maps[node];
            for (auto nei: node->neighbors) {
                auto node = maps[nei];
                copy_node->neighbors.push_back(node);
            }
        }      
        
    }
};
