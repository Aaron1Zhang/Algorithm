#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
示例 1：

输入：nums = [1,1,2]
输出：
[[1,1,2],
 [1,2,1],
 [2,1,1]]
示例 2：[1,1,2,2]
[1,1,2,2]
[1,2,1,2]
[1,2,2,1]
[2,1,2,1]
[2,1,1,2]
[2,2,1,1]

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

*/


vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> cur;
    vector<bool> visited(nums.size(), false);
    std::sort(nums.begin(), nums.end());
    helper(res, cur, nums, visited);
    return res;
}
void helper(vector<vector<int>>& res, vector<int>& cur, vector<int>& nums, vector<bool>& visited) {
    if(cur.size() == nums.size()) {
        res.push_back(cur);
        return;
    }       
    for(auto i = 0; i < nums.size(); ++i) {
        if(visited[i] == true) {
            continue;
        }
        if(i != 0 && nums[i] == nums[i-1] && visited[i-1] == false) {
            continue;
        }
        cur.push_back(nums[i]);
        visited[i] = true;
        helper(res, cur, nums, visited);
        cur.pop_back();
        visited[i] = false;
}

int main(int argc, const char** argv) {
    auto res = permute();
    cout << "the size is " << res.size() << endl;
    for(auto& v: res) {
        for(auto& i: v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}