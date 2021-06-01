class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        // write your code here
        if(n == 0) return false;
        if(edges.size() != n - 1) return false;
        if(edges.size() == 0) return true;
        int vetex_count = 0;
        vector<vector<int>> edges_rel;
        edges_rel.resize(n);
        for(int i = 0 ; i < edges.size(); ++i) {
            int u = edges[i][0], v = edges[i][1];
            edges_rel[u].push_back(v);
            edges_rel[v].push_back(u);
        }

        queue<int> Queue;
        bool visited[n] = {false};

        int start = edges[0][0];
        visited[start] = true;
        vetex_count++;
        Queue.push(start);
        while(!Queue.empty()) {
            int item = Queue.front();
            Queue.pop();
            for(auto& i : edges_rel[item]) {
                if(visited[i] == false) {
                    visited[i] = true;
                    Queue.push(i);
                    vetex_count++;
                }
            }
        }
        return vetex_count == n;


    }

    
};