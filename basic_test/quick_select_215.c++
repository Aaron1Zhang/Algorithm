#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() == 0) {
            return -1;
        }

        return helper(nums, 0, nums.size() - 1, k);
    }
private:
    int helper(vector<int>& nums, int start, int end, int k) {
        if (start == end) return nums[start];
        int i = start;
        int j = end;
        int pivot = nums[(i+j) / 2];
        while (i <= j) {
            while (i <= j && nums[i] > pivot) {
                i++;
            }
            while (i <= j && nums[j] < pivot) {
                j--;
            }
            if (i <= j) {
                std::swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }
        if (k <= j - start + 1)
        {
            return helper(nums, start, j, k);
        }
        else if (k >= i - start + 1)
        {
            return helper(nums, i, end, k-(i - start));
        }
        return nums[j + 1];
        

    }
};