#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        if(prerequisites.size() == 0 ) {
            return true;
        }
        int count = 0;
        int node_count = 0;
        queue<int> Queue;
        unordered_map<int, int> in;
        unordered_set<int> num_count;
        vector<vector<int>> edges;
        edges.resize(numCourses);

        for(auto& p: prerequisites) {
            in[p[0]]++;
            edges[p[1]].push_back(p[0]);
        }
        for(auto&p : prerequisites) {
           for(auto& i: p) {
               num_count.insert(i);
           }
        }
        for(int i = 0 ; i < edges.size(); ++i) {
            if(edges[i].size()) {
                if(in[i] == 0) {
                    Queue.push(i);  
                }
            }
        }
        while(!Queue.empty()) {
            auto item = Queue.front();
            Queue.pop();
            count++;
            for(auto& e: edges[item]) {
                if(--in[e] == 0) {
                    Queue.push(e);   
                }
            }
        }
        if(count == num_count.size())
            return true;
        return false;
        //return count == numCourses;



    }
};