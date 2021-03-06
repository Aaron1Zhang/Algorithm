#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
//set {1,2,3}, print all combantion
//{1,2,3}, {1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}

// void Permution(vector<int>& nums, vector<vector<int>>& results, vector<int>& cur) {
//     if(nums.size() == 0) {
//         results.push_back(cur);
//         return;
//     }
    
//     for(int i = 0; i < nums.size(); ++i) {
//         cur.push_back(nums[i]);
//         auto temp = nums;
//         temp.erase(temp.begin()+i);
//         Permution(temp, results, cur);
//         cur.pop_back();
//     }
// }

// int main(int argc, const char** argv) {
//     vector<vector<int>> results;
//     vector<int> s = {1,2,3};
//     vector<int> cur;
//     Permution(s, results, cur);
//     cout << "the size of all permution is " << results.size() << endl;
//     for(auto res: results) {
//         for(auto i : res) {
//             cout << i << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

 void helper(vector<int>& nums, vector<vector<int>>& results, vector<int>& cur, vector<bool>& visited)     {
        if(cur.size() == nums.size()) {
            results.push_back(cur);
            return;
        }
        for(int i = 0 ; i < nums.size(); ++i) {
            if(visited[i] == false) {
                visited[i] = true;
                cur.push_back(nums[i]);
                helper(nums, results, cur, visited);
                cur.pop_back();
                visited[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> cur;
        vector<bool> visited(nums.size(), false);
        helper(nums, results, cur, visited);
        //Permution(nums, results, cur);
        return results;
    }