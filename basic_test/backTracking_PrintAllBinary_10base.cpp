#include <iostream>
#include <string>
#include <vector>
using namespace std;

void helper(vector<vector<int>>& res, vector<int> cur, int len) {
    if(len == 0) {
        res.push_back(cur);
        return;
    }
    for(int i = 0; i <= 9; ++i) {
        cur.push_back(i);
        helper(res, cur, len - 1);
        cur.pop_back();
    }
}

auto printAllNumberBaseten(int len) {
    vector<vector<int>> res;
    vector<int> cur;
    helper(res, cur, len);
    return res;
}

int main(int argc, const char** argv) {
    auto res = printAllNumberBaseten(2);
    cout << "the size is " << res.size() << endl;
    for(auto& v: res) {
        for(auto& i: v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}