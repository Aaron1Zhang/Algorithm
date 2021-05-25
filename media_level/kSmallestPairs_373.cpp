class Solution {
private:
    int size{0};
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
       /*  auto lam = [](const pair<int, int>& p1, const pair<int,int>& p2) {
            return p1.first + p1.second > p2.first + p2.second;
        };

        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(lam)>  min_heap(lam);

        for(int i = 0; i < nums1.size(); ++i) {
            for(int j = 0 ; j < nums2.size(); ++j) {
                auto item = make_pair(nums1[i], nums2[j]);
                min_heap.push(item);
            }
        }
        vector<vector<int>> res;
        while(!min_heap.empty() && k) {
            --k;
            auto item = min_heap.top();
            res.push_back(vector<int>{item.first, item.second});
            min_heap.pop();
        }
        return res; */
		
		
		auto lam = [](const pair<int, int>& p1, const pair<int,int>& p2) {
             return p1.first + p1.second < p2.first + p2.second;
        };

        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(lam)> max_heap(lam);
        vector<vector<int>> res;    
        for(int i = 0; i < nums1.size(); ++i) {
            for(int j = 0 ; j < nums2.size(); ++j) {
                auto item = make_pair(nums1[i], nums2[j]);
                if(size < k) {
                    ++size;
                    max_heap.push(item);
                } else {
                    auto max_item = max_heap.top();
                    if((max_item.first+max_item.second) > (item.first + item.second)) {
                        max_heap.pop();
                        max_heap.push(item);
                    }
                }
               
            }
        }
        while(!max_heap.empty()) {
             auto item = max_heap.top();
             res.push_back(vector<int>{item.first, item.second});
             max_heap.pop();

        }
        return res;

    }
};