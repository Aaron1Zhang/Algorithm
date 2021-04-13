#include <iostream>
#include <vector>
using namespace std;

int Horme(vector<int>& arr, int left, int right) {
    auto pivot = arr[left];
    auto i = left;
    for(int j = i + 1; j <= right; ++j) {
        if(arr[j] <= pivot) {
            ++i;
            std::swap(arr[j], arr[i]);
        }
    }
    std::swap(arr[left], arr[i]);
    return i;
}

int divide(vector<int>& arr, int left, int right) {
    auto pivot = arr[left];
    auto pos = left;
    while(left < right) {
        while(left < right && arr[left] <= pivot) {
            left++;
        }
        while(left < right && arr[right] >= pivot) {
            right--;
        }
        if(left < right) {
            std::swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
    if(arr[right] <= pivot) {
        std::swap(arr[right], arr[pos]);
        return right;
    }
    std::swap(arr[right-1], arr[pos]);
    return right-1;
}

int better_divide(vector<int>& arr, int left, int right) {
    auto pivot = arr[left];
    while(left <= right) {
        while(left <= right && arr[left] < pivot) {
            left++;
        }
        while(left <= right && arr[right] > pivot) {
            right--;
        }
        if(left <= right) {
            std::swap(arr[left], arr[right]);
        }
    }
}
void quick_sort(vector<int>& arr, int left, int right) {
    if(left >= right)
        return;
    //auto pos = divide(arr, left, right);
    auto pos = Horme(arr, left, right);
    quick_sort(arr, 0, pos-1);
    quick_sort(arr, pos+1, right);
}

int main(int argc, const char** argv) {
    vector<int> vec{3,5,6,1,4,2,3};
    //int k = 2;
    quick_sort(vec, 0, vec.size()-1);
    for(auto i : vec) {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}