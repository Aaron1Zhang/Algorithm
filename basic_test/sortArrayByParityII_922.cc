#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i = 0, j = 1;
        int size = nums.size();
        vector<int> res;
        while (i < size && j < size) {
            while (i < size && nums[i] % 2 == 0) {
                i += 2;
            }
            while (j < size && nums[j] % 2 != 0) {
                j += 2;
            }
            if (i < size && j < size) {
                std::swap(nums[i], nums[j]);
                i += 2;
                j += 2;
            }

        }
        res = nums;
        return res;


    }
};

int main(int argc, const char** argv) {
    Solution s;
    vector<int> arr{2,3};
    auto res = s.sortArrayByParityII(arr);
    for (auto & i: res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}