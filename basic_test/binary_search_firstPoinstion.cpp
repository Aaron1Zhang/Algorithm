 #include <iostream>
 #include <vector>
 using namespace std;
 
 /**
     * @param nums: The integer array.
     * @param target: Target to find.
     * @return: The first position of target. Position starts from 0.
     */
    int binarySearch(vector<int> &nums, int target) {
        // write your code here
        int left = 0;
        int right = nums.size() - 1;
        while(left + 1 < right) {
            int mid = left + (right - left) /2 ;
            if(nums[mid] > target) {
                right = mid - 1;
            } else if(nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
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