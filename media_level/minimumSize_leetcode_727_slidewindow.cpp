class Solution {
public:
    /**
     * @param nums: an array of integers
     * @param s: An integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        int ans = nums.size() + 1;
        int j = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            while(j < nums.size() && sum < s) {
                sum += nums[j];
                ++j;
            } 
            if(sum >= s) {
                if(j - i < ans) {
                    ans = j - i;
                }    
            }
            
            sum -= nums[i]; 
        }
        if(ans == nums.size() + 1)
            return -1;
        return ans;
    }
        
};