#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left)/2;
            if(target > nums[mid]) {
                left = mid + 1;
            } else if(target < nums[mid]) {
                right = mid - 1;
            } else {
                return mid;
            }
        }
        return left;

    }

    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left + 1 < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] > target) {
                right = mid;
            } else if(nums[mid] < target) {
                left = mid;
            } else {
                return mid;
            }
        }
        if(target > nums[right]) {
            return right + 1;
        }
        if(target <= nums[left]) {
            return left;
        }
        return right;

    }
};