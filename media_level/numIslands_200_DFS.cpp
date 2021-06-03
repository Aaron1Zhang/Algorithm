#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
private:
    size_t rows{0};
    size_t cols{0};
public:
  
    int numIslands(vector<vector<bool>>& grid) {
        rows = grid.size();
        if (!rows) return 0;
        cols = grid[0].size();
        int row = 0, col = 0;
        int count = 0;
        for(int i = 0; i < rows; ++i) {
            for(int j = 0 ; j < cols; ++j) {
                if(grid[i][j] == 1) {
                    dfs(grid, i, j);
                    count++;
                }
                
            }
        }
        return count;
    }
    void dfs(vector<vector<bool>>& grid, int x, int y) {
        if(x >= 0 && x < rows && y >= 0 && y < cols) {
            if(grid[x][y] == 1) {
                grid[x][y] = 0;
                dfs(grid, x, y+1);
                dfs(grid, x-1, y);
                dfs(grid, x, y-1);
                dfs(grid, x+1, y);
                
            } 
        }
    }
};

int main(int argc, const char** argv) {
    vector<vector<bool>>grid{
    {0,1,0,0,1,1,1,0,0,0,0,0,1,0,0,0,0,1,0,1},
    {1,0,1,0,0,1,1,0,0,1,0,1,0,1,0,1,1,0,0,0},
    {0,1,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,0,1},
    {1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,1,0,1,1,0},
    {0,1,0,1,1,0,1,0,0,0,1,0,0,1,0,0,0,0,0,1},
    {1,0,0,1,0,1,0,0,0,1,1,0,1,0,0,1,0,0,0,0},
    {1,0,0,0,1,1,0,0,0,0,0,1,0,0,1,0,0,0,0,1},
    {1,0,0,0,1,0,1,1,1,0,1,0,1,1,1,1,0,0,0,1},
    {1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,1},
    {0,0,0,1,0,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0},
    {1,0,1,0,1,0,0,1,1,1,0,1,1,0,0,1,1,0,0,0},
    {0,1,0,0,1,0,0,0,0,0,0,1,1,1,1,0,0,0,1,0},
    {1,0,0,0,1,1,1,0,1,0,0,0,1,0,1,0,1,0,0,1},
    {0,0,0,0,1,0,1,1,0,1,0,1,0,1,1,1,1,0,0,0},
    {0,1,1,0,0,0,0,1,0,0,1,1,1,0,0,1,1,0,1,0},
    {1,0,1,1,1,1,1,1,0,1,1,0,1,0,0,1,0,0,0,1},
    {1,0,0,0,1,0,1,0,0,1,0,1,0,0,1,0,0,1,1,1},
    {0,0,1,0,0,0,0,1,0,0,1,1,0,1,1,1,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,1,1,0,1,0,1,0,0,0,1,1},
    {1,0,0,0,1,0,1,1,1,0,0,1,0,1,0,1,1,0,0,0}};
    vector<vector<bool>>grid1{{1,1,1,1,0},
                             {1,1,0,1,0},
                             {1,1,1,1,0},
                             {1,1,0,0,0},
                             {0,0,0,0,0},
                             };
    Solution s;
    auto res =  s.numIslands(grid1);
    cout << "res is " << res << endl;
    return 0;
}