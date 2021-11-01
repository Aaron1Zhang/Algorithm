class Solution {
public:
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid;
            } else if (nums[mid] < nums[right]) {
                right = mid;
            }
        }
        if (nums[left] < nums[right]) {
            return nums[left];
        }
        return nums[right];
    }
};