#include <iostream>
#include <vector>
#include <set>
#include <cassert>
using namespace std;
//give a set (1,2,3) , gen all subset:
//(1,2,3) (1,2) (1,3) (1) (2,3) (2) (3) ()
void subSets(set<int>& sets, set<int>& cur, vector<set<int>>& res) {
    if(sets.empty()) {
        res.push_back(cur);
        return;
    }
    auto item_iter = sets.begin();
    auto item_value = *item_iter;
    //case: include item
    auto cur_insert_iter = cur.insert(item_value);
    sets.erase(sets.begin()); 
    subSets(sets, cur, res);
    //case: not include item
    cur.erase(cur_insert_iter.first);
    subSets(sets, cur, res);
    sets.insert(item_value);
}
auto subSet(set<int>& sets) {
    vector<set<int>> res;
    set<int> cur;
    subSets(sets, cur, res);
    return res;
}

int main(int argc, const char** argv) {
    set<int> sets{1,2,3};
    auto res = subSet(sets);
    for(auto& item: res) {
        for(auto& i : item) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
