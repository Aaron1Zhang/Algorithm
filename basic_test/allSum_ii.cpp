#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


void helper(vector<int>& arr, vector<vector<int>>& res, vector<int> cur, int count, int sum) {
    if(count == 0) {
        if(std::accumulate(cur.begin(), cur.end(), 0) == sum) {
            res.push_back(cur);
        }      
        return;
    }
    for(int i = 0; i < arr.size(); ++i) {
        cur.push_back(arr[i]);
        helper(arr, res, cur, count-1, sum);
        cur.pop_back();
    }
}

auto allSum(vector<int>& arr, int count, int sum) {
    vector<vector<int>> res;
    vector<int> cur;
    helper(arr, res, cur, count, sum);
    return res;
}

int main(int argc, const char** argv) {
    vector<int> arr{1,2,3,4,5,6};
    int count = 2;
    int sum = 6;
    auto res = allSum(arr, count, sum);
    for(auto& item: res) {
        for(auto& i : item) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}