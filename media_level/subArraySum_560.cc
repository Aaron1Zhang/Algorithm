#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, int> prefix_sum;   //前缀和以及出现的次数
        prefix_sum[0] = 1;
        int sum_i = 0;

        for (int i = 0; i < nums.size(); ++i) {
            sum_i += nums[i];
            if (prefix_sum.find(sum_i - k) != prefix_sum.end()) {
                res += prefix_sum[sum_i - k];
            } 
            prefix_sum[sum_i] += 1;
            

        }
        return res;

    }
};