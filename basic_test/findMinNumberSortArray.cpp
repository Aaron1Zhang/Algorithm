#include <iostream>
#include <string>
#include <vector>
using namespace std;
/**
 * @brief 
 * 输入：nums = [3,4,5,1,2]
输出：1
解释：原数组为 [1,2,3,4,5] ，旋转 3 次得到输入数组。
 * 
 * @param nums 
 * @return int 
 */
int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
       
        while(left < right) {
            int mid = left + (right-left)/2;
            if(nums[mid] > nums[right]) {
                left = mid + 1;
            } else if(nums[mid] < nums[right]) {
                right = mid;
            } 
        }
    
        return nums[left];

    }