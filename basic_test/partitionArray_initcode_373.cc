class Solution {
public:
    /*
     * @param nums: an array of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        int i = 0, j = nums.size() - 1;
        while (i <= j) {
            while (i <= j && nums[i] % 2 == 1) {
                ++i;
            }
            while (i <= j && nums[j] % 2 == 0) {
                j--;
            }
            if (i <= j) {
                std::swap(nums[i], nums[j]);
                ++i;
                --j;
            }
        }
    }
};