class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> maps;
        auto n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (maps.count(nums[i])) {
                maps[nums[i]] += 1;
                
            } else {
                maps[nums[i]] = 1;
            }
            if (maps[nums[i]] > n/2) {
                return nums[i];
            }
        }
        return -1;

    }
};