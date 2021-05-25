class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> maps;
        for(const auto& c: s) {
            maps[c]++;
        }
        auto pc = [](const pair<char,int>& p1, const pair<char,int>& p2) {
            return p1.second < p2.second;
        };

        priority_queue<pair<char,int>, vector<pair<char,int>>, decltype(pc)> max_heap(pc);

        for(auto& p: maps) {
            max_heap.push(p);
        }
        string res;
        while(!max_heap.empty()) {
            for(int i = 0; i < max_heap.top().second; ++i) {
                res.push_back(max_heap.top().first);
            }
            
            max_heap.pop();
        }
        return res;
    }
};