#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left + 1 < right) {
            int mid = left + (right - left) /2 ;
            if(target == nums[mid]) {
                return mid;
            }
            if(nums[mid] >= nums[left]) {
                if(target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if(target > nums[mid] && target < nums[left]) {
                    left = mid + 1;   
                } else {
                    right = mid - 1;
                }

            } 
        }
        if(nums[left] == target) {
            return left;

        }
        if(nums[right] == target) {
            return right;
        }
        return -1;
    }
};