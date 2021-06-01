#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using std::cin;
using std::cout;
using std::endl;
using std::queue;
using std::vector;

class Graph {
private:
    int n;
    bool *visited;
    vector<int> *edges;
public:
    Graph(int input_n) {
        n = input_n;
        edges = new vector<int>[n];
        visited = new bool[n];
        memset(visited, 0, sizeof(bool) * n);
    }
    ~Graph() {
        delete[] edges;
        delete[] visited;
    }
    void insert(int x, int y) {
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    void bfs(int start_vertex) {
        queue<int> bfs_queue;
        bfs_queue.push(start_vertex);
        visited[start_vertex] = true;
        while(!bfs_queue.empty()) {
            int vertex = bfs_queue.front();
        	cout << vertex << endl;
            bfs_queue.pop();
            for(int adj_vertex: edges[vertex]) {
                if(!visited[adj_vertex]) {
                    visited[adj_vertex] = true;
                    bfs_queue.push(adj_vertex);
                    
                }
            }
        }

    }
};
int main() {
    int n, m, k;
    cin >> n >> m;
    Graph g(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        g.insert(x, y);
    }
    cin >> k;
    g.bfs(k);
    return 0;
}