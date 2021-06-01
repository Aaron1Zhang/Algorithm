#include <iostream>
#include <vector>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Graph {
private:
    int n;
    vector<int> *edges;
    bool* visited;
public:
    Graph(int input_n) {
        n = input_n;
        edges = new vector<int>[n];
        visited = new bool[n];
        memset(visited, 0, n);
    }
    ~Graph() {
        delete[] edges;
        delete[] visited;
    }
    void insert(int x, int y) {
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    void dfs(int vertex) {
        cout << vertex << endl;
        visited[vertex] = true;
        for(int adj_vertex: edges[vertex]) {
            if(!visited[adj_vertex]) {
                dfs(adj_vertex);
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
    g.dfs(k);
    return 0;
}