#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        helper(res, candidates, target, cur, 0);
       
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int>& candidates, int target, vector<int>& cur, int pos) {
        if(target < 0) {
            return;
        }
        if(target == 0) {
            res.push_back(cur);
            return;
        }

        for(int i = pos; i < candidates.size(); ++i) {
            if(i > pos && candidates[i] == candidates[i-1]) {
                continue;
            }
            cur.push_back(candidates[i]);   
            helper(res, candidates, target - candidates[i], cur, i+1);
            cur.pop_back();
        }
    }
};