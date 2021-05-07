/* 
*@param nums: The integer array you should partition
*@param k: As description
*return: The index after partition

Given an array nums of integers and an int k, partition the array (i.e move the elements in “nums”) such that:
All elements < k are moved to the left All elements >= k are moved to the right

Return the partitioning index, i.e the first index i nums[i] >= k.
*/

#include <iostream>
#include <vector>
using namespace std;

int partitionArray(vector<int>& nums, int k) {
    int i = 0;
    int j = nums.size() - 1;
    while(i < j) {
        while(i < j && nums[i] < k) {
            ++i;
        } 
        while(i < j && nums[j] >= k) {
            j--;
        }
        if(i < j) {
            std::swap(nums[i], nums[j]);
            ++i;
            --j;
        }
    }
    if(nums[i] < k) {
        return i++;
    }
    return i;
}
int main(int argc, const char** argv) {
    return 0;
}