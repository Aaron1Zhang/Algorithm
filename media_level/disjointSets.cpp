#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::swap;

class DisjointSet {
private:
    int *father, *rank;
    
public:
    DisjointSet(int size) {
        father = new int[size];
        rank = new int[size];
        for (int i = 0; i < size; ++i) {
            father[i] = i;
            rank[i] = 0;
        }
    }
    ~DisjointSet() {
        delete[] father;
        delete[] rank;
    }
    // int find_set(int node) {
    //     if (father[node] != node) {
    //         return find_set(father[node]);
    //     }
    //     return node;
    // }
    int find_set(int node) {
        if(father[node] != node) {
            father[node] = find_set(father[node]);
        }
        return father[node];
    }
    bool merge(int node1, int node2) {
        int ancestor1 = find_set(node1);
        int ancestor2 = find_set(node2);
        if (ancestor1 != ancestor2) {
            if(rank[ancestor1] > rank[ancestor2])
            {
                swap(ancestor1,ancestor2);
            }
            father[ancestor1] = ancestor2;
            rank[ancestor2] = max(rank[ancestor2], rank[ancestor1]+1);
            
            return true;
        }
        return false;
    }
};
int main() {
    DisjointSet dsu(100);
    int m, x, y;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        bool ans = dsu.merge(x, y);
        if (ans) {
            cout << "success" << endl;
        } else {
            cout << "failed" << endl;
        }
    }
    return 0;
}