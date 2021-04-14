#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

void helper(int count, int target, vector<int> path, set<int> range, set<vector<int>>& res)
{
    if(count == 0)
    {
        if(target == 0)
        {
            res.insert(path);
        }
        return;
    }
    for(auto i: range)
    {
        path.push_back(i);
        //range.erase(i);
        helper(count-1, target-i, path, range, res);
        path.pop_back();
        //range.insert(i);
    }
}
set<vector<int>> AllSum(int count, int target, set<int> range)
{
    set<vector<int>> res;
    vector<int> path;
    helper(count, target, path, range, res);
    return res;
}
int main(int argc, char const *argv[])
{
    set<int> range{1,2,3,4,5,6};
    set<vector<int>> res = AllSum(3, 7, range);
    for(auto v: res)
    {
        for(auto i: v)
            cout << i << " ";
        cout << endl;
    }
        
    return 0;
}
