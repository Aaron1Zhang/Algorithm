#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());
        vector<vector<int>> res(1, intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            auto last_inter = res.back();
            if (intervals[i][0] > last_inter[1]) {
                res.push_back(intervals[i]);
            }
            if (intervals[i][0] <= last_inter[1] && last_inter[1] < intervals[i][1]) {
                auto left = last_inter[0];
                auto right = intervals[i][1];
                res.pop_back();
                res.push_back({left, right});
            }
        }
        return res;
    }
};

int main(int argc, const char** argv) {
    vector<vector<int>> vec{{1,3},{2,6},{8,10},{15,18}};
    Solution S;
    S.merge(vec);
    return 0;
}