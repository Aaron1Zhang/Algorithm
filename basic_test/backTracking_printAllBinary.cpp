#include <iostream>
#include <string>
#include <vector>
using namespace std;

// void helper(size_t n, string cur_res) {
//     if(cur_res.size() == n) {
//         cout << cur_res << endl;
//         return;
//     }
//     helper(n, cur_res + '1');
//     helper(n, cur_res + '0');

// }
// void printAllBinary(size_t n) {
//     string s;
//     helper(n, s);
// }
void helper(size_t n, vector<vector<int>>& results, vector<int> cur) {
    if(cur.size() == n) {
        results.push_back(cur);
        return;
    }
    cur.push_back(1);
    helper(n, results, cur);
    cur.pop_back();
    cur.push_back(0);
    helper(n, results, cur);

}

// void helper(size_t n, vector<string>& results, string cur) {
//     if(cur.size() == n) {
//         results.push_back(cur);
//         return;
//     }
//     helper(n, results, cur + '1');
//     helper(n, results, cur + '0');
// }

auto printAllBinary(size_t n) {
    // vector<string> results;
    // string s;
    // helper(n, results, s);
    vector<vector<int>> results;
    vector<int> res;

    helper(n, results, res);
    return results;
}


int main(int argc, const char** argv) {
    auto results = printAllBinary(3);
    for(auto res: results) {
        for(auto i: res)
            cout << i << " ";
        cout << endl;
    }
    //printAllBinary(2);
    return 0;
}