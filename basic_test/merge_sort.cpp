#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    temp.reserve(right-left+1);

    auto i = left;
    auto j = mid + 1;
    while(i <= mid && j <= right) {
        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            ++i;
        } else {
            temp.push_back(arr[j]);
            ++j;
        }

    }
    while(i <= mid) {
        temp.push_back(arr[i]);
        ++i;
    }
    while(j <= right) {
        temp.push_back(arr[j]);
        ++j;
    }
    for(int k = left, t = 0; k <= right; ++k) {
        arr[k] = temp[t++];
    }
}

void merge_sort(vector<int>& arr, int left, int right) {
    if(left >= right)
        return;
    auto mid = left + (right-left)/2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid+1, right);
    merge(arr, left, mid, right);

}

int main(int argc, const char** argv) {
    vector<int> arr{3,5,1,7,2,4,1,3};
    merge_sort(arr, 0, arr.size() - 1);
    for(auto i: arr) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}