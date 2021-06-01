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
    int *color;
    vector<int> *edges;
    
public:
    Graph(int input_n) {
        n = input_n;
        edges = new vector<int>[n];
        color = new int[n];
        memset(color, 0, n * sizeof(int));
    }

    ~Graph() {
        delete[] edges;
        delete[] color;
    }

    void insert(int x, int y) {
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    void floodfill() {
        int color_cnt = 0;
        for(int i = 0; i < n; ++i)
        {
            if(color[i] == 0)
            {
                color_cnt++;
                color[i] = color_cnt;
                queue<int> q;
                q.push(i);
                while(!q.empty())
                {
                    int vertex = q.front();
                    for(int j: edges[vertex])
                    {
                        if(color[j] == 0)
                        {
                            color[j] = color_cnt;
                            q.push(j);
                        }
                    }
                    q.pop();
                }
            }
        }
        for(int i = 0; i < n; ++i)
        {
            cout << i << " " << color[i] << endl;
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    Graph g(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        g.insert(x, y);
    }
    g.floodfill();
    return 0;
}