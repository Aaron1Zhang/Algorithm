class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> maps;
        for (auto& word: words) {
            maps[word]++;
        }
        auto comp = [](std::pair<string, int>& p1, std::pair<string, int>& p2) {
           return p1.second == p2.second? p1.first < p2.first: p1.second > p2.second;
        };
        //构建一个小堆
        priority_queue<std::pair<string, int>, vector<std::pair<string, int>>, 
        decltype(comp)> queue(comp);
        for (auto& p: maps) {
            queue.push(p);
            if (queue.size() > k) {
                queue.pop();
            }
        }
        vector<string> res(k);
        for (int i = k-1; i >= 0; --i) {
            res[i] = queue.top().first;
            queue.pop();
        }
        return res;
    }
};