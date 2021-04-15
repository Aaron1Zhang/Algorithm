#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int binary_search(vector<int>& arr, int left, int right, int key) {
    if(right < left)
        return -1; 
    while(left <= right) {
        auto mid = left + (right - left) / 2;
        if(key < arr[mid]) {
            right = mid - 1;
        } else if(key > arr[mid]) {
            left = mid + 1;
        } else {
            return mid;
        }

    }
    return -1;
}


int main(int argc, const char** argv) {
    vector<int> arr{1,3,5,7,8};
    std::sort(arr.begin(), arr.end());
    int key = 8;
    auto pos = binary_search(arr, 0, arr.size() - 1, key);
    cout << "pos is at " << pos << endl;
    return 0;
}