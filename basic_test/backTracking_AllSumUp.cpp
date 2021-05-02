#include <iostream>
#include <vector>
using namespace std;
void helper(int target, vector<vector<int>>& res, vector<int>& cur, int count)
{
    if(count == 3) {
        if(target == 0) {
            res.push_back(cur);    
        }
        return;
    }
   
    for(int i = 1; i <= 6; ++i) {
        cur.push_back(i);
        helper(target - i, res, cur, count+1);
        cur.pop_back();
    }

}
vector<vector<int>> all(int target) {
    vector<vector<int>> res;
    vector<int> cur;
    helper(target, res, cur, 0);
    return res;
}


int main(int argc, const char** argv) {
    auto res = all(6);
    for(auto& r: res) {
        for(auto& i: r) {
            cout << i << " ";
        }
        cout << endl;

    }
    return 0;
}