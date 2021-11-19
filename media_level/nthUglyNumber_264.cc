class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long>> min_heap;
        unordered_set<long> visited;
        min_heap.push(1L);
        visited.insert(1L);
        vector<int> factor{2,3,5};
        long ugly = 0;
        for (int i = 0 ; i < n; ++i) {
            ugly = min_heap.top();
            min_heap.pop();
            for (auto& f: factor) {
                auto ugly_num = f * ugly;
                if (visited.find(ugly_num) == visited.end()) {
                    min_heap.push(ugly_num);
                    visited.insert(ugly_num);
                }
            }
        }
        return ugly;

    }
};