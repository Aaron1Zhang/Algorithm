#include <iostream>
#include <vector>
using namespace std;
//(1,2,3)的子集， (1,2,3),(1,2),(1,3),(1),(2,3),(2), (3) ()
void subSetsHelper(vector<int>& sets, vector<vector<int>>& res, vector<int>& cur, int pos) {
    if(pos == sets.size()) {
        res.push_back(cur);
        return;
    }
    for(int i = pos; i < sets.size(); ++i) {
        cur.push_back(sets[i]);
        subSetsHelper(sets, res, cur, i+1);
        cur.pop_back();
    }
    res.push_back(cur);
}

auto subSets(vector<int>& sets) {
    vector<vector<int>> res;
    vector<int> cur;
    subSetsHelper(sets, res, cur, 0);
    return res;
}

int main(int argc, const char** argv) {
    vector<int> sets{1,2,3};
    auto res = subSets(sets);
    cout << "res size" << res.size() << endl;
    for(auto& item: res) {
        for(auto& i : item) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}