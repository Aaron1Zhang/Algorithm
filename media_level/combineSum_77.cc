class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (n == 1) {
            return vector<vector<int>>{{1}};
        }

        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            nums[i] = i+1;
        }
        vector<vector<int>> res;
        vector<int> cur;
        //vector<bool> visited(n, false);
        helper(nums, res, cur, 0, k); 
        return res;
    }

    void helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& cur, int pos, int k) {
        if (cur.size() == k) {
            res.push_back(cur);
            return;
        }

        for (int i = pos; i < nums.size(); ++i) {
           
            cur.push_back(nums[i]);
            
            helper(nums, res, cur, i + 1, k);
            
            cur.pop_back();
        }
    }
};