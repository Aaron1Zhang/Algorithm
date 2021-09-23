#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int count = 0;
        for (int i = 2; i < nums.size(); ++i) {
            int left = 0;
            int right = i - 1;
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum <= nums[i]) {
                    left++;
                } else {
                    count += right - left;
                    right--;
                }
            }
        }
        return count;

    }
};