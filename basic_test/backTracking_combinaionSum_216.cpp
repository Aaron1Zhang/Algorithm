#include <set>
#include <iostream>
#include <vector>
using namespace std;
/*找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

说明：

所有数字都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: k = 3, n = 7
输出: [[1,2,4]]
示例 2:

输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]
*/
// void helper(vector<vector<int>>& res, vector<int>& cur,vector<bool>& visited, int k, int n, int count) {
//     if(count == k) {
//         if(n == 0) { 
//             res.push_back(cur);
//         }
//         return;
//     }
//     for(int i = 1; i <=9; ++i) {
//         if(visited[i-1] == false) {
//             visited[i-1] = true;
//             cur.push_back(i);
//             helper(res, cur, visited, k, n - i, count + 1);
//             cur.pop_back();
//             visited[i-1] = false;
//         }
//     }
// }
// vector<vector<int>> combinationSum3(int k, int n) {
//     vector<vector<int>> res;
//     vector<int> cur;
//     vector<bool> visited(9, false); 
//     helper(res, cur, visited, k, n, 0);
//     return res;
// }
void helper(vector<vector<int>>& res, vector<int>& cur, vector<bool>& visited, int k, int n, int count, int pos);
vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> cur;
    vector<bool> visited(9, false); 
    helper(res, cur, visited, k, n, 0, 1);
    
    return res;
}

void helper(vector<vector<int>>& res, vector<int>& cur, vector<bool>& visited, int k, int n, int count, int pos) {
    if(count == k) {
        if(n == 0) { 
            res.push_back(cur);
        }
        return;
    }
    for(int i = pos; i <= 9; ++i) {
        if(visited[i-1] == false) {
            visited[i-1] = true;
            cur.push_back(i);
            helper(res, cur, visited,k, n - i, count + 1, i+1);
            cur.pop_back(); 
            visited[i-1] = false;
        }
                    
    }
}
int main(int argc, const char** argv) {
    auto res = combinationSum3(3, 9);
    for(auto& v: res) {
        for(auto& i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
    
