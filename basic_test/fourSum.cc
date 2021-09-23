#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void findThreeSum(vector<int> &nums, int index, int target, vector<vector<int>> &res)
{
    int start = index + 1;
    for (int i = start; i < nums.size(); ++i)
    {
        if (i > start && nums[i] == nums[i - 1])
        {
            continue;
        }
        int tt = target - nums[i];
        int left = i + 1;
        int right = nums.size() - 1;
        while (left < right)
        {
            int sum = nums[left] + nums[right];
            if (sum > tt)
            {
                right--;
            }
            else if (sum < tt)
            {
                left++;
            }
            else
            {
                res.push_back(vector<int>{nums[index], nums[i], nums[left], nums[right]});
                left++;
                right--;
                while (left < right && nums[left] == nums[left - 1])
                {
                    left++;
                }
            }
        }
    }
}
vector<vector<int>> fourSum(vector<int> &numbers, int target)
{
    vector<vector<int>> res;
    std::sort(numbers.begin(), numbers.end());
    for (int i = 0; i < numbers.size(); ++i)
    {
        if (i != 0 && numbers[i] == numbers[i - 1])
        {
            continue;
        }
        int t = target - numbers[i];
        findThreeSum(numbers, i, t, res);
    }
    return res;
}


int main(int argc, const char** argv) {
    vector<int> arr{1,0,-1,0,-2,2};
    auto res = fourSum(arr, 0);
    for (auto r: res) {
        for (auto i : r) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}