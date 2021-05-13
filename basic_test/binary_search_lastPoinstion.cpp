#include <iostream>
#include <vector>
using namespace std;

int lastPosition(vector<int> &nums, int target) {
        if(nums.size() == 0) {
            return -1;
        }
        // write your code here
        int left = 0;
        int right = nums.size() - 1;
        while(left + 1 < right) {
            int mid = left+ (right - left)/2;
            if(nums[mid] > target) {
                right = mid - 1;
            } else if(nums[mid] < target) {
                left = mid + 1;
            } else {
                left = mid;
            }
        }
        if(nums[right] == target) {
            return right;
        }
        if(nums[left] == target) {
            return left;
        }
        return -1;
    }

int main(int argc, const char** argv) {
    return 0;
}