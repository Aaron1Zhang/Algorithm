class Solution {
private:
    int size{0};
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> maps;
        for(int i = 0 ; i < nums.size(); ++i) {
            maps[nums[i]]++;
        }
        auto pair_compare = [] (const pair<int,int>& v1, const pair<int,int>& v2) {
            return v1.second > v2.second;
        };

        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(pair_compare)>   min_heap(pair_compare);
        for(auto& p: maps) {
            if(size < k) {
                ++size;
                min_heap.push(p);
            } else {
                auto min_item = min_heap.top();
                if(p.second > min_item.second) {
                    min_heap.pop();
                    min_heap.push(p);
                }
            }

        }
        vector<int> res;
        while(!min_heap.empty()) {
            auto t = min_heap.top();
            res.push_back(t.first);
            min_heap.pop();
        }
        return res;
        


    }
};