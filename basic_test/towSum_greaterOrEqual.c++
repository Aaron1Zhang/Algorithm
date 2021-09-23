#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param target: an integer
     * @return: an integer
     */
    int twoSum5(vector<int> &nums, int target) {
        if (nums.size() < 2)
            return 0;
        // write your code here
        std::sort(nums.begin(), nums.end());
        int count = 0;
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum <= target) {
                count += right - left;
                left++;
            } else {
                right--;
            }
        }
        return count;
    }
};