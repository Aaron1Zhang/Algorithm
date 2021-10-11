#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> sets;
        for (int i = 0; i < nums.size(); ++i) {
            if (sets.find(nums[i]) != sets.end()) {
                return nums[i];
            }
            sets.insert(nums[i]);
        }
        return -1;
    }
};