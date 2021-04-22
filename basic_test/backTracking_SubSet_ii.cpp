#include <iostream>
#include <set>
#include <vector>
using namespace std;
//(1,2,3)subsets
//(1,2,3)、(1,2)、(1,3)、(1)、(2,3)、(2)、(3)、()
void subsetsHelper(vector<int>& nums, vector<int>& cur, int k, vector<vector<int>>& res)
{
    if(k == nums.size()) {
        res.push_back(cur);
        return;
    }
    cur.push_back(nums[k]);
    subsetsHelper(nums, cur, k+1, res);
    cur.pop_back();
    subsetsHelper(nums, cur, k+1, res);
    
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> cur;
    vector<vector<int>> result;
    subsetsHelper(nums, cur, 0, result);
    return result;
}

int main(int argc, const char** argv) {
    vector<int> nums{1,2,3};
    auto res = subsets(nums);
    cout << "the size is " << res.size() << endl;
    for(auto& v: res) {
        for(auto& i: v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}