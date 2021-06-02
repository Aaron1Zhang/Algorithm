#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        if(prerequisites.size() == 0) {
            for(int i = 0; i < numCourses; ++i) {
                ans.push_back(i);
            }
            return ans;
        }
        vector<int> in;
        vector<vector<int>> edges;
        queue<int> Queue;
        in.resize(numCourses);
        edges.resize(numCourses);
        for(auto& e: prerequisites) {
            edges[e[1]].push_back(e[0]);
            in[e[0]]++;
        }
        for(int i = 0; i < in.size(); ++i) {
            if(in[i] == 0) {
                Queue.push(i);
            }
        }
        int count = 0;
        while(!Queue.empty()) {
            auto item = Queue.front();
            ans.push_back(item);
            Queue.pop();
            count++;
            for(auto& e: edges[item]) {
                if(--in[e] == 0) {
                    Queue.push(e);

                }
            }
        }
        if(count == numCourses) {
            return ans;
        }
        return vector<int>{};
    }
};

int main(int argc, const char** argv) {
    int num = 2;
    vector<vector<int>> c{{0,1}};
    auto res = findOrder(num,c);
    cout << res.size() << endl;
    return 0;
}