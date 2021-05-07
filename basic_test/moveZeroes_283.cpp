#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

void moveZeroes(vector<int>& nums) {
    
    int left = 0;
    int right = 0;
    int size = nums.size();
    while(right < size) {
        if(nums[right]) {
            std::swap(nums[left], nums[right]);
            ++left;
        }
        ++right;
    }
        
}


int main(int argc, const char** argv) {
    vector<int> nums{0,1,0,3,12};
    moveZeroes(nums);
    return 0;
}
