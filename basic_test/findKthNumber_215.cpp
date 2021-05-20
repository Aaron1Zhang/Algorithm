#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int>& nums, int i, int j) {
    // int i = 0;
    // int j = nums.size()-1;
    int pivot_index = i;
    int pivot = nums[pivot_index];
    while(i <= j) {  
        while(i <= j && nums[i] <= pivot) {
            ++i;
        }
        while(i <= j && nums[j] >= pivot) {
            --j;
        }
        if(i <= j) {
            std::swap(nums[i], nums[j]);
            ++i;
            --j;
        }
            
    }
    std::swap(nums[pivot_index], nums[j]);
    return j;
}
int helper(vector<int>& nums, int k, int i, int j) {
    int r = partition(nums, i, j);
    if(k < r) {
        return helper( nums, k, i, r);
    } else if(k > r) {
        return helper(nums, k, r+1, j);
    } else {
        return nums[r];
    }
}
int findKthLargest(vector<int>& nums, int k) {
    int rank = nums.size() - k;  //第rank小  
    return helper(nums, rank, 0, nums.size() - 1);
}

int main(int argc, const char** argv) {
    vector<int> nums{7,5,3,9,11,2,1};
    //auto res = partition(nums, 0, nums.size()-1);
    //cout << "index " << res << endl;
    // for(auto& i : nums) {
    //     cout << i << " ";
    // }
    //cout << endl;
     auto r = findKthLargest(nums, 6);
     cout << r << endl;
    return 0;
}