#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    vector<vector<int>> subsets(vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> cur;
        helper(nums, res, cur, 0);
        return res;
        
    }

    void helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& cur, int pos) {
        if (pos == nums.size()) {
            res.push_back(cur);
            return;
        }
        
        cur.push_back(nums[pos]);
        helper(nums, res, cur, pos+1);
        cur.pop_back();
        helper(nums, res, cur, pos+1);
    }
};

int main(int argc, const char** argv) {
    Solution s;
    vector<int> num{1,2,3};
    auto res = s.subsets(num);
    cout << "res size is " << res.size() << endl;
    for (auto v: res) {
        for (auto i: v) {
            cout << i << ",";
        }
        cout << endl;
    }
}