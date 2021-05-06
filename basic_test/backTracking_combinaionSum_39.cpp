#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        helper(res, candidates, target, cur, 0);
        return res;
        
    }
    void helper(vector<vector<int>>& res, vector<int>& candidates,int target, vector<int>& cur, int pos) {
        if(target == 0) {
            res.push_back(cur);
            return;
        }
        if(target < 0) {
            return;
        }
        for(int i = pos; i < candidates.size(); ++i) {
            cur.push_back(candidates[i]);
            helper(res, candidates, target - candidates[i], cur, i);
            cur.pop_back();
        }
    }
};