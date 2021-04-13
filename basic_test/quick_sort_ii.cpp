#include <iostream>
#include <vector>
using namespace std;

// int Horim(vector<int>& arr, int left, int right) {
//     auto i = left;
//     auto j = i+1;
//     auto pivot = arr[left];
//     for(; j <= right; ++j) {
//         if(arr[j] <= pivot) {
//             ++i;
//             std::swap(arr[i], arr[j]);
//         }
//     }
//     std::swap(arr[i], arr[left]);
//     return i;
    
// }

// void quick_sort(vector<int>& arr, int left, int right) {
//     if(left >= right) {
//         return;
//     }

//     auto pos = Horim(arr, left, right);
//     quick_sort(arr, left, pos-1);
//     quick_sort(arr, pos+1, right);
// }
// int main(int argc, const char** argv) {
//     vector<int> arr{1,4,7,3,5,2,4, 4,-1};
//     quick_sort(arr, 0, arr.size() -1);
//     for(auto i: arr) {
//         cout << i << " ";
//     }
//     return 0;
// }

int Homre(vector<int>& arr, int left, int right) {
    int i = left;
    auto pivot = arr[left];
    int j = left + 1;
    for(; j <= right; ++j) {
        if(arr[j] <= pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[left], arr[i]);
    return i;
}
 
void quick_sort(vector<int>& arr, int left, int right) {
    if(left >= right) 
        return;
    auto pos = Homre(arr, left, right);
    quick_sort(arr, left, pos - 1);
    quick_sort(arr, pos + 1, right);
}

int main(int argc, const char** argv) {
    vector<int> arr{3,2,1,4,5, 0, -2, 0, 0};
    quick_sort(arr, 0, arr.size() - 1);

    for(auto i: arr) 
        cout << i << " ";
    cout << endl;
    return 0;
}