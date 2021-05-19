#include <iostream>
#include <vector>
using namespace std;

int twoSum6(vector<int> &nums, int target) {
        if(nums.size() < 2) return 0;
        int res = 0;
        sort(nums.begin(), nums.end());
        int i = 0; 
        int j = nums.size()-1;
        while(i < j) {
            if(i > 0 && nums[i] == nums[i-1]) {
                ++i;
                continue;
            }
            auto sum = nums[i] + nums[j];
            if(sum > target) {
                --j;
            } else if(sum < target) {
                ++i;
            } else {
                res++;   
                ++i;
                --j; 
            }
        }
        return res;
}