#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findTwoSum(vector<int> &numbers, int index, vector<vector<int>>& res) {
    int left = index + 1;
    int right = numbers.size() - 1;
    int target = -numbers[index];
    while (left < right) {
        int sum = numbers[left] + numbers[right];    
        if (target > sum) {
            left++;
        } else if (target < sum) {
            right--;
        } else {
            res.push_back(vector<int>{numbers[left], numbers[right], -target});
            left++;
            right--;
            while (left < right && numbers[left] == numbers[left-1]) {
                left++;
            }
        }
    }
}

vector<vector<int>> threeSum(vector<int> &numbers)
{
    vector<vector<int>> res;
    if (numbers.size() < 3) {
        return res;
    }
    std::sort(numbers.begin(), numbers.end());
    for (int i = 0; i < numbers.size(); ++i) {
        if (i != 0 && numbers[i] == numbers[i-1]) {
            continue;
        }
        findTwoSum(numbers, i, res);
    }

    return res;
}

int main(int argc, const char** argv) {
    vector<int> arr{-1,-1,-1,-1,0,0,1,1,1,1};
    auto res = threeSum(arr);
    for (auto r: res) {
        for (auto i : r) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}