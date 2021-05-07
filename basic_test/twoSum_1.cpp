#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    map<int, int> maps;
    auto size = nums.size();
    vector<int> res;
    for (int i = 0; i < size; ++i)
    {
        auto iter = maps.find(target - nums[i]);
        if (iter != maps.end())
        {
            res.push_back(i);
            res.push_back(iter->second);
            return res;
        }
        maps.emplace(nums[i], i);
    }
    return res;
}

int main(int argc, const char **argv)
{
    return 0;
}